/*
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 Action服务器 对象
        5.实现服务任务（发布任务反馈、返回最终结果）
        6.启动 Action 服务器
*/

// 1.包含头文件
#include <cmath>
#include <actionlib/server/simple_action_server.h>
#include <action_hello_world/FindPrimesAction.h>

typedef actionlib::SimpleActionServer<action_hello_world::FindPrimesAction> Server;

// 判断给定数字是否是质数
bool isPrime(int n)
{
    bool ret = true;
    if (n <= 1)
    {
        ret = false;
    }
    else if (n % 2 == 0)
    {
        ret = (n == 2);
    }
    else
    {
        for (int i = 3;; i += 2)
        {
            if (i > n / i)
            {
                break;
            }
            else if (n % i == 0)
            {
                ret = false;
            }
        }
    }
    ROS_INFO("%d %s prime.", n, ret ? "is" : "is not");

    return ret;
}

// 5.实现服务任务（发布任务反馈、返回最终结果）
void execute(const action_hello_world::FindPrimesGoalConstPtr &goal, Server *server)
{
    action_hello_world::FindPrimesFeedback feedback;
    std::vector<int> primes; // 存放找到的质数
    for (size_t i = 0; i <= goal->number; i++)
    {
        feedback.number = i;
        feedback.is_prime = isPrime(i);
        server->publishFeedback(feedback); // 发布反馈
        // 存储找到的质数
        if (feedback.is_prime)
        {
            primes.push_back(i);
        }

        ros::Duration(0.5).sleep();
    }
    // 返回最终结果
    action_hello_world::FindPrimesResult result;
    result.number = goal->number;
    result.primes = primes;
    server->setSucceeded(result);
}

int main(int argc, char **argv)
{
    // 解决中文打印乱码
    setlocale(LC_ALL, "");
    // 2.初始化 ROS 节点:命名(唯一)
    ros::init(argc, argv, "action_hello_world_server");
    // 3.实例化 ROS 句柄
    ros::NodeHandle nh;
    // 4.实例化 Action服务器 对象
    Server server(nh, "/find_primes", boost::bind(&execute, _1, &server), false);
    // 6.启动服务器
    server.start();
    ros::spin();

    return 0;
}