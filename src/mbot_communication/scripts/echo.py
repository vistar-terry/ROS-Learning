#!/usr/bin/python3
#-*- coding:UTF-8 -*-

import rospy
from std_msgs.msg import String

if __name__ == '__main__':

    rospy.init_node('echo')

    str = rospy.Publisher('/echo', String, queue_size=10)

    rate = rospy.Rate(10)

    i = 0

    while not rospy.is_shutdown():
        str_msg = String()
        str_msg.data = "hello [{}]".format(i)

        str.publish(str_msg)
        rospy.loginfo("Publish log message: %s", str_msg)
        i+=1
 
        rate.sleep()
        
