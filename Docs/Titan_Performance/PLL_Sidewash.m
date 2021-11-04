function [Kv,Kb,Kbeta,Sidewash_gradient]=PLL_Sidewash...
    (AR,RT,CL,bw,X,Y,Z,Planform,Lambda_c4,BIG_omeaga,Cl_aoa_bar,N) 
% Estimating the Low-Speed Sidewash Gradient on a Vertical Stabilizer.
% [Kb,Kv,Kbeta,Sidewash]=PLL_Sidewash...
%    (AR,RT,CL,bw,X,Y,Z,Planform,Lambda_c4,BIG_omeaga,Cl_aoa_bar,N)
%
% bibliography:
% [1] WARREN F.PHILLIPS,?¡±MECHANICS of FLIGHT??, 2nd Edition, John Wiley.
% 5.3 Estimating the Sidewash Gradient on a Vertical Tail. p518-p525.
% [2] Phillips, W.F., (2002c), ?¡±Estimating the Low-Speed Sidewash
% Gradient on a Vertical Stabilizer,?? Journal of Aircraft, 41, 5.
%
%    The first six input arguments are required;
%    the other six have default values.
% 
% input arguments:
%    AR = Aspect ratio.
%    RT = Taper ratio.
%    CL = Lift coefficient.
%    bw = Span of the main wing (m or ft). 
%    X = The axial coordinate in the direction of the freestream (m or ft). 
%    Y = The upward normal coordinate (m or ft). 
%    Z = The spanwise coordinate(m or ft). (default Z = 0)
%    Planform = Planform of the main wing. 
%               (default Planform = 'wings with linear taper')
%    % Planform can be change :
%    % 'wings with linear taper' or 'rectangular wing' or 'elliptic wing'
%    Lambda_c4 = Quarter-chord sweep angle (degrees). 
%                (default Lambda_c4 = 0 deg)
%    BIG_omeaga = Maximum total washout (degrees). 
%                 (default BIG_omeaga = 0 deg)
%    Cl_aoa_bar = Airfoil lift slope. 
%                 (default an airfoil lift slope of 2*pi).    
%    N = Number of nonzero terms in the truncated Fourier series.
%        (default N = 99).
% 
% output arguments:
%    Kv = vortex strength factor in downwash computations.
%    Kb = vortex span factor in downwash coputation.
%    Kbeta = vortex sidewash factor.
%    Sidewash_gradient = Sidewash gradient.
%
% example : 
%    % The wing has a AR = 6.05 ,RT = 0.4 and Quarter-chord sweep of 
%    % 10 (degrees). If the vertical tail were mounted 5 feet above the
%    % aerodynamic center of the wing. Assume an airfoil lift slope of 2*pi.
%    % For this wing-tail combination, we have
%    % bw = 33 ft, l_h-l_w = 15 ft, CL = 0.8916.
%    % (The lift on the wing for 80 mph at sea level is 2,625.9 lbf.
%    % CL = 2625.9/(0.5*0.0023769*(80*5280/3600)^2*180) = 0.8916).
%    % (where CL_alpha is lift slope for the main wing, l_h is distance aft 
%    % of the center of gravity to aerodynamic center of either an aft
%    % horizontal tail and l_w is distance aft of the center of gravity to
%    % aerodynamic center of the main wing.)
%    >> AR = 6.05; RT = 0.4; bw = 33; X = 15; Y = 5; Z = 0; Planform = [];
%    >> Lambda_c4 = 10; CL = 0.8916;
%    >> [Kv,Kb,Kbeta]=PLL_Sidewash(AR,RT,CL,bw,X,Y,Z,Planform,Lambda_c4);
%    >> disp([Kv,Kb,Kbeta]);
%
%    % The sidewash gradient at the tail is
%    >> sidewash_gradient = -Kv*Kbeta/Kb*CL/AR;
%    >> disp(sidewash_gradient);
%
%    See also PLL_Downwash

% Author : Po-Ming Lin
% Compiler : MATLAB Ver 7.12.0.635 (R2011a).
% edition : Revised for Version 1.3.2
% E-mail : 601430092@s01.tku.edu.tw
%
% Last change: 2014/04/15 10:03 am

% Check input arguments.
if nargin<6, error('At least 6 input arguments required'), end
if nargin<7 || isempty(Z), Z=0; end
if nargin<8 || isempty(Planform), Planform='wings with linear taper'; end
if nargin<9 || isempty(Lambda_c4), Lambda_c4=0; end
if nargin<10 || isempty(BIG_omeaga),BIG_omeaga=0; end
if nargin<11 || isempty(Cl_aoa_bar), Cl_aoa_bar=2*pi; end
if nargin<12 || isempty(N), N=99; end    % N can be change
if AR<=0, error('Aspect ratio cannot be below zero or equal zero.'), end
if RT<0, error('Taper ratio cannot be below zero.'), end
if N<=0, error('Number of nonzero terms in the truncated.'), end
if ~(RT<=1 || RT==0), error('Taper ratio not applicable'), end
if Cl_aoa_bar<=0, error('Airfoil lift slope not applicable'), end

