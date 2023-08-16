"""
General Summary:
a subscriber which listens to the chatter topic and then prints 
out the recieved message



"""
#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
#msgCallback function is called when new messaged is reicved
def msgCallback(msg):
#the rospy.loginfo is the print out the message that's recieved
    rospy.loginfo("New message received %s", msg.data)


if __name__ =='__main__':
    #initializes the node with the same anonymous(publisher)
    rospy.init_node("simple_subscriber_py", anonymous=True)
    #creates a subscriber called chatter which will expect a string 
    #message and will call it to the function
    rospy.Subscriber("chatter", String, msgCallback)
    #keeps the node active and not exiting.
    rospy.spin()

    '''
    Instructions:
    1.roscore
    2.rosrun pkgname filename
    3.rostopic lsit
    4.rostopic pub /chatter std_msgs/String "data: 'Hi ROs'"  # note for sending  message
    5.

    '''