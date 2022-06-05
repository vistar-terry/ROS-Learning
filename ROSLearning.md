# ROSLearning

## 一、Topic

### 1.1 常用函数接口

https://docs.ros.org/en/api/roscpp/html/classros_1_1Publisher.html#abf12a75cc104239930524fd0059e2153

#### ros::Publisher类

```c++
// 两个重载函数模板，用于发布topic消息
template <typename M>
void publish(const boost::shared_ptr<M>& message) const

template <typename M>
void publish(const M& message) const
```

```c++
// 关闭与此发布者关联的广播
void shutdown()

// 还不知道怎么用，mark一下，有知道的欢迎评论区留言
boost::function<void(const SubscriberLinkPtr &)> getLastMessageCallback()

// 获取与此发布者关联的订阅者的数量
uint32_t getNumSubscribers() const

// 获取此发布者发布的topic
std::string getTopic() const

// 此发布者是否为锁存模式
// 锁存模式：记录发布的最后一条消息，每有订阅者连接发布一次最后一条消息
// 通过advertise函数设置
bool isLatched() const
```



#### ros::Subscriber类

```c++
// 获取与此订阅者关联的发布者的数量
uint32_t getNumPublishers() const

// 获取此订阅者订阅的topic
std::string getTopic() const

// 关闭与此订阅者关联的广播
void shutdown ()
```



### 1.2 常用命令行工具

rostopic相关

```bash
rostopic bw    显示主题使用的带宽
rostopic delay 显示带header的topic的网络延迟
rostopic echo  将消息打印到屏幕
rostopic find  按类型查找主题
rostopic hz    显示主题的发布率
rostopic info  打印关于活动主题的信息
rostopic list  打印有关活动主题的信息
rostopic pub   将数据发布到主题
rostopic type  打印主题类型
```



#### 1.2.1 rostopic bw

```bash
rostopic bw <topic-name>
rostopic bw /rosout
```

显示topic使用的带宽，显示的带宽是subscriber端的带宽，由于rostopic是用python实现的，所以实际速度可能会低于c++实现的ros节点。

比如topic为`/rosout` ，发布默认消息

![20220423162139](img/20220423162139.png)

则subscribe端的带宽为

![Screenshot from 2022-04-23 17-55-22](img/Screenshot%20from%202022-04-23%2017-55-22.png)

其中，

`average`：带宽。

`mean`：从开始通信到现在，每次通信的平均数据量。

`min`：从开始通信到现在，最小的一次通信数据量。

`max`：从开始通信到现在，最大的一次通信数据量。

`window`：应该是从开始通信到现在接收数据的次数，但到100就不再增加了。作者代码里使用队列存储时间戳记录通信，通过获取队列大小得到通信次数，为限制内存开销，作者将队列大小限制为100，将队首元素pop，并将新时间戳加入队列，但pop后作者没有对记录通信次数的变量加1，所以`window`到100就不再增加了。



#### 1.2.2 rostopic delay

```
rostopic delay <topic-name>
rostopic delay /rosout
```

显示带header的topic的网络延迟(因为header会记录msg发出时的时间戳)，即msg从advertiser发出到subscriber接收经过的时间。

自己写一个测试topic `/log` 代码如下，

```python
#!/usr/bin/python3
#-*- coding:utf-8 -*-

import rospy
from rosgraph_msgs.msg import Log

if __name__ == '__main__':

    rospy.init_node('log')

    log = rospy.Publisher('/log', Log, queue_size=10)

    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        log_msg = Log()
        log_msg.header.stamp = rospy.get_rostime()

        log.publish(log_msg)
        rospy.loginfo("Publish log message %s", log_msg)
 
        rate.sleep()
```



则该topic的网络延迟为

![Screenshot from 2022-04-23 17-52-23](img/Screenshot%20from%202022-04-23%2017-52-23.png)

其中，

`average delay` ：从开始通信到现在，所有通信的平均延迟时间，单位：s

`min`：从开始通信到现在，所有通信中延迟时间最小的一次

