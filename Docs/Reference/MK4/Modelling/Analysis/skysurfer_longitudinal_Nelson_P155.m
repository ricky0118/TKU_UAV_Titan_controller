%% Example problem 4.3 p-155 
close all;clear;clc
%% Aircraft geometric and flying condition
rho = 1.2133; % kg/m^3
g = 9.8063; % m*sec^2
u0 = 10.5; % m/s^2 , forward velocity at equilibrium point
S = 0.3; % m^2
b = 1.5; % m, span
mac = 0.2; % m, Mean aerodynamic chord 
m = 1.11; % kg
Ix = 0.047; % kg*m^2
Iy = 0.068; % kg*m^2
Iz = 0.113; % kg*m^2
Ixz = 0.002; % kg*m^2

Q = 0.5*rho*u0^2; % Dynamic pressure
t_star = mac/(2*u0); % dimantionless time of longitudinal

%%  Aerodynamic Coefficients and derivatives
CL = 0.467; % C_L in equilibrium point = C_L_0
CD = 0.051; % C_D in equilibrium point = C_D_0
CLalpha = 4.9715; % 
    e = 0.961;AR_w = b^2 /S;
%CDalpha = ( 2*CL/(pi*e*AR_w) ) * CLalpha;
CDalpha = 0;
Cmalpha = -0.01135*57.3; % 
%CLalphadot =  2.3360; % 
CLq = 0.07305*57.3; % 
Cmq = -0.13*57.3; % 
CLM = 0.0; % 
CDM = 0.0; % 
CmM = 0.0; % 
Cmalphadot = -0.0554*57.3; % 
CDdeltae = 0.0225; % Drag slope of elevator deflacton within 30deg in DATCOM Rad^-1
CLdeltae = 0.2996; % within 10 degree deflection
Cmdeltae = -0.7921; % within 10 degree deflection

CDdelta_m=0.0255;
CLdelta_m=0.367;
Cmdelta_m=0.002;
mac_m=0.2;

CDu = 0.0; % Sub u = compressibility effect, which neglect in low speed
CLu = 0.0; % Sub u = change due to forward speed change
CMu = 0.0; % Mach number * slope of CM V.S. Mach diagram

% mu derivatives
Xu = - ( CDu+3*CD )*Q*S/(u0*m); %  CDu+3*CD for poston engien which ( partial T / partial u ) != 0
Zu = - ( CLu+2*CL )*Q*S/(u0*m); % 
Mu =   ( (Q*S*mac)/(u0*Iy) ) * CMu; % 

% w derivatives
Xw = - ( CDalpha-CL )*Q*S/(u0*m); % 
Zw = - ( CLalpha+CD )*Q*S/(u0*m); % 
Mw =   ( Cmalpha*Q*S*mac ) / (u0*Iy); % 

% alpha derivatives
Xalpha = u0*Xw; %  Xsub alpha = Xsub w * u0
Zalpha = u0*Zw; % 
Malpha = u0*Mw; % 

% wdot derivatives
Xwdot = 0.0; % 
Zwdot = 0.0; % 
Mwdot = ( Q*S*mac/(u0*Iy) ) * ( mac/(2*u0) ) * Cmalphadot; % 

% alpha dot derivatives
Xalphadot = u0*Xwdot; % 
Zalphadot = u0*Zwdot; % 
Malphadot = u0*Mwdot; % X_alphadot = X_wdot * u0

% q derivatives
Xq = 0.0; % 
Zq = 0.0; % 
Mq = ( Q*S*mac/ Iy )*( mac/(2*u0) )*Cmq; % quiatly different with Solution

% elevator deflection derivatives
Xdeltae = -1* ( CDdeltae*Q*S/m ); % Doesn't make sure that
Zdeltae = -1* ( CLdeltae*Q*S/m );
Mdeltae = Cmdeltae*Q*S*mac/Iy;

% motor deflection derivatives

Xdelta_m = -1* ( CDdelta_m*Q*S/m ); % Doesn't make sure that
Zdelta_m = -1* ( CLdelta_m*Q*S/m );
Mdelta_m = Cmdelta_m*Q*S*mac_m/Iy;
%% 
% Unforced, linesrized longitudinal equations in state form. 
% Nelson P-149, eq.(4.51)
A = [     Xu            Xw           0       -g;
          Zu            Zw           u0       0;
      Mu+Mwdot*Zu  Mw+Mwdot*Zw  Mq+Mwdot*u0   0;
          0             0            1        0]
B = [Xdeltae;Zdeltae;Mdeltae;0] 
B_m=[Xdelta_m;Zdelta_m;Mdelta_m;0]
KKK = charpoly(A) % Solve the Character equation of matrix A
syms s
Ch_eq = poly2sym( KKK, s) % Let's vector KKK be the coefficients of the polynomial of character eq.
lambda = roots( KKK ) % Solve eigenvalue of matrix A
damp(A) % Solving Damping, Frequency and Time Constant for each  Pole
[Omega,Zeta] = damp(A);

 %% 
fprintf('Phugoid (Long period)\n')
Lambda_phugoid = lambda(3:4)
P_long = 2*pi/ abs( imag( lambda(3) ) )
t_helf_long = 0.69/ abs( real( lambda(3) ) )
N_helf_long = t_helf_long / P_long

fprintf('Short period\n')
Lambda_short = lambda(1:2)
P_short = 2*pi/ abs( imag( lambda(1) ) )
t_helf_short = 0.69/ abs( real( lambda(1) ) )
N_helf_short = t_helf_short / P_short

%% Do it again with Longitudinal Approximations

fprintf('Phugoid Approximation\n')
omega_n_p = sqrt( -1*Zu*g/u0 )
zeta_p = -1*Xu/(2*omega_n_p)
lambda_app_p = zeros(2,1);
comp_p = complex( omega_n_p*sqrt( 1-zeta_p^2 )*i ) ;
lambda_app_p(1,1) = -1*zeta_p*omega_n_p + comp_p ;
lambda_app_p(2,1) = conj( lambda_app_p(1,1) )

P_long_app = 2*pi/ abs( imag( lambda_app_p(1,1) ) )
t_helf_long_app = 0.69/ abs( real( lambda_app_p(1,1) ) )
N_helf_long_app = 0.110*imag(lambda_app_p(1,1))/abs(real(lambda_app_p(1,1)))

fprintf('Short Approximation\n')
omega_n_sp = sqrt(Zalpha*Mq/u0 - Malpha)
zeta_sp = -1*( Mq+Malphadot+Zalpha/u0 ) / ( 2*omega_n_sp ) 
comp_sp = complex( omega_n_sp*sqrt( 1-zeta_sp^2 )*i ) ;
lambda_app_sp = zeros(2,1);
lambda_app_sp(1,1) = -1*zeta_sp*omega_n_sp + comp_sp ;
lambda_app_sp(2,1) = conj( lambda_app_sp(1,1) )

P_short_app = 2*pi/ abs( imag( lambda_app_sp(1,1) ) )
t_helf_short_app = 0.69/ abs( real( lambda_app_sp(1,1) ) )
N_helf_short_app = 0.110*imag(lambda_app_sp(1,1))/abs(real(lambda_app_sp(1,1)))

