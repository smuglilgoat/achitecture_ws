#!/bin/bash

rosbag record -O $(date +%d_%m_%Y_%H_%M).bag ego_data as_tx/point_cloud road_model_EH_data vehicle_speed_planning trajectory_GPS_generation_data fine_map_matching_data electronic_horizon_array_data obstacles_assignment_data road_model_data inspva camera_me_obstacles_align_data vehicle_guidance_data cmd_vel Distance_Curviligne_Ego trajectory_generation_vel lines_update_data steering_report steering_cmd

 
