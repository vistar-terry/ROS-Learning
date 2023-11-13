#include <ros/ros.h>
#include "topic_hello_world/RobotPose.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "user_msg_pub");
    ros::NodeHandle nh;

    ros::Publisher pose_pub = nh.advertise<topic_hello_world::RobotPose>("/robot_pose", 10);

    topic_hello_world::RobotPose pose;
    pose.id = "vbot";
    pose.x = 23.6;
    pose.y = 12.8;
    pose.angle = 90.0;

    while(ros::ok())
    {
        pose_pub.publish(pose);
        ROS_INFO("Pub robot: %s, pose(%lf, %lf, %lf)", pose.id.c_str(), pose.x, pose.y, pose.angle);
        ros::Duration(1).sleep();
        ros::spinOnce();
    }

    return 0;
}