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
%% Aerodynamic Coefficients and derivatives
eta_t=1;
S_t=0.2302; % m^2
CL_alpha_t = 2.96401; % 1/rad
V_H = (1.1272*S_t)/(S*mac); % 1.1272(m)=lt

CL = BaseTerm{1,1}.cl(10); % C_L_0 in equilibrium point
CD = BaseTerm{1,1}.cd(10); % C_D_0 in equilibrium point
CLalpha =BaseTerm{1,1}.cla(10);
CDalpha = 0;
Cmalpha = BaseTerm{1,1}.cma(10);
CLalphadot = BaseTerm{1,1}.clad(10);
CLq = BaseTerm{1,1}.clq(1);
Cmq = BaseTerm{1,1}.cmq(1);
CLM = 0.0;
CDM = 0.0;
CmM = 0.0;
Cmalphadot = BaseTerm{1,1}.cmad(10);
CDdeltae = 0 ;%Assume equal 0
CLdeltae = eta_t*(S_t/S)*CL_alpha_t*0.52; % 0.52=tau
Cmdeltae = -eta_t*V_H*CL_alpha_t*0.52; %0.52=tau

CDu = 0.0; % Sub u = compressibility effect, which neglect in low speed
CLu = 0.0; % Sub u = change due to forward speed change
CMu = 0.0; % Mach number * slope of CM V.S. Mach diagram
%%
% mu derivatives
Xu = - ( CDu+3*CD )*Q*S/(u0*m); %  CDu+3*CD for poston engien which ( partial T / partial u ) != 0
Zu = - ( CLu+2*CL )*Q*S/(u0*m); % 
Mu =   ( (Q*S*mac)/(u0*Iy) ) * CMu; % 

% w derivatives
Xw = - ( CDalpha-CL )*Q*S/(u0*m); % 
Zw = - ( CLalpha+CD )*Q*S/(u0*m); % 
Mw =   ( Cmalpha*Q*S*mac ) / (u0*Iy); % 

% wdot derivatives
Xwdot = 0.0; % 
Zwdot = 0.0; % 
Mwdot = ( Q*S*mac/(u0*Iy) ) * ( mac/(2*u0) ) * Cmalphadot; % 

% q derivatives
Xq = 0.0; % 
Zq = ( Q*S*mac/ m  )*( -1 /(2*u0) )*CLq; % L is opposent directon with Z-axis
Mq = ( Q*S*mac/ Iy )*( mac/(2*u0) )*Cmq; %

% elevator deflection derivatives
Xdeltae = -1* ( CDdeltae*Q*S/m ); %
Zdeltae = -1* ( CLdeltae*Q*S/m ); %
Mdeltae = Cmdeltae*Q*S*mac/Iy;    %

% alpha dot derivatives
Xalphadot = u0*Xwdot; % 
Zalphadot = u0*Zwdot; % 
Malphadot = u0*Mwdot; % X_alphadot = X_wdot * u0

% alpha derivatives
Xalpha = u0*Xw; %  X_{alpha} = X_{w} * u0
Zalpha = u0*Zw; % 
Malpha = u0*Mw; % 



% Thrust derivatives
Xdelta_T =0.0224 ;
Zdelta_T = 0;
Mdelta_T = 0;
 
%%  
% Stick free, linesrized longitudinal equations in state form. 
% X_dot = A*X+B*u
% X = [u w q theta](state),u = [ Ele Thr ](control)
% Elevator's partial differential derivatives are differential are
% differentiation with unit RADIAN
%%%%%% B = [Xdeltae                Xdelta_T;
%%%%%      Zdeltae                Zdelta_T/(1-Zwdot);
%%%%%      Mdeltae+Mwdot*Zdeltae  Mdelta_T+Mwdot*Zdelta_T/(1-Zwdot);
%%%%%      0                            0                           ] 
%%%%   assume   Xdelta_T = 1450
fprintf('x_dot = Ax+Bu\n')
fprintf('\nx = [u w q theta]\n')
fprintf('\nu = [ Ele Thr ]\n')
A_lon = [     Xu            Xw           0        -g;
              Zu            Zw           u0        0;
           Mu+Mwdot*Zu  Mw+Mwdot*Zw  Mq+Mwdot*u0   0;
              0             0            1         0]
