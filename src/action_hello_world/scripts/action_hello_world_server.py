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
from chores.msg import DoDishesAction
import actionlib
import rospy
import roslib
roslib.load_manifest('my_pkg_name')


class DoDishesServer:
    def __init__(self):
        self.server = actionlib.SimpleActionServer(
            'do_dishes', DoDishesAction, self.execute, False)
        self.server.start()

    def execute(self, goal):
        # Do lots of awesome groundbreaking robot stuff here
        self.server.set_succeeded()


if __name__ == '__main__':
    rospy.init_node('do_dishes_server')
    server = DoDishesServer()
    rospy.spin()
