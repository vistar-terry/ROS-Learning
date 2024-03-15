import rosbag
import rospkg
from std_msgs.msg import Int32, String


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

bag = rosbag.Bag(bags_path+'/pytest.bag', 'w')
print(bag._get_compression())
# try:
#     s = String()
#     s.data = 'foo'

#     i = Int32()
#     i.data = 42

#     bag.write('chatter', s)
#     bag.write('numbers', i)
# finally:
#     bag.close()