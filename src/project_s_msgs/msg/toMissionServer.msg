Header header				# Contains ROS timestamp, sequence & frame id			

uint32 idCar				# Car Identification Number

uint8 state				# Car status to server 
uint8 UNAVAILABLE=0
uint8 WAITING=1
uint8 NAVIGATING=2
uint8 ENDING=3
uint8 SLEEPING=4

uint8 mode
uint8 ARDUINOMODE=0
uint8 TRANSPARENTMODE=1
uint8 BYFIELDMODE=2

string lat				# Car position latitude
string lng				# Car position longitude

string url
string data
