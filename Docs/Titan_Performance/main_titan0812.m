clear
clc
%   Sizing brief :
%   Cruising speed is near 15 m/s ( greater than 15 is better ) 
%   Aircraft Cd0 is determined to be 0.0290.
%   Aircraft  K  is determined to be 0.0525.
%   The airport is located at a city with an elevation of 0 m. 
%   Using the matching plottechnique, determine the wing area (S) and engine power (P) 
%   of the aircraft that is required to have the following performance capabilities :

%   (1). Stall speed                  : less than 12 m/s.
%   (2). Region of velcoity stability : Vc greater than 1.15*V_minT 
%   (3). Maximum speed                : V_Max=Vc*1.2 at 100 m.(assume that the maximum speed is about 20¡V30% greater than the cruise speed)
%   (4). Take-off run                 : less than  70 m ( on a dry concrete runway ).
%   (5). Landing distance             : less than 140 m ( on a dry concrete runway ).
%   (6). Service ceiling              : h_c = 500 m; 
%% Initial Condition

% Flight Altitude condition. (m)
h = 100; % (m),cruising altitude
h_c = 500; % (m),service ceiling altitude
h_airport=0; %(m),airport altitude
h_sealevel = 0; % (m),sealevel altitude
[~,a,~,rho,g,mu]=Standard_Atmosphere(h); 
[~,~,~,rho_c,~,~]=Standard_Atmosphere(h_c);
[~,~,~,Rho_airport,~,~]=Standard_Atmosphere(h_airport); 
[~,~,~,rho_sealevel,g_sealevel,~]=Standard_Atmosphere(h_sealevel);   
Sigma = rho/rho_sealevel;
SigmaC=rho_c/rho_sealevel;
SigmaA=Rho_airport/rho_sealevel;

% spec
V_stall_spec=12; % (m/s)
S_To=70; % (m), Take-off run 
S_LD=150;% (m), Landing distance 
Vc=18; % (m/s),Cruising speed is near 15 m/s
    % for Step2, Step3
    factor_vc=1.1805;
    factor_vmax=1.5;
    
% interative Initial Condition
K =  0.0504;
Cd0= 0.0325;
CL_max=1.323;
interation_max=100;
error=0.001;

value=[ K Cd0 ];
iteration=0;
flag=true;
while flag
iteration=iteration+1
close all 

% for plot
N_x=600; % number of x interval 
x = 1:N_x; % for
V_Stall=sqrt(2/(Rho_airport*CL_max)*x);
y1 = x; % for Vstall
y2 = x; % for Region of velcoity stability
y5 = x; % for Landing distance

% for Step4 Take off run
h_ob=0.6; % (m),obstacle hight
Mu_r=0.04; % brake off
Eta_pr=0.7; % propeller efficiency
R=(1.15*V_Stall).^2/(g*(1.19-1));
theta_ob=acos(1-h_ob./R);
s_a=R.*sin(theta_ob);
L_over_W=(0.7*1.1)^2*0.9;
D_over_W=(Cd0+K*(0.9*CL_max)^2)/(0.9*CL_max);

% for Step5 Landing distance 
% w/p is independent of w/s, namely a line
j=1.15; % for GA aft
N=3; % s free siding time
h_ob_landing=0.6; % (m),same as h_ob
theta_appro = 3*pi/180;% approach angle
Mu_r_landing=0.04; % brake off
% make w/s as a function not a value
% x = w/s
syms x5
V_Stall_landing_use=sqrt(2/(Rho_airport*CL_max)*x5); 
V_flare = 1.23*V_Stall_landing_use;
R_landing = V_flare.^2/(0.2*g);
h_f_landing = R_landing*(1-cos(theta_appro));
s_a_landing = (h_ob_landing-h_f_landing)/tan(theta_appro);
s_f_landing = R_landing*sin(theta_appro);
n=1.2; n_safe=n/1.23^2; 
L_over_W_landing=(0.7*1.15)^2*n_safe;
D_over_W_landing=(Cd0+K*(n_safe*CL_max)^2)/(n_safe*CL_max);

% Step6 Ceiling
ROC_Ceiling=0.; %(m/s), Absolute ceiling
E_star=1/sqrt(4*K*Cd0); % (L/D)max  

%% Curve function from performance parameter
% 1HP = 745.7 W

% Step1 Vstall
% make w/s as a function not a value
% x = w/s
x1=0.5*rho_sealevel*V_stall_spec^2*CL_max*ones(1,N_x);%(N/m^2)

% Step2 Region of velcoity stability
x2=sqrt(Cd0/K)*Vc^2*rho/2*ones(1,N_x)/factor_vc^2;

% Step3 Vmax 
V_Max=factor_vmax*factor_vc*sqrt(2/rho*sqrt(K/Cd0)*x);
y3=(Eta_pr*745.7)./(0.5*rho_sealevel*V_Max.^3*Cd0.*(1./x)+...
    ((2*K)./(rho*Sigma*V_Max)).*x); %(HP^-1)

% Step4 Take off run
y4=745.7./( 1/SigmaA*0.7*1.1*V_Stall./Eta_pr.*((D_over_W+Mu_r*(1-L_over_W))...
    +1/(g*Rho_airport*CL_max)*1.21*x./(S_To-1.1*N*sqrt(2/Rho_airport*x/CL_max)-s_a)) ); %(HP^-1)

% Step5 Landing distance
[x5] =  vpasolve( S_LD==j*N*sqrt(2*x5/rho_sealevel/CL_max)...
    +j^2*x5/g/rho_sealevel/CL_max/((D_over_W_landing+Mu_r_landing*(1-L_over_W_landing)))...
    +s_a_landing+s_f_landing);
x5=x5*ones(1,N_x);

% Step6 Ceiling
Aux10 = (1/sqrt(3)+sqrt(3))/(2*E_star);
V_RC = sqrt(2*x/rho_c*sqrt(K/3/Cd0));
Aux11 = ROC_Ceiling+V_RC*Aux10;
y6=745.7*SigmaC*Eta_pr./Aux11;

% plot data
plot(x1,y1,'--',x2,y2,'k',x,y3,'-r',x,y4,'-m',x5,y5,'b',x,y6,'g')
legend('(1)Vstall','(2)Velcoity stability','(3)Vmax','(4)Take-Off-Run','(5)Landing distance','(6)Ceiling')
xlabel('W/S(N/m^2)'); ylabel('W/P(N/hp)')
axis([0 N_x/2 0 N_x]);
grid on

%% determine  Design Wingloading & Powerloading by itself
% let xpoint = Design Wingloading
x1=x1(1); x2=x2(1); x5=x5(1);
compare=[x1 x2 x5];
    if min(compare)==x2
        if x1<x5
            xpoint=x1;
        elseif x1==x5
            xpoint=x1;
        else
            xpoint=x5;
        end
    else
        disp('caution: "please ajust specification" ')
        return
    end

% let W_over_P = Design Powerloading
% Step3 Vmax
V_c=factor_vc*sqrt(2/rho*sqrt(K/Cd0)*xpoint);
V_max=V_c*factor_vmax;
y3=745.7*(Eta_pr)./(0.5*rho_sealevel*V_max.^3*Cd0.*(1./xpoint)+...
    ((2*K)./(rho*Sigma*V_max)).*xpoint);

% Step4 Takeoff run    
V_Stall=subs(V_Stall_landing_use,xpoint);
R=(1.15*V_Stall).^2/(g*(1.19-1));
theta_ob=acos(1-h_ob./R);
s_a=R.*sin(theta_ob);
L_over_W=(0.7*1.1)^2*0.9;
D_over_W=(Cd0+K*(0.9*CL_max)^2)/(0.9*CL_max);
y4=745.7./( 1/SigmaA*0.7*1.1*V_Stall./Eta_pr.*((D_over_W+Mu_r*(1-L_over_W))...
    +1/(g*Rho_airport*CL_max)*1.21*xpoint./(S_To-1.1*3*sqrt(2/Rho_airport*xpoint/CL_max)-s_a)) ); %(HP^-1)

