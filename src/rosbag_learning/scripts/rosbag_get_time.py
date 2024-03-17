import rosbag
import rospkg
from datetime import datetime


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

# 打开一个存在的 bag 文件
with rosbag.Bag(bags_path+'/pytest.bag', 'r') as bag:

    # 获取 bag 文件的开始结束时间
    start_time = bag.get_start_time()
    end_time = bag.get_end_time()

    # 将时间转换为更易读的字符串格式
    start_time_str = datetime.fromtimestamp(start_time)
    end_time_str = datetime.fromtimestamp(end_time)

    # 打印开始结束时间
    print(f"Bag file start time: {start_time_str}")
    print(f"Bag file end   time: {end_time_str}")