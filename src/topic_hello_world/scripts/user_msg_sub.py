#! /usr/bin python

import rospy
from topic_hello_world.msg import RobotPose


def robotPoseCallback(msg):
    rospy.loginfo("Sub robot: {}, pose({}, {}, {})".format(msg.id, msg.x, msg.y, msg.angle))


def main():
    rospy.init_node("user_msg_sub")
    rospy.Subscriber("/robot_pose", RobotPose, robotPoseCallback, queue_size=10)

    rospy.spin()


if __name__ == "__main__":
    main()