% Step6 Ceiling
V_RC_design = sqrt(2*xpoint/rho_c*sqrt(K/3/Cd0));
Aux11_design = ROC_Ceiling+V_RC_design*Aux10;
y6=745.7*SigmaC*Eta_pr/Aux11_design;
W_over_P=min([y3 y4 y6]);

%% =====================================================================================================================================
%% MOTWeight estimation
%% ===================================================================================================================================================
% MOTWeight brief :
% MTOW is less than 15 kg.
% Range_km=90

%% Initial Condition
Range_km=90; % Km

% [W_total,Mass_total,Mass_battery,Mass_emty,Rnage_max]=for_range(Cd0,K,xpoint,h,Range_km)
[W,~,~,~]=for_range_fuel(Cd0,K,xpoint,h,Range_km);
S=W/xpoint;
P_hp=W/W_over_P;
P_watt=P_hp*745.7;

%% Recompute the data when gettingWingloading & Powerloading 

% ROC: more than inf at sea level.
ROC_m_s = vpa( P_watt*Eta_pr*Sigma/W - sqrt(2*xpoint*sqrt(K/3/Cd0)/rho)*1.155*sqrt(4*Cd0*K),5 );

% Step1 Vstall
V_Stall=sqrt(2*xpoint/(Rho_airport*CL_max));

% Step2 Region of velcoity stability
V_c=factor_vc*sqrt(2/rho*sqrt(K/Cd0)*xpoint);

% Step3 Vmax 
V_max=V_c*factor_vmax;
Powerloading_maxspeed=(Eta_pr)./(0.5*rho_sealevel*V_max.^3*Cd0.*(1./xpoint)+...
    ((2*K)./(rho*Sigma*V_max)).*xpoint);
power_required_maxspeed=W/Powerloading_maxspeed;

% Step4 Takeoff run
total_takeoff = s_a + 1.21*xpoint/((g*Rho_airport*CL_max)*...
    (P_watt*SigmaA*Eta_pr/(0.7*1.1*V_Stall*W)-D_over_W-Mu_r*(1-L_over_W)))+1.1*N*sqrt(2/Rho_airport*xpoint/CL_max);
Powerloading_takeoff=1/( 1/SigmaA*0.7*1.1*V_Stall/Eta_pr*((D_over_W+Mu_r*(1-L_over_W))...
    +1/(g*Rho_airport*CL_max)*1.21*xpoint/(S_To-1.1*N*sqrt(2/Rho_airport*xpoint/CL_max)-s_a)) );
power_required_Takeoff =W/Powerloading_takeoff;

% Step5 Landing distance
V_flare = 1.23*V_Stall;
R_landing = V_flare.^2/(0.2*g);
h_f_landing = R_landing*(1-cos(theta_appro));
s_a_landing = (h_ob_landing-h_f_landing)/tan(theta_appro);
s_f_landing = R_landing*sin(theta_appro);
n=1.2;
n_safe=n/1.23^2; 
L_over_W_landing=(0.7*1.15)^2*n_safe;
D_over_W_landing=(Cd0+K*(n_safe*CL_max)^2)/(n_safe*CL_max);

s_g_landing = j*N*sqrt(2*xpoint/rho_sealevel/CL_max)+j^2*xpoint/g/rho_sealevel/CL_max/((D_over_W_landing+Mu_r_landing*(1-L_over_W_landing)));
total_landing_distance = s_a_landing+s_f_landing+s_g_landing;

% Step6 Ceiling
V_RC_design = sqrt(2*xpoint/rho_c*sqrt(K/3/Cd0));
Aux11_design = ROC_Ceiling+V_RC_design*Aux10;
Powerloading_ceiling=SigmaC*Eta_pr/Aux11_design;
power_required_ceiling=W/Powerloading_ceiling;

%% other power compute
% under minimum power requied
temp00_minP = (3/K/Cd0^(1/3))^(3/4)/4;
Powerloading_Min_power = Eta_pr*Sigma*sqrt(rho)*temp00_minP/sqrt(2)/xpoint^(0.5);
power_required_Min_power=W/Powerloading_Min_power;

% under minimum thrust requied
Cl_minT = sqrt(Cd0/K);
Cd_minT = 2*Cd0;
temp00_minT = Cl_minT^(3/2)/Cd_minT;
Powerloading_min_T=Eta_pr*Sigma*sqrt(rho)*temp00_minT/sqrt(2)/xpoint^(0.5);
power_required_min_T=W/Powerloading_min_T;

% under minimum crusing requied
Cl_c = 2*xpoint/rho/V_c^2;
Cd_c = Cd0 + K*Cl_c^2;
%---------Same vlaue as the following way-----------
%temp00_crusing = Cl_c^(3/2)/Cd_c;
%Powerloading_crusing=Eta_pr*Sigma*sqrt(rho)*temp00_crusing/sqrt(2)/xpoint^(0.5);
%power_required_crusing=vpa(W/Powerloading_crusing,5)
%---------------------------------------------------
Drag_c = 0.5*rho * V_c^2 * S *Cd_c; 
power_required_crusing = Drag_c*V_c/(Eta_pr*Sigma);

 %% display
fprintf(' ==========================================================\n')
fprintf('               Preliminary design of aircraft              \n')                              
fprintf(' ==========================================================\n')
fprintf('    Mainwing surface  = %.5f m^2  \n',S)
fprintf('    Wing loading      = %.5f N/m^2\n',xpoint)
fprintf('    Stall speed       = %.5f m/s  \n',V_Stall)
fprintf('    Cruising speed    = %.5f m/s  \n',V_c)
fprintf('    Maximum speed     = %.5f m/s  \n',V_max)
fprintf('    Take off distance = %.5f m    \n',total_takeoff)
fprintf('    landing distance  = %.5f m    \n\n',total_landing_distance)
fprintf(' << Minimum power (brake power) required analysis (sealevel) >> \n')
fprintf('       power required Takeoff    = %.3f watt \n',power_required_Takeoff)
fprintf('       power required ceiling    = %.3f watt \n',power_required_ceiling)
fprintf('       power required min_power  = %.3f watt \n',power_required_Min_power)
fprintf('       power required min_Thrust = %.3f watt \n',power_required_min_T)
fprintf('       power required crusing    = %.3f watt \n',power_required_crusing)
fprintf('       power required maxspeed   = %.3f watt \n',power_required_maxspeed)
fprintf('--------------Compared to above analysis-------------- \n')
Mini_power_req=max([power_required_Takeoff  power_required_ceiling  power_required_Min_power...
                    power_required_min_T    power_required_crusing  power_required_maxspeed]);
fprintf('         Minimum power required = %.3f watt\n',Mini_power_req)

%% ===================================================================================================================================================
%% Mainwing design
%% ===================================================================================================================================================
W_ave = W;
W_TO = W;

% ideal lift coefficient:
CL_cruise_w = 2*W_ave/(rho*V_c^2*S);
Cl_i = CL_cruise_w /0.9;

% maximum lift coefficient:
CL_max_w = 2*W_TO/(rho_sealevel*V_Stall^2*S);
Clmax_gross =  CL_max_w/0.9;

% The Uav has not flap, and the split flap generates a DCL of 0  
D_Clmax_HLD = 0;
Clmax =  Clmax_gross - D_Clmax_HLD;

