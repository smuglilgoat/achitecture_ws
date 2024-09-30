Header header
std_msgs/UInt16 id

geometry_msgs/Pose obstaclePosition	        		# obstacle position
float64 obstaclePosition_linear_Unknown = 999
float64 obstaclePosition_orientation_Unknown = 999

geometry_msgs/Pose obstacleBodyCenter	        		# Obstacle Center for Corner Computation

geometry_msgs/Twist obstacleVelocity	                    	# obstacle speed
float64 obstacleVelocity_linear_Unknown = 999
float64 obstacleVelocity_angular_Unknown = 999

geometry_msgs/Twist obstacleRelativeVelocity	           	# obstacle relative velocity
float64 obstacleRelativeVelocity_linear_Unknown = 999
float64 obstacleRelativeVelocity_angular_Unknown = 999

geometry_msgs/Accel obstacleAcceleration        		# obstacle acceleration
float64 obstacleAcceleration_linear_Unknown = 999
float64 obstacleAcceleration_angular_Unknown = 999

geometry_msgs/Vector3 obstacleDimensions        		# obstacle - length and width
float64 obstacleDimensions_Unknown = 999

uint8 blinkerInfo                               		# blinker status (eg. left blinker on)
uint8 blinkerInfo_Unknown=0

uint8 cutInAndOut                               		# Vehicle cutting in or out of ego lane 
uint8 cutInAndOut_Unknown=0

uint8 obstacleType                             			# obstacle classification
uint8 obstacleType_Unknown=7

uint8 obstacleStatus                            		# obstacle’s moving status
uint8 obstacleStatus_Unknown=0

bool obstacleBrakeLights                        		# obstacle brake light on or off
bool obstacleBrakeLights_Unknown=0 

int8 cipvFlag                                   		# If obstacle Closest in Path Vehicle
int8 cipvFlag_Unknown=2

int8 obstacleReplaced                           		# If obstacle replaced in this frame
int8 obstacleReplaced_Unknown=2

uint8 obstacleValid                             		# obstacle valid
uint8 obstacleValid_Unknown=3

uint16 obstacleAge                              		# obstacle age in number of frames
uint16 obstacleAge_Unknown=256

uint8 obstacleLane                              		# obstacle's lane (eg. ego lane or next lane)
uint8 obstacleLane_Unknown=0

float32 obstacleAngle                           		# angle to center of obstacle in degrees
float32 obstacleAngle_Unknown = 999

float32 obstacleAngleVariance                   		# Obstacle angle Variance (Lidar)
float32 obstacleAngleVariance_Unknown=-1

float32 obstacleAngleRate                       		# angle rate of the center of obstacle (degrees/sec)
float32 obstacleAngleRate_Unknown = 999

float64 obstacleScaleChange                     		# scale change from previous frame   
float64 obstacleScaleChange_Unknown = 999
                           
uint8 visionOnlySignType                        		# Traffic Signal Recognition (TSR) sign type
uint8 visionOnlySignType_Unknown=254

uint8 visionOnlySupplementarySignType               		# Supplementary sign type - rain, snow, arrow etc. 
uint8 visionOnlySupplementarySignType_Unknown=0

geometry_msgs/Vector3 signPosition                  		# X-Longitudnal position, Y-Lateral position ,Z-Height of sign relative to ME
float64 signPosition_Unknown = 999

float64 filterType                                    		# filtering 
float64 filterType_Unknown = 999

geometry_msgs/Pose obstaclePoseVariance		                # obstacle position variance
float64 obstaclePoseVariance_position_Unknown = -1
float64 obstaclePoseVariance_orientation_Unknown = -1

geometry_msgs/Twist obstacleVelocityVariance	                # obstacle speed variance
float64 obstacleVelocityVariance_linear_Unknown = -1
float64 obstacleVelocityVariance_angular_Unknown = -1

geometry_msgs/Twist obstacleRelativeVelocityVariance	        # obstacle relative velocity variance
float64 obstacleRelativeVelocityVariance_linear_Unknown = -1
float64 obstacleRelativeVelocityVariance_angular_Unknown = -1

std_msgs/Float32 groundHeight			                # ground height
float64 groundHeight_Unknown = 999

float64 classificationProbability
float64 classificationProbability_Unknown = 999

std_msgs/Float64 dateAcquisition
float64 dateAcquisition_Unknown = 999


# History
