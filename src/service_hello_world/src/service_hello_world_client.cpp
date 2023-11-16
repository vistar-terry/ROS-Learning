#include <ros/ros.h>
#include <std_srvs/SetBool.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "service_hello_world_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<std_srvs::SetBool>("/robotSwitch");

    std_srvs::SetBool srv;
    if (strcmp(argv[1], "on") == 0)
    {
        srv.request.data = true;
    }
    else if (strcmp(argv[1], "off") == 0)
    {
        srv.request.data = false;
    }
    else
    {
        ROS_WARN("仅支持on和off");

        return 1;
    }

    if (client.call(srv))
    {
        if (srv.response.success)
        {
            ROS_INFO("操作成功, %s", srv.response.message.c_str());
        }
        else
        {
            ROS_ERROR("操作失败, %s", srv.response.message.c_str());
        }
    }
    else
    {
        ROS_ERROR("操作失败, 未知错误!");
    }

    return 0;
}