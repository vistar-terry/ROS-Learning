#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <std_srvs/SetBool.h>

bool serverCallback(std_srvs::SetBoolRequest& req, std_srvs::SetBoolResponse& res)
{
    return true;
}

int main(int argc, char **argv)
{
    // ros::init(argc, argv, "namespace_learning", ros::init_options::AnonymousName);
    ros::init(argc, argv, "namespace_learning");

    // ros::M_string sMap;
    // sMap["__ns"] = "/namespace";
    // sMap["__name"] = "new_name";
    // ros::init(sMap, "namespace_learning");

    ROS_INFO("%s", ROSCONSOLE_DEFAULT_NAME);
    ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::Level::Debug);

    ros::NodeHandle nh;
    ros::Publisher puber = nh.advertise<std_msgs::Header>("/namespace_learning", 10);
    std_msgs::Header header;
    header.stamp - ros::Time::now();
    puber.publish(header);

    ros::ServiceServer server = nh.advertiseService("/namespace_learning", serverCallback);

    ros::spin();

    return 0;
}
