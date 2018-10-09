%% Collect Data and Plot
clear all
% define serial port
s1 = serial('COM4'); 
% define baud rate
s1.BaudRate=9600;   
% open the serial port
fopen(s1);
% read continuously to catch all serial data 
s1.ReadAsyncMode = 'continuous'; 
readasync(s1);
%initialize variables
sensorR = [];
sensorL = [];
speedR = [];
speedL = [];
dataSave = [];
count = 1;
% wait until Arduino outputs data 
while(s1.BytesAvailable <= 0) 
end
% loop for a long time, manually terminate 
% when done collecting data
flushinput(s1);
while 1
     % read, convert serial data to double
     data = str2num(fscanf(s1))
     % save x, y, sensor value
     sensorR(count,1) = data(1,1);
     sensorL(count,2) = data(1,2);
     speedR(count,3) = data(1,3);
     speedL(count,4) = data(1,4);
     % flush the serial buffer
     flushinput(s1);
     count = count +1;
end

fclose(s1);

%% Plot

time = linspace(0,1,685);
figure
plot(time', sensorL(:,2), 'r');
hold on
plot(time(1,1:end-1)', speedL(:,4), 'g');
xlim([0.1,0.3])
line([0.1535, 0.1535], get(gca, 'ylim'))
line([0.173, 0.173], get(gca, 'ylim'))
line([0.1915, 0.1915], get(gca, 'ylim'))
line([0.2456, 0.2456], get(gca, 'ylim'))
xlabel('Time (s)');
legend('Left Sensor Values', 'Left Wheel Speeds');
title('Left Sensor and Wheel Speed');
hold off

figure
plot(time', sensorR, 'r');
hold on
plot(time(1,1:end-1)', speedR(:,3), 'g');
line([0.1301, 0.1301], get(gca, 'ylim'))
line([0.136, 0.136], get(gca, 'ylim'))
line([0.1433, 0.1433], get(gca, 'ylim'))
line([0.1608, 0.1608], get(gca, 'ylim'))
line([0.179, 0.179], get(gca, 'ylim'))
line([0.2632, 0.2632], get(gca, 'ylim'))
line([0.269, 0.269], get(gca, 'ylim'))
line([0.2734, 0.2734], get(gca, 'ylim'))
line([0.2822, 0.2822], get(gca, 'ylim'))
line([0.2939, 0.2939], get(gca, 'ylim'))
line([0.1974, 0.1974], get(gca, 'ylim'))
line([0.2149, 0.2149], get(gca, 'ylim'))
line([0.231, 0.231], get(gca, 'ylim'))
line([0.2485, 0.2485], get(gca, 'ylim'))
xlim([0.1,0.3])
xlabel('Time (s)');
legend('Right Sensor Values', 'Right Wheel Speeds');
title('Right Sensor and Wheel Speed');