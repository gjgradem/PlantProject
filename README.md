# PlantProject
Creating an arduino/rpi communication to monitor and water plants.

Working version: :x:

Because I always forgot to water my plants in the summer,  I made this script with construction to feed them automatically. If you want this to run you'll need the following things:
- [An arduino](https://store.arduino.cc/)
- [A 5v pump](https://www.aliexpress.com/item/1pcs-Mute-Submersible-Pump-Water-Pump-DC-3V-5V-For-PC-Cooling-Water-Circulation-DIY/32816435741.html)
- [Some jumper cables](https://www.aliexpress.com/item/Dupont-Line-120pcs-10cm-Male-to-Male-Female-to-Male-and-Female-to-Female-Jumper-Wire/32824654220.html)
- [Some tube fitting the pump (because each pump has different sizes, you should check this for yourself)][https://www.aliexpress.com/item/1PCS-YT830-Imported-Silicone-Tube-Food-Grade-Capillary-Transparent-Hose-4-mm-5-6-7-8/32778136849.html]
- [A moisture sensor](https://www.aliexpress.com/item/2pcs-Soil-Humidity-Sensor-Module-Hygrometer-Detection-Moisture-Sensor-Sensing-Module-for-Arduino-Automatic-Watering-System/32760389137.html)

If you want data collection you will need a dedicated computer or [Raspberry Pi](https://www.raspberrypi.org/products/) aswell. Maybe I'll try to implement the rPi script in the arduino if I have time enough.

The different scripts in existance are: 
- :white_check_mark: [Arduino script](arduino/script/arduino.md)
- :white_check_mark: [Raspberry Pi script (python)](raspberrypi/raspberrypi.md)
- :x: [An app](plantapp/mobileapp.md)
- :x: [A web dashboard](webapp/webapp.md)

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
* Ethernet connection on the arduino so the raspberry won't be needed anymore

So far the Raspberry Pi script and the Arduino script are done. Below you can checkout how they work and how to install them.

## Raspberry Pi
For now only my own plants and firebase config are used. Nothing generalized yet. To use the raspbery script, which is made to store seeial data from the arduino into a google firebase app, download the processor.py sand place it on your raspberry. type "python processor.py" in a terminal pointing to the folder where you downloaded your script. for now you NEED an arduino connected to start.

[For more documentation about the raspberry pi script, check this link](raspberrypi/raspberrypi.md)
