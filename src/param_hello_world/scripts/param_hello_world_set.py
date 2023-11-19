import rospy
import os


if __name__ == "__main__":
    rospy.init_node("param_hello_world_set")

    # 设置参数
    rospy.set_param("name", "vbot")                         # 字符串, string
    rospy.set_param("geometry", "rectangle")                # 字符串, string
    rospy.set_param("wheel_radius", 0.1)                    # double
    rospy.set_param("wheel_num", 4)                         # int
    rospy.set_param("vision", True)                         # bool
    rospy.set_param("base_size", [0.7, 0.6, 0.3])           # list
    rospy.set_param("sensor_id", {"camera": 0, "laser": 2}) # dictionary

    # 验证是否设置成功
    os.system("rosparam get name")
    os.system("rosparam get geometry")
    os.system("rosparam get wheel_radius")
    os.system("rosparam get wheel_num")
    os.system("rosparam get vision")
    os.system("rosparam get base_size")
    os.system("rosparam get sensor_id")
