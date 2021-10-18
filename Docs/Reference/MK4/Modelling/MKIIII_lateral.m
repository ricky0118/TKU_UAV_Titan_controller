%% MKIIII-longitudinal
close all;clear;clc
BaseTerm = datcomimport('MK_IV_BWHV2.out');

%% Aircraft geometric and flying condition

rho = 1.2133; % kg/m^3
g = 9.8063;   % m*sec^2
u0 = 15.006935;    % m/s^2 , Mach = 0.0441, forward velocity at equilibrium point
S = 0.77675;    % m^2, wing area
b = 2.4115;   % m, span
mac = 0.33367; % m, Mean aerodynamic chord 
m = 7.50283;     % kg, WT = 73.575N
Ix = 0.765;   % kg*m^2
Iy = 1.241;   % kg*m^2
Iz = 1.926;   % kg*m^2
Ixz = 0.027;  % kg*m^2
Q = 0.5*rho*u0^2; % Dynamic pressure
theta0 = 0; % rad

%%  Aerodynamic Coefficients and derivatives

eta_v=0.98;
S_v=0.0621; % m^2
CL_alpha_w =4.234 ; % 1/rad
CL_alpha_v =1.2568163; % 1/rad
V_v = (1.1707*S_v)/(S*b); % 1.1707(m)=lv
z_v = 0.1776;

% beta derivatives
Cyb = BaseTerm{1,1}.cyb(1);
Cnb = BaseTerm{1,1}.cnb(1);
Clb = BaseTerm{1,1}.clb(10);

%  p derivatives
Cyp = BaseTerm{1,1}.cyp(10);
Cnp = BaseTerm{1,1}.cnp(10);
Clp = BaseTerm{1,1}.clp(10);

% r derivatives
Cyr = 2*eta_v*V_v*CL_alpha_v; 
Cnr = BaseTerm{1,1}.cnr(10);
Clr = BaseTerm{1,1}.clr(10);
% Aileron derivatives
CL = BaseTerm{1,1}.cl(10);
CLalpha =BaseTerm{1,1}.cla(10);

Cy_Ail = 0.0;
Cl_Ail = ((2*CLalpha*0.42)/(S*b))*(0.1286798424);
Cn_Ail = 2*Cl_Ail*CL*(-0.2);
    % Dafination of aileron : 
    %     Ail_deflection = ( Ail_right + Ail_left )/2
    %     Ail_right positive for Trailing Edge Up
    %     Ail_left  positive for TED
    %     positive Delta_ail for roll left & yaw right

% Rudder derivatives
Cy_Rud = (S_v/S)*CL_alpha_v*eta_v*0.55; 
Cn_Rud = -eta_v*V_v*CL_alpha_v*0.55; 
Cl_Rud = (S_v/S)*(z_v/b)*0.55*CL_alpha_v; 

% ------------------------------
% beta derivatives
Ybeta = Q*S/m * Cyb;
Nbeta = Q*S*b/Iz * Cnb;
Lbeta = Q*S*b/Ix * Clb;

% beta derivatives
Yv = Ybeta/u0;
Nv = Nbeta/u0;
Lv = Lbeta/u0;

% p derivatives
Yp = Q*S*b/(2*m*u0) * Cyp;
Np = Q*S*b*b/(2*Iz*u0) * Cnp;
Lp = Q*S*b*b/(2*Ix*u0) * Clp;

% r derivatives
Yr = Q*S*b/(2*m*u0) * Cyr;
Nr = Q*S*b*b/(2*Iz*u0) * Cnr;
Lr = Q*S*b*b/(2*Ix*u0) * Clr;

% Aileron derivatives
Y_Ail = Q*S/m * Cy_Ail;
N_Ail = Q*S*b/Iz * Cn_Ail;
L_Ail = Q*S*b/Ix * Cl_Ail;

% Rudder derivatives
Y_Rud = Q*S/m * Cy_Rud;
N_Rud = Q*S*b/Iz * Cn_Rud;
L_Rud = Q*S*b/Ix * Cl_Rud;

%%
% x = [ v p r phi ], u = [ Aileron Rudder ]
% Aileron's partial differential derivatives are differential are
% differentiation with unit RADIAN
% Istar =  (Ix*Iz)/ (Ix*Iz-Ixz^2);

Istar =  (Ix*Iz)/ (Ix*Iz-Ixz^2);

fprintf('x_dot = Ax+Bu\n')
fprintf('\nx = [ v p r phi]\n')
fprintf('\nu = [ Aileron Rudder ]\n')

A_lat=[   Yv                     Yp                   Yr-u0                g*cos(theta0);
     ( Lv+(Nv*Ixz/Ix) )*Istar ( Lp+(Np*Ixz/Ix) )*Istar ( Lr+(Nr*Ixz/Ix) )*Istar 0;
     ( Nv+(Lv*Ixz/Iz) )*Istar ( Np+(Lp*Ixz/Iz) )*Istar ( Nr+(Lr*Ixz/Iz) )*Istar 0;
       0                        1                        0                      0]
   

