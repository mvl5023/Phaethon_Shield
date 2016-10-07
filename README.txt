* 	Phaethon Shield Unit 		*
*	Michael Lipski			*
*	Summer 2016			*

Contains sketches demonstrating control of the custom Arduino Mega 2560 shield designed 
to aid in CPV testing.  Shield houses a transimpedance amplifier for the two pyranometers
(global and DNI) and the two photovoltaic microcells (bare and concentrator).  PV transimpedance
amps have gain controlled by digital potentiometers (addressable over I2C). Two latching relays
route the PV signals either through their respective transimpedance amp or to an SMB coaxial port 
that would nominally be connected to an SMU.

Also contains test sketches for Adafruit RGB LCD shield and Datalogger SD card/RTC shield.