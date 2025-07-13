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
#include <chores/DoDishesAction.h> // Note: "Action" is appended
#include <actionlib/server/simple_action_server.h>

typedef actionlib::SimpleActionServer<chores::DoDishesAction> Server;

void execute(const chores::DoDishesGoalConstPtr &goal, Server *as) // Note: "Action" is not appended to DoDishes here
{
    // Do lots of awesome groundbreaking robot stuff here
    as->setSucceeded();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "do_dishes_server");
    ros::NodeHandle n;
    Server server(n, "do_dishes", boost::bind(&execute, _1, &server), false);
    server.start();
    ros::spin();
    return 0;
}