#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "mastering_ros_demo_pkg/demo_msg.h"
#include <iostream>

void number_callback(const mastering_ros_demo_pkg::demo_msg msg) {
    ROS_INFO("Greeting, %s", msg.greeting.c_str());
    ROS_INFO("Received [%d]", msg.number);
}

int main(int argc, char **argv) {
    ros::init(argc, argv,"demo_topic_subscriber");
    ros::NodeHandle node_obj;
    ros::Subscriber nubmer_subscriber = node_obj.subscribe("/msg", 10, number_callback);
    ros::spin();
    return 0;
    
}