#!/usr/bin/env python
"""
Created on Thu May 25 2017

@author: Dadhichi Shukla
"""
#Simple subscriber
import rospy # ros_python
from performance_tests.msg import SuperAwesome # Import customized message

#Callback function
def callback(the_message):
    rospy.loginfo(the_message) # To display on terminal

def simple_subscriber_func():
    # Choose rostopic to subscribe
    #rospy.Subscriber('/cpp_publisher',SuperAwesome,callback) # subscribe to the topic
    rospy.Subscriber('/py_publisher',SuperAwesome,callback) # subscribe to the topic
    
if __name__ == '__main__':
    rospy.init_node('simple_subscriber_node')
    simple_subscriber_func()
    rospy.spin() # to keep script going on

