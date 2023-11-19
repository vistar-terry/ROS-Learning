import rospy


if __name__ == "__main__":
    rospy.init_node("param_hello_world_get")

    # 修改参数
    rospy.set_param("name", "mybot")             # 字符串, string
    rospy.set_param("geometry", "circular")      # 字符串, string
    rospy.set_param("wheel_radius", 0.15)        # double
    rospy.set_param("wheel_num", 2)              # int
    rospy.set_param("vision", False)             # bool
    rospy.set_param("base_size", [0.2, 0.04])    # list
    rospy.set_param("sensor_id", {"camera": 0, "laser": 2, "ultrasonic": 5}) # dictionary

    # 获取参数
    name = rospy.get_param("name")                    # 字符串, string
    geometry = rospy.get_param("geometry")            # 字符串, string
    wheel_radius = rospy.get_param("wheel_radius")    # double
    wheel_num = rospy.get_param("wheel_num")          # int
    vision = rospy.get_param("vision")                # bool
    base_size = rospy.get_param("base_size")          # list
    sensor_id = rospy.get_param("sensor_id")          # dictionary
    rospy.loginfo("get_param, name: {}, geometry: {}, wheel_radius: {}, wheel: {}, vision: {}, base_size: ({}, {})"
                  .format(name, geometry, wheel_radius, wheel_num, vision, base_size[0], base_size[1]))
    for key, value in sensor_id.items():
        rospy.loginfo("get_param, sensor: {}, id: {}".format(key, value))

    # 删除参数
    rospy.delete_param("vision")

    # 其他操作
    wheel_radius1 = rospy.get_param_cached("wheel_radius")

    keys = rospy.get_param_names()
    for key in keys:
        rospy.loginfo("get_param_names, key: {}".format(key))

    if rospy.has_param("vision"):
        rospy.loginfo("has_param, 存在该参数")
    else:
        rospy.loginfo("has_param, 不存在该参数")

    result = rospy.search_param("name")
    rospy.loginfo("search_param, result: {}".format(result))


