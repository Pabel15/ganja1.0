import serial, time
import matplotlib.pyplot as plt
import numpy as np
from datetime import datetime

va=[5.*i/100. for i in range(0,100)]
va=np.array(va)
vin=5.
R1=50
rluz=R1*va/(vin-va)
rluz2=R1*(vin-va)/va
dR1=0.1*R1
Dva=5./1024.
drluz=np.sqrt((va/(vin-va))**2*dR1**2+R1**2*vin**2/(vin-va)**4*Dva**2)

plt.plot(va,np.sqrt(1.7/(rluz)),"k-")
plt.plot(va,np.sqrt(1.7/((rluz+drluz))),"k--")
plt.plot(va,np.sqrt(1.7/((rluz-drluz))),"k--")

plt.show()