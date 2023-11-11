#! /usr/bin python
"""
    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据
"""
# 1.导包
import rospy
from std_msgs.msg import String


def main():
    # 2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("publisher")

    # 3.实例化 发布者 对象
    pub = rospy.Publisher("/hello_world_topic", String, queue_size=10)
    # rospy.sleep(1)
    while pub.get_num_connections() == 0:
        if rospy.is_shutdown():
            return
        rospy.loginfo_once("Waiting for subscribers to connect...")
        rospy.sleep(1)

    # 4.组织要发布的数据，并编写逻辑发布数据
    msg = String()  # 创建 msg 对象
    msg_front = "Hello World "
    count = 0  # 计数器
    # 设置循环频率
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        # 拼接字符串
        msg.data = msg_front + str(count)
        pub.publish(msg)
        rate.sleep()
        rospy.loginfo("发送的消息: %s", msg.data)
        count += 1


if __name__ == "__main__":
    main()
