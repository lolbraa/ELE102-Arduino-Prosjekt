clear
close all

% Definere frekvenser
f1=1
f2=1

% Samplingsperioden
t=0:0.001:50;

% Simulerte kurver for sending (y1), mottaker (y2) og mottaker 90grader
% forskøvet (y2_b)
y1=sin(6.28.*f1.*t);
y2=sin(6.28.*f2.*t);
y2_b=sin(6.28.*f2.*t+pi/2);

% Plotte sending og mottaking
subplot(2,1,1)
plot(y1)
hold on
plot(y2)


% Bruker identiteten: sin(x)^2 + cos(x)^2 = 1
% og filtrerer signalet for å finne en linje som beskriver sammenfalling 
a=y1.*y2;
b=y1.*y2_b;
ab=a.^2+b.^2;
ab_filtrert=lavpassfilter(ab,0.1,500);

subplot(2,1,2)
plot(y1.*y2)
hold on
plot(y1.*y2_b)


figure
plot(ab)
hold on
plot(ab_filtrert)

function y = lavpassfilter(x, dt,RC)
% Digitalt RC lavpassfilter
% Variable:
% inputdata - x
% tidsintervall – dt
% tidskonstant RC
%
% Eksempel på bruk:
% y_filter10 = lavpassfilter(stoy_data,1,10);
alfa = dt/(RC+dt);
y(1) = x(1);
n = length(x);
for i = 2:n
    y(i) = alfa*x(i) + (1-alfa)*y(i-1);
end
end