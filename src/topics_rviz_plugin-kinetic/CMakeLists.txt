cmake_minimum_required(VERSION 2.8.3)
project(topics_rviz_plugin)
add_compile_options(-std=c++11 -Wall -Wextra)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rqt_gui
  rviz
)

## Find Qt5 modules
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(
  PROJECT_QT_PANELS_TARGETS
  ${PROJECT_NAME}_display_topics
)

set(
  PROJECT_TARGETS
  ${PROJECT_QT_PANELS_TARGETS}
  ${PROJECT_NAME}_topic_info
)

################################################
## Declare ROS messages, services and actions ##
################################################

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS
  include
  LIBRARIES
  ${PROJECT_TARGETS}
  CATKIN_DEPENDS
  roscpp
  rqt_gui
  rviz
#  DEPENDS
#  qtbase5-dev
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# TopicInfo class / library
qt5_wrap_cpp(
  topic_info_MOCS
  include/${PROJECT_NAME}/topic_info.hpp
)
add_library(
  ${PROJECT_NAME}_topic_info
  ${topic_info_MOCS}
  src/topic_info.cpp
)
target_link_libraries(
  ${PROJECT_NAME}_topic_info
  Qt5::Widgets
  Qt5::Gui
  ${catkin_LIBRARIES}
)
add_dependencies(
  ${PROJECT_NAME}_topic_info
  ${catkin_EXPORTED_TARGETS}
)

# Qt panel - Display topics
qt5_wrap_cpp(
  display_topics_MOCS
  include/${PROJECT_NAME}/display_topics.hpp
)
add_library(
  ${PROJECT_NAME}_display_topics
  ${display_topics_MOCS}
  src/display_topics.cpp
)
target_link_libraries(
  ${PROJECT_NAME}_display_topics
  ${PROJECT_NAME}_topic_info
  Qt5::Widgets
  Qt5::Gui
  ${catkin_LIBRARIES}
)
add_dependencies(
  ${PROJECT_NAME}_display_topics
  ${catkin_EXPORTED_TARGETS}
)

# Needed by Qt / RViz / ROS
class_loader_hide_library_symbols(
  ${PROJECT_QT_PANELS_TARGETS}
)

find_package(class_loader REQUIRED)
class_loader_hide_library_symbols(
  ${PROJECT_QT_PANELS_TARGETS}
)

#############
## Install ##
#############

## Mark executables and/or libraries for installation
# Qt panel
install(TARGETS
  ${PROJECT_TARGETS}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
install(FILES
  plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

#############
## Testing ##
#############
