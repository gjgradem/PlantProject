//Start of the file
import serial

ser = serial.Serial('/dev/ttyXXX', 9600)

while 1: 
    ser.readline()
