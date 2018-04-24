#Start of the file
import serial
from time import gmtime, strftime
import json
from firebase import firebase

firebase = firebase.FirebaseApplication('https://plantproject-c1a0c.firebaseio.com', None)

def commandSwitch( cmd, data ):
	if cmd == "feed":
		doFeedRow(data)
	elif cmd == "measure":
		doMeasureRow(data)
	return

def doFeedRow(data):
	pumpSeconds = int(data) / 1000
	#print("Starting firebase entry with value {} seconds and date {}").format(pumpSeconds,)
	rawdata = dict()
	rawdata['pumpSeconds'] = pumpSeconds
	rawdata['timestamp'] = strftime("%Y-%m-%d %H:%M:%S", gmtime())

	firebase.post('/plants/komkommer/feedrows', rawdata)
	return

def doMeasureRow(data):
	rawdata = dict()
	rawdata['pumpSeconds'] = pumpSeconds
	rawdata['timestamp'] = strftime("%Y-%m-%d %H:%M:%S", gmtime())

	firebase.post('/plants/komkommer/measure', rawdata)

ser = serial.Serial('/dev/ttyACM0', 9600)

while 1:
	rawinput = ser.readline()
	if not (rawinput is None):
		splittedinput = rawinput.split(":")
		firstarg = splittedinput[0]
		print(firstarg)
		if firstarg  == 'command':
			print('command recognised!')
			commandSwitch(splittedinput[1], splittedinput[2])
	else:
		print("No input read..")