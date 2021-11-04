
  
%==========================================================================
%                          MaxTOWeight Range
%==========================================================================

function [W_total,Mass_total,Mass_fuel,Mass_emty]=for_range_fuel(Cd0,K,xpoint,h,Range_km)
%% Initial Condition
[~,~,~,rho,g,~]=Standard_Atmosphere(h);
Range = Range_km*1000; % m.
Epropeller=0.7;% Á³±Û¼Õ®Ä²v 
W_payload = 2.1*g;
SFC=0.000013094; % Nt/sec/watt
W2_over_W1=0.98;
W3_over_W2=0.97;
W5_over_W4=0.99;
W6_over_W5=0.997;

%% compute
V_c=1.15*sqrt(2/rho*sqrt(K/Cd0)*xpoint);
Cl_c = 2*xpoint/rho/V_c^2; 
Cd_c = Cd0 + K*Cl_c^2;

% Weight ratio of battery
 W4_over_W3=exp( (-Range*SFC)/(Epropeller*Cl_c/Cd_c) );
 W6_over_W1=W2_over_W1*W3_over_W2* W4_over_W3*W5_over_W4*W6_over_W5;
 W_fuel_per_weight=1-W6_over_W1;

    a=0.001;
    b=0.0408;
    c=31.211;
    q_equation = [ a     (-1+b+W_fuel_per_weight)      (W_payload + c)   ];
    W_total_s = roots(q_equation);
    W_total = double( W_total_s(2) );
    
    % recompute
    Mass_total = W_total /g;
    Mass_fuel = W_total * W_fuel_per_weight/g;
    Mass_emty = (a*(W_total)^2 + b*W_total + c)/g;
   
    fprintf(' ==========================================================\n')
    fprintf('                      MaxTOWeight Range                    \n')                              
    fprintf(' ==========================================================\n')
    fprintf('    Range           = %.5f  Km \n',Range_km)
    fprintf('    Total weight    = %.5f  N  \n',W_total) 
    fprintf('    Mass of total   = %.5f  kg \n',Mass_total)
    fprintf('    Mass of fuel    = %.5f  kg \n',Mass_fuel)
    fprintf('    Mass of empty   = %.5f  kg \n',Mass_emty+2.1)
    fprintf('    Mass of payload = %.5f  kg \n',W_payload/g-2.1)
end