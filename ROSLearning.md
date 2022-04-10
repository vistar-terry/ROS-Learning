# ROSLearning

### 一、Topic

#### 1.1 function interface

https://docs.ros.org/en/api/roscpp/html/classros_1_1Publisher.html#abf12a75cc104239930524fd0059e2153

template<typename M >
void 	publish (const boost::shared_ptr< M > &message) const



template<typename M >
void 	publish (const M &message) const



void 	shutdown ()



boost::function< void(const SubscriberLinkPtr &)> 	getLastMessageCallback ()



uint32_t 	getNumSubscribers () const


std::string 	getTopic () const


bool 	isLatched () const



#### 1.2 command line

http://wiki.ros.org/rostopic
