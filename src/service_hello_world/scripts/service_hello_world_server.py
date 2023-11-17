import rospy
from std_srvs.srv import SetBool, SetBoolResponse


def dealRobotSwitch(req):
    flag = req.data
    rospy.loginfo("服务器收到 [%s] 机器人的指令.", "启动" if flag else "关闭")
    if flag:
        rospy.loginfo("正在启动机器人各模块...")
        if rospy.Time.now().to_nsec() % 2 == 0:
            rospy.loginfo("机器人各模块启动成功.\n")
            return SetBoolResponse(True, "Hello World.")
        else:
            rospy.logerr("机器人各模块启动失败.\n")
            return SetBoolResponse(False, "再睡一会")
    else:
        rospy.loginfo("正在关闭机器人各模块...")
        if rospy.Time.now().to_nsec() % 2 == 0:
            rospy.loginfo("机器人各模块关闭成功.\n")
            return SetBoolResponse(True, "Good Night.")
        else:
            rospy.logerr("机器人各模块关闭失败.\n")
            return SetBoolResponse(False, "我还能卷")


if __name__ == "__main__":
    rospy.init_node("service_hello_world_server")
    server = rospy.Service("/robotSwitch", SetBool, dealRobotSwitch)
    rospy.loginfo("robotSwitch 服务已启动...")
    rospy.spin()