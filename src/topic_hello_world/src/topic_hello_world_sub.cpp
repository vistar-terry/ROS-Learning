/*
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 订阅者 对象
        5.处理订阅的消息(回调函数)
        6.设置循环调用回调函数
*/

// 1.包含头文件
#include "ros/ros.h"
#include "std_msgs/String.h"

// 5.处理订阅的消息(回调函数)
// topic回调函数，处理订阅的消息
void topicCallback(const std_msgs::String::ConstPtr &msg_p)
{
    ROS_INFO("收到的消息: %s", msg_p->data.c_str());
}

int main(int argc, char **argv)
{
    // 以下任意一句： 设置编码，解决ROS LOG打印中文乱码的问题
    // 但 rostopic echo 中文乱码的问题无法解决
    // setlocale(LC_ALL, ""); 
    setlocale(LC_CTYPE, "zh_CN.utf8");

    // 2.初始化 ROS 节点:命名(唯一)
    ros::init(argc, argv, "subscriber");

    // 3.实例化 ROS 句柄
    ros::NodeHandle nh;

    // 4.实例化 订阅者 对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("/hello_world/topic", 10, topicCallback);

    // 6.设置循环调用回调函数
    ros::spin(); // 循环读取接收的数据，并调用回调函数处理

    return 0;
}
