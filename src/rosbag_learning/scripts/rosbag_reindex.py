import rosbag
import rospkg


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

with rosbag.Bag(bags_path+'/pytest.bag', 'r') as bag:
    try:
        for topic, msg, t in bag.read_messages():
            print(f"Received message on topic {topic} at time {t}: {msg}")

    except Exception as e:
        print(f"An error occurred while reading the bag file: {e}")
        print("Reindexing the bag file...")
        bag.reindex()  # 尝试重新索引 bag 文件
        print("Reindexing completed.")

    # 现在可以正常使用 bag 文件中的数据了