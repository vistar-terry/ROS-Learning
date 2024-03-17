import rospy
import rosbag
import rospkg
from std_msgs.msg import String, Int32


rospy.init_node('bag_writer')  

rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

# 创建一个bag文件用于写入
with rosbag.Bag(bags_path + '/flush.bag', 'w') as bag:

    # 写入一条消息
    msg = String(data='Hello, ROSbag!')
    bag.write('/chatter', msg, rospy.Time.now())

    # 在写入更多消息之前调用flush()
    bag.flush()

    # 这里可以继续写入更多消息
    msg = Int32(data=25)
    bag.write('/number', msg, rospy.Time.now())

    # 在退出with块之前，flush()会被自动调用（如果需要的话）