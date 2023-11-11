#! /usr/bin python
"""
    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 订阅者 对象
        4.处理订阅的消息(回调函数)
        5.设置循环调用回调函数
"""
# 1.导包
import rospy
from std_msgs.msg import String


# 4.处理订阅的消息(回调函数)
def topicCallback(msg):
    rospy.loginfo("收到的消息: %s", msg.data)


def main():
    # 2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("subscriber")

    # 3.实例化 订阅者 对象
    sub = rospy.Subscriber("/hello_world_topic", String, topicCallback, queue_size=10)

    # 5.设置循环调用回调函数
    rospy.spin()


if __name__ == "__main__":
    main()
