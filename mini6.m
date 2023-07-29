clc;
clf;
clear all;
close all;
delete(instrfind({'Port'},{'COM4'}));
device = serial('COM4','BaudRate',9600);
fopen(device);
load('D:\Personal\college\Mini Proj\6th sem proj\database\A1_Force Exp\Ball_med\A1_Ball_med_t3.mat');
y =t3(1:23687);
subplot(2,2,1);
plot(y(1:23687));
xlabel('Time');
ylabel('Amplitude');
title('Raw signal');


y1=movmean(y,1);
subplot(2,2,2);
plot(y1(1:23687));
xlabel('Time');
ylabel('Amplitude');
title('Averaged signal');
y2=y1.*y1;
y3=sqrt(y2);
subplot(2,2,3);
plot(y3(1:23687));
xlabel('Time');
ylabel('Amplitude');
title('Full wave rectified signal');
y4=envelope(y2,2000,'rms');
subplot(2,2,4);
plot(y4(1:23687));
xlabel('Time');
ylabel('Amplitude');
title('RMS Enveloped signal');
threshold = 0.01;
for n=1:23687
    if y4(n) >= threshold
        y5(n)=1;
    else
        y5(n)=0;
    end
end
figure;
plot(y5);
a=1;
b=256;
for m=1:90
    a=a+256;
    b=b+256;
    fprintf(device,y5(a:b));
end