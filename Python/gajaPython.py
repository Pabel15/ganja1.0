import serial, time
import matplotlib.pyplot as plt
import numpy as np
from datetime import datetime
arduino = serial.Serial('/dev/ttyUSB0', 115200)
i=0
x=[]
luz=[]
temp=[]
hum=[]
rawString = arduino.readline()
print(rawString)
e=[float(x) for x in rawString.strip().split()]
print(e)
luz.append(e[0])
temp.append(e[1])
hum.append(e[2])
x.append(i)
i+=1
plt.ion()
fig, ax = plt.subplots(3)
line1, = ax[0].plot(x,luz, 'r-')
line2, = ax[1].plot(x,temp, 'k-')
line3, = ax[2].plot(x,hum, 'g-')
ax[0].set_ylabel("Luz [lux]")
ax[1].set_ylabel("Temperatura [ºC]")
ax[2].set_ylabel("Saturacion Agua ")
ax[0].set_autoscale_on(True) # enable autoscale
ax[0].autoscale_view(True,True,True)
ax[1].set_autoscale_on(True) # enable autoscale
ax[1].autoscale_view(True,True,True)
ax[2].set_autoscale_on(True) # enable autoscale
ax[2].autoscale_view(True,True,True)

file=open("datos.dat","w")
while(True):
	rawString = arduino.readline()
	e=[float(x) for x in rawString.strip().split()]
	x.append(i)
	print(datetime.now().strftime("%d/%m/%Y %H:%M:%S"),e[0],e[1],e[2],file=file)
	print(datetime.now().strftime("%d/%m/%Y %H:%M:%S"),e[0],e[1],e[2])
	i+=1
	luz.append(e[0])
	temp.append(e[1])
	hum.append(e[2])
	line1.set_ydata(luz)
	line2.set_ydata(temp)
	line3.set_ydata(hum)
	line1.set_xdata(x)
	line2.set_xdata(x)
	line3.set_xdata(x)
	ax[0].relim()        # Recalculate limits
	ax[0].autoscale_view(True,True,True) #Autoscale	plt.draw()
	ax[1].relim()        # Recalculate limits
	ax[1].autoscale_view(True,True,True) #Autoscale	plt.draw()
	ax[2].relim()        # Recalculate limits
	ax[2].autoscale_view(True,True,True) #Autoscale	plt.draw()
	plt.pause(0.0001)
arduino.close()	
