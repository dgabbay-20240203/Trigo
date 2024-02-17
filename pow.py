# Author: Dan Gabbay
# Creation date: February 17, 2024

import math
import matplotlib.pyplot as plt

def ConvertValueToIndex(time_power, power_level):
    min_delta = 100
    time_delay = 0

    j=0
    while j < len(time_power):
        if min_delta > abs(time_power[j] - power_level):
            min_delta = abs(time_power[j] - power_level)
            time_delay = j
        j = j + 1
    return time_delay    

time_step = 0.000001
#--------------------------------------------
# Select "Frequency" and "fraction_step" as needed.
#fraction_step = 0.4 # 0.4%
fraction_step = 1 # 1%
#Frequency = 50 # 50 Hz
Frequency = 60 # 60 Hz
#--------------------------------------------
PI = 3.141592653589793
n = 1
angle = 2*PI*Frequency*time_step*n
sine_square_table = []
Integral = []
opposite_Integral = []
power_fraction = []

while angle <= PI:
    sine_square_table.append(math.sin(angle)**2)
    Integral.append(angle/2 - math.sin(2*angle)/4)
    n = n + 1
    angle = 2*PI*Frequency*time_step*n

for x in Integral:
    opposite_Integral.append(PI/2 - x)
    
for x in opposite_Integral:
    power_fraction.append(200 * x / PI)

power_level = 0
delays_table = []
while power_level <= 100.1:
    k = ConvertValueToIndex(power_fraction, power_level)
    delays_table.append(k)
    power_level = power_level + fraction_step

print("const unsigned short powerToDelayTbale_" + str(Frequency)+"_Hz[" + str(len(delays_table)) + "]" + " = {")
i = 0
while i < len(delays_table) - 1:
    print(str(delays_table[i]) + ", ", end = "")
    i = i + 1
    if ((i % 16) == 0):
        print("")
print(str(delays_table[i]) + "};")

plt.plot(power_fraction)
plt.ylabel("Power level in % of maximum power")
plt.xlabel("Time delay of firing pulse from zero-crossing in microseconds (" + str(Frequency) + " Hz)")
plt.show()
