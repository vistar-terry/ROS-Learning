#include "ros/ros.h"

int main(int argc, char **argv)
{
    // 初始化ros节点，"hello_world_cpp"为自定义节点名称
    ros::init(argc, argv, "hello_world_cpp");

    // 在控制台打印 Hello World!
    ROS_INFO("Hello World!");

    return 0;
}
