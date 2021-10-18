clear;close all;clc
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
theta0 = 0; % in Level Flight now
Q = 0.5*rho*u0^2; % Dynamic pressure
t_star = b/(2*u0)
%%  Aerodynamic Coefficients and derivatives
CL_alpha_v = 3.001082431;eta_v = 0.885;V_v = 0.04116; 
cyr_notDATCOM = 2*CL_alpha_v*eta_v*V_v;
%Equations from Ph.Ma 
%    PPT The Aerodynamic Stability Derivatives - P.50

Cyb = -0.1668; Cnb = 0.0289; Clb = -0.1097;
Cyp = -0.0993; Cnp =-0.0524; Clp = -0.4416;
Cyr = cyr_notDATCOM; Cnr = -0.0310; Clr = 0.1467;
Cy_Ail=0 ;Cn_Ail = -0.0081; Cl_Ail = -0.0032; % Ail from DATCOM, Ail_deflection = DELTAL+DELTAR 
%Cy_Ail=0 ;Cn_Ail = 0.0078; Cl_Ail = -0.0025; % Ail from DATCOM, Ail_deflection = DELTAL+DELTAR 
Cy_Rud = 0.011446875;Cn_Rud=-0.005409 ;Cl_Rud=0.00233058375 ; % not provided in DATCOM

% beta derivatives
Ybeta = Q*S/m * Cyb;
Nbeta = Q*S*b/Iz * Cnb;
Lbeta = Q*S*b/Ix * Clb;

% p derivatives
Yp = Q*S*b/(2*m*u0) * Cyp;
Np = Q*S*b*b/(2*Iz*u0) * Cnp;
Lp = Q*S*b*b/(2*Ix*u0) * Clp;

% r derivatives
Yr = Q*S*b/(2*m*u0) * Cyr;
Nr = Q*S*b*b/(2*Iz*u0) * Cnr;
Lr = Q*S*b*b/(2*Ix*u0) * Clr;

% % Aileron derivatives
 Y_Ail = Q*S/m * Cy_Ail;
 N_Ail = Q*S*b/Iz * Cn_Ail;
 L_Ail = Q*S*b/Ix * Cl_Ail;
% 
% % Rudder derivatives
 Y_Rud = Q*S/m * Cy_Rud;
 N_Rud = Q*S*b/Iz * Cn_Rud;
 L_Rud = Q*S*b/Ix * Cl_Rud;


% assume I_xz equal to zero --> by Nelason 5.35
% x = [ beta p r phi ]
% A = [ Ybeta/u0 Yp/u0 -(1-(Yr/u0)) g/u0*cos(theta0);
%          Lbeta   Lp        Lr     0;
%          Nbeta   Np        Nr     0;
%          0       1     tan(theta0)      0];


% x = [ beta p r phi ]
Istar =  1/( 1 - ( Ixz^2/( Ix*Iz ) ) );
A=[Ybeta/u0                       Yp/u0                  -(1-(Yr/u0))              g/u0*cos(theta0);
     ( Lbeta+(Nbeta*Ixz/Ix) )*Istar ( Lp+(Np*Ixz/Ix) )*Istar ( Lr+(Nr*Ixz/Ix) )*Istar 0;
     ( Nbeta+(Lbeta*Ixz/Iz) )*Istar ( Np+(Lp*Ixz/Iz) )*Istar ( Nr+(Lr*Ixz/Iz) )*Istar 0;
         0                          1                        tan(theta0)              0];
B=[0 Y_Rud/u0;
    Istar*(L_Ail+(Ixz/Ix)*N_Ail) Istar*(L_Rud+(Ixz/Ix)*N_Rud);
    Istar*(N_Ail+(Ixz/Iz)*L_Ail) Istar*(N_Rud+(Ixz/Iz)*L_Rud);
    0 0;]
C=[0 0 0 1];
D=[0]
KKK = charpoly(A) % Solve the Character equation of matrix A
syms s
Ch_eq = poly2sym( KKK, s); % Let's vector KKK be the coefficients of the polynomial of character eq.
lambda = roots( KKK ); % Solve eigenvalue of matrix A
% damp(A); % Solving Damping, Frequency and Time Constant for each  Pole
[Omega,Zeta,Poles] = damp(A);
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %  %%  
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % don't add the Conditional statements to find out the modes automatically
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % fprintf('Spiral mode\n')
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % Lambda_Spiral = lambda(4)
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % if lambda(4) < 0
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %     t_helf_Spiral = 0.69/ abs( lambda(4) ) 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % else
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %     t_Double_Spiral = 0.69/ abs( lambda(4) ) 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % end
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % fprintf('Roll mode\n')
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % Lambda_Roll = lambda(1)
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % TimeConstant_Roll = 1/ abs( lambda(1) )
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % if lambda(4) < 0
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %     t_helf_Roll = 0.69/ abs( lambda(1) ) 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % else
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %     t_Double_Roll = 0.69/ abs( lambda(1) ) 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % end
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % fprintf('Dutch roll mode\n')
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % Lambda_Dutch = lambda(2:3)
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % ZetaMultOmega = Omega(2) * Zeta(2)
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % P_Dutch = 2*pi/ abs( imag( lambda(2) ) )
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % t_helf_Dutch = 0.69/ abs( real( lambda(2) ) )
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % N_helf_Dutch = 0.110*imag(lambda(2)) / abs(real(lambda(2)))

fprintf('Spiral mode Approximation\n')
Lambda_Spiral_app = ( Lbeta*Nr - Lr*Nbeta )/( Lbeta );
eta_Spiral = real(Lambda_Spiral_app)  
T_half_Spiral = 0.69 / abs( eta_Spiral  )

fprintf('Roll mode Approximation\n')
Lambda_Roll_app = Lp;
eta_Roll = real(Lambda_Roll_app)  
T_half_Roll = 0.69 / abs( eta_Roll  )

fprintf('Dutch roll mode Approximation\n')
lambda_dutch = lambda( 2,1 )/t_star
w_Dutch = imag( lambda_dutch )
eta_Dutch = real( lambda_dutch )
P_P = 2 * pi /  w_Dutch
T_half_Dutch = 0.69 / abs( eta_Dutch  )
N_half_Dutch = 0.11 * w_Dutch / abs( eta_Dutch )
%{
syms x
p = [1 1.102 4.71] % input coefficients of the polynomial of character eq.
Dutch = poly2sym( p ) % show the polynomial from coefficients
lambda_Dutch_App = roots( p ) % Solve eigenvalue of matrix A
omega_n_Dutch =  sqrt( p(3) ) % Solve Undamped natural frequency
zeta_Dutch =  p(2)/2/omega_n_Dutch % Solve Damping ratio
%}
damp(A)
figure(1)
plot(Poles,'x')
grid on



