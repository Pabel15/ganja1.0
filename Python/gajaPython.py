import serial, time
import matplotlib.pyplot as plt
import numpy as np

arduino = serial.Serial('/dev/ttyUSB0', 115200)
i=0
x=[]
luz=[]
temp=[]
rawString = arduino.readline()
e=[float(x) for x in rawString.strip().split()]
luz.append(e[0])
temp.append(e[1])
x.append(i)
i+=1
plt.ion()
fig, ax = plt.subplots(2)
line1, = ax[0].plot(luz, 'r-')
line2, = ax[1].plot(temp, 'k-')
ax[0].set_autoscale_on(True) # enable autoscale
ax[0].autoscale_view(True,True,True)
ax[1].set_autoscale_on(True) # enable autoscale
ax[1].autoscale_view(True,True,True)
while(True):
	rawString = arduino.readline()
	e=[float(x) for x in rawString.strip().split()]
	x.append(i)
	i+=1
	luz.append(e[0])
	temp.append(e[1])
	line1.set_ydata(luz)
	line2.set_ydata(temp)
	line1.set_xdata(x)
	line2.set_xdata(x)
	ax[0].relim()        # Recalculate limits
	ax[0].autoscale_view(True,True,True) #Autoscale	plt.draw()
	ax[1].relim()        # Recalculate limits
	ax[1].autoscale_view(True,True,True) #Autoscale	plt.draw()
	plt.pause(0.0001)
arduino.close()	
