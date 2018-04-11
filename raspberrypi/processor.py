//Start of the file
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

while 1:
	kek = ser.readline()
	print(kek)
