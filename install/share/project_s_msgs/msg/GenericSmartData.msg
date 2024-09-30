Header header
std_msgs/UInt16 id

geometry_msgs/Pose obstaclePosition		# obstacle position
geometry_msgs/Twist obstacleVelocity		# obstacle speed
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance

uint8 OBSTACLE_CLASS_NONE = 0
uint8 OBSTACLE_CLASS_SIGN = 1
uint8 OBSTACLE_CLASS_PLOT = 2
uint8 OBSTACLE_CLASS_INVALID = 255
uint8 obstacleClass

uint8 vision_only_sign_type
