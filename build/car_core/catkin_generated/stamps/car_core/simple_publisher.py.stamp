'''
General summary:

This code initializes a ROS node in python with the goal of
sending a string message to the chatter topic by entering a loop
that count ups and the loop will start when called and end when closed.
''' 
#!/usr/bin/env/ python3

#important imports
import rospy 
from std_msgs.msg import String


if __name__ == '__main__':
    #initializes node and the anonymous will cause the name to be 
    #changed if another node with the same name exists
    rospy.init_node('simple_publisher_py', anonymous=True)
    
    #creates a publisher named chatter with type string. 
    # the qeuesize is the amount of messages that can be added before being discarded
    pub = rospy.Publisher("Chatter", String, queue_size=10)
    
    #.rate is for the frequency of the while loop
    r = rospy.Rate(10)
    counter = 0
    
    #the loop will be run until the node is shut down
    while not rospy.is_shutdown():
        # string message
        hello_msg = "Hello World from Python: %d" % counter
        # publishes to the chatter topic in line 19
        pub.publish(hello_msg) 
        #dictates the frequency of the loop by suspending it
        r.sleep()
        counter +=1
        

"""
For Python
1.catkin_make
2 rosrun car_core simple_publisher.py
3.rostopic list
4.rostopic echo /nodename
"""