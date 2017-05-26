#!/usr/bin/env python
"""
Created on Thu May 25 2017

@author: Dadhichi Shukla
"""
# Simple publisher
import rospy # ros_ python
from performance_tests.msg import SuperAwesome # Import customized message

def simple_publisher_func():
    pub_name = rospy.Publisher('/py_publisher',SuperAwesome) # rostopic publishing string with custom message type
    return pub_name
    
if __name__ == '__main__':
    # ros_initiliaze
    rospy.init_node('simple_publisher_node')
    # publisher name
    pub_name = simple_publisher_func()
    rate = rospy.Rate(10) # 10hz loop rate
    
    while not rospy.is_shutdown():
        the_msg_is = 'SuperAwesome message Python'
        rospy.loginfo(the_msg_is) # Un/comment to see the published message on the terminal
        pub_name.publish(the_msg_is) # publish the message
        rate.sleep()
      
    
    
