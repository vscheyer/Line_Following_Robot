%% Collect Data and Plot
clear all
% define serial port
s1 = serial('COM4'); 
% define baud rate
s1.BaudRate=400;   
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
while count < 1000000000000
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

time = linspace(0,1,435);
figure
plot(time, sensorL);
hold on
plot(time, speedL);
xlim([0,0.3])
