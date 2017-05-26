/*
Created on Thu May 25 2017

@author: Dadhichi Shukla
*/

#include <ros/ros.h>
#include <performance_tests/SuperAwesome.h>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
//ros_initialize
ros::init(argc, argv, "simple_publisher_node_cpp");
//Node handler
ros::NodeHandle n_pub;

//rostopic publishing string with custom message type
ros::Publisher pub_name_cpp = n_pub.advertise<performance_tests::SuperAwesome>("/cpp_publisher", 1000);

//Set loop rate
ros::Rate loop_rate(10);

while (ros::ok()){
//Declare custom message 
performance_tests::SuperAwesome msg;

std::stringstream ss;
ss << "SuperAwesome message C++ ";
msg.message = ss.str();

ROS_INFO("%s", msg.message.c_str()); //Display string as ros_info

pub_name_cpp.publish(msg); //publish the message

ros::spinOnce(); //Allow ros to process incoming messages
loop_rate.sleep();
}

return 0;
}


