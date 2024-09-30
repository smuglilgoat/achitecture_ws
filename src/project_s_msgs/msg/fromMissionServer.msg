Header header				# Contains ROS timestamp, sequence & frame id

uint8 mode
uint8 ARDUINOMODE=0
uint8 TRANSPARENTMODE=1
uint8 BYFIELDMODE=2

bool err				# Server msg error: false, true
string msg				# text message (for information only)
uint8 mission				# Track number
uint32 idUser				# User Identification Number

uint8 errCode				
uint8 MissionSearchError=1
uint8 NoMissionAvailable=2
uint8 MissionAssignmentError=3
uint8 ServerError=4

uint32 idCar				# Car Identification Number

uint8 stateCmd				# Car status echo & command from server
uint8 UNAVAILABLE=0
uint8 WAITING=1
uint8 NAVIGATING=2
uint8 ENDING=3
uint8 SLEEPING=4
uint8 WAKEUP=5
uint8 NAVIGATE=6
uint8 ENDOFNAV=7
uint8 SLEEP=8

string lat				# Car position latitude
string lng				# Car position longitude

string url				# Echo of the URL Request
string data
