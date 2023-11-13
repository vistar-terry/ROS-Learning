#include <ros/ros.h>
#include "topic_hello_world/RobotPose.h"

void robotPoseCallback(const topic_hello_world::RobotPose::ConstPtr &pose)
{
    ROS_INFO("Sub robot: %s, pose(%lf, %lf, %lf)", pose->id.c_str(), pose->x, pose->y, pose->angle);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "user_msg_sub");
    ros::NodeHandle nh;
    ros::Subscriber pose_sub = nh.subscribe<topic_hello_world::RobotPose>("/robot_pose", 10, robotPoseCallback);

    ros::spin();

    return 0;
}