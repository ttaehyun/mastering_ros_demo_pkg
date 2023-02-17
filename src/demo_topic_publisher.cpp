#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "mastering_ros_demo_pkg/demo_msg.h"
#include <iostream>

int main(int argc, char **argv) {
    ros::init(argc, argv, "demo_topic_publisher");
    ros::NodeHandle node_obj;
    ros::Publisher number_publisher = node_obj.advertise<mastering_ros_demo_pkg::demo_msg>("/msg", 10);
    ros::Rate loop_rate(10);
    int number_count= 0;
    while( ros::ok()) {
        mastering_ros_demo_pkg::demo_msg msg;
        msg.number = number_count;
        msg.greeting = "HellO";
        //ROS_INFO("%d",msg.data);
        number_publisher.publish(msg);
        loop_rate.sleep();
        ++number_count;
    }
    return 0;
}