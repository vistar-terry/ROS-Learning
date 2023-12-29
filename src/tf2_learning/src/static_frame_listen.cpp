#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "static_frame_listen");

    ros::NodeHandle nh;

    // 创建 TF 订阅节点
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate rate(1);
    while (ros::ok())
    {
        // 生成一个坐标点, 模拟雷达检测到的障碍物坐标点(雷达坐标系下的坐标)
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id = "laser";
        point_laser.header.stamp = ros::Time::now();
        point_laser.point.x = 2.0;
        point_laser.point.y = 2.5;
        point_laser.point.z = 0.3;

        // 转换坐标点, 计算障碍物坐标点在 base_link 下的坐标
        try
        {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_laser, "base_link");
            ROS_INFO("point_base: (%.2f, %.2f, %.2f), frame: %s",
                     point_base.point.x, point_base.point.y, point_base.point.z,
                     point_base.header.frame_id.c_str());
        }
        catch (const std::exception &e)
        {
            ROS_ERROR("%s", e.what());
        }

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
