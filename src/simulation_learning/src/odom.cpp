#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    geometry_msgs::Quaternion q = msg->pose.pose.orientation;
    ROS_INFO("pose: [%.2lf, %.2lf, %.1lf], linear: %.2lf, angular: %.2lf", 
        msg->pose.pose.position.x, msg->pose.pose.position.y, 
        std::atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))*180/M_PI, 
        msg->twist.twist.linear.x, msg->twist.twist.angular.z*180/M_PI);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "robot_odom");
    ros::NodeHandle nh;
    ros::Subscriber odomSub = nh.subscribe<nav_msgs::Odometry>("/odom", 10, odomCallback);
    ros::spin();

    return 0;
}