`max`：从开始通信到现在，所有通信中延迟时间最大的一次

`std dev`：从开始通信到现在，所有通信延迟数据的标准差，表征延迟数据的波动大小，标准差越小表示延迟数据波动越小。

`window`：和 `rostopic bw` 的`window` 一样，不过它的队列大小限制为50000。



#### 1.2.3 rostopic echo

```bash
rostopic echo <topic-name>
rostopic echo /rosout
```

将消息内容打印到屏幕

![Screenshot from 2022-04-23 19-24-57](img/Screenshot%20from%202022-04-23%2019-24-57.png)



`rostopic echo` 有自己的参数选项，如下，

```
rostopic echo --offset	
rostopic echo --filter
rostopic echo -c
rostopic echo -b
rostopic echo -p
rostopic echo -p --nostr
rostopic echo -p --noarr
rostopic echo -w
rostopic echo -n
```



##### rostopic echo --offset

在打印的消息中显示advertiser发布时间与subscriber接收时间的偏移量，和`delay`一样，topic要有header，否则打印中没有时间戳。

```bash
rostopic echo --offset /topic_name
```

测试程序如下：

自定义msg：

```xml
# HeaderString.msg
# 自定义msg
std_msgs/Header header
string data
```

offset节点源文件：

package名称为mbot_communication，自建包需相应修改

```c++
#include "ros/ros.h"
#include "mbot_communication/HeaderString.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offset");

    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<mbot_communication::HeaderString>("/offset", 1000);

    ros::Rate loop_rate(5);

    int count = 0;

    while (ros::ok())
    {
        mbot_communication::HeaderString msg;
        msg.header.stamp = ros::Time::now();
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        chatter_pub.publish(msg);

        ROS_INFO("sec: %d, nsec: %d, data: %s", msg.header.stamp.sec, msg.header.stamp.nsec, msg.data.c_str());

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}
```

启动offset节点后，执行以下命令会有相应打印：

![Screenshot from 2022-04-23 23-21-07](img/Screenshot%20from%202022-04-23%2023-21-07.png)

其中，

stamp是时间戳，这里是advertiser发布时间与subscriber接收时间的偏移量，stamp = advertiser发布时间戳 - subscriber接收时间戳，secs是秒，nsecs是纳秒，1秒= $1*10^{-9}$ 纳秒，上图第一个消息的偏移量就是 $-1+998923014*10^{-9} = -0.001076986(s)$ 。



##### rostopic echo --filter

显示与指定python语法的逻辑表达式匹配的消息

```
rostopic echo --filter "逻辑表达式"  /topic_name
rostopic echo --filter "m.data=='foo'"  /topic_name
```

可以对消息内容做逻辑匹配，比如上述自定义 `/offset` topic，只显示seq为偶数的消息，

![Screenshot from 2022-04-24 21-29-17](img/Screenshot%20from%202022-04-24%2021-29-17.png)

默认消息变量为 `m`，使用`.`表示字段包含关系，只支持匹配数字和字符串，

支持python的所有内置运算符和内置函数，比如对于数字，支持 `+`、`-`、`*`、`**`、`/`、`//`、`%` 等数学运算，`&`、`|`、`~`、`^`、`<<`、`>>` 等位运算，`pow()`、`abs()`、`round()`、`max()` 等内置函数，对于字符串，支持 `split()`、`upper()`、`find()`、`len()` 等内置函数，就是那种使用时不需要另外`import`包的函数在这里都支持。

对于逻辑运算支持 `==`、`!=`、`>`、`<`、`>=`、`<=`、`and`、`or` 等。

另外，如果和字符或字符串进行比较，需要用 `''` 括起来。

再给两个例子，其他自己探索吧：

![Screenshot from 2022-04-24 22-20-48](img/Screenshot%20from%202022-04-24%2022-20-48.png)

![Screenshot from 2022-04-24 22-24-06](img/Screenshot%20from%202022-04-24%2022-24-06.png)



##### rostopic echo -c

打印每条消息前清除屏幕，不能与 `-p` 一起使用。

```bash
rostopic echo -c /topic_name
```



