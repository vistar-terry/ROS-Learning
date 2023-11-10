/*

需求:
    现有坐标系统，父级坐标系统 map,下有两子级系统 son1，son2，
    son1 相对于 map，以及 son2 相对于 map 的关系是已知的，
    求 son1 与 son2中的坐标关系，又已知在 son1中一点的坐标，要求求出该点在 son2 中的坐标
实现流程:
    1.包含头文件
    2.初始化 ros 节点
    3.创建 ros 句柄
    4.创建 TF 订阅对象
    5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
      解析 son1 中的点相对于 son2 的坐标
    6.spin

*/
// 1.包含头文件
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/PointStamped.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化 ros 节点
    ros::init(argc, argv, "sub_frames");
    // 3.创建 ros 句柄
    ros::NodeHandle nh;
    // 4.创建 TF 订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    // 5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
    ros::Rate r(1);
    while (ros::ok())
    {
        try
        {
            // 解析 base 中的点相对于 map 的坐标
            geometry_msgs::TransformStamped t_map_base = buffer.lookupTransform("map", "base", ros::Time(0));
            ROS_INFO("base 相对于 map 的坐标关系: (%f, %f, %f)",
                     t_map_base.transform.translation.x,
                     t_map_base.transform.translation.y,
                     t_map_base.transform.translation.z);

            // 解析 pallet 中的点相对于 map 的坐标
            geometry_msgs::TransformStamped t_map_pallet = buffer.lookupTransform("map", "pallet", ros::Time(0));
            ROS_INFO("base 相对于 pallet 的坐标关系: (%f, %f, %f)",
                     t_map_pallet.transform.translation.x,
                     t_map_pallet.transform.translation.y,
                     t_map_pallet.transform.translation.z);

            // 解析 code 中的点相对于 map 的坐标
            geometry_msgs::TransformStamped t_map_code = buffer.lookupTransform("map", "code", ros::Time(0));
            ROS_INFO("base 相对于 code 的坐标关系: (%f, %f, %f)",
                     t_map_code.transform.translation.x,
                     t_map_code.transform.translation.y,
                     t_map_code.transform.translation.z);

            // new_base 相对于 map 的坐标关系: (50.980789, 45.264047, 0.000000)
            ROS_INFO("new_base 相对于 map 的坐标关系: (%f, %f, %f)",
                t_map_code.transform.translation.x - t_map_pallet.transform.translation.x + t_map_base.transform.translation.x,
                t_map_code.transform.translation.y - t_map_pallet.transform.translation.y + t_map_base.transform.translation.y,
                t_map_code.transform.translation.z - t_map_pallet.transform.translation.z + t_map_base.transform.translation.z);

            // 坐标点解析
            // geometry_msgs::PointStamped ps;
            // ps.header.frame_id = "son2";
            // ps.header.stamp = ros::Time::now();
            // ps.point.x = 1.0;
            // ps.point.y = 2.0;
            // ps.point.z = 3.0;

            // geometry_msgs::PointStamped psAtSon2;
            // psAtSon2 = buffer.transform(ps, "map");
            // ROS_INFO("在 map 中的坐标:x=%.2f,y=%.2f,z=%.2f",
            //          psAtSon2.point.x,
            //          psAtSon2.point.y,
            //          psAtSon2.point.z);
        }
        catch (const std::exception &e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("异常信息: %s", e.what());
        }

        r.sleep();
        // 6.spin
        ros::spinOnce();
    }
    return 0;
}
