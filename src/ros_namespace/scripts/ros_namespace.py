#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy

if __name__ == "__main__":
    rospy.init_node("namespace_learning", anonymous=True)

    rospy.spin()