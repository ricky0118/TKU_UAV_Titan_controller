%%
close all;clear;clc
load TF
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%          PID-controller        
%%%          T.F. = kp + ki/s + kd*s 
%%%               = kp(1+ki/(kp*s)+(kd/kp)*s
%%%               =kp(1+(1/(Ti*s))+Td*s)        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%          ziegler-nichols 經驗公式        
%%%          kp = 0.6*ku
%%%          Ti = 0.5*Tu
%%%          Td = 0.125*Tu
%%%          ku = 10^(GM/20) % GM = Gain
%%%          Tu = 2*pi/omega
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 內迴圈

Gs = tf([10],[1 10]) % aileron servo transfer function
Gp = TF_p_delta_a
G = Gs*Gp
figure(1)
rlocus(G) %還未加控制器的內迴圈根軌跡
sgrid
figure(2)
sys = tf(G) 
sysp = feedback(sys,1); %還未加控制器的內迴圈
step(sysp)
hold on
xlim([0 2])
grid
fprintf('\n未加控制器之內迴圈數值')
S_in = stepinfo(sysp)

%(1)
 GM = 0.00602
 omega = 2.46
 ku = 10^(GM/20)
 Tu = (2*pi)/omega
 
 kp = 0.6*ku
 Ti = 0.5*Tu
 Td = 0.125*Tu
 Gc = pidstd(kp,Ti,Td) 
sysc = feedback(G*Gc,1) 
step(sysc)
hold on
fprintf('\n加PID-controller之內迴圈數值')
S_in1 = stepinfo(sysc)

%(2)微調
kp1 = 0.7
Ti1 = 0.5
Td1 = 0.3193
Gc1 = pidstd(kp1,Ti1,Td1)
sysc1 = feedback(G*Gc1,1) %經過微調後的內迴圈step response
step(sysc1)

fprintf('微調後PID-controller之內迴圈數值')
S_in2 = stepinfo(sysc1)
legend('未加控制器之內迴圈','加PID-controller之內迴圈','經過微調後的PID-controller之內迴圈')

%% 外迴圈

Gss = tf([1],[1 0]) %1/s
G1 = Gss*sysc1
figure(4)
rlocus(G1)
sgrid


figure(5) 
sysc2 = feedback(G1,1) %未加控制器的外迴圈
step(sysc2)
hold on
xlim([0 5])
grid
fprintf('\n未加控制器之外迴圈數值')
S_out = stepinfo(sysc2)


%(1)
GM1 = 36
omega1 = 2.49
ku1 = 10^(GM1/20)
Tu1 = (2*pi)/omega1
 
 kp2 = 0.6*ku1
 Ti2 = 0.5*Tu1
 Td2 = 0.125*Tu1
 Gc2 = pidstd(kp2,Ti2,Td2) 
sysc3 = feedback(G1*Gc2,1) 
step(sysc3)
hold on
fprintf('\n加PID-controller之外迴圈數值')
S_out1 = stepinfo(sysc3)

%(2)微調
 kp3 = 40
 Ti3 = 0.35
 Td3 = 0.01
 Gc3 = pidstd(kp3,Ti3,Td3) 
sysc4 = feedback(G1*Gc3,1) 
step(sysc4)

fprintf('\n微調後PID-controller之外迴圈數值')
S_out2 = stepinfo(sysc4)

legend('未加控制器之外迴圈','加PID-controller之外迴圈','微調後PID-controller之外迴圈')

%% PID-controller 連續轉離散
Gc1_dis = c2d(Gc1,1/250,'matched')
Gc3_dis = c2d(Gc3,1/250,'matched')

