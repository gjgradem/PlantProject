# Raspberry Pi script

The only purpose of this script yet is to be able to receive serial data and convert the commands the arduino is giving, into readable data for the Firebase. It's nothing special yet, and it needs some work to be 100% complete, but the basics are there

## Already done
- Firebase connection
- Recognition of commands from the arduino

## To do
- When no arduino found, wait for one or check another port
- When firebase connection fails, use a try catch or something but don't end the script