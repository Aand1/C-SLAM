addpath('lib')

global path
global stopAll
    
stopAll = 1;

pause(1)

stopAll = 0;

path = '/tmp/roamfree/';

%close all
%figure(1)
%figure(2)
%set(2, 'DefaultAxesPosition', [0.05, 0.05, 0.9, 0.9])

close all
figure(1)
set(1,'OuterPosition', [0 0 1680/2 1050])

figure(2)  
set(2,'OuterPosition', [1680/2 0 1680/2 1050])


watchFile();