B_lat=[ 0                            Y_Rud                       ;
    (L_Ail+(Ixz/Ix)*N_Ail)*Istar (L_Rud+(Ixz/Ix)*N_Rud)*Istar;
    (N_Ail+(Ixz/Iz)*L_Ail)*Istar (N_Rud+(Ixz/Iz)*L_Rud)*Istar;
    0                            0                           ;]

% x = [ beta p r phi ] ,u = [ Aileron Rudder ]
fprintf('x_dot = Ax+Bu\n')
fprintf('\nx = [ beta p r phi]\n')
fprintf('\nu = [ Aileron Rudder ]\n')
A_beta=[          Ybeta/u0                           Yp/u0                     (Yr/u0)-1                   g/u0;
         ( Lbeta+(Nbeta*Ixz/Ix) )*Istar     ( Lp+(Np*Ixz/Ix) )*Istar     ( Lr+(Nr*Ixz/Ix) )*Istar            0 ;
         ( Nbeta+(Lbeta*Ixz/Iz) )*Istar     ( Np+(Lp*Ixz/Iz) )*Istar     ( Nr+(Lr*Ixz/Iz) )*Istar            0 ;
                         0                               1                         0                         0]
   

B_beta=[            0                           Y_Rud/u0;
        (L_Ail+(Ixz/Ix)*N_Ail)*Istar  (L_Rud+(Ixz/Ix)*N_Rud)*Istar;         
        (N_Ail+(Ixz/Iz)*L_Ail)*Istar  (N_Rud+(Ixz/Iz)*L_Rud)*Istar;
                    0                            0;]
    


%%

CharacterPoly = charpoly(A_beta); % Solve the Character equation of matrix A
syms s
Rounding = fix( CharacterPoly.*10^3 ) ./ 10^3; 
    % round off value up to 3 decimal point, better looking than CharacterPoly XD

fprintf('\n\n\n Character equation of matrix A\n')
    Ch_eq = poly2sym( Rounding, s); disp( Ch_eq );
           % Let's vector Rounding be the coefficients of the polynomial of character eq.
fprintf('\n\n\n Eigenvalue of matrix A\n')
    lambda = roots( CharacterPoly ); disp( lambda )
fprintf('\n\n\n Solving Damping, Frequency and Time Constant\n')
    damp(A_beta) 
    [Omega,Zeta,Pole] = damp(A_beta);
fig=1.0;
figure(fig);fig=fig+1;
    plot(Pole,'x')
    title('$Pole\ location\ of\ lateral\ matrix$','Interpreter','latex')
    grid on



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This program doesn't using conditional statements to find out the modes
% automatically, so please change lambda vector to fit each mode manually.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fprintf('\n\n\n Spiral mode\n')
Lambda_Spiral = lambda(4);
disp([ '    Eigenvalues : ', ...
    num2str(Lambda_Spiral) ])
if lambda(4) < 0
    t_helf__of_Spiral = log(2)/ abs( Lambda_Spiral );
    disp([ '    Time to helf amplitude : ', ...
        num2str(t_helf__of_Spiral), ' sec' ])
else
    t_Double_of_Spiral = log(2)/ abs( Lambda_Spiral );
    disp([ '    Time to double amplitude : ', ...
        num2str(t_Double_of_Spiral), ' sec' ])
end


fprintf('\n\n\n Roll mode\n')
Lambda_Roll = lambda(1);
TimeConstant_of_Roll = 1/ abs( Lambda_Roll );
disp([ '    Eigenvalues : ', ...
    num2str(Lambda_Roll) ])
if Lambda_Roll < 0
    t_helf_of_Roll = log(2)/ abs( Lambda_Roll );
    disp([ '    Time to helf amplitude : ', ...
        num2str(t_helf_of_Roll), ' sec' ])
else
    t_Double_of_Roll = log(2)/ abs( Lambda_Roll );
    disp([ '    Time to double amplitude : ', ...
        num2str(t_Double_of_Roll), ' sec' ])
end

fprintf('\n\n\n Dutch roll mode\n')
Lambda_of_Dutch = lambda(2:3);
P_Dutch =           2*pi/ abs( imag( Lambda_of_Dutch(1) ) );
t_helf_of_Dutch = log(2)/ abs( real( Lambda_of_Dutch(1) ) );
N_helf_of_Dutch = t_helf_of_Dutch / P_Dutch;
disp([ '    Eigenvalues : ', ...
    num2str(real(Lambda_of_Dutch(1))), ' +  ', ...
    num2str(imag(Lambda_of_Dutch(1))), ' i'])
disp([ '                  ', ...
    num2str(real(Lambda_of_Dutch(2))), ' + ', ...
    num2str(imag(Lambda_of_Dutch(2))), ' i'])
disp([ '    Period : ', ...
    num2str(P_Dutch), ' sec' ])
disp([ '    Time to helf amplitude : ', ...
    num2str(t_helf_of_Dutch), ' sec' ])
disp([ '    Number of cycle for helfing the amplitude : ', ...
    num2str(N_helf_of_Dutch), ' cycles' ])
%%
save('matrix_lat','A_lat','B_lat','A_beta','B_beta')