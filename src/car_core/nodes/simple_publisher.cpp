
/*
General Summary 


*/
// important imports
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv)
{
    //initiates the simple_publisher node
    ros::init(argc, argv, "simple_publisher_cpp");
    // creates a handle to ros node which allows for ros functionality
    ros::NodeHandle n;
    //creates the topic with the chatter topic as well as 10 being rate
    ros::Publisher pub = n.advertise<std_msgs::String>("chatter", 10);
    //creates a rate object which controls loop frequency 
    ros::Rate rate(10);
    int counter = 0; 
   //while the node is running without issues
    while(ros::ok()){
        //publishes string message type
        std_msgs::String msg;
        // used to create  string message
        std::stringstream ss;
        ss <<"Hello world from C++ " << counter;
        msg.data = ss.str(); 
        // publishes messge to chatter topic 
        pub.publish(msg);
        //allows for callbacks
        ros::spinOnce();
        //determins frequency of loop
        rate.sleep();
        counter++;

    }
    return 0;
}


// for cpp steps1
// 1. catkin_make
// 2. roscore
// 3. rosrun car_core simple_cpp_publisher // from cmakelist