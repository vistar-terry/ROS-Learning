import rosbag
import rospkg 


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

# 打开一个存在的 bag 文件
with rosbag.Bag(bags_path+'/pytest.bag', 'r') as bag:

    # 定义我们想要计算消息数的话题过滤器列表
    topic_filters = ['/chatter', '/number']

    # 获取指定话题的消息数量
    message_counts = bag.get_message_count(topic_filters=topic_filters)
      
    # 打印话题的消息数量
    print(f"Message Count: {message_counts}")