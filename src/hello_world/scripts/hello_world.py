#!/usr/bin/env python
# -*- coding: utf-8 -*-  python2默认使用ASCII编码，需要加这一行

import rospy

if __name__ == "__main__":
    # 初始化ros节点，"hello_world_py"为自定义节点名称
    rospy.init_node("hello_world_py")

    # 在控制台打印 Hello World!
    rospy.loginfo("Hello World!")
