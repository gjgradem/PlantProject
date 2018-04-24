# PlantProject
Creating an arduino/rpi communication to monitor and water plants.

Working version: :x:

# Stuff i want to implement for sure
* Arduino & rPI serial communication :white_check_mark:
* A database to store data about watering times, moisture levels and time of the day :white_check_mark:
* A 5v pump powered by the arduino to water the plants with a tube :white_check_mark:
* A moisture sensor to measure the plant's moisture levels to generate data and optimize the water supply so the plant doesn't die :white_check_mark:
* A google firebase database to store the data :white_check_mark:


# Nice to haves
* Google weather connection to get data based on daily sun and watering.
* Some kind of webhost to control manual watering
* Webpage to see stats and interact with them (possibly on an external host)
* Multiple plants support

# Extra's if I have enough time
* Application to monitor the plant (ionic?)
* Functionality to manually water the plant
* Extra pumping system for plant supplements with automation or manual triggers

So far the Raspberry Pi script and the Arduino script are done. Below you can checkout how they work and how to install them.

## Raspberry Pi
For now only my own plants and firebase config are used. Nothing generalized yet. To use the raspbery script, which is made to store seeial data from the arduino into a google firebase app, download the processor.py sand place it on your raspberry. type "python processor.py" in a terminal pointing to the folder where you downloaded your script. for now you NEED an arduino connected to start.

[For more documentation about the raspberry pi script, check this link](raspberrypi/raspberrypi.md)
