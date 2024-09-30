# Ava

## Overview
The `Ava` project

## Hardware Environment
This project is designed to run on a Linux-based system with the following hardware components:
- Ubuntu 16 
- ROS Kinetic 

## Software Requirements
Ensure that the following packages and dependencies are installed on your system:

### ROS Packages
- `dbw-mkz`
- `novatel-gps-driver`
- `delphi-esr`
- `delphi-srr`
- `kartech-linear-actuator`
- `mobileye-560-660`

### System Dependencies
- CMake (version 2.8.3 or newer)
- Protobuf (ensure the library and include paths are set correctly)

### Installation Instructions
1. **Install ROS Kinetic**:
   Follow the instructions on the [ROS Kinetic installation page](http://wiki.ros.org/kinetic/Installation).

2. **Install Required ROS Packages**:
   ```sh
   sudo apt install ros-$ROS_DISTRO-delphi-esr ros-$ROS_DISTRO-delphi-srr ros-$ROS_DISTRO-kartech-linear-actuator ros-$ROS_DISTRO-mobileye-560-660 ros-$ROS_DISTRO-dbw-mkz ros-$ROS_DISTRO-novatel-gps-driver

3. **Install Protobuf binaries**:
    Copy Protobuf binaries to `/usr/local/` [Protobuf Binaries](https://drive.google.com/file/d/1wWL7qE5e82HqOhfZU1051LX60Kq_Ey94/view?usp=drive_link)

4. **Build project**:
    Run `catkin_make` in the root folder

5. **Run project**:
    Launch files are located in  `src\launch_project_s\launch`
    ```sh
    source devel/setup.bash
    roslaunch launch_project_s launch_Projet_S_vehicle.launch
