import sys
import rospy
from std_srvs.srv import SetBool, SetBoolRequest


if __name__ == "__main__":
    rospy.init_node("service_hello_world_client")

    if len(sys.argv) != 2:
        rospy.logerr("参数个数有误")
        sys.exit(1)

    flag = False
    if sys.argv[1] == "on":
        flag = True
    elif sys.argv[1] == "off":
        pass
    else:
        rospy.logwarn("仅支持on和off")
        sys.exit(1)

    rospy.loginfo("客户端请求 [%s] 机器人.", "启动" if flag else "关闭")
    client = rospy.ServiceProxy("/robotSwitch", SetBool)
    client.wait_for_service()
    req = SetBoolRequest()
    req.data = flag
    res = client.call(req)

    if res.success:
        rospy.loginfo("操作成功，%s", res.message)
    else:
        rospy.logerr("操作失败，%s", res.message)
        