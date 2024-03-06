#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "bag_read");

    std::string packagePath = ros::package::getPath("rosbag_learning");
    std::string bagsPath = packagePath + "/bags";
    rosbag::Bag bag;
    bag.open(bagsPath+"/test.bag"); // BagMode is Read by default

    for (rosbag::MessageInstance const m : rosbag::View(bag))
    {
        std_msgs::String::ConstPtr i = m.instantiate<std_msgs::String>();
        if (i != nullptr)
        {
            ROS_INFO("%s", i->data.c_str());
        }
    }

    bag.close();

    return 0;
}