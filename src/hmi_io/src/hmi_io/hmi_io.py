# Copyright (c) 2011, Guillaume Guibert, Segula Technologies
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#   * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above
#     copyright notice, this list of conditions and the following
#     disclaimer in the documentation and/or other materials provided
#     with the distribution.
#   * Neither the name of the TU Darmstadt nor the names of its
#     contributors may be used to endorse or promote products derived
#     from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

from __future__ import division
import os
import rospkg

from geometry_msgs.msg import Point
from std_msgs.msg import Float64, UInt32
import rospy
from python_qt_binding import loadUi
#from python_qt_binding.QtCore import Qt, QTimer, Slot
#from python_qt_binding.QtGui import QKeySequence
from python_qt_binding.QtCore import *
from python_qt_binding.QtGui import *
from python_qt_binding.QtWidgets import QShortcut, QWidget
from rqt_gui_py.plugin import Plugin

from project_s_msgs.msg import ObstacleFusion, GenericSmartData, ObstacleReport




class Sniffer(Plugin):

    def __init__(self, context):
        super(Sniffer, self).__init__(context)
        self.setObjectName('Sniffer')

        self._widget = QWidget()
        rp = rospkg.RosPack()
        ui_file = os.path.join(rp.get_path('hmi_io'), 'resource', 'Sniffer.ui')
        loadUi(ui_file, self._widget)
        self._widget.setObjectName('SnifferUI')
        if context.serial_number() > 1:
            self._widget.setWindowTitle(self._widget.windowTitle() + (' (%d)' % context.serial_number()))
        context.add_widget(self._widget)

        self._subCam = None
        self._subLidar = None

        self._subCam = rospy.Subscriber("/camera_me_obstacle", ObstacleReport, self.callback_cam_data)
        self._subLidar = rospy.Subscriber("/lidar_obstacle", ObstacleReport, self.callback_lidar_data)

        self._subEnv = None
        self._subEnv = rospy.Subscriber("/obstacles", ObstacleReport, self.callback_env_data)

  
        self._widget.cameraTopicLine.textChanged.connect(self.fct_camera_topic)
        self._widget.lidarTopicLine.textChanged.connect(self.fct_lidar_topic)
        self._widget.envTopicLine.textChanged.connect(self.fct_env_topic)


        self._update_parameter_timer = QTimer(self)
        self._update_parameter_timer.timeout.connect(self._on_update)
        self._update_parameter_timer.start(10)



    def _on_update(self):
        print("")

    # Received camera data handler
    def callback_cam_data(self,data):
        self._widget.camPosXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.x)
        self._widget.camPosYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.y)
        self._widget.camPosZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.z)

        self._widget.camRollLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.x)
        self._widget.camPitchLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.y)
        self._widget.camYawnLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.z)

        self._widget.camSpeedXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.x)
        self._widget.camSpeedYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.y)
        self._widget.camSpeedZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.z)
        
        self._widget.camDimXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.x)
        self._widget.camDimYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.y)
        self._widget.camDimZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.z)
    
    # Received lidar data handler
    def callback_lidar_data(self,data):
        self._widget.lidarPosXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.x)
        self._widget.lidarPosYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.y)
        self._widget.lidarPosZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.z)

        self._widget.lidarRollLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.x)
        self._widget.lidarPitchLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.y)
        self._widget.lidarYawnLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.z)

        self._widget.lidarSpeedXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.x)
        self._widget.lidarSpeedYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.y)
        self._widget.lidarSpeedZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.z)
        
        self._widget.lidarDimXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.x)
        self._widget.lidarDimYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.y)
        self._widget.lidarDimZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.z)
    

    # Received Environment data handler
    def callback_env_data(self,data):
        self._widget.idLabel.setText ('%0.2f'  % data.id.data)
        self._widget.envPosXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.x)
        self._widget.envPosYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.y)
        self._widget.envPosZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.position.z)

        self._widget.envRollLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.x)
        self._widget.envPitchLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.y)
        self._widget.envYawnLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstaclePosition.orientation.z)

        self._widget.envSpeedXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.x)
        self._widget.envSpeedYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.y)
        self._widget.envSpeedZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleVelocity.linear.z)
        
        self._widget.envDimXLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.x)
        self._widget.envDimYLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.y)
        self._widget.envDimZLabel.setText ('%0.2f'  % data.GenericSmartData[0].obstacleDimensions.z)
    


    # Modify topic for the camera publisher handler
    def fct_camera_topic(self,topic):
        topic = str(topic)
        self._unregister_subCam()
        try:
            self._subCam = rospy.Subscriber(topic, ObstacleReport, self.callback_cam_data)
        except TypeError:
            print("")

    def fct_lidar_topic(self,topic):
        topic = str(topic)
        self._unregister_subLidar()
        try:
            self._subLidar = rospy.Subscriber(topic, ObstacleReport, self.callback_lidar_data)
        except TypeError:
            print("")

    def fct_env_topic(self,topic):
        topic = str(topic)
        self._unregister_subEnv()
        try:
            self._subEnv = rospy.Subscriber(topic, ObstacleReport, self.callback_env_data)
        except TypeError:
            print("")


# Unregister functions
    def _unregister_subCam(self):
        if self._subCam is not None:
            self._subCam.unregister()
            self._subCam = None

    def _unregister_subLidar(self):
        if self._subLidar is not None:
            self._subLidar.unregister()
            self._subLidar = None

    def _unregister_subEnv(self):
        if self._subEnv is not None:
            self._subEnv.unregister()
            self._subEnv = None

    def shutdown_plugin(self):
        self._unregister_subEnv()
        self._unregister_subCam()
        self._unregister_subLidar()
 

    def save_settings(self, plugin_settings, instance_settings):
        instance_settings.set_value('topicCam' , self._widget.cameraTopicLine.text())
        instance_settings.set_value('topicLidar' , self._widget.lidarTopicLine.text())
        instance_settings.set_value('topicEnv' , self._widget.envTopicLine.text())

   
    def restore_settings(self, plugin_settings, instance_settings):
        value = instance_settings.value('topicCam', "/vehicles_viewed_me")         
        value = rospy.get_param("~default_topicCam", value)           
        self._widget.cameraTopicLine.setText(value)

        value = instance_settings.value('topicLidar', "/vehicles_viewed_lidar")   		
        value = rospy.get_param("~default_topicLidar", value)           
        self._widget.lidarTopicLine.setText(value)

        value = instance_settings.value('topicEnv', "/vehicles")   		
        value = rospy.get_param("~default_topicEnv", value)           
        self._widget.envTopicLine.setText(value)

#
        

