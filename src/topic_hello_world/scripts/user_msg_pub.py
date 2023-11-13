#! /usr/bin python

import rospy
from topic_hello_world.msg import RobotPose


def main():
    rospy.init_node("user_msg_pub")
    pub = rospy.Publisher("/robot_pose", RobotPose, queue_size=10)
    msg = RobotPose()
    msg.id = "vbot"
    msg.x = 52.1
    msg.y = 12.6
    msg.angle = 180.0

    while not rospy.is_shutdown():
        pub.publish(msg)
        rospy.loginfo("Pub robot: {}, pose({}, {}, {})".format(msg.id, msg.x, msg.y, msg.angle))
        rospy.sleep(1)


if __name__ == "__main__":
    main()