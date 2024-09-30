
from __future__ import division
import os
import rospkg

from geometry_msgs.msg import Point
from std_msgs.msg import Float64, UInt32
from std_msgs.msg import Bool
import rospy
from python_qt_binding import loadUi
#from python_qt_binding.QtCore import Qt, QTimer, Slot
#from python_qt_binding.QtGui import QKeySequence
from python_qt_binding.QtCore import *
from python_qt_binding.QtGui import *
from python_qt_binding.QtWidgets import QShortcut, QWidget
from rqt_gui_py.plugin import Plugin

from project_s_msgs.msg import ObstacleFusion, GenericSmartData, ObstacleReport, RoadModel, Speed
from dbw_mkz_msgs.msg import GearCmd
from dbw_mkz_msgs.msg import Gear
from dbw_mkz_msgs.msg import ThrottleCmd
from dbw_mkz_msgs.msg import BrakeCmd
from dbw_mkz_msgs.msg import SteeringCmd
from dbw_mkz_msgs.msg import SteeringReport
from geometry_msgs.msg import Twist
from dbw_mkz_msgs.msg import TwistCmd
from sensor_msgs.msg import Imu
from dbw_mkz_msgs.msg import TurnSignalCmd
from dbw_mkz_msgs.msg import TurnSignal
from std_msgs.msg import Empty

