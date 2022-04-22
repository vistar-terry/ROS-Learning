# ROSLearning

### 一、Topic

#### 1.1 常用函数接口

https://docs.ros.org/en/api/roscpp/html/classros_1_1Publisher.html#abf12a75cc104239930524fd0059e2153

**ros::Publisher类**

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

// 此发布者是否被锁定
// 源码中没有找到锁定发布者的接口
bool isLatched() const
```



#### 1.2 常用命令行工具

http://wiki.ros.org/rostopic



