/*
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 发布者 对象
        5.组织被发布的数据，并编写逻辑发布数据
*/
// 1.包含头文件
#include "ros/ros.h"
#include "std_msgs/String.h" // std_msgs包自带的普通文本的消息类型
#include <sstream>

int main(int argc, char **argv)
{
    // 以下任意一句： 设置编码，解决ROS LOG打印中文乱码的问题
    // 但 rostopic echo 中文乱码的问题无法解决
    // setlocale(LC_ALL, "");
    setlocale(LC_CTYPE, "zh_CN.utf8");

    // 2.初始化 ROS 节点： 命名(唯一)
    // 参数1和参数2 后期为节点传值会使用
    // 参数3 是节点名称，是一个标识符，需要保证运行后，在 ROS 拓扑网络中唯一
    ros::init(argc, argv, "publisher");

    // 3.实例化 ROS 句柄
    // 该类封装了 ROS 中的一些常用功能
    ros::NodeHandle nh;

    // 4.实例化 发布者 对象，向ROS Master注册发布者
    // 泛型 std_msgs::String: 发布的消息类型
    // 参数1: 要发布到的话题名称
    // 参数2: 队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
    ros::Publisher pub = nh.advertise<std_msgs::String>("/hello_world_topic", 10);

    // 延时1s等待publisher在ROS Master注册成功后，再发布消息。
    // ros::Duration(1.0).sleep();
    // 目的同上，为了确保发布者注册成功再发布消息
    // 等待直到发布者成功注册到 ROS Master，并有订阅者订阅
    while (pub.getNumSubscribers() == 0)
    {
        if (!ros::ok())
        {
            // 如果节点被关闭，退出程序
            return 0;
        }
        ROS_INFO_ONCE("Waiting for subscribers to connect...");
        ros::Duration(1.0).sleep(); // 等待一秒钟
    }

    // 5.组织被发布的数据，并编写逻辑发布数据
    std_msgs::String msg;
    std::string msg_front = "Hello World "; // 消息前缀
    int count = 0;                          // 消息计数器

    // 运行loop的频率(1Hz: 一秒1次)
    ros::Rate r(1);

    // 节点不死
    while (ros::ok())
    {
        // 拼接字符串与编号，并组装消息数据
        msg.data = msg_front + std::to_string(count);
        // 发布消息
        pub.publish(msg);
        // 打印发送的消息
        ROS_INFO("发送的消息: %s", msg.data.c_str());

        // 根据前面制定的发布频率自动休眠 休眠时间 = 1/频率 s；
        r.sleep();
        // 循环结束前，让 count 自增
        count++;
    }

    return 0;
}