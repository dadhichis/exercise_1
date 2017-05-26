/*
Created on Thu May 25 2017

@author: Dadhichi Shukla
*/

//Publisher stops after 30seconds of publishing the message
//Script to test the performance between languages
#include <ros/ros.h>
#include <performance_tests/SuperAwesome.h>
#include <sstream>
#include <time.h>

using namespace std;

int main(int argc, char **argv)
{
//ros_initialize
ros::init(argc, argv, "simple_publisher_node_cpp");
//Node handler
ros::NodeHandle n_pub;

//Declare
time_t timer;
time_t timer2;
double seconds_time;
int rate_val = 100000; // Set loop rate

//Publish message on topic /cpp_publisher
ros::Publisher pub_name_cpp = n_pub.advertise<performance_tests::SuperAwesome>("/cpp_publisher", 1000);

time(&timer);  // get current time

while (ros::ok()){
//rostopic publishing string with custom message type
ros::Rate loop_rate(rate_val); 
//Declare custom message 
performance_tests::SuperAwesome msg;

std::stringstream ss;
ss << "SuperAwesome message C++ ..";
msg.message = ss.str(); // Above string as message

ROS_INFO("%s", msg.message.c_str()); //Display string as ros_info
pub_name_cpp.publish(msg); //publish the message

ros::spinOnce(); //Allow ros to process incoming messages
loop_rate.sleep();

time(&timer2); // read time
seconds_time = difftime(timer2,timer); // Compute elased time

printf ("%f seconds", seconds_time); // Display
if(seconds_time>29.0){break;} // if time 30.0 seconds shutdown the node
}
return 0;
}