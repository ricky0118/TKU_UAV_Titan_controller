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
%%%          ziegler-nichols �g�礽��        
%%%          kp = 0.6*ku
%%%          Ti = 0.5*Tu
%%%          Td = 0.125*Tu
%%%          ku = 10^(GM/20) % GM = Gain
%%%          Tu = 2*pi/omega
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ���j��

Gs = tf([-10],[1 10]) % elevator servo transfer function
Gp = TF_q_delta_e
G = Gs*Gp
figure(1)
rlocus(G) %�٥��[��������j��ڭy��
sgrid

figure(2)
sys = tf(G) 
sysp = feedback(sys,1); %�٥��[��������j��
step(sysp)
hold on
xlim([0 5])
grid
fprintf('\n���[��������j��ƭ�')
S_in = stepinfo(sysp)

%(1)
 GM = 0.522
 omega = 26.7
 ku = 10^(GM/20)
 Tu = (2*pi)/omega
 
 kp = 0.6*ku
 Ti = 0.5*Tu
 Td = 0.125*Tu
 Gc = pidstd(kp,Ti,Td) 
sysc = feedback(G*Gc,1) 
step(sysc)
hold on
fprintf('\n�[PID-controller�����j��ƭ�')
S_in1 = stepinfo(sysc)


%(2)�L��
kp1 = 0.99
Ti1 = 0.045
Td1 = 0.08
Gc1 = pidstd(kp1,Ti1,Td1)
sysc1 = feedback(G*Gc1,1) %�g�L�L�ի᪺���j��step response
step(sysc1)
legend('���[��������j��','�[PID-controller�����j��','�g�L�L�ի᪺PID-controller�����j��')
fprintf('�L�ի�PID-controller�����j��ƭ�')
S_in2 = stepinfo(sysc1)

%% �~�j��

Gss = tf([1],[1 0]) %1/s
G1 = Gss*sysc1
figure(4)
rlocus(G1)
sgrid

figure(5) 
sysc2 = feedback(G1,1) %���[������~�j��
step(sysc2)
hold on
xlim([0 5])
grid
fprintf('\n���[������~�j��ƭ�')
S_out = stepinfo(sysc2)

%(1)
GM1 = 33.9
omega1 = 17.3
ku1 = 10^(GM1/20)
Tu1 = (2*pi)/omega1
 
 kp2 = 0.6*ku1
 Ti2 = 0.5*Tu1
 Td2 = 0.125*Tu1
 Gc2 = pidstd(kp2,Ti2,Td2) 
sysc3 = feedback(G1*Gc2,1) 
step(sysc3)
hold on
fprintf('\n�[PID-controller���~�j��ƭ�')
S_out1 = stepinfo(sysc3)

%(2)�L�ի�
 kp3 = 15.5
 Ti3 = 0.29
 Td3 = 0.0454
 Gc3 = pidstd(kp3,Ti3,Td3) 
sysc4 = feedback(G1*Gc3,1) 
step(sysc4)
legend('���[������~�j��','�[PID-controller���~�j��','�L�ի�')
fprintf('\n�[PID-controller���~�j��ƭ�')
S_out2 = stepinfo(sysc4)

figure(6)
step(sysc3)
hold on
step(sysc4)
xlim([0 3])
grid
legend('PID-controller���~�j��','�L�ի�PID-controller���~�j��')
%% PID-controller �s��������
Gc1_dis = c2d(Gc1,1/250,'matched')
Gc3_dis = c2d(Gc3,1/250,'matched')