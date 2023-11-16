import sys
import rospy
from std_srvs.srv import SetBool


if __name__ == "__main__":
    if len(sys.argv) != 2:
        rospy.logerr("参数个数有误")

    switch = sys.argv[1]
    flag = False
    if switch is "on":
        flag = True
    elif switch is "off":
        pass
    else:
        rospy.logwarn("仅支持on和off")
        sys.exit(1)
    
    rospy.wait_for_service("service_hello_world_server")
    client = rospy.ServiceProxy("/robotSwitch", SetBool)
