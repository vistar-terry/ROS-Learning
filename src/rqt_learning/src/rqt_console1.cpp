#include <ros/ros.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rqt_console_node1");
    ros::NodeHandle nh;

    ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug);

    while (ros::ok())
    {
        ROS_DEBUG("This is a Debug message.");
        ROS_INFO("This is a Info message.");
        ROS_WARN("This is a Warn message.");
        ROS_ERROR("This is a Error message.");
        ROS_FATAL("This is a Fatal message.");
        ros::Duration(1).sleep();
    }

    return 0;
}