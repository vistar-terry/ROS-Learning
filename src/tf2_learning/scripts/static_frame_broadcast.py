#! /usr/bin/env python

import rospy
import tf
import tf2_ros
from geometry_msgs.msg import TransformStamped


if __name__ == "__main__":

    # 初始化 ROS 节点
    rospy.init_node("static_frame_broadcast_py")

    # 创建静态坐标广播器
    broadcaster = tf2_ros.StaticTransformBroadcaster()

    # 创建并组织被广播的消息
    tfs = TransformStamped()
    # -- 头信息
    tfs.header.frame_id = "base_link" # 父坐标系
    tfs.header.stamp = rospy.Time.now()
    tfs.header.seq = 101
    # -- 子坐标系
    tfs.child_frame_id = "laser"
    # -- 坐标系相对信息
    # ---- 相对于父坐标系的平移偏移量
    tfs.transform.translation.x = 0.5
    tfs.transform.translation.y = 0.0
    tfs.transform.translation.z = 0.3
    # ---- 相对于父坐标系的旋转偏移量
    # ---- 设置欧拉角，并将欧拉角转换成四元数
    qtn = tf.transformations.quaternion_from_euler(0, 0, 0)
    tfs.transform.rotation.x = qtn[0]
    tfs.transform.rotation.y = qtn[1]
    tfs.transform.rotation.z = qtn[2]
    tfs.transform.rotation.w = qtn[3]

    # 广播器发送消息
    broadcaster.sendTransform(tfs)

    # spin
    rospy.spin()