##### rostopic echo -b

显示bag文件中录制的topic

```bash
rostopic echo -b log_file.bag /topic_name
```

录制了一段/offset的消息，使用该命令打印如下：

![Screenshot from 2022-04-24 22-50-20](img/Screenshot%20from%202022-04-24%2022-50-20.png)

`.bag`有特定的编码格式，不能直接打开，如果想直接查看bag记录的内容而不想每次播放bag，可以使用这个命令将bag内容重定向，offset.txt文件就可以随时打开查看了。

![Screenshot from 2022-04-24 22-57-36](img/Screenshot%20from%202022-04-24%2022-57-36.png)

和 `rostopic echo -b` 一起用的还有一个 `-a` 参数选项，用来显示 `bag` 文件中记录的所有消息，也就是 `rostopic echo -b log_file.bag` 后面如果接 `topic` 名字，就显示对应 `topic` 的消息内容，如果接 `-a` 就显示所有消息。

![Screenshot from 2022-04-25 23-45-32](img/Screenshot%20from%202022-04-25%2023-45-32.png)

![Screenshot from 2022-04-25 23-44-20](img/Screenshot%20from%202022-04-25%2023-44-20.png)

![Screenshot from 2022-04-25 23-39-32](img/Screenshot%20from%202022-04-25%2023-39-32.png)

显示所有消息时，是按照记录时的时间顺序打印每条消息的。



##### rostopic echo -p

以 matlab/octave 友好的格式显示消息。不能与 `-c` 一起使用。

```
rostopic echo -p /topic_name
```

![Screenshot from 2022-04-25 22-25-13](img/Screenshot%20from%202022-04-25%2022-25-13.png)

其中，以`%`开头的第一行是标题，按顺序对应每行以 `,` 隔开的变量名。

`rostopic echo -p` 还有两个参数选项，`--nostr ` 和 `--noarr` ，分别代表 `忽略字符串` 和 `忽略数组` 

![Screenshot from 2022-04-25 22-33-24](img/Screenshot%20from%202022-04-25%2022-33-24.png)

使用 `--nostr` 参数选项后，忽略掉了字符串类型的 `frame_id` 和 `data` 。



##### rostopic echo -w

以固定宽度 `NUM_WIDTH` 打印所有数值，如果 `NUM_WIDTH` 小于实际宽度，则以实际宽度打印。

```bash
rostopic echo -w NUM_WIDTH /topic_name
```

![Screenshot from 2022-04-25 23-11-23](img/Screenshot%20from%202022-04-25%2023-11-23.png)

每个数字的宽度为13，实际宽度不足13的，在数字前面补空格。

符合python的 `%` 占位符规则，具体可查询 `python % 占位符` 。



##### rostopic echo -n

打印接收到的 `COUNT` 条消息并退出。

```bash
rostopic echo -n COUNT /topic_name
```

![Screenshot from 2022-04-25 23-16-09](img/Screenshot%20from%202022-04-25%2023-16-09.png)



#### 1.2.4 rostopic find

```bash
rostopic find <msg-type>
rostopic find rosgraph_msgs/Log
```

按照 `topic` 的消息类型查找运行的 `topic`。

![Screenshot from 2022-04-26 22-55-28](img/Screenshot%20from%202022-04-26%2022-55-28.png)



#### 1.2.5 rostopic hz

```
rostopic hz <topic-name>
rostopic hz /rosout
```

显示主题的发布率。默认情况下，报告的速率是 rostopic 运行期间的平均速率。

![Screenshot from 2022-04-26 23-03-31](img/Screenshot%20from%202022-04-26%2023-03-31.png)

和 `rostopic delay` 的打印类似，其中，

`average rate` ：从开始通信到现在，所有通信的平均发布率，单位：Hz

`min`：从开始通信到现在，所有通信中发布周期最小的一次

`max`：从开始通信到现在，所有通信中发布周期最大的一次

`std dev`：从开始通信到现在，所有通信发布周期的标准差，表征发布周期的波动大小，标准差越小表示波动越小。