B_lon = [Xdeltae               1450;
         Zdeltae                0;
         Mdeltae+Mwdot*Zdeltae  0;
         0                      0     ] 
% x = [u alpha q theta](state),u = [ Ele Thr ](control)
%%%%%% B_alpha =  [Xdeltae                 XdeltaT;
%%%%%%             Zdeltae/(u0-Zalphadot)  ZdeltaT/(u0-Zalphadot);
%%%%%%             Mdeltae+Malphadot*Zdeltae/(u0-Zalphadot) ...
%%%%%%             MdeltaT+Malphadot*ZdeltaT/(u0-Zalphadot);
%%%%%%             0                            0];

fprintf('x_dot = Ax+Bu\n')
fprintf('\nx = [u alpha q theta]\n')
fprintf('\nu = [ Ele Thr ]\n')
A_alpha = [     Xu           Xalpha          0   -g;
           Zu/u0  Zalpha/u0   (u0+Zq)/(u0-Zalphadot) 0;
           Mu+Malphadot*Zu/(u0-Zalphadot)  Malpha+Malphadot*Zalpha/(u0-Zalphadot) ...
               Mq+Malphadot*(u0+Zq)/(u0-Zalphadot)   0;
           0             0            1        0]
B_alpha =  [Xdeltae                               1450;
            Zdeltae/(u0-Zalphadot)                   0;
            Mdeltae+Malphadot*Zdeltae/(u0-Zalphadot) 0;
            0                                        0]

%%
CharacterPoly = charpoly(A_alpha); % Solve the Character equation of matrix A
Rounding = fix( CharacterPoly.*10^3 ) ./ 10^3; 
    % round off value up to 3 decimal point, better looking than CharacterPoly XD

fprintf('\n\n\n Character equation of matrix A:\n')
    syms s
    Ch_eq = poly2sym( Rounding, s); disp( Ch_eq );
           % Let's vector Rounding be the coefficients of the polynomial of character eq.
fprintf('\n\n\n Eigenvalue of matrix A:\n')
    lambda = roots( CharacterPoly ); disp( lambda )
fprintf('\n\n\n Solving Damping, Frequency and Time Constant:\n')
    damp(A_alpha)
    [Omega,Zeta,Pole] = damp(A_alpha);
fig=1.0;
figure(fig);fig=fig+1;
    plot(Pole,'x')
    title('$Pole\ location\ of\ longitudinal\ matrix$','Interpreter','latex')
    grid on


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This program doesn't using conditional statements to find out the modes
% automatically, so please change lambda vector to fit each mode manually.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fprintf('\n\n\n Phugoid (Long period)\n')
Lambda_phugoid = lambda(3:4);
P_long = 2*pi/ abs( imag( Lambda_phugoid(1) ) );
t_helf_long = log(2)/ abs( real( Lambda_phugoid(1) ) );
N_helf_long = t_helf_long / P_long;
disp([ '    Eigenvalues : ', ...
    num2str(real(Lambda_phugoid(1))), ' +  ', ...
    num2str(imag(Lambda_phugoid(1))), ' i'])
disp([ '                  ', ...
    num2str(real(Lambda_phugoid(2))), ' + ', ...
    num2str(imag(Lambda_phugoid(2))), ' i'])
disp([ '    Period : ', ...
    num2str(P_long), ' sec' ])
disp([ '    Time to helf amplitude : ', ...
    num2str(t_helf_long), ' sec' ])
disp([ '    Number of cycle for helfing the amplitude : ', ...
    num2str(N_helf_long), ' cycles' ])



