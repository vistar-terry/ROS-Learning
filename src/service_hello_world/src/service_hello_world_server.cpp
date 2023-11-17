#include <ros/ros.h>
#include <std_srvs/SetBool.h>

bool dealRobotSwitch(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &resp)
{
    bool flag = req.data;
    ROS_INFO("服务器收到 [%s] 机器人的指令.", flag ? "启动" : "关闭");

    // 逻辑处理
    if (flag)
    {
        ROS_INFO("正在启动机器人各模块...");
        ros::Duration(2).sleep();
        // 使用时间模拟随机成功与失败
        if (ros::Time::now().toNSec() % 2 == 0)
        {
            resp.success = true;
            resp.message = "Hello World.";
            ROS_INFO("机器人各模块启动成功.\n");
        }
        else
        {
            resp.success = false;
            resp.message = "再睡一会";
            ROS_INFO("机器人各模块启动失败.\n");
        }
    }
    else
    {
        ROS_INFO("正在关闭机器人各模块...");
        ros::Duration(2).sleep();
        // 模拟成功与失败
        if (ros::Time::now().toNSec() % 2 == 0)
        {
            resp.success = true;
            resp.message = "Good Night.";
            ROS_INFO("机器人各模块关闭成功.\n");
        }
        else
        {
            resp.success = false;
            resp.message = "我还能卷";
            ROS_INFO("机器人各模块关闭失败.\n");
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "service_hello_world_server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("/robotSwitch", dealRobotSwitch);
    ROS_INFO("robotSwitch 服务已启动...");
    ros::spin();
    return 0;
}
