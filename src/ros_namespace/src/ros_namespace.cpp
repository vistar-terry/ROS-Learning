#include <ros/ros.h>

int main(int argc, char **argv)
{
    // ros::init(argc, argv, "namespace_learning", ros::init_options::AnonymousName);

    ros::M_string sMap;
    sMap["__ns"] = "/namespace";
    sMap["__name"] = "new_name";
    ros::init(sMap, "namespace_learning");

    ros::spin();

    return 0;
}