class Sniffer(Plugin):

    def __init__(self, context):
        super(Sniffer, self).__init__(context)
        self.setObjectName('Sniffer')

        self._widget = QWidget()
        rp = rospkg.RosPack()
        ui_file = os.path.join(rp.get_path('hmi_as'), 'resource', 'Sniffer.ui')
        loadUi(ui_file, self._widget)
        self._widget.setObjectName('SnifferUI')
        if context.serial_number() > 1:
            self._widget.setWindowTitle(self._widget.windowTitle() + (' (%d)' % context.serial_number()))
        context.add_widget(self._widget)

        # Subscriber Topics
        self._sub_steering_cmd = None
        self._sub_steering_cmd = rospy.Subscriber("steering_cmd", SteeringCmd, self.callback_steering_cmd_data)

        self._sub_throttle_cmd = None
        self._sub_throttle_cmd = rospy.Subscriber("throttle_cmd", ThrottleCmd, self.callback_throttle_cmd_data)

        self._sub_brake_cmd = None
        self._sub_brake_cmd = rospy.Subscriber("brake_cmd", BrakeCmd, self.callback_brake_cmd_data)

        steering_report = SteeringReport()
        self._sub_steering_report = None
        self._sub_steering_report = rospy.Subscriber("/steering_report", SteeringReport, self.callback_steering_report_data)
        # sert a recevoir manuellement pour validation
        # self._widget.steering_report_speed.textChanged.connect(self.changed_steering_report_speed)
        # self._widget.steering_report_wheel_angle.textChanged.connect(self.changed_steering_report_wheel_angle)

        self.IMU_report = Imu()
        self._sub_imu = None
        self._sub_imu = rospy.Subscriber("imu/data_raw", Imu, self.callback_imu_data)
        # sert a recevoir manuellement pour validation
        # self._widget.IMU_yaw_rate.textChanged.connect(self.changed_IMU_yaw_rate)

        # Publisher Topics
        self.roadModel = RoadModel()
        self.pub_road_model_EH = rospy.Publisher("road_model_EH_data", RoadModel, queue_size=1)

        self.vehicle_speed_planning = Float64()
        self.pub_vehicle_speed_planning = rospy.Publisher("vehicle_speed_planning", Float64, queue_size=1)

        self.cmd_vel = Twist()
        self.pub_cmd_vel = rospy.Publisher("cmd_vel", Twist, queue_size=1)
        self._widget.pushButton_SteeringLeft_1.clicked.connect(self.changed_cmd_vel_angular_Left_1)
        self._widget.pushButton_SteeringCenter_1.clicked.connect(self.changed_cmd_vel_angular_Center)
        self._widget.pushButton_SteeringRight_1.clicked.connect(self.changed_cmd_vel_angular_Right_1)
        self._widget.pushButton_SteeringLeft_2.clicked.connect(self.changed_cmd_vel_angular_Left_2)
        self._widget.pushButton_SteeringCenter_2.clicked.connect(self.changed_cmd_vel_angular_Center)
        self._widget.pushButton_SteeringRight_2.clicked.connect(self.changed_cmd_vel_angular_Right_2)

        self._widget.pushButtonSpeed_1.clicked.connect(self.changed_Vel_1)
        self._widget.pushButtonSpeed_2.clicked.connect(self.changed_Vel_2)
        self._widget.pushButtonSpeed_3.clicked.connect(self.changed_Vel_3)
        self._widget.pushButtonSpeed_4.clicked.connect(self.changed_Vel_4)

        self.pub_enable = rospy.Publisher("enable", Empty, queue_size=1)
        self.pub_disable = rospy.Publisher("disable", Empty, queue_size=1)
        self._widget.dbw_enabled.stateChanged.connect(self.changed_dbw_enabled)

        self.pub_gear_cmd = rospy.Publisher("gear_cmd", GearCmd, queue_size=1)
        self._widget.radioButton_Gear_P.clicked.connect(self.changed_gear_cmd)
        self._widget.radioButton_Gear_R.clicked.connect(self.changed_gear_cmd)
        self._widget.radioButton_Gear_N.clicked.connect(self.changed_gear_cmd)
        self._widget.radioButton_Gear_D.clicked.connect(self.changed_gear_cmd)

        self.turn_signal_cmd = TurnSignalCmd()
        self.pub_turn_signal_cmd = rospy.Publisher("turn_signal_cmd", TurnSignalCmd, queue_size=1)
        self._widget.pushButton_Blink_Left.clicked.connect(self.changed_Blink_Left)
        self._widget.pushButton_Blink_Right.clicked.connect(self.changed_Blink_Right)

	# Circuit Manager
        self.circuit_manager_cmd = UInt32()
        self.pub_circuit_manager_cmd = rospy.Publisher("circuit_manager_cmd", UInt32, queue_size=1)
        self._widget.Circuit_Manager_STOP.clicked.connect(self.changed_Circuit_Manager_STOP)
        self._widget.Circuit_Manager_SQUARE.clicked.connect(self.changed_Circuit_Manager_SQUARE)
        self._widget.Circuit_Manager_EIGHT.clicked.connect(self.changed_Circuit_Manager_EIGHT)

        self._update_parameter_timer = QTimer(self)
        self._update_parameter_timer.timeout.connect(self._on_update)
        self._update_parameter_timer.start(10)

	# A ENLEVER POUR LA DEMO CHICAGO
        rospy.Timer(rospy.Duration(0.02), self.periodically_cmd_vel)
	# FIN
        rospy.Timer(rospy.Duration(0.05), self.periodically_turn_signal_cmd)

    def _on_update(self):
        print("")

    # periodic topics
    # A ENLEVER POUR LA DEMO CHICAGO
    def periodically_cmd_vel(self,event):
        self.pub_cmd_vel.publish(self.cmd_vel)
        self.vehicle_speed_planning = self.cmd_vel.linear.x
        self.pub_vehicle_speed_planning.publish(self.vehicle_speed_planning)
        self.roadModel.odom.header.stamp = rospy.Time.now()
        self.roadModel.speedEnveloppe[0].offset.data = 0
        self.roadModel.speedEnveloppe[0].speed.data = self.cmd_vel.linear.x
        self.pub_road_model_EH.publish(self.roadModel)
    # FIN

    def periodically_turn_signal_cmd(self,event):
     	self.pub_turn_signal_cmd.publish(self.turn_signal_cmd)

    # Received topic
    def callback_steering_cmd_data(self,data):
        self._widget.SteeringWheelAngleCmd.setText('%0.2f'  % data.steering_wheel_angle_cmd)
        f_buffer = data.steering_wheel_angle_cmd*180.0/3.14159
        self._widget.SteeringWheelAngleCmd_deg.setText('%0.2f'  % f_buffer)

        # TEMPORAIRE, a valider & a enlever
        if data.steering_wheel_angle_cmd > 0:
            f_buffer = 200
            self._widget.progressBar_SteeringWheel_Left.setValue(f_buffer)
            self._widget.progressBar_SteeringWheel_Right.setValue(0)
        else:
            f_buffer = 100
            self._widget.progressBar_SteeringWheel_Left.setValue(f_buffer)
            self._widget.progressBar_SteeringWheel_Right.setValue(100)

    def callback_throttle_cmd_data(self,data):
        self._widget.ThrottleCmd.setText('%0.2f'  % data.pedal_cmd)

    def callback_brake_cmd_data(self,data):
        self._widget.BrakeCmd.setText('%0.2f'  % data.pedal_cmd)

    def callback_imu_data(self,data):
        self.IMU_report = data

        self._widget.IMU_Accel_X.setText('%0.2f'  % data.linear_acceleration.x)
        self._widget.IMU_Accel_Y.setText('%0.2f'  % data.linear_acceleration.y)
        self._widget.IMU_Accel_Z.setText('%0.2f'  % data.linear_acceleration.z)

        self._widget.IMU_Gyro_X.setText('%0.2f'  % data.angular_velocity.x)
        self._widget.IMU_Gyro_Y.setText('%0.2f'  % data.angular_velocity.y)
        self._widget.IMU_Gyro_Z.setText('%0.2f'  % data.angular_velocity.z)

        self._widget.ActualYawRate.setText('%0.2f'  % data.angular_velocity.z)
        f_buffer = data.angular_velocity.z*180.0/3.14159
        self._widget.ActualYawRate_deg.setText('%0.2f'  % f_buffer)

    def callback_steering_report_data(self,data):
        steering_report = data

        # TEMPORAIRE, a remettre
        self._widget.ActualVel.setText('%0.2f'  % data.speed)
        f_buffer = data.speed * 3.6
        self._widget.progressBar_ActualVel_kmh.setValue(f_buffer)

        # TEMPORAIRE, a valider & a remettre
        if data.steering_wheel_angle >= 0:
           self._widget.progressBar_SteeringWheel_Left.setValue(200)
           self._widget.progressBar_SteeringWheel_Right.setValue(0)
        else:
           self._widget.progressBar_SteeringWheel_Left.setValue(0)
           self._widget.progressBar_SteeringWheel_Right.setValue(200)

        # question : steering_report.steering_wheel_angle_cmd est la meme variable que steering_cmd.steering_wheel_angle_cmd ?
        self._widget.SteeringWheelAngleCmd.setText ('%0.2f'  % data.steering_wheel_angle_cmd)
        f_buffer = data.steering_wheel_angle_cmd*180.0/3.14159
        self._widget.SteeringWheelAngleCmd_deg.setText ('%0.2f'  % f_buffer)

    # Modify topic or hmi on changed_hmi
    def changed_Vel_1(self):
        self.cmd_vel.linear.x = float(self._widget.Vel_1.text())
        #self.cmd_vel.angular.z =

        self._widget.TargetVel.setText('%0.2f'  % self.cmd_vel.linear.x)
        f_buffer = self.cmd_vel.linear.x * 3.6
        self._widget.progressBar_TargetVel_kmh.setValue(f_buffer)
        # TEMPORAIRE, a enlever
        self._widget.ActualVel.setText('%0.2f'  % self.cmd_vel.linear.x)
        self._widget.progressBar_ActualVel_kmh.setValue(f_buffer)

    def changed_Vel_2(self):
        self.cmd_vel.linear.x = float(self._widget.Vel_2.text())
        #self.cmd_vel.angular.z =

        self._widget.TargetVel.setText('%0.2f'  % self.cmd_vel.linear.x)
        f_buffer = self.cmd_vel.linear.x * 3.6
        self._widget.progressBar_TargetVel_kmh.setValue(f_buffer)
        # TEMPORAIRE, a enlever
        self._widget.ActualVel.setText('%0.2f'  % self.cmd_vel.linear.x)
        self._widget.progressBar_ActualVel_kmh.setValue(f_buffer)

    def changed_Vel_3(self):
        self.cmd_vel.linear.x = float(self._widget.Vel_3.text())
        #self.cmd_vel.angular.z =

        self._widget.TargetVel.setText('%0.2f'  % self.cmd_vel.linear.x)
        f_buffer = self.cmd_vel.linear.x * 3.6
        self._widget.progressBar_TargetVel_kmh.setValue(f_buffer)
        # TEMPORAIRE, a enlever
        self._widget.ActualVel.setText('%0.2f'  % self.cmd_vel.linear.x)
        self._widget.progressBar_ActualVel_kmh.setValue(f_buffer)

    def changed_Vel_4(self):
        self.cmd_vel.linear.x = float(self._widget.Vel_4.text())
        #self.cmd_vel.angular.z =

        self._widget.TargetVel.setText('%0.2f'  % self.cmd_vel.linear.x)
        f_buffer = self.cmd_vel.linear.x * 3.6
        self._widget.progressBar_TargetVel_kmh.setValue(f_buffer)
        # TEMPORAIRE, a enlever
        self._widget.ActualVel.setText('%0.2f'  % self.cmd_vel.linear.x)
        self._widget.progressBar_ActualVel_kmh.setValue(f_buffer)

    def changed_cmd_vel_angular_Left_1(self):
        #self.cmd_vel.linear.x =
        if self._widget.radioButton_SteeringYawRate_1.isChecked():
            f_buffer = float(self._widget.SteeringYawRate_deg_1.text()) * 3.14159 / 180
            self.cmd_vel.angular.z = +f_buffer

        f_buffer = self.cmd_vel.angular.z * 180 / 3.14159
        self._widget.TargetYawRate.setText('%0.2f'  % self.cmd_vel.angular.z)
        self._widget.TargetYawRate_deg.setText('%0.2f'  % f_buffer)

    def changed_cmd_vel_angular_Center(self):
        #self.cmd_vel.linear.x =
        self.cmd_vel.angular.z = 0

        f_buffer = self.cmd_vel.angular.z * 180 / 3.14159
        self._widget.TargetYawRate.setText('%0.2f'  % self.cmd_vel.angular.z)
        self._widget.TargetYawRate_deg.setText('%0.2f'  % f_buffer)

    def changed_cmd_vel_angular_Right_1(self):
        #self.cmd_vel.linear.x =
        if self._widget.radioButton_SteeringYawRate_1.isChecked():
            f_buffer = float(self._widget.SteeringYawRate_deg_1.text()) * 3.14159 / 180
            self.cmd_vel.angular.z = -f_buffer

        f_buffer = self.cmd_vel.angular.z * 180 / 3.14159
        self._widget.TargetYawRate.setText('%0.2f'  % self.cmd_vel.angular.z)
        self._widget.TargetYawRate_deg.setText('%0.2f'  % f_buffer)

    def changed_cmd_vel_angular_Left_2(self):
        #self.cmd_vel.linear.x =
        if self._widget.radioButton_SteeringYawRate_2.isChecked():
            f_buffer = float(self._widget.SteeringYawRate_deg_2.text()) * 3.14159 / 180
            self.cmd_vel.angular.z = +f_buffer

        f_buffer = self.cmd_vel.angular.z * 180 / 3.14159
        self._widget.TargetYawRate.setText('%0.2f'  % self.cmd_vel.angular.z)
        self._widget.TargetYawRate_deg.setText('%0.2f'  % f_buffer)

    def changed_cmd_vel_angular_Right_2(self):
        #self.cmd_vel.linear.x =
        if self._widget.radioButton_SteeringYawRate_2.isChecked():
            f_buffer = float(self._widget.SteeringYawRate_deg_2.text()) * 3.14159 / 180
            self.cmd_vel.angular.z = -f_buffer

        f_buffer = self.cmd_vel.angular.z * 180 / 3.14159
        self._widget.TargetYawRate.setText('%0.2f'  % self.cmd_vel.angular.z)
        self._widget.TargetYawRate_deg.setText('%0.2f'  % f_buffer)

    def changed_dbw_enabled(self):
        msg_empty = Empty()
        if self._widget.dbw_enabled.isChecked() == True:
            self.pub_enable.publish(msg_empty)
	    self.cmd_vel.linear.x = 0
	    self.cmd_vel.angular.z = 0
	    self.vehicle_speed_planning = 0
	else:
            self.pub_disable.publish(msg_empty)

    def changed_gear_cmd(self):
        msg = GearCmd()
        if self._widget.radioButton_Gear_P.isChecked():
            msg.cmd.gear = Gear.PARK
        elif self._widget.radioButton_Gear_R.isChecked():
            msg.cmd.gear = Gear.REVERSE
        elif self._widget.radioButton_Gear_N.isChecked():
            msg.cmd.gear = Gear.NEUTRAL
        elif self._widget.radioButton_Gear_D.isChecked():
            msg.cmd.gear = Gear.DRIVE
        else:
            msg.cmd.gear = Gear.NONE
        try:
            self.pub_gear_cmd.publish(msg)
        except TypeError:
            print("")

    def changed_Blink_Left(self):
        if self._widget.pushButton_Blink_Left.isChecked():
            self.turn_signal_cmd.cmd.value = TurnSignal.LEFT
        else:
            self.turn_signal_cmd.cmd.value = TurnSignal.NONE

    def changed_Blink_Right(self):
        if self._widget.pushButton_Blink_Right.isChecked():
            self.turn_signal_cmd.cmd.value = TurnSignal.RIGHT
        else:
            self.turn_signal_cmd.cmd.value = TurnSignal.NONE

    def changed_Circuit_Manager_STOP(self):
        msg = UInt32()
        msg = 0
        try:
            self.pub_circuit_manager_cmd.publish(msg)
        except TypeError:
            print("")

    def changed_Circuit_Manager_SQUARE(self):
        msg = UInt32()
        msg = 1
        try:
            self.pub_circuit_manager_cmd.publish(msg)
        except TypeError:
            print("")

    def changed_Circuit_Manager_EIGHT(self):
        msg = UInt32()
        msg = 2
        try:
            self.pub_circuit_manager_cmd.publish(msg)
        except TypeError:
            print("")


