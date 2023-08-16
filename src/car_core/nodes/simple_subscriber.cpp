#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

void msgCallback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO("New Message Recieved: %s", msg->data.c_str());

}

int main(int argc, char **argv){
    ros::init(argc, argv, "simple_subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter", 10, msgCallback);
    ros::spin();

    return 0;

}