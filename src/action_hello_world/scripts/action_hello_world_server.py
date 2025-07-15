#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 1. 导入依赖包
import rospy
import math
import actionlib
from action_hello_world.msg import FindPrimesAction, FindPrimesResult, FindPrimesFeedback

# 判断给定数字是否是质数
def is_prime(n):
    if n <= 1:
        rospy.loginfo(f"{n} 不是质数")
        return False
    if n == 2:
        rospy.loginfo(f"{n} 是质数")
        return True
    if n % 2 == 0:
        rospy.loginfo(f"{n} 不是质数")
        return False
    
    # 检查从3到sqrt(n)的奇数因子
    ret = True
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            ret = False
            break
    
    status_str = "是" if ret else "不是"
    rospy.loginfo(f"{n} {status_str}质数")
    return ret

# 实现服务任务（发布任务反馈、返回最终结果）
def execute_cb(goal):
    primes = []  # 存放找到的质数
    target = goal.number
    
    # 创建反馈对象
    feedback = FindPrimesFeedback()
    
    # 从2开始检查到目标数字
    for num in range(2, target + 1):
        # 更新反馈信息
        feedback.number = num
        feedback.is_prime = is_prime(num)
        
        # 如果是质数则添加到结果列表
        if feedback.is_prime:
            primes.append(num)
        
        # 发布反馈
        server.publish_feedback(feedback)
        
        # 模拟处理时间
        rospy.sleep(0.5)
    
    # 返回最终结果
    result = FindPrimesResult()
    result.number = target
    result.primes = primes
    server.set_succeeded(result)

if __name__ == "__main__":
    # 2. 初始化ROS节点
    rospy.init_node("action_hello_world_server")

    # 3. 实例化Action服务器对象
    server = actionlib.SimpleActionServer(
        "/find_primes", 
        FindPrimesAction, 
        execute_cb, 
        auto_start=False
    )
    
    # 4. 启动服务器
    server.start()
    rospy.loginfo("质数查找服务器已启动...")
    
    # 保持节点运行
    rospy.spin()