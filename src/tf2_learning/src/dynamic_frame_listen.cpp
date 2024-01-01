/**
 * @file: dynamic_frame_listen.cpp
 * @brief: 订阅动态坐标系并转换相应坐标
 * @author: 万俟淋曦(1055311345@qq.com)
 * @date: 2023-12-31 11:55:40
 * @modifier:
 * @date: 2023-12-31 11:55:40
 */
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h" // 包含TF坐标转换方法

int main(int argc, char **argv)
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "dynamic_frame_listen");
    ros::NodeHandle nh;

    // 创建 TF 订阅节点
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate r(1);
    while (ros::ok())
    {
        // 生成一个坐标点, 模拟末端执行器坐标系下的点坐标(小乌龟坐标系下的坐标)
        geometry_msgs::PointStamped point_turtle1;
        point_turtle1.header.frame_id = "turtle1";
        point_turtle1.header.stamp = ros::Time();
        point_turtle1.point.x = 1;
        point_turtle1.point.y = 1;
        point_turtle1.point.z = 0;

        // 转换坐标点, 计算小乌龟坐标系下的坐标点在 world 下的坐标
        try
        {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_turtle1, "world");
            ROS_INFO("point_base: (%.2f, %.2f, %.2f), frame: %s", 
                point_base.point.x, 
                point_base.point.y, 
                point_base.point.z,
                point_base.header.frame_id.c_str());
        }
        catch (const std::exception &e)
        {
            ROS_ERROR("%s", e.what());
        }

        r.sleep();
        ros::spinOnce();
    }

    return 0;
}