% theta => theta ; theta= [(i-1)*pi/(N-1)] ; i = 1,N
% c(theta)/b
[i,j] = meshgrid(2:(N-1),1:N);
theta=((i'-1)*pi)/(N-1);
c_of_theta_over_b=(2/(AR*(1+RT)))*(1-(1-RT)*abs(cos(theta)));
C=zeros(N,N); 
% C(i,j) = [4b/(Cl,a_bar*c(theta))+j/sin(theta)]*sin(j*theta)
% However,applying l'Hospital's rule gives.
C(1,:) = j(:,1).^2;
C(2:(N-1),1:N) = (((1./c_of_theta_over_b).*(4/Cl_aoa_bar))+...
               (j'./sin(theta))).*sin(j'.*theta);
C(N,:)=((-1).^(j(:,1)+1)).*(j(:,1).^2);

% where the Fourier coefficients , a(n) are obtained from :
% [C]{a}={1}
[a]=C\ones(1,N)';

n=1:N;
if BIG_omeaga == 0,
    % Fourier coefficients,An
    [A]=((a(n)./(pi*AR*a(1))).*CL)';
else
    % optimum washout distribution function.
    i=1:N;
    theta=((i-1)*pi)/(N-1);
    omeaga=abs(cos(theta));
    % where the Fourier coefficients , b(n) are obtained from :
    % {b}=[C]^-1{?sopt}
    [b]=C\omeaga';

    % Fourier coefficients,An
    [A]=((((a(n)*b(1))./a(1))-b(n)).*deg2rad(BIG_omeaga)+...
        (a(n)./(pi*AR*a(1))).*CL)';
end

% dimensionless aftward axial coordinate, X_bar
X_bar=X/(bw/2);
% dimensionless upward normal coordinate, Y_bar
Y_bar=Y/(bw/2);
% dimensionless leftward aerodynamic spanwise coordinate, Z_bar
Z_bar=Z/(bw/2);

switch lower(Planform)
    case {'wings with linear taper','rectangular wing'}
        n=2:N;
        % vortex strength factor in downwash computations, Kv
        Kv=1+sum((A(n).*sin(n.*pi*0.5))./A(1));
        % vortex span factor in downwash coputation, Kb
        Kb_N=sum((n.*A(n).*cos(n.*pi*0.5))./(((n.^2)-1)*A(1)));
        Kb_D=sum((A(n).*sin(n.*pi*0.5))./A(1));
        Kb=((pi/4)+Kb_N)/(1+Kb_D);
    case 'elliptic wing'
        Kv=1.0;
        Kb=pi/4;
end

Lambda=deg2rad(Lambda_c4);
% vortex sidewash factor , Kbeta(X_bar,Y_bar,0)
% [1] page 521.
Kbeta=((4*Y_bar*(X_bar-Kb*tan(Lambda))*Kb^2)/(pi^2*(Y_bar^2+Kb^2)^2))*...
(1+(X_bar-Kb*tan(Lambda))/sqrt((X_bar-Kb*tan(Lambda))^2+Y_bar^2+Kb^2))+...
((2*Y_bar*Kb)/(pi^2*(Y_bar^2+Kb^2)))*...
(((X_bar-Kb*tan(Lambda))^2*Kb)...
/((X_bar-Kb*tan(Lambda))^2+Y_bar^2+Kb^2)^(3/2));

if nargout>3 % [1] page 520.
    % Sidewash gradient (X_bar,Y_bar,Z_bar) can be written as :
    Z_bar_beta=-(X_bar-Kb*tan(Lambda));
    Sidewash_gradient=Z_bar_beta*...
    ((CL*Kv)/((pi^2)*AR))*...
    (((-2*Y_bar*(Z_bar-Kb))/((Y_bar^2+(Z_bar-Kb)^2)^2))*...
    (1+...
    (X_bar-Kb*tan(Lambda))/(...
    sqrt((X_bar-Kb*tan(Lambda))^2+(Y_bar)^2+(Z_bar-Kb)^2)))+...
    ((2*Y_bar*(Z_bar+Kb))/((Y_bar^2+(Z_bar+Kb)^2)^2))*...
    (1+...
    (X_bar-Kb*tan(Lambda))/(...
    sqrt((X_bar-Kb*tan(Lambda))^2+(Y_bar)^2+(Z_bar+Kb)^2)))-...
    ((Y_bar)/((Y_bar^2)+(Z_bar-Kb)^2))*...
    (((X_bar-Kb*tan(Lambda))*(Z_bar-Kb))/(...
    (X_bar-Kb*tan(Lambda))^2+(Y_bar)^2+(Z_bar-Kb)^2)^(3/2))+...
    ((Y_bar)/((Y_bar^2)+(Z_bar+Kb)^2))*...
    (((X_bar-Kb*tan(Lambda))*(Z_bar+Kb))/(...
    (X_bar-Kb*tan(Lambda))^2+(Y_bar)^2+(Z_bar+Kb)^2)^(3/2)));
end

end