`window`：从开始通信到现在接收数据的次数，队列限制大小50000。



`rostopic hz` 的参数选项如下：

```bash
rostopic hz -w 
rostopic hz --filter
```



##### rostopic hz -w

使用窗口大小（样本数）报告速率，以对速率进行时间局部估计。

如不使用 `-w` 选项，报告的平均速率时从开始通信以来所有通信的平均速率，如使用 `-w` 则为最近 `WINDOW_SIZE` 次通信的平均速率。

```bash
 rostopic hz -w WINDOW_SIZE /topic_name
```

![Screenshot from 2022-04-26 23-40-50](img/Screenshot%20from%202022-04-26%2023-40-50.png)



##### rostopic hz --filter

仅报告指定python语法的逻辑表达式匹配的消息的速率。

逻辑表达式的使用规则同 `rostopic echo --filter`

此选项对性能有很大影响，不应用于高速率主题。

```
rostopic hz --filter FILTER_EXPR /topic_name
```

![Screenshot from 2022-04-26 23-48-00](img/Screenshot%20from%202022-04-26%2023-48-00.png)



#### 1.2.6 rostopic info

```bash
rostopic info <topic-name>
rostopic info /rosout
```

打印 `topic` 的信息

![Screenshot from 2022-04-27 22-16-46](img/Screenshot%20from%202022-04-27%2022-16-46.png)

其中，

Type：是 `topic` 的消息类型

Publishers：是该 `topic` 的发布者节点名，如果是通过 `rostopic` 指令发布，则节点名称就是 `/rostopic_7739_1651069588197` 的命名形式，其中 `7739` 是节点的 `PID`（线程ID），

`1651069588197` 是什么不知道（如果你知道欢迎评论区留言）

Subscribers：是该 `topic` 的订阅者节点名。

`http://Yogo:40683/` 是该节点的网络地址，

![Screenshot from 2022-04-27 23-18-47](img/Screenshot%20from%202022-04-27%2023-18-47.png)



#### 1.2.7 rostopic list

列出当前运行的topic

![Screenshot from 2022-04-30 16-35-34](img/Screenshot%20from%202022-04-30%2016-35-34.png)

rostopic的参数选项如下：

```bash
rostopic list <namespace>    # 列出指定命名空间中的topic
rostopic list -b <bag_file>  # 列出bag文件中的topic
rostopic list -p  # 只列出发布者
rostopic list -s  # 只列出订阅者
rostopic list -v  # 详细模式
rostopic list --host  # 按主机名分组列表
```



##### rostopic list \<namespace\>

