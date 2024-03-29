#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char **argv)
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "static_frame_broadcast");

    // 创建静态坐标转换广播器
    tf2_ros::StaticTransformBroadcaster broadcaster;

    // 创建坐标系信息
    geometry_msgs::TransformStamped ts;
    // --设置头信息
    ts.header.seq = 100;
    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "base_link";
    // --设置子级坐标系
    ts.child_frame_id = "laser";
    // --设置子坐标系相对于父坐标系的平移偏移量
    ts.transform.translation.x = 0.5;
    ts.transform.translation.y = 0.0;
    ts.transform.translation.z = 0.3;
    // --设置子坐标系相对于父坐标系的旋转偏移量
    // --将欧拉角转换成四元数
    tf2::Quaternion qtn; // tf2的四元数类
    qtn.setRPY(0, 0, 0); // 设置欧拉角
    // 获取旋转的四元数值
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    // 广播器发布坐标系信息
    broadcaster.sendTransform(ts);

    ros::spin();

    return 0;
}
