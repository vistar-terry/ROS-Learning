import rosbag
import rospkg

rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

bag = rosbag.Bag(bags_path+'/pytest.bag')

for topic, msg, t in bag.read_messages(topics=['chatter', 'numbers']):
    print(msg)

bag.close()