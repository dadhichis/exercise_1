/*
Created on Thu May 25 2017

@author: Dadhichi Shukla
*/

#include <ros/ros.h>
#include <performance_tests/SuperAwesome.h>

//Callback function
//Declare custom message type
void SubCallback(const performance_tests::SuperAwesome::ConstPtr& msg) {
ROS_INFO("%s", msg->message.c_str());
}

int main(int argc, char **argv){
//ros initialize
ros::init(argc, argv, "simple_subscriber_node_cpp");
//Node handler
ros::NodeHandle n_sub;
//choose rostopic subscribe
ros::Subscriber sub = n_sub.subscribe("/cpp_publisher", 1000, SubCallback);
//ros::Subscriber sub = n_sub.subscribe("/py_publisher", 1000, SubCallback);

ros::spin(); //Allow ros to process incoming messages

return 0;
}


