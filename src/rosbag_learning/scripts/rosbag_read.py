import rosbag
import rospkg

rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

bag = rosbag.Bag(bags_path+'/pytest.bag')

for topic, msg, t in bag.read_messages(topics=['/chatter', '/numbers']):
    print(f"Received message on topic {topic} at time {t}: {msg}")

print(bag.get_compression_info())

bag.close()