% NACA 63(2)-615 airfoil is chosen.
alpha=pi/180*[-10	-9.75	-9.5	-9.25	-9	-8.75	-8.5	-8.25	-8	-7.75	-7.5	-7.25	-7	-6.75	-6.5	-6.25	-6	-5.75	-5.5	-5.25	-5	-4.75	-4.5	-4.25	-4	-3.75	-3.5	-3.25	-3	-2.75	-2.5	-2.25	-2	-1.75	-1.5	-1.25	-1	-0.75	-0.5	-0.25	0	0.25	0.5	0.75	1	1.25	1.5	1.75	2	2.25	2.5	2.75	3	3.25	3.5	3.75	4.25	4.5	4.75	5	5.25	5.5	5.75	6	6.25	6.5	6.75	7	7.25	7.5];
cl=[-0.5706	-0.5437	-0.5185	-0.4957	-0.4736	-0.4497	-0.4261	-0.4036	-0.3804	-0.3555	-0.3304	-0.3069	-0.2816	-0.2552	-0.2296	-0.2033	-0.1761	-0.1492	-0.1214	-0.0938	-0.0658	-0.0378	-0.0096	0.0193	0.0486	0.0778	0.107	0.1361	0.1653	0.1944	0.2234	0.2524	0.2815	0.3105	0.3393	0.3684	0.3972	0.4261	0.4551	0.4838	0.5129	0.5414	0.5701	0.5991	0.6275	0.6562	0.6847	0.713	0.7417	0.7698	0.7981	0.8262	0.8542	0.8823	0.9098	0.9374	0.9917	1.0183	1.045	1.071	1.0962	1.1212	1.1464	1.1714	1.1956	1.2187	1.2407	1.2607	1.2771	1.2893];
p1=polyfit(alpha,cl,1);

%%  oswald efficiency factor(find AR)
syms AR_w 
lambda = 0.4; % Taper ratio
M = V_c/a;
thickness = 0.15;
sweep_angle = 0;
f = 0.005*(1+1.5*(lambda-0.6)^2);
AR_w = double(solve(    1/(pi*AR_w*K) == 1/( (1+ 0.12*M^6)*(1 + ( 0.142 + f*AR_w*(10*thickness)^0.33 )/cos(sweep_angle)^2) )   ));
e=double(1/(pi*AR_w*K));
%% geometry
i_w = 2; % wing setting angle (deg)
a_2d = p1(1); % lift curve slope (1/rad)
alpha_L0 = -p1(2)/p1(1)*180/pi; % zero-lift angle of attack (deg)
b = double(sqrt(AR_w*S)); % wing span (m)
Croot = 2*S/(1+lambda)/b;
Ctip = Croot*lambda;
mac_w = Croot *(2/3)*(1+lambda+lambda^2)/(1+lambda);
wing_y_mac=b*(1+2*lambda)/6/(1+lambda);
%% Lift distribution
N = 9; % (number of segments - 1)
theta = pi/(2*N):pi/(2*N):pi/2;
alpha_twist = 0.0001; % Twist angle (deg)
alpha = i_w+alpha_twist:-alpha_twist/(N-1):i_w;
% segment's angle of attack
z = (b/2)*cos(theta);
c = Croot * (1 - (1-lambda)*cos(theta)); % Mean Aerodynamics
%Chord at each segment (m)
mu_liftdistri = c * a_2d / (4 * b);
LHS = mu_liftdistri .* (alpha-alpha_L0)/57.3; % Left Hand Side
% Solving N equations to find coefficients A(i):
for i=1:N
    for j=1:N
    B(i,j) = sin((2*j-1) * theta(i)) * (1 + (mu_liftdistri(i) * (2*j-1)) /sin(theta(i)));
    end
end
A=B\transpose(LHS);
for i = 1:N
    sum1(i) = 0;
    sum2(i) = 0;
    for j = 1 : N
        sum1(i) = sum1(i) + (2*j-1) * A(j)*sin((2*j-1)*theta(i));
        sum2(i) = sum2(i) + A(j)*sin((2*j-1)*theta(i));
    end
end
CL = 4*b*sum2 ./ c;
CL1=[0 CL(1) CL(2) CL(3) CL(4) CL(5) CL(6) CL(7) CL(8) CL(9)];
y_s=[b/2 z(1) z(2) z(3) z(4) z(5) z(6) z(7) z(8) z(9)];
figure(2)
plot(y_s,CL1,'-o')
grid
title('Lift distribution')
xlabel('Semi-span location (m)')
ylabel ('Lift coefficient')
% A
CL_cruise_Ld = vpa(pi * AR_w * A(1));
delta = 3*(A(3)/A(1))^2+5*(A(5)/A(1))^2+7*(A(7)/A(1))^2+9*(A(9)/A(1))^2;
CD_wing_i = vpa(CL_cruise_Ld^2/((pi*AR_w)*(1+delta)) );
%% lift curve slope of wing (recompute by setting angle )
CL_alpha_w = a_2d/(1 + a_2d/((pi*AR_w)*(1+delta))) ;
CL_cruise_sa = vpa( (i_w - alpha_L0)*CL_alpha_w/57.3 );
i_w = (CL_cruise_w/CL_alpha_w)*180/pi + alpha_L0; % CL_cruise_w is in line 254
%% display
fprintf(' ==========================================================\n')
fprintf('               Mainwing design of aircraft                 \n')                              
fprintf(' ==========================================================\n')
fprintf('    ideal lift coefficient Cl_i     = %.5f \n',Cl_i)
fprintf('    maximum lift coefficient Cl_max = %.5f \n',Clmax)
fprintf(' ===========find airfoil to go to next section ===========\n\n')
fprintf('    desired CL_cruise                    = %.5f  \n',CL_cruise_w)
fprintf('    desired CL_max                       = %.5f  \n',CL_max_w)
fprintf('    actual CL_cruise by distribution way = %.5f  \n',CL_cruise_Ld)
fprintf('    actual CL_cruise by setting angle    = %.5f  \n',CL_cruise_sa)
fprintf(' ====compared above is working, then go to next section======\n\n')
fprintf('    Span          of mainwing       = %.5f m \n',b)
fprintf('    AR            of mainwing       = %.5f   \n',AR_w)
fprintf('    Mean Aerodynamic Chord          = %.5f m \n',mac_w)
fprintf('    MAC y position(spanwise)        = %.5f m \n',wing_y_mac)
fprintf('    Taper  ratio  of mainwing       = %.5f   \n',lambda)
fprintf('    Root chord    of mainwing       = %.5f m \n',Croot)
fprintf('    Tip  chord    of mainwing       = %.5f m \n',Ctip)
fprintf('    lift slope of mainwing(3D)      = %.5f 1/rad \n',CL_alpha_w)
fprintf('    setting angle of mainwing       = %.5f deg\n',i_w)


%% ===================================================================================================================================================
%% horizontal tail design and size
%% ===================================================================================================================================================

%------------- the following data need to manually update ----------------
% vertical tail need to be declared in order to make sure cr_ht is aligned with ct_vt
b_vt=0.277; % measure from catia
align_length_z=-0.018; % Distance from ac_w to edge of vertical tail root chord
V_vt=0.07; % vertical_stabiliser_volume_coefficient

% horizontal tail basic parameter
Cm_ac_w = -0.1125; % wing A.C. moment coefficient
b_ht =0.85;
SM_spec=15;
factor_l_ht2l_w=3.1;
%--------------------------------------------------------------------------

% solve S_ht for SM_spec
syms S_ht
l_ht2l_w=factor_l_ht2l_w*mac_w; % empirical assumption (distance from tail a.c. to wing a.c., meter)
% tail aspect ratio (empirical assumption)
rad2deg = 90./asin(1);
a_2d_t =0.0992*rad2deg ; % observe from excel, lift curve slope per radian (NACA-0012)
eta_ht = 1;% tail efficiency
AR_ht=b_ht^2/S_ht;
mac_ht = S_ht/ b_ht; % assume rectangular planform
CL_alpha_ht = a_2d_t/(1 + a_2d_t/(pi*AR_ht))  ; % tail lfit slope per radian

