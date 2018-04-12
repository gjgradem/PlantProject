#Start of the file
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

while 1:
	rawinput = ser.readline()
	splittedinput = rawinput.split(":")
	print(splittedinput[1])
