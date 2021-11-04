clear;clc;close all

time=linspace(0,8760,8760);
A = cos(10*time);
% A is an input signal from an external model
A_noDC=A-mean(A); %This cuts the 0 Hz DC component
f=1/3600; %frequency is 1 sample per hour, thus 1/3600 per second
N=length(A); 
X=fft(A_noDC);
X_mag=abs(X);
X_amp=X_mag/N; %normalises magnitude into amplitude
X_ampsingle=X_amp(1:N/2+1); %divides the plot from two-sided to one
X_ampsingle(2:end-1)=2*X_ampsingle(2:end-1); %idem
freq=(0:(N/2))*f/N; %plots the frequency on the x-axis rather than bins
figure('visible','on')
plot(freq,X_ampsingle);
title('Frequency spectrum')
xlabel({'Frequency','[Hertz]'});
ylabel({'Amplitude [MW]'});
figure('visible','on');
plot(time,A); %plots original signal
title('original signal');


X2=X
threshold=max(abs(X)/10);
X2(abs(X)<threshold)=0; % determines the low-amplitude threshold
phase=atan2(imag(X2),real(X2))*180/pi;
phase_single=phase(1:N/2+1); %turns the plot into a one-sided plot
phase_single(2:end-1)=2*phase_single(2:end-1);
figure('visible','on')
plot(freq,phase_single);
title('Phase information')
xlabel({'frequency','[Hertz]'});
ylabel({'phase [degrees]'});