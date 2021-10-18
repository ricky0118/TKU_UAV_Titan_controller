%%
close all;clear;clc
load matrix_lon
load matrix_lat
%%
%long.
fprintf('x_dot = Ax+Bu\n\n')
fprintf('y \t= \tCx+Du\n')
fprintf('\nx = [alpha w q theta]\n')
fprintf('\nu = [ Ele Thr ]\n')
sprintf('\lambda')


C_alpha = eye(4)
D_alpha = zeros(4,2)

% Transfer Function delta_e to input(s)
[Num,Den] = ss2tf(A_alpha,B_alpha,C_alpha,D_alpha,1);
fprintf('\n\n')
TF_u_delta_e = tf(Num(1,:),Den)
TF_alpha_delta_e = tf(Num(2,:),Den)
TF_q_delta_e = tf(Num(3,:),Den)
TF_theta_delta_e = tf(Num(4,:),Den)

% Transfer Function delta_t to input(s)
[Num_t,Den_t] = ss2tf(A_alpha,B_alpha,C_alpha,D_alpha,2);
TF_u_delta_t = tf(Num_t(1,:),Den_t)
TF_alpha_delta_t = tf(Num_t(2,:),Den_t)
TF_q_delta_t = tf(Num_t(3,:),Den_t)
TF_theta_delta_t = tf(Num_t(4,:),Den_t)
figure(1)
subplot(2,1,1)
step(TF_q_delta_e)
title('pitch-angle velocity')
subplot(2,1,2);
step(TF_theta_delta_e)
title('pitch-attitude')
%%
%lat.

fprintf('\nx_dot = Ax+Bu\n\n')
fprintf('y \t= \tCx+Du\n')
fprintf('\nx = [ beta p r phi ]\n')
fprintf('\nu = [ Aileron Rudder ]\n')

C_beta = eye(4)
D_beta = zeros(4,2)


% Transfer Function delta_a to input(s)
[Num,Den] = ss2tf(A_beta,B_beta,C_beta,D_beta,1);
TF_beta_delta_a = tf(Num(1,:),Den)
TF_p_delta_a = tf(Num(2,:),Den)
TF_r_delta_a = tf(Num(3,:),Den)
TF_phi_delta_a = tf(Num(4,:),Den)
figure(2)
subplot(2,1,1)
step(TF_p_delta_a)
title('roll-angle velocity')
subplot(2,1,2);
step(TF_phi_delta_a)
title('roll-attitude')
% Transfer Function delta_r to input(s)
[Num_t,Den_t] = ss2tf(A_beta,B_beta,C_beta,D_beta,2);
TF_beta_delta_r = tf(Num_t(1,:),Den_t)
TF_p_delta_r = tf(Num_t(2,:),Den_t)
TF_r_delta_r = tf(Num_t(3,:),Den_t)
TF_phi_delta_r = tf(Num_t(4,:),Den_t)
figure(3)
subplot(2,1,1)
step(TF_r_delta_r)
title('yaw-angle velocity')
subplot(2,1,2);
step(TF_beta_delta_r)
title('yaw-attitude')
%%
save('TF','TF_q_delta_e','TF_theta_delta_e','TF_p_delta_a','TF_phi_delta_a','TF_beta_delta_r','TF_r_delta_r','TF_beta_delta_r')