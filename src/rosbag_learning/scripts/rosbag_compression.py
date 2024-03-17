import rosbag
import rospkg 


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

# 打开一个存在的 bag 文件
with rosbag.Bag(bags_path+'/pytest.bag', 'r') as bag:

    # 获取压缩信息
    compression_info = bag.get_compression_info()

    # 打印压缩信息
    if compression_info:
        print("Compression Type:", compression_info[0])
        print("UnCompressed Size:", compression_info[1])
        print("compressed Size:", compression_info[2])
    else:
        print("The bag file is not compressed.")