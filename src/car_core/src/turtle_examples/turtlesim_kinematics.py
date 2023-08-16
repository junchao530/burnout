#!/usr/bin/env python3
import rospy

class TurtlesimKinematics(object):

    def __init__(self):
        self.turtle1_pose_sub_ = rospy.Subscriber("/turtle1/pose")
        self.turtle2_pose_sub_ = rospy.Subscriber("/turtle2/pose")