%% the downwah angle & gradient can be estimated from PLL_Downwash.m
Planform = [];
Lambda_c4=[];
BIG_omeaga=[];
X=l_ht2l_w;
Y=b_vt+align_length_z;
Z=0; % spanwise direction
[Kv,Kb,Kp,Ks,Kd]=PLL_Downwash... 
    (AR_w,lambda,CL_cruise_w,b,X,Y,Z,Planform,Lambda_c4,BIG_omeaga,a_2d);
epsilon_d0 = vpa(Kv*Kp*Ks/Kb*CL_cruise_w/AR_w*rad2deg,5);
epsilon_alpha = vpa(Kv*Kp*Ks/Kb*CL_alpha_w/AR_w,5);
i_t = epsilon_d0;

% simple way (no use)
% epsilon_d0_o = vpa((2/pi/AR_w)*CL_cruise_w*rad2deg,5)
% epsilon_alpha_O = vpa((2/pi/AR_w)*CL_alpha_w,5)

%% The location of the aerodynamic center of the wing relative to the center of gravity
% Assuming the minimum drag axis of fuselage is aligned with the FRL
l_w = Cm_ac_w/CL_cruise_w*mac_w; % distance from wing a.c to c.g.
l_ht = l_ht2l_w +l_w;
V_ht =l_ht*S_ht/(S*mac_w);
Cm_alpha = -(l_w/mac_w)*CL_alpha_w - ... 
           (l_ht/mac_w)*(S_ht/S)*eta_ht*CL_alpha_ht*(1-epsilon_alpha);
CL_alpha = CL_alpha_w + (S_ht/S)*eta_ht*CL_alpha_ht*(1-epsilon_alpha);
SM = -Cm_alpha/CL_alpha*100;
S_ht=solve(SM==SM_spec);
AR_ht=subs(AR_ht);
mac_ht =subs(mac_ht);
CL_alpha_ht=double(subs(CL_alpha_ht));
V_ht=double(subs(V_ht));
Cm_alpha=subs(Cm_alpha);
CL_alpha=subs(CL_alpha);
SM=subs(SM);

%% explain line 443 is CL_alpha_w, is not CL_alpha , and author is lazy to revise. 
np=double((0 + eta_ht*V_ht*CL_alpha_ht/CL_alpha_w*(1-epsilon_alpha) ))*mac_w;
st_m=double(-Cm_alpha/CL_alpha_w)*100;
%%  Plot the trimmed angle of attack and elevator deflection for variable airspeed between  stallspeed & maximum speed 
CL_0 = CL_cruise_w;
v_1 = V_Stall:0.01:V_max; % variable airspeed between  stallspeed % maximum speed 
CL_trim = W./(0.5*rho*v_1.^2*S);
Cm_0 = 0;
tau_ht = 0.5; % elevator effectiveness, observe from "control_surface_tau"jpg., select C_ele/C_ht=0.31764, b_ele/b_ht=0.85