fprintf('\n\n\n Short period\n')
Lambda_short = lambda(1:2);
P_short = 2*pi/ abs( imag( Lambda_short(1) ) );
t_helf_short = log(2)/ abs( real( Lambda_short(1) ) );
N_helf_short = t_helf_short / P_short;
disp([ '    Eigenvalues : ', ...
    num2str(real(Lambda_short(1))), ' +  ', ...
    num2str(imag(Lambda_short(1))), ' i'])
disp([ '                  ', ...
    num2str(real(Lambda_short(2))), ' + ', ...
    num2str(imag(Lambda_short(2))), ' i'])
disp([ '    Period : ', ...
    num2str(P_short), ' sec' ])
disp([ '    Time to helf amplitude : ', ...
    num2str(t_helf_short), ' sec' ])
disp([ '    Number of cycle for helfing the amplitude : ', ...
    num2str(N_helf_short), ' cycles' ])

%% Do it again with Longitudinal Approximations

fprintf('\n\n\n Phugoid Approximation\n')
omega_n_p = sqrt( -1*Zu*g/u0 );
zeta_p = -1*Xu/(2*omega_n_p);
lambda_app_p = zeros(2,1);
comp_p = complex( omega_n_p*sqrt( 1-zeta_p^2 )*1i ) ;
lambda_app_p(1,1) = -1*zeta_p*omega_n_p + comp_p ;
lambda_app_p(2,1) = conj( lambda_app_p(1,1) );

P_long_app = 2*pi/ abs( imag( lambda_app_p(1,1) ) );
t_helf_long_app = 0.69/ abs( real( lambda_app_p(1,1) ) );
N_helf_long_app = 0.110*imag(lambda_app_p(1,1))/abs(real(lambda_app_p(1,1)));

disp([ '    Eigenvalues : ', ...
    num2str(real(lambda_app_p(1))), ' +  ', ...
    num2str(imag(lambda_app_p(1))), ' i'])
disp([ '                  ', ...
    num2str(real(lambda_app_p(2))), ' + ', ...
    num2str(imag(lambda_app_p(2))), ' i'])
disp([ '    Period : ', ...
    num2str(P_long_app), ' sec' ])
disp([ '    Time to helf amplitude : ', ...
    num2str(t_helf_long_app), ' sec' ])
disp([ '    Number of cycle for helfing the amplitude : ', ...
    num2str(N_helf_long_app), ' cycles' ])



fprintf('\n\n\n Short Approximation\n')
omega_n_sp = sqrt(Zalpha*Mq/u0 - Malpha);
zeta_sp = -1*( Mq+Malphadot+Zalpha/u0 ) / ( 2*omega_n_sp ) ;
comp_sp = complex( 0 , omega_n_sp*sqrt( 1-zeta_sp^2 ) ) ;
lambda_app_sp = zeros(2,1);
lambda_app_sp(1,1) = -1*zeta_sp*omega_n_sp + comp_sp ;
lambda_app_sp(2,1) = conj( lambda_app_sp(1,1) );

P_short_app = 2*pi/ abs( imag( lambda_app_sp(1,1) ) );
t_helf_short_app = 0.69/ abs( real( lambda_app_sp(1,1) ) );
N_helf_short_app = 0.110*imag(lambda_app_sp(1,1))/abs(real(lambda_app_sp(1,1)));

disp([ '    Eigenvalues : ', ...
    num2str(real(lambda_app_sp(1))), ' +  ', ...
    num2str(imag(lambda_app_sp(1))), ' i'])
disp([ '                  ', ...
    num2str(real(lambda_app_sp(2))), ' + ', ...
    num2str(imag(lambda_app_sp(2))), ' i'])
disp([ '    Period : ', ...
    num2str(P_short_app), ' sec' ])
disp([ '    Time to helf amplitude : ', ...
    num2str(t_helf_short_app), ' sec' ])
disp([ '    Number of cycle for helfing the amplitude : ', ...
    num2str(N_helf_short_app), ' cycles' ])



%%
save('matrix_lon','A_lon','B_lon','A_alpha','B_alpha')