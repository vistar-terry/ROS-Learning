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

    rosbag::View view(bag);
    std::vector<const rosbag::ConnectionInfo*> cInfo = view.getConnections();
    for (size_t i = 0; i < cInfo.size(); i++)
    {
        ROS_INFO("id: %d, topic: %s, dataType: %s, md5: %s, msg_def: %s", 
            cInfo[i]->id, cInfo[i]->topic.c_str(), cInfo[i]->datatype.c_str(),
            cInfo[i]->md5sum.c_str(), cInfo[i]->msg_def.c_str());
    }
    
    for (rosbag::MessageInstance const m : view)
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