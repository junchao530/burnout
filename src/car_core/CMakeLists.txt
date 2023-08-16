cmake_minimum_required(VERSION 3.0.2)
project(car_core)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(

)




include_directories(
  ${catkin_INCLUDE_DIRS}
)

#specific cmake function for installing python scripts and
#programs is an arguement for the type of files that get installed
catkin_install_python(PROGRAMS
  #the paths to the two python files
  nodes/simple_publisher.py 
  nodes/simple_subscriber.py
  #specifies the direction of where the scripts will be installed
  #the ${} is the standard bin directory of the package
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

#the equiavelnt for cpp
#add executable defines a new executable
#simple_cpp_publisher is the name and nodes/... is the location
add_executable(simple_cpp_publisher nodes/simple_publisher.cpp)
#specifies which libaries the executable will be linked to
target_link_libraries(simple_cpp_publisher ${catkin_LIBRARIES}) 

# same as above but with subscriber
add_executable(simple_cpp_subscriber nodes/simple_subscriber.cpp)
target_link_libraries(simple_cpp_subscriber ${catkin_LIBRARIES})
