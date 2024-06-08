#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

geometry_msgs::Twist moveRobot(const double& linear, const double& angular)
{
    geometry_msgs::Twist msg;
    msg.linear.x = linear;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = angular;
    ROS_INFO("moveRobot, linear: %.3lf, angular: %.1lf", linear, angular*180/M_PI);

    return msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_robot");
    ros::NodeHandle nh;
    ros::Publisher velPub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    ros::Rate r(1);

    while (ros::ok())
    {
        velPub.publish(moveRobot(0.5, -0.3));
        ros::Duration(3.0).sleep();
        velPub.publish(moveRobot(-0.5, -0.3));
        ros::Duration(3.0).sleep();

        r.sleep();
    }

    return 0;
}