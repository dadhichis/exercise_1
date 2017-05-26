#!/usr/bin/env python
"""
Created on Thu May 25 2017

@author: Dadhichi Shukla
"""
#Pulisher stops after 30seconds of publishing the message
#Script to test the performance between languages

import rospy # ros_ python
from performance_tests.msg import SuperAwesome # Import customized message
import time

def simple_publisher_func():
    pub_name = rospy.Publisher('/py_publisher',SuperAwesome) # rostopic publishing string with custom message type
    return pub_name
    
if __name__ == '__main__':
    # ros_initiliaze
    rospy.init_node('simple_publisher_node')
    # publisher name
    pub_name = simple_publisher_func()
    rate_val = 100000 # set loop rate
    time_start = time.time() # Start time
    rate = rospy.Rate(rate_val)

    while not rospy.is_shutdown():        
        the_msg_is = 'SuperAwesome message Python'
        rospy.loginfo(the_msg_is) # Un/comment to see the published message on the terminal
        pub_name.publish(the_msg_is) # publish the message
        rate.sleep()
        
        time_end = time.time() # Check time
        diff_time = time_end - time_start # Compute elased time
        print diff_time # Display
        # If time more than 30 seconds shutdown the node
        if diff_time > 30.0: 
            break