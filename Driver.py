

import serial
import time
import psutil
import wmi
import math
import datetime


arduinoSerialData = serial.Serial('com3', 9600)
time.sleep(1)

while True:

    net_io = psutil.net_io_counters()
    svmem = psutil.virtual_memory()
    data = ("a"+str(psutil.cpu_percent())+"%"+"b"+str(svmem.percent)+"%" + "c" +str(datetime.datetime.now().strftime("%H:%M:%S/%p")))
    arduinoSerialData.write(data.encode())
    arduinoSerialData.flush()
    time.sleep(1)