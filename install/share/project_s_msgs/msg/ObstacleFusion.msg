Header header
std_msgs/UInt8 id

geometry_msgs/Pose obstaclePosition		# obstacle position
geometry_msgs/Pose obstacleBodyCenter	        # Obstacle Center for Corner Computation
float32 distanceCurviligne
std_msgs/Float32 groundHeight			# ground height
geometry_msgs/Twist obstacleVelocity		# obstacle speed
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
geometry_msgs/Vector3 obstacleCap
std_msgs/UInt8 existenceProbability
std_msgs/UInt8 existenceState
uint8 IDLE_TRACK    = 0
uint8 PRE_TRACK	    = 1
uint8 POST_TRACK    = 2
uint8 CURRENT_TRACK = 3
std_msgs/Float32 scoreDetection
std_msgs/Float32 nbrDetection
std_msgs/Float32 nbrVisibility
std_msgs/Float32 scorePersistence
std_msgs/Float32 nbrUpdate
std_msgs/Float32 nbrAge
time existenceFirstTime
std_msgs/Float32 existenceDurationTime
std_msgs/UInt8 anchorPoint			# reference point
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
uint8 obstacleClass
uint8 vision_only_sign_type
std_msgs/UInt8 classificationProbability

uint8 obstacleAssignment
uint8 ASSIGNMENT_COTE_DROIT  = 1
uint8 ASSIGNMENT_COTE_GAUCHE = 2

uint8 CORNER_FRONT_RIGHT= 0
uint8 CORNER_FRONT_LEFT = 1
uint8 CORNER_BACK_RIGHT = 2
uint8 CORNER_BACK_LEFT  = 3
geometry_msgs/Point[4] obstacleCorner

uint8 OCCUPIED_LANE_INDEFINI  = 255
uint8 NbrOccupiedLane
uint8 INDEX_LINE_INDEFINI  = 255
uint8[2] indexAssignmentLine
std_msgs/Float32 positionLane
std_msgs/Float32 departureRighttDistance
std_msgs/Float32 departureLeftDistance

std_msgs/Int16 trafficLights
std_msgs/Int16 vehicleLights
std_msgs/UInt16[3] idPiste			#define NBR_SENSOR		3	(voir obstacles_fusion.cpp)

# History




