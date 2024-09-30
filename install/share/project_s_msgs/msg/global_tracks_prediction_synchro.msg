Header header
std_msgs/UInt8 id

geometry_msgs/Pose obstaclePosition		# obstacle position
Header headerPosition
std_msgs/Float32 groundHeight			# ground height
geometry_msgs/Twist obstacleVelocity		# obstacle speed
geometry_msgs/Accel obstacleAcceleration	# obstacle acceleration
geometry_msgs/Pose obstaclePoseVariance		# obstacle position variance
Header headerPoseVariance
geometry_msgs/Twist obstacleVelocityVariance	# obstacle speed variance
Header headerVelocityVariance
geometry_msgs/Vector3 obstacleDimensions	# obstacle x,y,z - length, width, height
std_msgs/UInt8 obstacleClass
std_msgs/UInt8 classificationProbability
std_msgs/Float64 dateAcquisition

# History




