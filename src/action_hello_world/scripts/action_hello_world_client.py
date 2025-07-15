#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 1. 导入依赖包
import rospy
import actionlib
from action_hello_world.msg import FindPrimesAction, FindPrimesGoal, FindPrimesResult, FindPrimesFeedback

def done_cb(state, result):
    """处理最终结果回调"""
    if state == actionlib.GoalStatus.SUCCEEDED:
        primes_str = " ".join(str(n) for n in result.primes)
        rospy.loginfo(f"{result.number} 以内的质数有: [ {primes_str} ]")

def active_cb():
    """目标激活回调"""
    rospy.loginfo("开始查找...")

def feedback_cb(feedback):
    """处理反馈回调"""
    status_str = "是" if feedback.is_prime else "不是"
    rospy.loginfo(f"当前数字: {feedback.number}, {status_str}质数")

if __name__ == "__main__":
    # 2. 初始化ROS节点
    rospy.init_node("action_hello_world_client")
    
    # 3. 实例化Action客户端对象
    client = actionlib.SimpleActionClient("/find_primes", FindPrimesAction)
    
    # 4. 等待服务端启动
    rospy.loginfo("等待服务端启动...")
    client.wait_for_server()
    rospy.loginfo(f"添加任务前的状态: {client.get_state()}")
    
    # 5. 实例化目标对象
    goal = FindPrimesGoal()
    goal.number = 12
    rospy.loginfo(f"查找 {goal.number} 以内的质数")
    
    # 6. 发送目标任务
    client.send_goal(goal, done_cb=done_cb, active_cb=active_cb, feedback_cb=feedback_cb)
    rospy.loginfo(f"添加任务后的状态: {client.get_state()}")
    
    rospy.sleep(1.0)
    rospy.loginfo(f"执行任务时的状态: {client.get_state()}")
    
    # 7. 等待任务完成
    client.wait_for_result(rospy.Duration(1000.0))  # 1000秒超时
    rospy.loginfo(f"任务执行完的状态: {client.get_state()}")