Cm_ac_delta_e=-0.22; %(1/rad) tail A.C. moment coefficient due to elevator deflection (NACA-0012
CL_delta = (S_ht/S)*eta_ht*CL_alpha_ht*tau_ht;
Cm_delta = (mac_ht/mac_w)*(S_ht/S)*eta_ht*Cm_ac_delta_e- ...
           (l_ht/mac_w)*(S_ht/S)*eta_ht*CL_alpha_ht*tau_ht;
dy_pressure = 0.5*rho*(v_1).^2;

% solve alpha_trim & delta_trim
det = CL_alpha*Cm_delta - CL_delta*Cm_alpha;
alpha_trim = double( ((CL_trim - CL_0)*Cm_delta + CL_delta*Cm_0)/det  );
delta_trim = double( (-(CL_trim - CL_0)*Cm_alpha - CL_alpha*Cm_0)/det );

%compute Lift force on Tail
Tail_force = ((S_ht/S)*eta_ht*CL_alpha_ht*(1-epsilon_alpha)*alpha_trim + ...
               CL_delta * delta_trim).* dy_pressure* S;

% plot
figure(3)
yyaxis left
plot(v_1, alpha_trim*rad2deg, v_1, delta_trim*rad2deg)
title('Trimmed AOA,Elevator Deflections and Tail Force')
xlabel('Airspeed (m/sec)')
ylabel('AOA and Elevator deflection Degree')

yyaxis right
plot(v_1,Tail_force)
ylabel('Tail force (Nt)')
legend('\alpha','\delta','Lift force on Tail')
grid on
       
%% display
fprintf(' ==========================================================\n')
fprintf('            Horizontal tail design of aircraft             \n')                              
fprintf(' ==========================================================\n')
fprintf('    Area          of horizontal tail    = %.5f m^2   \n',S_ht)
fprintf('    span          of horizontal tail    = %.5f m     \n',b_ht)
fprintf('    AR            of horizontal tail    = %.5f       \n',AR_ht)
fprintf('    MAC           of horizontal tail    = %.5f m     \n',mac_ht)
fprintf('    Taper ratio   of horizontal tail    = %.5f       \n',1)
fprintf('    lift slope of horizontal tail (3D)  = %.5f 1/rad \n',CL_alpha_ht)
fprintf('    setting angle of horizontal tail    = %.5f deg   \n',i_t)
fprintf('    horizontal Tail Volume ratio        = %.5f       \n',V_ht)
fprintf('    distance from wing a.c to n.p.      = %.5f m     \n',np)
fprintf('    distance from wing a.c to c.g.      = %.5f m     \n',-l_w)
fprintf('    distance from wing a.c.to tail a.c. = %.5f m     \n',l_ht2l_w)
fprintf('    CL_delta (without fuselage)         = %.5f 1/rad \n',CL_delta)
fprintf('    Cm_delta (without fuselage)         = %.5f 1/rad \n',Cm_delta)
fprintf('    CL_alpha (without fuselage)         = %.5f 1/rad \n',CL_alpha)
fprintf('    Cm_alpha (without fuselage)         = %.5f 1/rad \n',Cm_alpha)
fprintf('    static margin                       = %.5f %%    \n',SM)
%% ===================================================================================================================================================
%%  vertiacal tail design and size(H tail design)
%% ===================================================================================================================================================
Ctip_vt=mac_ht;
b_vt=b_vt;

% solve l_vt to make sure cr_ht is aligned with ct_vt 
syms l_vt
S_vt = V_vt*b*S/l_vt;
AR_vt =2*b_vt^2/S_vt;
lambda_vt=Ctip_vt*b_vt/(S_vt-Ctip_vt*b_vt);
Croot_vt=Ctip_vt/lambda_vt;
mac_vt=Croot_vt *(2/3)*(1+lambda_vt+lambda_vt^2)/(1+lambda_vt);
wing_z_vt=b_vt*(1+2*lambda_vt)/3/(1+lambda_vt);
d1=( -(Croot_vt -Croot_vt *lambda_vt )/b_vt *wing_z_vt + Croot_vt )/4;
d3=Ctip_vt/4-Ctip_vt+3*d1;
l_vt=solve(l_ht-l_vt==d3);
[~,I]=min(abs(l_ht - l_vt)); % find nearest sol.
l_vt=double(l_vt(I));
% subdstitute value
l_vt2l_w=l_vt-l_w;
S_vt=double(subs(S_vt));
AR_vt=double(subs(AR_vt));
lambda_vt=double(subs(lambda_vt));
Croot_vt=double(subs(Croot_vt));
mac_vt=double(subs(mac_vt));
wing_z_vt=double(subs(wing_z_vt));
d3=double(subs(d3));
d1=double(subs(d1));

% equivalent traditional tail
b_vt_eq = sqrt(AR_vt*S_vt);
Croot_vt_eq = 2*S_vt/(1+lambda_vt)/b_vt_eq;
Ctip_vt_eq = Croot_vt_eq*lambda_vt;
mac_vt_eq = Croot_vt_eq *(2/3)*(1+lambda_vt+lambda_vt^2)/(1+lambda_vt);
wing_z_vt_eq=b_vt_eq*(1+2*lambda_vt)/3/(1+lambda_vt);

%% the Sidewash gradient can be estimated from PLL_Sidewash.m
%------------- the following data need to manually update ----------------
sweep_vt=1.015125*pi/180; % per radian 
%--------------------------------------------------------------------------
eta_vt=eta_ht;
Planform = [];
Lambda_c4=[];
BIG_omeaga=[];
X=l_vt2l_w;
Y=wing_z_vt+align_length_z;
Mach=V_c/a;
B=sqrt(1+Mach^2);
kappa=a_2d_t/(2*pi*B);
CL_alpha_vt=double(a_2d_t*AR_vt/( 2+sqrt(B^2*AR_vt^2/kappa^2*(1+tan(sweep_vt)^2/B^2)+4) ));

% H tail design
Z=b_ht/2; % spanwise direction
[~,~,~,Sidewash_gradient]=PLL_Sidewash...
    (AR_w,lambda,CL_cruise_w,b,X,Y,Z,Planform,Lambda_c4,BIG_omeaga,a_2d);
Sidewash_gradient=vpa(Sidewash_gradient,5);
Cn_beta_vt=vpa(eta_vt*V_vt*CL_alpha_vt*(1-Sidewash_gradient));

% equivalent traditional tail
Z=0.0; % spanwise direction
[~,~,~,Sidewash_gradient_eq]=PLL_Sidewash...
    (AR_w,lambda,CL_cruise_w,b,X,Y,Z,Planform,Lambda_c4,BIG_omeaga,a_2d);
Sidewash_gradient_eq=vpa(Sidewash_gradient_eq,5);

%------------- the following data need to manually update ----------------
% The VeDSC method for Cn_beta_vt
K_Fv=1;
K_Wv=0.85;
K_Hv=1.29;
Cn_beta_vt_VEDSC=vpa(K_Fv*K_Wv*K_Hv*eta_vt*V_vt*CL_alpha_vt);
% Flight Stability and Automatic Control textbook. p75
% This's a method for Cn_beta_f 
% h=h1=h2=0.2, 
xm=0.78;
kn=0.0035;
kRl=1.02;
Sfs=0.277559;
lf=1.1;
Cn_beta_f=-kRl*kn*Sfs*lf/(S*b)*57.3;
Cn_beta=vpa(Cn_beta_vt_VEDSC + Cn_beta_f);
%--------------------------------------------------------------------------

%% display
fprintf(' ==========================================================\n')
fprintf('               Vertiacal tail of aircraft                  \n')                              
fprintf(' ==========================================================\n')
fprintf('    Area          of vertiacal tail   = %.5f m^2   \n',S_vt)
fprintf('    span          of vertiacal tail   = %.5f m     \n',b_vt)
fprintf('    AR            of vertiacal tail   = %.5f       \n',AR_vt)
fprintf('    MAC           of vertiacal tail   = %.5f m     \n',mac_vt)
fprintf('    Root chord    of vertiacal tail   = %.5f m     \n',Croot_vt)
fprintf('    Tip  chord    of vertiacal tail   = %.5f m     \n',Ctip_vt)
fprintf('    Taper ratio   of vertiacal tail   = %.5f       \n',lambda_vt)
fprintf('    lift slope of vertiacal tail (3D) = %.5f 1/rad \n',CL_alpha_vt)
fprintf('    vertiacal Tail Volume ratio       = %.5f       \n',V_vt)
fprintf('    vertiacal distance from Croot_vt edge to tail a.c. = %.5f m \n',wing_z_vt)
fprintf('    horizontal distance from wing a.c.to tail a.c.     = %.5f m  \n',l_vt2l_w)
fprintf('    Cn_beta                                            = %.5f 1/rad \n',Cn_beta)



%% ===================================================================================================================================================
%% DATCOM ANALYSIS
%% ===================================================================================================================================================

% page 33 (reference point is the catia original point)
%------------- the following data need to manually update ----------------
ZCG=0.00718;
XW=0.613;
ZW=0.068;
align_length_z=align_length_z;
D=13; % diameter of propeller, apc13*6
df=0.2; % max fuselage diameter
gamma=2;% deg, £F dihedral angle
z_vt = 0.14311; % Distance from ac_vt to cg
%--------------------------------------------------------------------------

% Z compute
ZH=b_vt+ZW+align_length_z;
d4=(sqrt(2)-1)*b_vt/3*(1+2*lambda_vt)/(1+lambda_vt);
ZV=+ZW+align_length_z-d4;

% ac compute
Xac=XW+Croot/4;
Xac_ht=Xac+l_ht2l_w;
Xac_vt=Xac+l_vt2l_w;

% X compute
XCG=Xac-l_w;
XH=Xac_ht-mac_ht/4;
d1_eq=( -(Croot_vt_eq -Croot_vt_eq *lambda_vt )/b_vt_eq *wing_z_vt_eq + Croot_vt_eq )/4;
d2_eq=(Croot_vt_eq -Croot_vt_eq *lambda_vt)/b_vt_eq *wing_z_vt_eq;
XV=Xac_vt-d1_eq-d2_eq;

% datcom other compute
max_fuselage_width=df/2; % y direction, half df
propeller_rudius=D*0.0254/2;
u0=V_c;
Mach=u0/a;
thrust_coeff=2*Drag_c/(rho*V_c^2*S);

% write the  data into datcom
fid = fopen('F:\UAV\my_designed_plane\titan_twin_tail\titan.dcm','w');
fprintf(fid, '* DURING CRUISE                                              \n');
fprintf(fid, '************************                                     \n');
fprintf(fid, '*   List of Command Card                                     \n');
fprintf(fid, '************************                                     \n');
fprintf(fid, 'DIM M                                                        \n');
fprintf(fid, 'DAMP                                                         \n');
fprintf(fid, 'DERIV RAD                                                    \n');
fprintf(fid, 'PART                                                         \n');
fprintf(fid, '**********************                                       \n');
fprintf(fid, '*  Flight Conditions *                                       \n');
fprintf(fid, '**********************                                       \n');
fprintf(fid, ' $FLTCON NMACH=1.0,   MACH=%.3f,                             \n',Mach);
fprintf(fid, '         NALT=1.0,    ALT=%.3f,                              \n',h);
fprintf(fid, '         NALPHA=20.0, ALSCHD=-9.0,-8.0,-7.0,-6.0,-5.0,-4.0,-3.0,-2.0,-1.0,           \n');
fprintf(fid, '                              0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0,\n');
fprintf(fid, '         WT=%.3f,  GAMMA=0.0,                                \n',W);
fprintf(fid, '         LOOP=2.0$                                           \n');
fprintf(fid, '*************************                                    \n');
fprintf(fid, '*  Reference Parameters *                                    \n');
fprintf(fid, '*************************                                    \n');
fprintf(fid, ' $OPTINS BLREF=%.3f,SREF=%.3f,CBARR=%.3f$                    \n',b,S,mac_w);
fprintf(fid, '**************************************                       \n');
fprintf(fid, '* Group II     Synthesis Parameters  *                       \n');
fprintf(fid, '**************************************                       \n');
fprintf(fid, ' $SYNTHS XCG =%.4f,    ZCG=%.4f,                             \n',XCG,ZCG);
fprintf(fid, '         XW  =%.4f,    ZW=%.4f,                              \n',XW,ZW);
fprintf(fid, '         XH  =%.4f,    ZH=%.4f,                              \n',XH,ZH);
fprintf(fid, '         XV  =%.4f,    ZV=%.4f,                              \n',XV,ZV);
fprintf(fid, '         ALIW=%.4f,  ALIH=%.4f,                              \n',i_w,i_t);
fprintf(fid, '         VERTUP=.TRUE.$                                      \n');
fprintf(fid, '**********************************                           \n');
fprintf(fid, '*  Body Configuration Parameters *                           \n');
fprintf(fid, '**********************************                           \n');
fprintf(fid, ' $BODY NX=10.0,                                              \n');
fprintf(fid, '       X =-0.004, 0.055, 0.105, 0.155, 0.205, 0.255, 0.910, 0.950, 1.000, 1.100,\n');
fprintf(fid, '       S = 0.000, 0.014, 0.024, 0.032, 0.037, 0.039, 0.039, 0.037, 0.030, 0.008,\n');
fprintf(fid, '       R = 0.000, 0.061, 0.080, 0.090, 0.097, 0.100, 0.100, 0.097, 0.087, 0.050,\n');
fprintf(fid, '       P = 0.000, 0.435, 0.573, 0.672, 0.739, 0.765, 0.765, 0.736, 0.643, 0.314,\n');
fprintf(fid, '       ZU=-0.016, 0.055, 0.083, 0.100, 0.110, 0.115, 0.115, 0.112, 0.100, 0.050,\n');
fprintf(fid, '       ZL=-0.016,-0.068,-0.077,-0.082,-0.084,-0.084,-0.084,-0.082,-0.076,-0.050,\n');
fprintf(fid, '       DS=1.0,ITYPE=1.0,METHOD=1.0$                          \n');
fprintf(fid, '***********************************                          \n');
fprintf(fid, '*         Wing planform variables *                          \n');
fprintf(fid, '***********************************                          \n');
fprintf(fid, ' $WGPLNF CHRDTP=%.3f,  CHRDR=%.3f,                           \n',Ctip, Croot);
fprintf(fid, '         SSPNE =%.3f,  SSPN=%.3f,                            \n',(b/2-max_fuselage_width), b/2);
fprintf(fid, '         DHDADI=%.3f,  DHDADO=0.0,                           \n',gamma);
fprintf(fid, '         CHSTAT=0.25,  TWISTA=0.0,                           \n');
fprintf(fid, '         TYPE=1.0$                                           \n');
fprintf(fid, '**********************************************               \n');
fprintf(fid, '*         Horizontal Tail planform variables *               \n');
fprintf(fid, '**********************************************               \n');
fprintf(fid, ' $HTPLNF CHRDTP=%.3f,  CHRDR=%.3f,                           \n',mac_ht, mac_ht);
fprintf(fid, '         SSPNE =%.3f,  SSPN=%.3f,                            \n',b_ht/2, b_ht/2);
fprintf(fid, '         CHSTAT=0.25,  TWISTA=0.0,                           \n');
fprintf(fid, '         TYPE=1.0$                                           \n');
fprintf(fid, '********************************************                 \n');
fprintf(fid, '*         Vertical Tail planform variables *                 \n');
fprintf(fid, '********************************************                 \n');
fprintf(fid, ' $VTPLNF CHRDTP=%.3f, CHRDR=%.3f,                            \n',Ctip_vt_eq, Croot_vt_eq);
fprintf(fid, '         SSPNE =%.3f, SSPN=%.3f,                             \n',b_vt_eq, b_vt_eq);
fprintf(fid, '         CHSTAT=1.0,  TWISTA=0.0,                            \n');
fprintf(fid, '         TYPE=1.0$                                           \n');
fprintf(fid, '********************************************                 \n');
fprintf(fid, '*                                   PROPWR *                 \n');
fprintf(fid, '********************************************                 \n');
fprintf(fid, ' $PROPWR AIETLP=0.0, NENGSP=1.0,   THSTCP=%.4f,              \n',thrust_coeff);
fprintf(fid, '         PHALOC=1.25,PHVLOC=%.4f,PRPRAD=%.4f,                \n',ZCG,propeller_rudius);
fprintf(fid, '         ENGFCT=0.7, NOPBPE=2.0,                             \n');
fprintf(fid, '         YP=0.0,     CROT=.FALSE.$                           \n');
fprintf(fid, '**********************************************               \n');
fprintf(fid, '*  Wing Sectional Characteristics Parameters *               \n');
fprintf(fid, '**********************************************               \n');
fprintf(fid, 'NACA-W-6-63-615                                              \n');
fprintf(fid, 'NACA-H-4-0012                                                \n');
fprintf(fid, 'NACA-V-4-0012                                                \n');
fprintf(fid, 'CASEID titan                                                 \n');
fclose('all');

% execute titan.dcm
system('titan.dcm &');
while system(' "C:\Windows\System32\taskkill.exe" /F /im ac3dview.exe')
    pause(1)
end

% delete redundant files
[status,result] =system(' "C:\Windows\System32\taskkill.exe" /F /im ac3dview.exe /im cmd.exe & ');
delete('titan.xml')
delete('titan_aero.xml')
delete('titan.lfi')
delete('titan.csv')
delete('titan.1.ac')
delete('titan.2.ac')

% input titan.out
aero = datcomimport('titan.out');

% find new K Cd0 CL_max
CL = aero{1,1}.cl; 
CD = aero{1,1}.cd;
    % delete the 99999 data
    ind=find(CL < 2);
    CL=CL(min(ind):max(ind));
    ind=find(CD < 2);
    CD=CD(min(ind):max(ind));
p2= polyfit(CL,CD,2);
new_value=[p2(1) p2(3)];

current_error=abs(new_value - value)/abs(new_value)
    if current_error <= error
        flag=false;
    elseif iteration==interation_max
        flag=false;
    else 
        flag=true;
    end
    
value=new_value
K=value(1);
Cd0=value(2);
fprintf('=======================================================================================\n')
fprintf('=======================================================================================\n')
end

%% ===================================================================================================================================================
%% logitudinal motion
%% ===================================================================================================================================================
% basic data

%------------- the following data need to manually update ----------------
Ix = 0.620145; % kg*m^2
Iy = 1.324120; % kg*m^2
Iz = 1.703003; % kg*m^2
Ixz=-0.158395; % kg*m^2
%--------------------------------------------------------------------------
m=W/g;
Q = 0.5*rho*u0^2;
%% Aerodynamic Coefficients
CL_0 = aero{1,1}.cl(10); % C_L_0 is a equilibrium point
CD_0 = aero{1,1}.cd(10); % C_D_0 is a equilibrium point
CLM = 0;  % coefficient can be neglected at low flight speeds (P112) by Prandtl-Glauent formula
CDM = 0;  % coefficient can be neglected at low flight speeds
CmM = 0;  % coefficient can be neglected at low flight speeds


% u derivatives
CTu=CD_0; % for propeller driven
CDu = Mach*CDM;
CLu = Mach*CLM;
%-------------------------------
Cxu=-(CDu+2*CD_0)+CTu;
Czu=-(CLu+2*CL_0);
CMu = Mach*CmM;


% alpha derivatives
CLalpha = aero{1,1}.cla(10);
CDalpha=( 2*p2(1)*CL_0 + p2(2) )*CLalpha;
%--------------------------------
Cxalpha=-(CDalpha-CL_0);
Czalpha=-(CLalpha+CD_0);
Cmalpha=double(Cm_alpha+0.2073); % aero{1,1}.cma(10);
% Body alone cma=0.2073
% wing alone cma=0.852
% Htail alone cma=-2.92


% alpha dot derivatives
Cxalphadot=0;
CLalphadot = aero{1,1}.clad(10);
Cmalphadot = aero{1,1}.cmad(10);
%---------------------------------
cLalphadot = 2*eta_ht*V_ht*CL_alpha_ht*epsilon_alpha;
cmalphadot =-2*eta_ht*V_ht*CL_alpha_ht*epsilon_alpha*l_ht/mac_w;


% q derivatives
Cxq=0;
CLq = aero{1,1}.clq(1);
Cmq = aero{1,1}.cmq(1);
%------------------------------
cLq = 2*eta_ht*V_ht*CL_alpha_ht;
cmq =-2*eta_ht*V_ht*CL_alpha_ht*l_ht/mac_w;


% elevator deflection derivatives
Cxdeltae = 0; 
CLdeltae = CL_delta;
Cmdeltae = Cm_delta;


% other
epsilon_d0_datcom=aero{1,1}.eps(10); % in deg
epsilon_alpha_datcom=aero{1,1}.depsdalp(10);
%% Aerodynamic Derivatives

% u derivatives
Xu =   Cxu*Q*S/(u0*m);
Zu =   Czu*Q*S/(u0*m); 
Mu =   ( (Q*S*mac_w)/(u0*Iy) )*CMu; 

% alpha derivatives
Xalpha =  Q*S/m*Cxalpha;
Zalpha =  Q*S/m*Czalpha;
Malpha =  (Q*S*mac_w)/Iy*Cmalpha;

% w derivatives
Xw = Xalpha/u0;
Zw = Zalpha/u0;
Mw = Malpha/u0;

% alpha dot derivatives
Xalphadot =  (Q*S/m)* ( mac_w/(2*u0) )* Cxalphadot;
Zalphadot = -(Q*S/m)* ( mac_w/(2*u0) )* CLalphadot; % L is opposite directon with Z-axis
Malphadot =  (Q*S*mac_w/Iy)*( mac_w/(2*u0) )* Cmalphadot;

% wdot derivatives
Xwdot = Xalphadot/u0;
Zwdot = Zalphadot/u0;
Mwdot = Malphadot/u0;

% q derivatives
Xq =  (Q*S/m)*( mac_w/(2*u0) )* Cxq;
Zq = -(Q*S/m)*( mac_w/(2*u0) )* CLq; % L is opposite directon with Z-axis
Mq =  (Q*S*mac_w/Iy)*( mac_w/(2*u0) )* Cmq;

% elevator deflection derivatives
Xdeltae =  1* ( Q*S/m*Cxdeltae ); 
Zdeltae = -1* ( Q*S/m*CLdeltae ); % L is opposent directon with Z-axis
Mdeltae = double(Q*S*mac_w/Iy*Cmdeltae);    

%%  display
fprintf(' ==========================================================\n')
fprintf('               longitudinal motion analysis                 \n')                              
fprintf(' ==========================================================\n')
fprintf('\nx = [u  w  q  %c]\n',952)
fprintf('\nu = [ %ce %ct ] \n',948,948)
A_lon = double([ Xu            Xw           Xq           -g
                 Zu            Zw         Zq+u0           0
              Mu+Mwdot*Zu  Mw+Mwdot*Zw  Mq+Mwdot*u0       0
                 0             0            1             0])
      
B_lon = double([Xdeltae                0
                Zdeltae                0
                Mdeltae+Mwdot*Zdeltae  0
                0                      0] )

[Vector,~]=eig(A_lon)
damp(A_lon)
[~,~,pole]=damp(A_lon);
sys=ss(A_lon,B_lon,eye(4),0);
figure(4)
pzmap(sys)

% sorts the elements of real of pole in ascending order
pole = sort(pole,'ComparisonMethod','real');

% Phugoid period
fprintf('\n\n Phugoid (Long period)\n')
P_long = 2*pi/ abs( imag( pole(3) ) ); 
t_helf_long = log(2)/ abs( real( pole(3) ) );
N_helf_long = t_helf_long / P_long;
disp([ '    Eigenvalues : ',num2str(real(pole(3))), ' + ',num2str(abs(imag(pole(3)))), ' i'])
disp([ '                  ',num2str(real(pole(4))), ' - ',num2str(abs(imag(pole(4)))), ' i'])
disp([ '    Period : ',num2str(P_long), ' sec' ])
disp([ '    Time to helf amplitude : ',num2str(t_helf_long), ' sec' ])
disp([ '    Number of cycle for helfing the amplitude : ',num2str(N_helf_long), ' cycles' ])   

% Short period
fprintf('\n\n Short period\n')
P_short = 2*pi/ abs( imag( pole(1) ) );
t_helf_short = log(2)/ abs( real( pole(1) ) );
N_helf_short = t_helf_short / P_short;
disp([ '    Eigenvalues : ',num2str(real(pole(1))), ' + ',num2str(abs(imag(pole(1)))), ' i'])
disp([ '                  ',num2str(real(pole(2))), ' - ',num2str(abs(imag(pole(2)))), ' i'])
disp([ '    Period : ',num2str(P_short), ' sec' ])
disp([ '    Time to helf amplitude : ',num2str(t_helf_short), ' sec' ])
disp([ '    Number of cycle for helfing the amplitude : ',num2str(N_helf_short), ' cycles' ])

% controllability
R=rank(A_lon);
fprintf('\n\nControllability analysis\n')
fprintf('    Rank of longitudinal motion = %.1d\n',R)

%% ===================================================================================================================================================
%% lateral motion 
%% ===================================================================================================================================================
% basic data

%------------- the following data need to manually update -----------------
% Aileron geometry
% c1: inboard  chord
% c2: outboard chord
% y1: location of c1 from fuselage centerline (spanwise direction)
% y2: location of c2 from fuselage centerline (spanwise direction)
loc_y=[0.519353184   1.009340184]; % [y1 y2]
tau_w=0.3;   % Aileron effectiveness, observe from "control_surface_tau"jpg., select C_ail/C_w=0.25, b_ail/b_w=0.45
tau_vt=0.55; % Rudder  effectiveness, observe from "control_surface_tau"jpg., select C_rud/C_vt=0.4, b_rud/b_vt=0.86
K=-0.175;    % P121 table3.4 also see figure 3.12 
%--------------------------------------------------------------------------

% other calculation
CL_0 = aero{1,1}.cl(10);
CLalpha =aero{1,1}.cla(10);

% Aileron calculation
c=-(Croot -(Croot*lambda))/(b /2).*loc_y + Croot; % [c1 c2]
syms y
p3=polyfit(loc_y,c,1);
c_of_y= p3(1)*y+p3(2);
f=c_of_y*y;
integral=double( int(f,y,loc_y(1),loc_y(2)) );
%%  Aerodynamic Coefficients
for i=1 % 1 for datcom analysis, 2 for estimated lateral eqns
if i==1
% beta derivatives
Cyb = aero{1,1}.cyb(1);
Cnb = aero{1,1}.cnb(1);
Clb = aero{1,1}.clb(10);

% p derivatives
Cyp = aero{1,1}.cyp(10);
Cnp = aero{1,1}.cnp(10);
Clp = aero{1,1}.clp(10);

% r derivatives
Cyr = 2*eta_vt*V_vt*CL_alpha_vt;  % P118
Cnr = aero{1,1}.cnr(10);
Clr = aero{1,1}.clr(10);

elseif i==2
% estimating equations
% beta derivatives
cyb_vt=double(-eta_vt*(S_vt/S)*CL_alpha_vt*(1-Sidewash_gradient));
cyb_f=double(-2*pi*df^2/(4*S));
cyb_dihedral=-Cd0-double(pi)*AR_w/(1+sqrt(1+AR_w^2))*(gamma/57.3)^2;
Cyb=cyb_vt + cyb_f + cyb_dihedral;
%------------------------------------------------
Cnb= Cn_beta % eta_vt*V_vt*CL_alpha_vt*(1-Sidewash_gradient)
%------------------------------------------------
syms y
c=-(Croot -(Croot*lambda))/(b /2)*y + Croot;
f=c*y;
integral4=double(int(f,y,0,b/2));
clb_dihedral=-2*CL_alpha_w*(gamma/57.3)/(S*b)*integral4;
clb_vt=-double( eta_vt*(S_vt/S)*(z_vt/b)*CL_alpha_vt*(1-Sidewash_gradient));
Clb=clb_vt+clb_dihedral;

% p derivatives
syms z
c=-(Croot_vt -Croot_vt *lambda_vt )/b_vt *z +Croot_vt;
f=c*z;
integral3=double(int(f,z,0,b_vt));
cyp_vt=-2*eta_vt*CL_alpha_vt/(S*b)*integral3;
syms y
c=-(Croot -(Croot*lambda))/(b /2)*y + Croot;
f=c*y;
integral5=double(int(f,y,0,b/2));
cyp_dihedral=-4*CL_alpha_w*tan(gamma/57.3)/(S*b)*integral5;
Cyp=cyp_vt+cyp_dihedral;
%------------------------------------------------
syms y
c=-(Croot -(Croot*lambda))/(b /2)*y + Croot;
f=c*y^2;
integral6=double(int(f,y,0,b/2));
cnp_w=-4*CL_0/(S*b^2)*integral6;
cnp_vt=-cyp_vt*l_vt/b;
Cnp=cnp_w+cnp_vt;
%------------------------------------------------
syms y
c=-(Croot -(Croot*lambda))/(b /2)*y + Croot;
f=c*y^2;
integral2=double(int(f,y,0,b/2));
Clp=-4*CL_alpha_w/(S*b^2)*integral2;

% r derivatives
Cyr=2*eta_vt*V_vt*CL_alpha_vt;
Cnr=-2*eta_vt*V_vt*(l_vt/b)*CL_alpha_vt;
Clr=CL_0/4+2*eta_vt*V_vt*CL_alpha_vt*z_vt/b;
end

% Aileron derivatives
Cy_ail = 0.0; % It's 0
Cl_ail =-2*CL_alpha_w*tau_w/(S*b)*integral;  % P121 table3.4
Cn_ail = 2*K*CL_0*Cl_ail;


% Rudder derivatives
Cy_rud =  eta_vt*(S_vt/S)*CL_alpha_vt*tau_vt;  
Cn_rud = -eta_vt*V_vt*CL_alpha_vt*tau_vt;
Cl_rud =  eta_vt*(S_vt/S)*(z_vt/b)*tau_vt*CL_alpha_vt; 
%% Aerodynamic Derivatives

% beta derivatives
Ybeta = Q*S/m * Cyb;
Nbeta = Q*S*b/Iz * Cnb;
Lbeta = Q*S*b/Ix * Clb;

% p derivatives
Yp = Q*S*b/(2*m*u0) * Cyp;
Np = Q*S*b^2/(2*Iz*u0) * Cnp;
Lp = Q*S*b^2/(2*Ix*u0) * Clp;

% r derivatives
Yr = Q*S*b/(2*m*u0) * Cyr;
Nr = Q*S*b^2/(2*Iz*u0) * Cnr;
Lr = Q*S*b^2/(2*Ix*u0) * Clr;

% Aileron derivatives
Y_Ail = Q*S/m * Cy_ail;
N_Ail = Q*S*b/Iz * Cn_ail;
L_Ail = Q*S*b/Ix * Cl_ail;

% Rudder derivatives
Y_Rud = Q*S/m * Cy_rud;
N_Rud = Q*S*b/Iz * Cn_rud;
L_Rud = Q*S*b/Ix * Cl_rud;
%% display
Istar =  (Ix*Iz)/ (Ix*Iz-Ixz^2);

fprintf(' ==========================================================\n')
fprintf('                   lateral motion analysis                 \n')                              
fprintf(' ==========================================================\n')
fprintf('\nx = [ %c  p  r  %c ]\n',946,966)
fprintf('\nu = [ %ca %cr ] \n',948,948)
A_lat=double( [          Ybeta/u0                           Yp/u0                     (Yr/u0)-1                   g/u0
                ( Lbeta+(Nbeta*Ixz/Ix) )*Istar     ( Lp+(Np*Ixz/Ix) )*Istar     ( Lr+(Nr*Ixz/Ix) )*Istar            0 
                ( Nbeta+(Lbeta*Ixz/Iz) )*Istar     ( Np+(Lp*Ixz/Iz) )*Istar     ( Nr+(Lr*Ixz/Iz) )*Istar            0 
                                0                               1                         0                         0 ] )
   

B_lat=double([            0                           Y_Rud/u0
               (L_Ail+(Ixz/Ix)*N_Ail)*Istar  (L_Rud+(Ixz/Ix)*N_Rud)*Istar     
               (N_Ail+(Ixz/Iz)*L_Ail)*Istar  (N_Rud+(Ixz/Iz)*L_Rud)*Istar
                          0                            0                  ])
                
[Vector,~]=eig(A_lat)
damp(A_lat)
[~,~,pole]=damp(A_lat);
sys=ss(A_lat,B_lat,eye(4),0);
figure(5)
pzmap(sys)

% sorts the elements of real of pole in ascending order
pole = sort(pole,'ComparisonMethod','real');

% Spiral mode
fprintf('\n\n Spiral mode\n')
disp([ '    Eigenvalues : ',num2str(pole(4)) ])
if pole(4) < 0
    t_helf__of_Spiral = log(2)/ abs( pole(4) );
    disp([ '    Time to helf amplitude : ',num2str(t_helf__of_Spiral), ' sec' ])
else
    t_Double_of_Spiral = log(2)/ abs( pole(4) );
    disp([ '    Time to double amplitude : ',num2str(t_Double_of_Spiral), ' sec' ])
end  

% Roll mode
fprintf('\n\n Roll mode\n')
disp([ '    Eigenvalues : ',num2str(pole(1)) ])
if pole(1) < 0
    t_helf_of_Roll = log(2)/ abs( pole(1) );
    disp([ '    Time to helf amplitude : ',num2str(t_helf_of_Roll), ' sec' ])
else
    t_Double_of_Roll = log(2)/ abs( pole(1) );
    disp([ '    Time to double amplitude : ',num2str(t_Double_of_Roll), ' sec' ])
end


% Dutch roll mode
fprintf('\n\n Dutch roll mode\n')
P_Dutch = 2*pi/ abs( imag( pole(2) ) );
t_helf_of_Dutch = log(2)/ abs( real( pole(2) ) );
N_helf_of_Dutch = t_helf_of_Dutch / P_Dutch;
disp([ '    Eigenvalues : ',num2str(real(pole(2))), ' + ',num2str(abs(imag(pole(2)))), ' i'])
disp([ '                  ',num2str(real(pole(3))), ' - ',num2str(imag(pole(3))), ' i'])
disp([ '    Period : ',num2str(P_Dutch), ' sec' ])
disp([ '    Time to helf amplitude : ',num2str(t_helf_of_Dutch), ' sec' ])
disp([ '    Number of cycle for helfing the amplitude : ',num2str(N_helf_of_Dutch), ' cycles' ])

% controllability
R=rank(A_lat);
fprintf('\n\nControllability analysis\n')
fprintf('    Rank of lateral motion = %.1d\n',R)
%% crosswind
V_W=6;
V_rel=sqrt(u0^2+V_W^2);
beta=atan(V_W/u0);
Q_cw=0.5*rho*V_rel^2;
crosswind_A=[ W/(Q_cw*S)  Cy_ail   Cy_rud
                  0       Cl_ail   Cl_rud
                  0       Cn_ail   Cn_rud ];
crosswind_B=-beta*[Cyb;Clb;Cnb];
angle=crosswind_A\crosswind_B;
fprintf(' ==========================================================\n')
fprintf('              crosswind performance analysis               \n')                              
fprintf(' ==========================================================\n')
angle=[beta*57.3  ;  double( angle*180/pi )]
fprintf('which angle = %c %c %ca %cr\n',946,966,948,948)

end
