/**
 * @file: dynamic_frame_broadcast.cpp
 * @brief: 动态的坐标系相对姿态发布
 * @author: 万俟淋曦(1055311345@qq.com)
 * @date: 2023-12-30 22:47:33
 * @modifier:
 * @date: 2023-12-30 22:47:33
 */

#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

void turtle1PoseCallback(const turtlesim::Pose::ConstPtr &pose)
{
    // 创建 TF 广播器
    static tf2_ros::TransformBroadcaster broadcaster;

    // 创建 广播的数据
    geometry_msgs::TransformStamped tfs;
    // --头设置
    tfs.header.frame_id = "world";
    tfs.header.stamp = ros::Time::now();
    // --坐标系id
    tfs.child_frame_id = "turtle1";
    // --坐标系相对信息设置
    tfs.transform.translation.x = pose->x;
    tfs.transform.translation.y = pose->y;
    tfs.transform.translation.z = 0.0; // 二维, z为0
    //  --欧拉角转四元数
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta); // 二维, 只有偏航角
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();

    // 广播器发布数据
    broadcaster.sendTransform(tfs);
}

int main(int argc, char **argv)
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "dynamic_frame_broadcast");

    // 创建 ROS 句柄
    ros::NodeHandle nh;

    // 创建订阅对象，订阅乌龟的世界位姿
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, turtle1PoseCallback);

    ros::spin();

    return 0;
}
