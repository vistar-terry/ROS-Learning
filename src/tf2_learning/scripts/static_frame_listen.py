#! /usr/bin/env python

import rospy
import tf2_ros
# 不要使用 geometry_msgs,需要使用 tf2 内置的消息类型
from tf2_geometry_msgs import PointStamped
# from geometry_msgs.msg import PointStamped

if __name__ == "__main__":
    # 初始化 ROS 节点
    rospy.init_node("static_frame_listen")
    # 创建 TF 订阅对象
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        # 生成一个坐标点, 模拟雷达检测到的障碍物坐标点(雷达坐标系下的坐标)
        point_laser = PointStamped()
        point_laser.header.frame_id = "laser"
        point_laser.header.stamp = rospy.Time.now()
        point_laser.point.x = 2.0
        point_laser.point.y = 2.5
        point_laser.point.z = 0.3

        try:
            # 转换坐标点, 计算障碍物坐标点在 base_link 下的坐标
            point_base = buffer.transform(point_laser, "base_link")
            rospy.loginfo("point_base: (%.2f, %.2f, %.2f), frame: %s",
                          point_base.point.x,
                          point_base.point.y,
                          point_base.point.z,
                          point_base.header.frame_id)
        except Exception as e:
            rospy.logerr("%s", e)

        # spin
        rate.sleep()