列出指定命名空间中的topic，关于ROS的命名空间，见 [ROS WiKi/Names/Graph Resource Names](http://wiki.ros.org/ROS/Concepts#Names.Names)

```bash
rostopic list /up
```

![Screenshot from 2022-04-30 17-15-56](img/Screenshot%20from%202022-04-30%2017-15-56.png)



##### rostopic list -b <bag_file>

列出bag文件中的topic

```bash
rostopic list -b all.bag
```

![Screenshot from 2022-04-30 17-47-31](img/Screenshot%20from%202022-04-30%2017-47-31.png)



##### rostopic list -p

只列出有发布者的topic

```bash
rostopic list -p
```

##### rostopic list -s

只列出有订阅者的topic

```bash
rostopic list -s
```

![Screenshot from 2022-04-30 17-54-54](img/Screenshot%20from%202022-04-30%2017-54-54.png)



##### rostopic list -v

列出所有topic的详细信息

```
rostopic list -v
```

![Screenshot from 2022-04-30 17-58-24](img/Screenshot%20from%202022-04-30%2017-58-24.png)

其中包括topic的属性(发布者/订阅者)、topic名、topic消息类型(方括号里的)、该topic发布者/订阅者的数量。



##### rostopic list --host

按主机名分组列表

```bash
rostopic list --host
```

![Screenshot from 2022-04-30 19-58-32](img/Screenshot%20from%202022-04-30%2019-58-32.png)

其中，方括号里是主机名。



#### 1.2.8 rostopic pub

将数据发布到主题

```bash
rostopic pub <topic-name> <topic-type> [data...]
rostopic pub /topic_name std_msgs/String "hello"
```

关于topic发布的三种模式：

-   latching mode
    -   记录发布的最后一条消息，每有订阅者连接，发布一次最后一条消息
    -   默认为这个模式
-   once mode
    -   保持latching模式3秒，然后退出。
-   rate mode
    -   可以自定义消息的发布频率



关于topic发布消息的数据源：

-   命令行参数（最常用的方法）

    ```bash
    rostopic pub /topic_name std_msgs/String "hello"
    ```

-   管道输入

    ```bash
    rostopic echo /chatter | rostopic pub /bar std_msgs/String
    ```

    这个没发现有什么好用的场景，就是把`/chatter`的消息内容转发给`/bar`了。

-   通过YAML文件输入

    首先要有一个存有msg的文件，可以重定向topic内容：

    ```bash
    rostopic echo /chatter > chatter.bagy
    ```

    然后使用`-f`参数选项将文件内容输入到topic

    ```bash
    rostopic pub -f chatter.bagy /bar std_msgs/String
    ```

​		关于YAML格式在ROS中的使用，见 [YAML on the ROS command line](http://wiki.ros.org/ROS/YAMLCommandLine)



参数选项：

```bash
rostopic pub -l <topic-name> <topic-type> [data...]
rostopic pub --latch <topic-name> <topic-type> [data...]
rostopic pub -r RATE <topic-name> <topic-type> [data...]
rostopic pub -1 <topic-name> <topic-type> [data...]
rostopic pub --once <topic-name> <topic-type> [data...]
rostopic pub -f FILE <topic-name> <topic-type> [data...]
```

##### rostopic pub -l/--latch

`-l`和`--latch`是一样的，代表`latching mode`

![Screenshot from 2022-05-02 22-00-02](img/Screenshot%20from%202022-05-02%2022-00-02.png)

发布者发布一次消息，并将最后一条消息保存等待，直到有新的订阅者连接，把保存的消息发给新的订阅者（每个新订阅者收到的都是这条保存的消息）



##### rostopic pub -r RATE

`rate mode`，`RATE`的单位是`Hz`。

![Screenshot from 2022-05-02 22-00-53](img/Screenshot%20from%202022-05-02%2022-00-53.png)

发布者按`10Hz`的频率不停发布消息，订阅者一直接收消息。



##### rostopic pub -1/--once

`-1`(注意是数字1) 和 `--once` 是一样的，代表`once mode`



##### rostopic pub -f FILE

通过YAML文件输入



#### 1.2.9 rostopic type

显示topic的消息类型

```bash
rostopic type <topic-name>
rostopic type /topic_name
```

![Screenshot from 2022-05-02 22-24-45](img/Screenshot%20from%202022-05-02%2022-24-45.png)

http://wiki.ros.org/rostopic





## 二、Service

### 2.1 常用函数接口

#### ros::ServiceClient类

```c++
// 四个重载函数模板，用于调用服务
// 使用指定的服务类型调用服务
template<class Service>
bool call(Service &service)

// 使用指定的请求/响应消息类型调用服务
template<class MReq, class MRes>
bool call(MReq &req, MRes &res)

// 多用于内部调用，以上两个函数最终均调用到该函数
template<typename MReq , typename MRes>
bool call(const MReq &req, MRes &resp, const std::string &service_md5sum)
 
bool call(const SerializedMessage &req, SerializedMessage &resp, const std::string &service_md5sum)

// 返回此句柄是否有效。对于持续性服务，当连接断开时，这将变为false。非持续性服务句柄始终有效。
bool isValid() const;

// 返回此句柄是否是持续性服务
bool isPersistent() const;

// 等待此服务发布并可用。
bool waitForExistence(ros::Duration timeout = ros::Duration(-1));

// 检查该服务是否已发布并可用。
bool exists();
    
// 返回此ServiceClient连接到的服务的名称。
std::string getService();

// 关闭与此ServiceClient关联的连接
void shutdown();
```



#### ros::ServiceServer类

```c++
// 返回此ServiceServer发布的服务的名称。
std::string getService();

// 取消发布与此ServiceServer关联的服务
void shutdown();
```



### 2.2 常用命令行工具

rosservice相关

```bash
rosservice call   使用提供的参数调用服务
rosservice find   通过服务消息类型查找服务
rosservice list   列出活跃的服务
rosservice node   打印服务的node名称
rosservice uri    打印服务的ROSRPC uri
rosservice type   打印指定服务的消息类型
rosservice args   打印服务的参数列表
rosservice info   打印服务相关信息
```



#### 2.2.1 rosservice call

```bash
rosservice call <service-name> [service-args]
rosservice call /service_name service-args
```

使用提供的参数调用服务

![Screenshot from 2022-06-03 15-33-22](img/Screenshot%20from%202022-06-03%2015-33-22.png)

可以在服务名后直接跟参数列表，也可以使用字典的格式（键入服务名后，按tab自动补全，默认是这种格式）。



```bash
参数选项：--wait
```

等待服务发布才调用

![Screenshot from 2022-06-03 15-45-23](img/Screenshot%20from%202022-06-03%2015-45-23.png)

如果服务没有发布，直接调用，会返回错误，使用 `--wait` 选项后，会一直等待服务发布才调用。



#### 2.2.2 rosservice find

```bash
rosservice find <service-type>
rosservice find rospy_tutorials/AddTwoInts
```

按照特定的消息类型查找已发布的 `service`。

![Screenshot from 2022-06-03 21-42-12](img/Screenshot%20from%202022-06-03%2021-42-12.png)



#### 2.2.3 rosservice list

```bash
rosservice list
```

列出当前所有活跃的service

![Screenshot from 2022-06-05 13-58-20](img/Screenshot%20from%202022-06-05%2013-58-20.png)



```bash
rosservice list <namespace>
```

列出指定名空间下当前所有活跃的service

![Screenshot from 2022-06-05 14-00-43](img/Screenshot%20from%202022-06-05%2014-00-43-16544089031571.png)



```bash
-n选项：同时打印服务所在节点的名称
rosservice list -n
rosservice list <namespace> -n
```

![Screenshot from 2022-06-05 14-05-27](img/Screenshot%20from%202022-06-05%2014-05-27.png)

前面是服务名，后面是节点名。



#### 2.2.4 rosservice node

```bash
rosservice node <service-name>
rosservice node /add_two_ints 
```

![Screenshot from 2022-06-05 14-30-44](img/Screenshot%20from%202022-06-05%2014-30-44.png)



#### 2.2.5 rosservice uri

```bash
rosservice uri <service-name>
rosservice uri /add_two_ints 
```

打印服务的ROSRPC uri

![Screenshot from 2022-06-05 14-25-09](img/Screenshot%20from%202022-06-05%2014-25-09.png)




#### 2.2.6 rosservice type

```bash
rosservice type <service-name>
rosservice type /add_two_ints 
```

打印指定service的消息类型

![Screenshot from 2022-06-05 14-21-10](img/Screenshot%20from%202022-06-05%2014-21-10.png)



#### 2.2.7 rosservice args

```bash
rosservice args <service-name>
rosservice args /service_name
```

打印服务的参数列表，没有参数则没有打印

![Screenshot from 2022-06-03 15-21-02](img/Screenshot%20from%202022-06-03%2015-21-02.png)



#### 2.2.8 rosservice info

```bash
rosservice info <service-name>
rosservice info /rosout
```

打印指定service的信息，相当于 `rosservice node`、`rosservice uri`、`rosservice type`、`rosservice args` 的集合。

![Screenshot from 2022-06-05 13-19-09](img/Screenshot%20from%202022-06-05%2013-19-09.png)

其中，

Node：是service所在节点的名称。

URI：是service的ROSRPC地址。

Type：是service的消息类型。

Args：是service的参数列表。
























http://wiki.ros.org/rosservice?distro=noetic





























 
