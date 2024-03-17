import rosbag
import rospkg
from datetime import datetime


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

# 打开一个存在的 bag 文件
with rosbag.Bag(bags_path+'/pytest.bag', 'r') as bag:

    topic_filters = ['/chatter', '/number']
    msg_types, topics = bag.get_type_and_topic_info(topic_filters)
    print("Message Types:")
    for type_name, md5_hash in msg_types.items():
        print(f"  {type_name}: {md5_hash}")

    print("Topics:")
    for type_name, topic_info in topics.items():
        print("  Topic: {}, Type: {}, MessageCount: {}, Connections: {}, Frequency: {}".format(
            type_name, 
            topic_info.msg_type, 
            topic_info.message_count, 
            topic_info.connections,
            topic_info.frequency))
