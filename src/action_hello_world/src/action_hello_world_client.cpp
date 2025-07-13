/*
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 Action客户端 对象
        4.等待服务端启动完成
        5.实例化目标对象
        6.发送目标任务到服务端
        7.等待任务完成
*/

// 1.包含头文件
#include <ros/ros.h>
#include <sstream>
#include <actionlib/client/simple_action_client.h>
#include <action_hello_world/FindPrimesAction.h>

typedef actionlib::SimpleActionClient<action_hello_world::FindPrimesAction> Client;

// 处理最终结果
void done_cb(const actionlib::SimpleClientGoalState &state, const action_hello_world::FindPrimesResultConstPtr &result)
{
    if (state.state_ == state.SUCCEEDED)
    {
        std::stringstream ss;
        for (const int n : result->primes)
        {
            ss << std::to_string(n) << " ";
        }
        ROS_INFO("%d 以内的质数有: [ %s]", result->number, ss.str().c_str());
    }
}

// 确认目标，服务激活
void active_cb()
{
    ROS_INFO("开始查找...");
}

// 处理连续反馈的定期任务信息
void feedback_cb(const action_hello_world::FindPrimesFeedbackConstPtr &feedback)
{
    ROS_INFO("当前数字: %d, %s质数", feedback->number, feedback->is_prime?"是":"不是");
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, ""); // 解决中文打印乱码

    // 2.初始化 ROS 节点:命名(唯一)
    ros::init(argc, argv, "action_hello_world_client");
    // 3.实例化 Action客户端 对象
    Client client("/find_primes", true);
    // 4.等待服务端启动完成
    client.waitForServer();
    ROS_INFO("添加任务前的状态: %s", client.getState().toString().c_str());
    // 5.实例化目标对象
    action_hello_world::FindPrimesGoal goal;
    goal.number = 12;
    ROS_INFO("查找 %d 以内的质数", goal.number);
    // 6.发送目标任务到服务端，并注册任务完成、确认目标、定期任务信息的回调函数
    client.sendGoal(goal, &done_cb, &active_cb, &feedback_cb);
    ROS_INFO("添加任务后的状态: %s", client.getState().toString().c_str());

    ros::Duration(1.0).sleep();
    ROS_INFO("执行任务时的状态: %s", client.getState().toString().c_str());
    // 7.等待任务完成
    client.waitForResult(ros::Duration(1000.0)); // 等待结果，1000秒超时
    ROS_INFO("任务执行完的状态: %s", client.getState().toString().c_str());

    return 0;
}