Steps:

git clone https://github.com/dadhichis/excercise_1.git 
package in your catkin workspace

catkin_make 
OR 
catkin_make performance_tests

source ~/catkin_ws/devel/setup.bash
roscore

---Simple publisher-subscriber---
--Python:
cd ~/catkin_ws/src/performance_tests/scripts/
python simple_publisher.py

cd ~/catkin_ws/src/performance_tests/scripts/
python simple_subscriber.py

--C++:
cd ~/catkin_ws/src/performance_tests/src/
rosrun performance_tests simple_publisher_node_cpp 

cd ~/catkin_ws/src/performance_tests/src/
rosrun performance_tests simple_subscriber_node_cpp 

--To test 4 conditions:
1. C++ publisher to Python subscriber
2. C++ publisher to C++ subscriber
3. Python publisher to Python subscriber
4. Python publisher to C++ subscriber

--Comment/ Uncomment subscriber topics in subscriber .py and .cpp files
After editing .cpp file you need to do catkin_make

---Test loop rate---
--Subscribers for both, Python and C++ remain the same.
The loop rate was changed in the following files to obtain the graph. To run same as mentioned above.

simple_publisher_rate.py

simple_publisher_Cpp_rate.cpp


The scripts publishes message for 30 seconds. The difference in real time between the sent message and the received message was recorded for the 4 conditions. The loop rate were in powers of 10 from 0-5 and the time difference for all 4 conditions is shown on the logarithmic graph.

It can be seen that at frequency rates higher than 1000Hz the delay starts increasing for conditions 1 and 3 (both python subscribers). The disparity for C++ subscribers i.e. conditions 2 and 4, is less than 1000th of a second. Therefore, the performance of C++ is significantly better than Python.

