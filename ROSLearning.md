# ROSLearning

# 一、ROS概览与开发环境

## 1.1 ROS简介

### 1.1.1 为什么要诞生ROS

机器人是一种高度复杂的系统性实现，机器人设计包含了机械加工、机械结构设计、硬件设计、嵌入式软件设计、上层软件设计....是各种硬件与软件集成，甚至可以说机器人系统是当今工业体系的集大成者。

机器人体系是相当庞大的，其复杂度之高，以至于没有任何个人、组织甚至公司能够独立完成系统性的机器人研发工作。

一种更合适的策略是：让机器人研发者专注于自己擅长的领域，其他模块则直接复用相关领域更专业研发团队的实现，当然自身的研究也可以被他人继续复用。这种基于"复用"的分工协作，遵循了**不重复发明轮子**的原则，显然是可以大大提高机器人的研发效率的，尤其是随着机器人硬件越来越丰富，软件库越来越庞大，这种复用性和模块化开发需求也愈发强烈。

在此大背景下，于 **2007** 年，一家名为 **柳树车库（Willow Garage）**的机器人公司发布了 ***ROS***(机器人操作系统)，ROS是一套机器人通用软件框架，可以提升功能模块的复用性，并且随着该系统的不断迭代与完善，如今 ROS 已经成为机器人领域的事实标准。

### 1.1.2 什么是ROS

**ROS全称Robot Operating System(机器人操作系统)**

- ROS是适用于机器人的**开源**元操作系统
- ROS集成了大量的工具，库，协议，提供类似OS所提供的功能，简化对机器人的控制
- 还提供了用于在**多台计算机**上获取，构建，编写和运行代码的工具和库，ROS在某些方面类似于“机器人框架”
- ROS设计者将ROS表述为“ROS = Plumbing + Tools + Capabilities + Ecosystem”，即ROS是通讯机制、工具软件包、机器人高层技能以及机器人生态系统的集合体

![05ROS简介](img/05ROS简介.png)

### 1.1.3 ROS的目标

机器人开发的分工思想，实现了不同研发团队间的共享和协作，提升了机器人的研发效率，为了服务“ 分工”，ROS主要设计了如下目标：

- **代码复用:**ROS的目标不是成为具有最多功能的框架，ROS的主要目标是支持机器人技术研发中的代码*重用*。
- **分布式:**ROS是进程（也称为*Nodes*）的分布式框架,ROS中的进程可分布于不同主机，不同主机协同工作，从而分散计算压力
- **松耦合:**ROS中功能模块封装于独立的功能包或元功能包，便于分享，功能包内的模块以节点为单位运行，以ROS标准的IO作为接口，开发者不需要关注模块内部实现，只要了解接口规则就能实现复用,实现了模块间点对点的松耦合连接
- **精简：**ROS被设计为尽可能精简，以便为ROS编写的代码可以与其他机器人软件框架一起使用。ROS易于与其他机器人软件框架集成：ROS已与OpenRAVE，Orocos和Player集成。
- **语言独立性：**包括Java，C++，Python等。为了支持更多应用开发和移植，ROS设计为一种语言弱相关的框架结构，使用简洁，中立的定义语言描述模块间的消息接口，在编译中再产生所使用语言的目标文件，为消息交互提供支持，同时允许消息接口的嵌套使用
- **易于测试：**ROS具有称为[rostest](http://wiki.ros.org/rostest)的内置单元/集成测试框架，可轻松安装和拆卸测试工具。
- **大型应用：**ROS适用于大型运行时系统和大型开发流程。
- **丰富的组件化工具包：**ROS可采用组件化方式集成一些工具和软件到系统中并作为一个组件直接使用，如RVIZ（3D可视化工具），开发者根据ROS定义的接口在其中显示机器人模型等，组件还包括仿真环境和消息查看工具等
- **免费且开源：**开发者众多，功能包多

### 1.1.4 ROS发展历程

- ROS是一个由来已久、贡献者众多的大型软件项目。在ROS诞生之前，很多学者认为，机器人研究需要一个开放式的协作框架，并且已经有不少类似的项目致力于实现这样的框架。在这些工作中，斯坦福大学在2000年年中开展了一系列相关研究项目，如斯坦福人工智能机器人（STandford AI Robot, STAIR）项目、个人机器人（Personal Robots, PR）项目等，在上述项目中，在研究具有代表性、集成式人工智能系统的过程中，创立了用于室内场景的高灵活性、动态软件系统，其可以用于机器人学研究。

- 2007年，柳树车库（Willow Garage）提供了大量资源，用于将斯坦福大学机器人项目中的软件系统进行扩展与完善，同时，在无数研究人员的共同努力下，ROS的核心思想和基本软件包逐渐得到完善。

- ROS的发行版本（ROS distribution）指ROS软件包的版本，其与Linux的发行版本（如Ubuntu）的概念类似。推出ROS发行版本的目的在于使开发人员可以使用相对稳定的代码库，直到其准备好将所有内容进行版本升级为止。因此，每个发行版本推出后，ROS开发者通常仅对这一版本的bug进行修复，同时提供少量针对核心软件包的改进。

- 版本特点: 按照英文字母顺序命名，ROS 目前已经发布了ROS1 的最终版本: noetic，并建议后期过渡至 ROS2 版本。noetic 版本之前默认使用的是 Python2，noetic 支持 Python3。

    建议版本: noetic 或 melodic 或 kinetic

## 1.2 ROS安装

ROS不是真正的操作系统，它需要依赖于其他操作系统，我们以**noetic**为例，它依赖于**Ubuntu20.04**，所以安装ROS noetic之前需要先安装Ubuntu20.04，有以下两种方式：

- 物理机安装：可以保证性能，且不需要考虑硬件交互问题，但和windows系统交互不便；
- 虚拟机安装：可以方便的实现 windows 与 ubuntu 切换，不过性能稍差，且与硬件交互不便。

实际应用中，ROS常需要获取硬件数据，且对性能要求较高，所以原则上建议在物理机中安装，但初学只需要了解ROS原理与初级使用，虚拟机已足够，所以初学建议虚拟机安装ubuntu和ROS。

常用的虚拟机有VMware和virtualbox，前者收费后者免费，按需选择。

### 1.2.1 安装虚拟机

### 1.2.2 安装Ubuntu

### 1.2.3 安装ROS

#### 1.2.3.1 设置Ubuntu的软件和更新

在搜索框输入software，选择软件和更新一项，勾选 `main`、`universe`、`restricted` 和 `multiverse`，然后在`Downlosd from`选择一个中国的服务器，我选的上海交大的源，然后点 `Close` 关闭就行了。
![在这里插入图片描述](img/8913dd98f375480185c441cc1ac325a9.png)

![在这里插入图片描述](img/b0c1141d13da422c9c500442480537a5.png)

#### 1.2.3.2 添加源

如果网速快，可以直接用官方源，打开terminal输入一下命令：

```bash
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
```

网速慢的话，可以用国内源：
[国内源列表](http://wiki.ros.org/ROS/Installation/UbuntuMirrors)

上海交大源

```bash
sudo sh -c '. /etc/lsb-release && echo "deb http://mirrors.sjtug.sjtu.edu.cn/ros/ubuntu/ `lsb_release -cs` main" > /etc/apt/sources.list.d/ros-latest.list'
```

清华源

```bash
sudo sh -c '. /etc/lsb-release && echo "deb http://mirrors.tuna.tsinghua.edu.cn/ros/ubuntu/ `lsb_release -cs` main" > /etc/apt/sources.list.d/ros-latest.list'
```

#### 1.2.3.3 添加密钥

```bash
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
```

#### 1.2.3.4 更新软件包索引

```bash
sudo apt update
```

#### 1.2.3.5 安装ROS

ROS有好几个安装模式，包含的功能有多有少，我选择的完全安装。

```bash
sudo apt install ros-noetic-desktop-full
```

#### 1.2.3.6 设置环境变量

为了每次启动新terminal，ROS仍能用，不用每次手动设置环境变量。

```bash
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

#### 1.2.3.7 安装其他工具和依赖关系

ROS的核心部分已经安装完了，但还有一些构建软件包的依赖关系和工具。

```bash
sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
```

#### 1.2.3.8 初始化rosdep

rosdep可以为要编译的源安装系统依赖性，并且是运行ROS中某些核心组件所必需的。

```bash
sudo rosdep init
rosdep update
```

这一步，由于软件服务器在国外，常常访问超时，解决办法见 [ERROR: cannot download default sources list from: 20-default.list. Website may be down.](https://blog.csdn.net/maizousidemao/article/details/109476275)

另外，也可以安装国内版的rosdep，如下：

##### 国内版rosdep

为了方便国内同学学习ROS，大佬 **鱼香ROS** 基于 `rosdep` 源码制作了 `rosdepc`，后缀 `c` 即 `China` 。

##### 1. 安装  `rosdepc`

```bash
sudo pip install rosdepc
```

如果显示没有 `pip` 可以使用 `pip3`：

```bash
sudo pip3 install rosdepc
```

如果 `pip3` 还没有，需要先安装 `pip3`：

```bash
sudo apt-get install python3-pip
```

##### 2. 使用  `rosdepc`

```bash
sudo rosdepc init
rosdepc update
```

#### 1.2.3.9 验证

这样ROS就安装好啦，输入

```bash
roscore
```

如果没有错误，就是安装成功了。

![在这里插入图片描述](img/1994310d8c8440a2808687fe403448e5.png)



## 1.3 ROS Hello World

万物始于Hello World，为了体验ROS，使用Hello World介绍ROS的简单使用。

### 1.3.1 Hello World工程简介

首先需要创建工程，流程为：

1. 创建工作空间目录（即工程根目录，注意此时还不是ROS工作空间，只是一个目录）
2. 初始化工作空间（即把当前目录初始化为一个ROS工作空间）
3. 创建功能包（ROS基本单元，可以理解为一个功能模块，每个工程至少有一个功能包）
4. 编辑源文件（写代码实现需求）
5. 编辑编译配置文件（ROS1使用CMake编译系统，这里编辑CMakeList.txt文件）
6. 编译工程（使用CMake编译ROS工程，生成可执行文件，即ros节点，下文均称作节点）

不只是Hello World，所有ROS工程都是这样的流程。

另外，目前ROS开发主要使用C++和Python语言，这里会分别实现。

### 1.3.2 ROS Hello World C++ 版

注：其中`ros_learning`是工作空间的自定义名称。

#### 1.3.2.1 创建工作空间目录

```bash
# 递归创建工作空间目录
mkdir -p ros_learning/src
```

#### 1.3.2.2 初始化工作空间

这一步有两种方法都可以达到初始化工作空间的目的：

方法一：

```bash
# 1.进入src目录
cd ros_learning/src
# 2.初始化工作空间
catkin_init_workspace
```

方法二：

```bash
# 1.进入ros_learning目录
cd ros_learning/src
# 2.编译工作空间
catkin_make
```

#### 1.3.2.3 创建功能包

```bash
cd ros_learning/src
catkin_create_pkg hello_world std_msgs rospy roscpp
```

其中，hello_world：自定义功能包名称，

std_msgs rospy roscpp：功能包依赖，roscpp是C++实现的库，而rospy是python实现的库，std_msgs是ROS标准消息库

#### 1.3.2.4 编辑源文件

在`ros_learning/src/hello_world/src`目录下新增`hello_world.cpp`文件，文件内容如下：

```c++
#include "ros/ros.h"

int main(int argc, char **argv)
{
    // 初始化ros节点，"hello_world_cpp"为自定义节点名称
    ros::init(argc, argv, "hello_world_cpp");

    // 在控制台打印 hello world
    ROS_INFO("Hello World!");

    return 0;
}
```

#### 1.3.2.5 编辑编译配置文件CMakeList.txt

由于新增了源文件`hello_world.cpp`，所以要配置该文件的编译规则。

找到`ros_learning/src/hello_world/CMakeLists.txt`中的`Build`，如下：

![image-20231029144244947](img/image-20231029144244947.png)

修改其中的`add_executable`和`target_link_libraries`两项，如下：

![image-20231029144443946](img/image-20231029144443946.png)

修改说明如下：

```cmake
add_executable(${PROJECT_NAME}_node src/hello_world.cpp)
# 生成可执行文件，其中 ${PROJECT_NAME}_node 代表节点的名称（也可以自定义，比如hello_world）
# src/hello_world.cpp 是源文件，也可以有多个。

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)
# 链接库文件，因为我们使用了ros的 ros::init 和 ROS_INFO，所以需要链接相应的库才可以编译成功。
# ${PROJECT_NAME}_node 代表要执行链接库的节点名称
# ${catkin_LIBRARIES} 搜索库的路径
```

#### 1.3.2.6 编译工程

进入到ros_learning目录，编译该工程

```bash
cd ros_learning
catkin_make
```

编译成功后，会在ros_learning目录下生成build 和devel。

#### 1.3.2.7 运行节点

生成的节点在 `devel/lib/hello_world` 中，我们可以直接执行：

![image-20231029152451986](img/image-20231029152451986.png)

不过这样需要知道节点的具体路径，实际中操作较麻烦。

ROS提供了 `rosrun` 命令，可以根据包名和节点名，在任何目录执行。

但需要具备以下两个条件：

- 启动 roscore
- 进入到工作空间目录中，执行 source ./devel/setup.bash（为了让系统找到节点）

![image-20231029153313604](img/image-20231029153313604.png)

但 `source ./devel/setup.bash` 只对当前终端有效，新打开终端仍需再执行该命令，为了避免每次执行，可以把该命令加到当前用户的 `.bashrc` 文件中，该文件在用户的 `home` 目录下。

方法一：直接打开 `~/.bashrc` 文件，在末尾添加 `source 你的工作空间目录/devel/setup.bash` ，保存。

方法二：使用命令 `echo "source 你的工作空间目录/devel/setup.bash" >> ~/.bashrc`

最后，使用命令 `source ~/.bashrc` 使修改生效。



### 1.3.3 ROS Hello World Python 版

1到3步骤上面已经做过，这里直接编辑源文件。

#### 1.3.3.1 编辑源文件

进入到 `ros_learning/src/hello_world` 目录，新建 `scripts` 目录，在该目录中新增 `hello_world.py`，内容如下：

```python
#! /usr/bin python

import rospy

if __name__ == "__main__":
    # 初始化ros节点，"hello_world_py"为自定义节点名称
    rospy.init_node("hello_world_py")

    # 在控制台打印 Hello World!
    rospy.loginfo("Hello World!")
```

#### 1.3.3.2 编辑编译配置文件CMakeList.txt

找到`ros_learning/src/hello_world/CMakeLists.txt`中的`Install`，修改`catkin_install_python`如下：

![image-20231029173411432](img/image-20231029173411432.png)

修改说明：

```cmake
catkin_install_python(PROGRAMS
  scripts/hello_world.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
# 将脚本scripts/hello_world.py安装到指定位置
# PROGRAMS 关键字指定脚本程序
# DESTINATION 关键字指定安装位置
# ${CATKIN_PACKAGE_BIN_DESTINATION} 系统环境变量，存储当前功能包可执行文件安装路径
```

#### 1.3.3.3 编译工程

进入到ros_learning目录，编译该工程

```bash
cd ros_learning
catkin_make
```

编译成功后，会在ros_learning目录下生成build 和devel。

#### 1.3.3.4 运行节点

生成的脚本在 `devel/lib/hello_world` 中，同样可以直接运行，也可以使用 `rosrun`命令。

这里注意，无论直接运行还是使用`rosrun`命令，都需要先启动`roscore`。

![image-20231029183114667](img/image-20231029183114667.png)



## 1.4 ROS架构

### 1.4.1 ROS架构简介

立足不同的角度，对ROS架构的描述也是不同的，一般我们可以从设计者、维护者、系统结构与自身结构4个角度来描述ROS结构:

#### 1. 设计者

ROS设计者将ROS表述为 `ROS = Plumbing + Tools + Capabilities + Ecosystem`

- Plumbing：**通讯机制(实现ROS不同节点之间的交互)**
- Tools：**工具软件包(ROS中的开发和调试工具)**
- Capabilities：机器人高层技能(ROS中某些功能的集合，比如：导航)
- Ecosystem：机器人生态系统(跨地域、跨软件与硬件的ROS联盟)

#### 2. 维护者

立足**维护者**的角度: ROS 架构可划分为两大部分

- main：核心部分，主要由Willow Garage 和一些开发者设计、提供以及维护。它提供了一些分布式计算的基本工具，以及整个ROS的核心部分的程序编写。
- universe：全球范围的代码，有不同国家的ROS社区组织开发和维护。一种是库的代码，如OpenCV、PCL等；库的上一层是从功能角度提供的代码，如人脸识别，他们调用下层的库；最上层的代码是应用级的代码，让机器人完成某一确定的功能。

#### 3. 系统架构

立足系统架构: ROS 可以划分为三层

- OS 层，也即经典意义的操作系统

    ROS 只是元操作系统，需要依托真正意义的操作系统，目前兼容性最好的是 Linux 的 Ubuntu，Mac、Windows 也支持 ROS 的较新版本

- 中间层

    是 ROS 封装的关于机器人开发的中间件，比如:

    - 基于 TCP/UDP 继续封装的 TCPROS/UDPROS 通信系统
    - 用于进程间通信 Nodelet，为数据的实时性传输提供支持
    - 另外，还提供了大量的机器人开发实现库，如：数据类型定义、坐标变换、运动控制....

- 应用层

    功能包，以及功能包内的节点，比如: master、turtlesim的控制与运动节点...

#### 4. 自身结构

就 ROS 自身实现而言，也可以划分为三层：

- 文件系统

    ROS文件系统级指的是在硬盘上面查看的ROS源代码的组织形式

- 计算图

    ROS 分布式系统中不同进程需要进行数据交互，计算图可以以点对点的网络形式表现数据交互过程，计算图中的重要概念: 节点(Node)、消息(message)、通信机制主题(topic)、通信机制服务(service)

- 开源社区

    ROS的社区级概念是ROS网络上进行代码发布的一种表现形式

    - 发行版（Distribution）　ROS发行版是可以独立安装、带有版本号的一系列综合功能包。ROS发行版像Linux发行版一样发挥类似的作用。这使得ROS软件安装更加容易，而且能够通过一个软件集合维持一致的版本。
    - 软件库（Repository）　ROS依赖于共享开源代码与软件库的网站或主机服务，在这里不同的机构能够发布和分享各自的机器人软件与程序。
    - ROS维基（ROS Wiki）　ROS Wiki是用于记录有关ROS系统信息的主要论坛。任何人都可以注册账户、贡献自己的文件、提供更正或更新、编写教程以及其他行为。网址是http://wiki.ros.org/。
    - Bug提交系统（Bug Ticket System）如果你发现问题或者想提出一个新功能，ROS提供这个资源去做这些。
    - 邮件列表（Mailing list）　ROS用户邮件列表是关于ROS的主要交流渠道，能够像论坛一样交流从ROS软件更新到ROS软件使用中的各种疑问或信息。网址是http://lists.ros.org/。
    - ROS问答（ROS Answer）用户可以使用这个资源去提问题。网址是https://answers.ros.org/questions/。
    - 博客（Blog）你可以看到定期更新、照片和新闻。网址是https://www.ros.org/news/，不过博客系统已经退休，ROS社区取而代之，网址是https://discourse.ros.org/。



### 1.4.2 ROS文件系统

ROS文件系统级指的是ROS源代码在硬盘上的组织形式，其结构大致可以如下图所示：

![img](img/文件系统.png)

其中：

```bash
catkin workspace 工作空间
├── build：编译空间，用于存放CMake和catkin的缓存信息、配置信息和其他中间文件。
├── devel：开发空间，用于存放编译后生成的目标文件，包括头文件、动态&静态链接库、可执行文件等。
└── src：源码
    ├── CMakeList.txt：编译的基本配置
    ├── package1：功能包(ROS基本单元)包含多个节点、库与配置文件
    └── package2
        ├── CMakeList.txt：配置编译规则，比如源文件、依赖项、目标文件
        ├── package.xml：包信息，如:包名、版本、作者、依赖项等(ROS旧版本是manifest.xml)
        ├── scripts：脚本文件
        ├── msg：消息通信格式文件
        ├── srv：服务通信格式文件
        ├── include：头文件
        ├── src：C++源文件
        ├── launch：启动文件
        ├── action：动作格式文件
        └── config：参数配置文件
```



#### 1.4.1.1 package.xml 内容说明

该文件基于XML语言，XML指可扩展标记语言（e**X**tensible **M**arkup **L**anguage），被设计用来传输和存储数据。

该文件定义有关软件包的属性信息，如：软件包名称、版本号、作者、维护者以及对其他catkin软件包的依赖性。请注意，该概念类似于旧版ROS的 `rosbuild` 构建系统中使用的 `manifest.xml` 文件。

```xml
<!-- xml声明：文档符合xml1.0规范 -->
<?xml version="1.0"?>
<!-- 格式: 以前是 1，推荐使用格式 2 -->
<package format="2">
    <!-- 包名 -->
    <name>hello_world</name>
    <!-- 包版本 -->
    <version>0.0.0</version>
    <!-- 描述信息 -->
    <description>The hello_world package</description>
  
    <!-- One maintainer tag required, multiple allowed, one person per tag -->
    <!-- Example:  -->
    <!-- <maintainer email="jane.doe@example.com">Jane Doe</maintainer> -->
    <!-- 维护人员 -->
    <maintainer email="vistar@todo.todo">vistar</maintainer>
  
  
    <!-- One license tag required, multiple allowed, one license per tag -->
    <!-- Commonly used license strings: -->
    <!--   BSD, MIT, Boost Software License, GPLv2, GPLv3, LGPLv2.1, LGPLv3 -->
    <!-- 许可证信息，ROS核心组件默认 BSD -->
    <license>TODO</license>
  
  
    <!-- Url tags are optional, but multiple are allowed, one per tag -->
    <!-- Optional attribute type can be: website, bugtracker, or repository -->
    <!-- Example: -->
    <!-- <url type="website">http://wiki.ros.org/hello_world</url> -->
  
  
    <!-- Author tags are optional, multiple are allowed, one per tag -->
    <!-- Authors do not have to be maintainers, but could be -->
    <!-- Example: -->
    <!-- <author email="jane.doe@example.com">Jane Doe</author> -->
  
  
    <!-- The *depend tags are used to specify dependencies -->
    <!-- Dependencies can be catkin packages or system dependencies -->
    <!-- Examples: -->
    <!-- Use depend as a shortcut for packages that are both build and exec dependencies -->
    <!--   <depend>roscpp</depend> -->
    <!--   Note that this is equivalent to the following: -->
    <!--   <build_depend>roscpp</build_depend> -->
    <!--   <exec_depend>roscpp</exec_depend> -->
    <!-- Use build_depend for packages you need at compile time: -->
    <!--   <build_depend>message_generation</build_depend> -->
    <!-- Use build_export_depend for packages you need in order to build against this package: -->
    <!--   <build_export_depend>message_generation</build_export_depend> -->
    <!-- Use buildtool_depend for build tool packages: -->
    <!--   <buildtool_depend>catkin</buildtool_depend> -->
    <!-- Use exec_depend for packages you need at runtime: -->
    <!--   <exec_depend>message_runtime</exec_depend> -->
    <!-- Use test_depend for packages you need only for testing: -->
    <!--   <test_depend>gtest</test_depend> -->
    <!-- Use doc_depend for packages you need only for building documentation: -->
    <!--   <doc_depend>doxygen</doc_depend> -->
    <!-- 构建工具，这是必须的 -->
    <buildtool_depend>catkin</buildtool_depend>
    
    <!-- 指定此软件包依赖的其他软件包 -->
    <build_depend>roscpp</build_depend>
    <build_depend>rospy</build_depend>
    <build_depend>std_msgs</build_depend>
    
    <!-- 指定根据这个包构建成库所依赖的其他包 -->
    <build_export_depend>roscpp</build_export_depend>
    <build_export_depend>rospy</build_export_depend>
    <build_export_depend>std_msgs</build_export_depend>
    
    <!-- 指定运行该软件包所依赖的其他包 -->  
    <exec_depend>roscpp</exec_depend>
    <exec_depend>rospy</exec_depend>
    <exec_depend>std_msgs</exec_depend>
  
  
    <!-- The export tag contains other, unspecified, tags -->
    <export>
      <!-- Other tools can request additional information be placed here -->
  
    </export>
</package>

```

#### 1.4.1.2 CMakelists.txt 内容说明

该文件基于CMake语言，CMake是一个跨平台的编译工具，可以用简单的语句来描述所有平台的编译过程。

```cmake
# 所需 cmake 的最小版本
cmake_minimum_required(VERSION 3.0.2)
# 工程名称，隐式定义 ${PROJECT_NAME} 
project(hello_world)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
# 设置构建所需要的软件包
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# 启动 python 模块支持
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
## 设置 ROS 消息、服务、动作等
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# 生成消息、服务的依赖包
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

################################################
## Declare ROS dynamic reconfigure parameters ##
## 声明 ROS 动态参数配置
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
## catkin 特定配置
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
# 运行时依赖
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES hello_world
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# 添加头文件路径，注意当前程序包的头文件路径要位于其他文件路径之前
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# 声明 C++ 库
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/hello_world.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# 添加库的目标依赖
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# 生成可执行文件
add_executable(${PROJECT_NAME}_node src/hello_world.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# 重命名c++可执行文件
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# 添加可执行文件的目标依赖
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# 指定库、可执行文件的链接库
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# 设置用于安装的可执行脚本
catkin_install_python(PROGRAMS
  scripts/hello_world.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_hello_world.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

```



### 1.4.3 ROS计算图

#### 1.4.2.1 计算图简介

**计算图**是ROS处理数据的一种点对点的网络形式。程序运行时，所有进程以及他们所进行的数据处理，将会通过一种点对点的网络形式表现出来。计算图中的重要概念：节点(Node)、消息(message)、话题(topic)、服务(service)。

**节点(Node)**

节点就是一些直行运算任务的进程。ROS利用规模可增长的方式是代码模块化：一个系统就是典型的由很多节点组成的。在这里，节点也可以被称之为“软件模块”。我们使用“节点”使得基于ROS的系统在运行的时候更加形象化：当许多节点同时运行时，可以很方便的将端对端的通讯绘制成一个图表，在这个图表中，进程就是图中的节点，而端对端的连接关系就是其中弧线连接。

**消息(message)**

节点之间是通过传送消息进行通讯的。每一个消息都是一个严格的数据结构。原来标准的数据类型（整型，浮点型，布尔型等等）都是支持的，同时也支持原始数组类型。消息可以包含任意的嵌套结构和数组（很类似于C语言的结构structs）。

**话题(topic)**

![1365775624_5015](img/1365775624_5015-1698933677587-5.png)

消息以一种发布/订阅的方式传递。一个节点可以在一个给定的主题中发布消息。一个节点针对某个主题关注与订阅特定类型的数据。可能同时有多个节点发布或者订阅同一个主题的消息。总体上，发布者和订阅者不了解彼此的存在。

**服务(service)**

虽然基于话题的发布/订阅模型是很灵活的通讯模式，但是它广播式的路径规划对于可以简化节点设计的同步传输模式并不适合。在ROS中，我们称之为一个服务，用一个字符串和一对严格规范的消息定义：一个用于请求，一个用于回应。这类似于web服务器，web服务器是由URIs定义的，同时带有完整定义类型的请求和回复文档。需要注意的是，不像话题，只有一个节点可以以任意独有的名字广播一个服务：只有一个服务可以称之为“分类象征”，比如说，任意一个给出的URI地址只能有一个web服务器。

在上面概念的基础上，需要有一个控制器可以使所有节点有条不紊的执行，这就是一个ROS的控制器（ROS Master）。

ROS Master 通过RPC（Remote Procedure Call Protocol，远程过程调用）提供了登记列表和对其他计算图表的查找。没有控制器，节点将无法找到其他节点，交换消息或调用服务。

比如控制节点订阅和发布消息的模型如下：

![1365776033_9242](img/1365776033_9242-1698933687792-7.png)

ROS的控制器给ROS的节点存储了主题和服务的注册信息。节点与控制器通信从而报告它们的注册信息。当这些节点与控制器通信的时候，它们可以接收关于其他以注册及节点的信息并且建立与其它以注册节点之间的联系。当这些注册信息改变时控制器也会回馈这些节点，同时允许节点动态创建与新节点之间的连接。
节点与节点之间的连接是直接的，控制器仅仅提供了查询信息，就像一个DNS服务器。节点订阅一个主题将会要求建立一个与出版该主题的节点的连接，并且将会在同意连接协议的基础上建立该连接。

ROS控制器控制服务的模型如下：

![1365776154_8077](img/1365776154_8077-1698933700789-9.png)

#### 1.4.2.2 查看计算图

ROS 中提供了一个实用的工具 `rqt_graph` 可以查看ROS计算图。它能够创建一个显示当前系统运行情况的动态图形。使用以下命令启动（注意：首先要启动roscore）：

```bash
rosrun rqt_graph rqt_graph
或直接使用 rqt_graph 命令
```

利用ROS自带的小乌龟示例，我们可以看到如下计算图：

其中，圈起来的代表节点，带箭头的线代表话题发布流向。

![image-20231102222106418](img/image-20231102222106418.png)



# 二、ROS通讯机制

机器人是一种高度复杂的系统性实现，在机器人上可能集成各种传感器(雷达、摄像头、GPS...)以及运动控制实现，为了解耦合，在ROS中每一个功能点都是一个单独的进程，每一个进程都是独立运行的。更确切的讲，**ROS是进程（也称为Nodes）的分布式框架。** 因为这些进程甚至还可分布于不同主机，不同主机协同工作，从而分散计算压力。不过随之也有一个问题: 不同的进程是如何通信的？也即不同进程间如何实现数据交换的？在此我们就需要介绍一下ROS中的通信机制了。

ROS 中的基本通信机制主要有如下三种实现策略:

- 话题通信(发布订阅模式)
- 服务通信(请求响应模式)
- 参数服务器(参数共享模式)

## 2.1 话题通讯（Topic）

话题通信适用于不断更新数据、少逻辑处理的传输相关的应用场景。

### 2.2.1 话题通讯模型

话题是一种单向通讯方式，它通过发布和订阅的方式传递消息，该模型涉及到三个角色：

- Master (管理者)
- Publisher（发布者）
- Subscriber（订阅者）

**Master** 负责保管 **Publisher** 和 **Subscriber** 的注册信息，并匹配话题相同的 **Publisher** 和 **Subscriber** ，帮助 他们建立连接，连接建立后，**Publisher** 可以发布消息，且发布的消息会被 **Subscriber** 订阅。

![01话题通信模型](img/01话题通信模型.png)

话题模型通讯流程：

- **0）advertise：发布者注册**

​	发布者（Publisher）向管理者（Master）注册信息，包括RPC地址和Topic名字。Master会将发布者的注册信息加入到注册表中，并查询是否有该话题的订阅者。

- **1）subscribe：订阅者注册**

​	订阅者（Subscriber）向管理者（Master）注册信息，包括Topic名字。Master会将订阅者（Subscriber）的注册信息加入到注册表中，并查询是否有该话题的发布者。

- **2）Master匹配信息：牵线搭桥**

​	管理者（Master）通过查询注册表发现有匹配的发布者（Publisher）和订阅者（Subscriber），则向订阅者（Subscriber）发送发布者的RPC地址信息。

- **3）connect：订阅者请求连接发布者**

​	订阅者根据发布者的RPC地址，请求连接发布者（Publisher），并传输订阅的话题名称、消息类型以及通信协议(TCP/UDP)。

- **4）发布者确认请求**

    发布者（Publisher）收到请求后，通过RPC向订阅者确认连接信息，并发送自身的 TCP/UDP 地址信息。

- **5）建立连接**

​	订阅者根据发布者的TCP/UDP地址信息与订阅者建立TCP/UDP连接。

- **6）发送消息**

​	连接建立后，发布者开始向订阅者发布话题消息数据。

> Note：
>
> 1. 上述实现流程中，前五步使用 RPC 协议，最后两步使用 TCP/UDP 协议，默认TCP。
> 2.  发布者 与 订阅者 的启动无先后顺序要求。
> 3.  发布者 与 订阅者 都可以有多个。
> 4.  发布者 与 订阅者 连接建立后，不再需要 ROS Master。即便关闭 ROS Master，发布者 与 订阅者 照常通信。不过不会再有新的发布者 与 订阅者加入。



### 2.2.2 Topic Hello World

万物始于Hello World，同样，使用Hello World介绍Topic的简单使用。

使用Topic传输数据时，需要注意以下几点：

- Topic名称
- 消息格式
- 发布者实现
- 订阅者实现

接下来实现一个简单的 `Topic` 话题通信，发布者发布 `Hello Word n` （n代表递增数列）字符串，订阅者接收到后输出到屏幕。

#### 2.2.2.1 创建并初始化功能包

（这一步不是必须，这里只是为了方便清晰的说明，也可以使用已有的包，在包里新增节点等方法）

首先创建 `topic_hello_world` 包，命令如下：

```bash
catkin_creat_pkg topic_hello_world std_msgs roscpp rospy
```

创建后，文件结构如下：

![image-20231108230000306](img/image-20231108230000306.png)

#### 2.2.2.2 确定Topic名称及消息格式

Topic名称：/hello_world_topic

消息格式：std_msgs::String

消息文件路径：/opt/ros/noetic/share/std_msgs/msg/String.msg

消息文件内容：

```xml
string data
```

#### 2.2.2.3 实现发布者与订阅者（C++版）

在创建的 `topic_hello_world` 包路径下有一个 `src` 目录，在这里存储C++源码，我们创建 `topic_hello_world_pub.cpp` 以实现发布者，编辑内容如下：

```cpp
/*
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 发布者 对象
        5.组织被发布的数据，并编写逻辑发布数据
*/
// 1.包含头文件
#include "ros/ros.h"
#include "std_msgs/String.h" // std_msgs包自带的普通文本的消息类型
#include <sstream>

int main(int argc, char **argv)
{
    // 以下任意一句： 设置编码，解决ROS LOG打印中文乱码的问题
    // 但 rostopic echo 中文乱码的问题无法解决
    // setlocale(LC_ALL, ""); 
    setlocale(LC_CTYPE, "zh_CN.utf8");

    // 2.初始化 ROS 节点： 命名(唯一)
    // 参数1和参数2 后期为节点传值会使用
    // 参数3 是节点名称，是一个标识符，需要保证运行后，在 ROS 拓扑网络中唯一
    ros::init(argc, argv, "publisher");

    // 3.实例化 ROS 句柄
    // 该类封装了 ROS 中的一些常用功能
    ros::NodeHandle nh;

    // 4.实例化 发布者 对象，向ROS Master注册发布者
    // 泛型 std_msgs::String: 发布的消息类型
    // 参数1: 要发布到的话题名称
    // 参数2: 队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
    ros::Publisher pub = nh.advertise<std_msgs::String>("/hello_world_topic", 10);

    // 延时1s等待publisher在ROS Master注册成功后，再发布消息。
    // ros::Duration(1.0).sleep();
    // 目的同上，为了确保发布者注册成功再发布消息
    // 等待直到发布者成功注册到 ROS Master，并有订阅者订阅
    while (pub.getNumSubscribers() == 0)
    {
        if (!ros::ok())
        {
            // 如果节点被关闭，退出程序
            return 0;
        }
        ROS_INFO_ONCE("Waiting for subscribers to connect...");
        ros::Duration(1.0).sleep(); // 等待一秒钟
    }
    
    // 5.组织被发布的数据，并编写逻辑发布数据
    std_msgs::String msg;
    std::string msg_front = "Hello World "; // 消息前缀
    int count = 0;                          // 消息计数器

    // 运行loop的频率(1Hz: 一秒1次)
    ros::Rate r(1);

    // 让节点一直运行
    while (ros::ok())
    {
        // 拼接字符串与编号，并组装消息数据
        msg.data = msg_front + std::to_string(count);
        // 发布消息
        pub.publish(msg);
        // 打印发送的消息
        ROS_INFO("发送的消息: %s", msg.data.c_str());

        // 根据前面制定的发布频率自动休眠 休眠时间 = 1/频率 s；
        r.sleep();
        // 循环结束前，让 count 自增
        count++;
    }

    return 0;
}
```

创建 `topic_hello_world_sub.cpp` 以实现订阅者，编辑内容如下：

```cpp
/*
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 订阅者 对象
        5.处理订阅的消息(回调函数)
        6.设置循环调用回调函数
*/

// 1.包含头文件
#include "ros/ros.h"
#include "std_msgs/String.h"

// 5.处理订阅的消息(回调函数)
// topic回调函数，处理订阅的消息
void topicCallback(const std_msgs::String::ConstPtr &msg_p)
{
    ROS_INFO("收到的消息: %s", msg_p->data.c_str());
}

int main(int argc, char **argv)
{
    // 以下任意一句： 设置编码，解决ROS LOG打印中文乱码的问题
    // 但 rostopic echo 中文乱码的问题无法解决
    // setlocale(LC_ALL, ""); 
    setlocale(LC_CTYPE, "zh_CN.utf8");

    // 2.初始化 ROS 节点:命名(唯一)
    ros::init(argc, argv, "subscriber");

    // 3.实例化 ROS 句柄
    ros::NodeHandle nh;

    // 4.实例化 订阅者 对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("/hello_world_topic", 10, topicCallback);

    // 6.设置循环调用回调函数
    ros::spin(); // 循环读取接收的数据，并调用回调函数处理

    return 0;
}
```

修改 `CMakeLists.txt` ，只需添加如下内容：

```cmake
add_executable(${PROJECT_NAME}_pub src/topic_hello_world_pub.cpp)
add_executable(${PROJECT_NAME}_sub src/topic_hello_world_sub.cpp)
    
target_link_libraries(${PROJECT_NAME}_pub
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}_sub
  ${catkin_LIBRARIES}
)
```

**编译运行**

进入工作空间执行 `catkin_make` 命令编译工程，编译成功后，使用如下命令依次启动发布者和订阅者。

```bash
1. 启动ros master
roscore
2. 启动发布者
./devel/lib/topic_hello_world/topic_hello_world_pub
3. 启动订阅者
./devel/lib/topic_hello_world/topic_hello_world_sub
```

结果如下：

![image-20231110231909839](img/image-20231110231909839.png)

目前为止，**Topic Hello World** 已经成功了。

#### 2.2.2.4 实现发布者与订阅者（Python版）

在创建的 `topic_hello_world` 包路径下 `src` 目录的同级，创建一个 `scripts` 目录，在这里存储脚本（如python脚本），我们创建 `topic_hello_world_pub.py` 以实现发布者，编辑内容如下：

```python
#! /usr/bin python
"""
    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据
"""
# 1.导包
import rospy
from std_msgs.msg import String


def main():
    # 2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("publisher")

    # 3.实例化 发布者 对象
    pub = rospy.Publisher("/hello_world_topic", String, queue_size=10)
    # rospy.sleep(1)
    while pub.get_num_connections() == 0:
        if rospy.is_shutdown():
            return
        rospy.loginfo_once("Waiting for subscribers to connect...")
        rospy.sleep(1)

    # 4.组织要发布的数据，并编写逻辑发布数据
    msg = String()  # 创建 msg 对象
    msg_front = "Hello World "
    count = 0  # 计数器
    # 设置循环频率
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        # 拼接字符串
        msg.data = msg_front + str(count)
        pub.publish(msg)
        rate.sleep()
        rospy.loginfo("发送的消息: %s", msg.data)
        count += 1


if __name__ == "__main__":
    main()
```

在`scrips`中创建 `topic_hello_world_sub.py` 以实现订阅者，编辑内容如下：

```python
#! /usr/bin python
"""
    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 订阅者 对象
        4.处理订阅的消息(回调函数)
        5.设置循环调用回调函数
"""
# 1.导包
import rospy
from std_msgs.msg import String


# 4.处理订阅的消息(回调函数)
def topicCallback(msg):
    rospy.loginfo("收到的消息: %s", msg.data)


def main():
    # 2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("subscriber")

    # 3.实例化 订阅者 对象
    sub = rospy.Subscriber("/hello_world_topic", String, topicCallback, queue_size=10)

    # 5.设置循环调用回调函数
    rospy.spin()


if __name__ == "__main__":
    main()
```

修改 `CMakeLists.txt` ，只需添加如下内容：

```cmake
catkin_install_python(PROGRAMS
  scripts/topic_hello_world_pub.py
  scripts/topic_hello_world_sub.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
```

**编译运行**

进入工作空间执行 `catkin_make` 命令编译工程，编译成功后，使用如下命令依次启动发布者和订阅者。

```bash
1. 启动ros master(如果已启动，无需再启动)
roscore
2. 启动发布者
python ./devel/lib/topic_hello_world/topic_hello_world_pub.py
3. 启动订阅者
python ./devel/lib/topic_hello_world/topic_hello_world_pub.py
```

结果如下：

![image-20231111141651883](img/image-20231111141651883.png)



#### 2.2.2.5 关于Topic Hello World的注意

启动发布者与订阅者时建议用如下命令：（上述命令只是给初学者的）：

```bash
启动发布者
rosrun topic_hello_world topic_hello_world_pub （C++版）
rosrun topic_hello_world topic_hello_world_pub.py （Python版）
启动订阅者
rosrun topic_hello_world topic_hello_world_sub （C++版）
rosrun topic_hello_world topic_hello_world_sub.py （Python版）
```

其中，`rosrun` 是执行ROS可执行文件的命令，`topic_hello_world`是功能包的名称，`topic_hello_world_pub`是该功能包下可执行文件（如节点）的名称。

如果你遇到如下错误：

![image-20231110221417114](img/image-20231110221417114.png)

那么可能你没有把工作空间的路径加到终端环境变量中，听起看来是不是很晕，不要急，`catkin` 为我们提供了一个脚本可以做这件事，它位于工作空间下的 `devel` 目录中，有如下三个脚本：

```bash
setup.bash 
setup.zsh
setup.sh
```

其中，

- **setup.sh：**是一个**Shell**脚本，用于设置ROS软件包的环境变量。当你使用`source devel/setup.sh`命令时，它会将当前工作空间的路径添加到`ROS_PACKAGE_PATH`中，并设置其他与ROS运行时相关的环境变量，如：将当前工作空间的 `bin`, `lib`, `include` 和 `share` 文件夹添加到终端环境的 `PATH`, `LD_LIBRARY_PATH`, `CMAKE_PREFIX_PATH` 和 `PYTHONPATH` 变量中。这样，在执行 ROS 命令和使用 ROS 相关库时，终端将能够找到和访问这些文件夹中的内容。
- **setup.bash：**一个**Bash**脚本，用于设置ROS软件包的环境变量。他调用了 `setup.sh`。
- **setup.zsh：**是一个**Zsh**脚本，类似于`setup.bash`，用于设置ROS软件包的环境变量。他调用了 `setup.sh`。

根据你使用的shell类型运行相应的脚本，我们一般把脚本加到终端配置文件中，以**bash**为例：

1. 编辑`~/.bashrc`文件，将`source <setup.bash_abs_path>`添加到文件中，一般添加到末尾，其中`<setup.bash_path>`代表`setup.bash`文件的绝对路径。
2. 执行 `source ~/.bashrc` 使修改生效。

至此，再执行 `rosrun topic_hello_world topic_hello_world_pub` 就不会报错了。



### 拓展1：devel下其他文件与目录的作用

![image-20231110235612869](img/image-20231110235612869.png)

1. **cmake.lock**: 一个用于记录构建过程中的锁文件。它包含有关构建状态和依赖项的信息，用于锁定CMake的缓存信息。当CMake在构建过程中遇到相同的输入时，它会使用这个文件来避免重复编译。
2. **lib**: 包含编译生成的库文件。ROS软件包中的节点或其他模块编译后生成的库文件通常会存放在这个目录下。
3. **local_setup.zsh**: 一个Zsh脚本，用于设置当前终端会话的环境变量，使其能够识别和运行与ROS相关的程序和软件包。
4. **_setup_util.py**: 一个Python脚本，用于设置ROS软件包的环境变量。这个脚本被`setup.sh`调用。
5. **env.sh**: 一个用于设置环境变量的脚本。当你希望手动设置ROS软件包的环境变量时，可以使用这个脚本。
6. **local_setup.bash**: 一个Bash脚本，用于设置当前终端会话的环境变量，使其能够识别和运行与ROS相关的程序和软件包。
7. **include**: 包含头文件。在编译时，一些头文件可能会被拷贝到这个目录下，以便在其他ROS软件包中使用。
8. **local_setup.sh**: 一个Shell脚本，用于设置当前终端会话的环境变量，使其能够识别和运行与ROS相关的程序和软件包。
9. **share**: 包含共享的数据文件、配置文件和其他资源。这些资源可以被其他软件包或节点访问和使用。可能包含ROS软件包的配置文件、启动文件、参数设置等共享资源。



### 拓展2：build 目录下各文件与目录的作用

1. **atomic_configure**: 包含构建配置的原子配置文件，用于确保配置的原子性。这个文件可能包含一些构建系统的配置信息。
2. **bin**: 包含构建生成的可执行文件。ROS软件包中的节点或其他二进制文件通常会存放在这个目录下。
3. **catkin**: 包含Catkin构建系统的一些生成文件和配置信息。
4. **catkin_generated**: 包含由Catkin工具生成的文件。这个目录包含一些与Catkin相关的中间文件和构建信息。
5. **CATKIN_IGNORE**: 一个标记文件，用于指示Catkin在构建过程中忽略此目录。这对于排除特定目录或文件不参与构建是很有用的。
6. **gtest**: Google Test（gtest）的相关文件和构建信息。gtest是一个用于C++单元测试的测试框架。
7. **test_results**: 包含测试运行的结果。当运行`catkin_make run_tests`时，测试框架会将测试结果输出到这个目录。
8. **catkin_make.cache**: 一个Catkin缓存文件，包含构建系统的一些缓存信息，以提高构建效率。
9. **CMakeCache.txt**: 由CMake生成，包含有关CMake配置的缓存信息。这个文件记录了CMake变量的当前值，以及一些配置选项。
10. **Makefile**: 由CMake生成，用于执行实际的编译和构建操作。
11. **CMakeFiles**: 包含由CMake生成的中间文件。这些文件包括用于构建过程中生成的临时对象文件、编译器输出等。
12. **cmake_install.cmake**: 由CMake生成，包含用于将文件安装到指定目录的指令。
13. **CTestConfiguration.ini**: 用于配置CTest（CMake的测试工具）的配置文件。
14. **CTestCustom.cmake**: CTest的自定义配置文件，其中可以包含一些用户自定义的测试配置选项。
15. **CTestTestfile.cmake**: CTest的测试文件配置，用于指定要运行的测试用例。
16. **my_pkg**: 这个名字是你的功能包的名字，可能有多个，即ROS功能包的构建目录，其中包含了编译生成的中间文件、目标文件以及其他与构建过程相关的信息。

这些文件和目录是构建和测试过程中的临时文件和配置文件，它们会在ROS工作空间的生命周期内动态生成和修改。



### 2.2.3 自定义msg

















## 关于ROS的网络通讯方式TCP/UDP

### TCP与UDP

TCP/IP协议族为传输层指明了两个协议：TCP和UDP，它们都是作为应同程序和网络操作的中介物。

**TCP（Transmission Control Protocol）协议全称是传输控制协议，是一种面向连接的、可靠的、基于字节流的传输层通信协议，由IETF的RFC793定义。**TCP是面向连接的、可靠的流协议，提供超时重发，丢弃重复数据，检验数据，流量控制等功能，保证数据能从一端传到另一端。

TCP传输数据稳定可靠，适用于对网络通讯质量要求较高的场景，需要准确无误的传输给对方，比如，传输文件，发送邮件，浏览网页等等。在传输数据前，双方会先建立一条虚拟的通道，可以减少数据传输差错。

传输流程类似下图：

![01fbaa31de51e304fe54d418df4fa1](img/01fbaa31de51e304fe54d418df4fa1.png)

**UDP（User Datagram Protocol）协议全称是用户数据报协议，在网络中它与TCP协议一样用于处理数据包，是一种无连接的协议。**位于OSI模型中第四层——传输层，处于IP协议的上一层。UDP有不提供数据包分组、组装和不能对数据包进行排序的缺点。由于UDP在传输数据报前不用在客户和服务器之间建立一个连接，且没有超时重发等机制，故而传输速度很快。

UDP的优点是速度快，但是可能产生丢包，所以适用于对实时性要求较高但是对少量丢包并没有太大要求的场景。比如：域名查询，语音通话，视频直播等。在数据传输时，每个数据段都是一个独立的信息，包括完整的源地址和目的地，因此，数据能否被对方接收、数据到达的实践和内容的完整性有序性都无法得到保证。

传输流程类似下图：

![01fbaa31de51e304fe54d418dc1f4fa1](img/01fbaa31de51e304fe54d418dc1f4fa1.png)

UDP协议就相当于是写信给对方，寄出去信件之后不能知道对方是否收到信件，信件内容是否完整，也不能得到及时反馈，而TCP协议就像是打电话，你需要知道对方的号码才能打电话，交流的内容可以实时反馈，确保信息的完整性。

两者对比：

|          TCP           |            UDP             |
| :--------------------: | :------------------------: |
|        面向连接        |         面向无连接         |
|                        |       程序结构较简单       |
|       面向字节流       |         基于数据报         |
|      保证数据顺序      |       不保证数据顺序       |
|                        |          速度很快          |
| 可以检查错误与纠正错误 | 可以检查错误，不可纠正错误 |

总结，UDP更快，更简单，更高效，因此通常用于发送音频和视频文件。TCP是健壮的，可靠的，并保证以相同的顺序传递数据包。



### ROS的网络通讯方式

ROS提供了两种网络通讯方式，一种是`TCP`协议，一种是`UDP`协议。默认采用TCP进行通讯，但在实际的wifi网络使用中经常遇到客户端和机器人连接中断且无法重新建立连接的情况。在ROS wiki中官方也有说明，`ROSTCP`更适合有线网连接的网络，而`ROSUDP`更适合wifi等网络不可靠的无线网络。下面介绍一下如何在ROS中使用UDP连接。

**首先，rospy不支持udp连接，** 所以要实现ROSUDP必须是用`roscpp`写的，然后在订阅的时候添加 `ros::TransportHints` 指定连接方式。如下面的代码：

```cpp
#include <ros/ros.h>
#include <std_msgs/String.h>

void print_message(const std_msgs::String data)
{
    ROS_INFO_STREAM("received: " << data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "udp_test_node");
    ros::AsyncSpinner spinner(4);
    spinner.start();
    ros::NodeHandle private_nh("~");
    ros::Subscriber chatter_sub = private_nh.subscribe("/chatter", 10, print_message,                 			ros::TransportHints().unreliable().maxDatagramSize(1000));
    while (ros::ok())
    {
        sleep(1);
    }
}
```

其中 `unreliable` 用于指定采用udp连接。详细例子可以参照 [这个](https://github.com/BluewhaleRobot/udp_test) 项目。







## 一、Topic

### 1.1 常用函数接口

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

#### rostopic相关

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



##### 1.2.1 rostopic bw

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



##### 1.2.2 rostopic delay

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



##### 1.2.3 rostopic echo

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



###### rostopic echo --offset

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



###### rostopic echo --filter

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



###### rostopic echo -c

打印每条消息前清除屏幕，不能与 `-p` 一起使用。

```bash
rostopic echo -c /topic_name
```



###### rostopic echo -b

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



###### rostopic echo -p

以 matlab/octave 友好的格式显示消息。不能与 `-c` 一起使用。

```
rostopic echo -p /topic_name
```

![Screenshot from 2022-04-25 22-25-13](img/Screenshot%20from%202022-04-25%2022-25-13.png)

其中，以`%`开头的第一行是标题，按顺序对应每行以 `,` 隔开的变量名。

`rostopic echo -p` 还有两个参数选项，`--nostr ` 和 `--noarr` ，分别代表 `忽略字符串` 和 `忽略数组` 

![Screenshot from 2022-04-25 22-33-24](img/Screenshot%20from%202022-04-25%2022-33-24.png)

使用 `--nostr` 参数选项后，忽略掉了字符串类型的 `frame_id` 和 `data` 。



###### rostopic echo -w

以固定宽度 `NUM_WIDTH` 打印所有数值，如果 `NUM_WIDTH` 小于实际宽度，则以实际宽度打印。

```bash
rostopic echo -w NUM_WIDTH /topic_name
```

![Screenshot from 2022-04-25 23-11-23](img/Screenshot%20from%202022-04-25%2023-11-23.png)

每个数字的宽度为13，实际宽度不足13的，在数字前面补空格。

符合python的 `%` 占位符规则，具体可查询 `python % 占位符` 。



###### rostopic echo -n

打印接收到的 `COUNT` 条消息并退出。

```bash
rostopic echo -n COUNT /topic_name
```

![Screenshot from 2022-04-25 23-16-09](img/Screenshot%20from%202022-04-25%2023-16-09.png)



##### 1.2.4 rostopic find

```bash
rostopic find <msg-type>
rostopic find rosgraph_msgs/Log
```

按照 `topic` 的消息类型查找运行的 `topic`。

![Screenshot from 2022-04-26 22-55-28](img/Screenshot%20from%202022-04-26%2022-55-28.png)



##### 1.2.5 rostopic hz

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



###### rostopic hz -w

使用窗口大小（样本数）报告速率，以对速率进行时间局部估计。

如不使用 `-w` 选项，报告的平均速率时从开始通信以来所有通信的平均速率，如使用 `-w` 则为最近 `WINDOW_SIZE` 次通信的平均速率。

```bash
 rostopic hz -w WINDOW_SIZE /topic_name
```

![Screenshot from 2022-04-26 23-40-50](img/Screenshot%20from%202022-04-26%2023-40-50.png)



###### rostopic hz --filter

仅报告指定python语法的逻辑表达式匹配的消息的速率。

逻辑表达式的使用规则同 `rostopic echo --filter`

此选项对性能有很大影响，不应用于高速率主题。

```
rostopic hz --filter FILTER_EXPR /topic_name
```

![Screenshot from 2022-04-26 23-48-00](img/Screenshot%20from%202022-04-26%2023-48-00.png)



##### 1.2.6 rostopic info

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



##### 1.2.7 rostopic list

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



###### rostopic list \<namespace\>

列出指定命名空间中的topic，关于ROS的命名空间，见 [ROS WiKi/Names/Graph Resource Names](http://wiki.ros.org/ROS/Concepts#Names.Names)

```bash
rostopic list /up
```

![Screenshot from 2022-04-30 17-15-56](img/Screenshot%20from%202022-04-30%2017-15-56.png)



###### rostopic list -b <bag_file>

列出bag文件中的topic

```bash
rostopic list -b all.bag
```

![Screenshot from 2022-04-30 17-47-31](img/Screenshot%20from%202022-04-30%2017-47-31.png)



###### rostopic list -p

只列出有发布者的topic

```bash
rostopic list -p
```

###### rostopic list -s

只列出有订阅者的topic

```bash
rostopic list -s
```

![Screenshot from 2022-04-30 17-54-54](img/Screenshot%20from%202022-04-30%2017-54-54.png)



###### rostopic list -v

列出所有topic的详细信息

```
rostopic list -v
```

![Screenshot from 2022-04-30 17-58-24](img/Screenshot%20from%202022-04-30%2017-58-24.png)

其中包括topic的属性(发布者/订阅者)、topic名、topic消息类型(方括号里的)、该topic发布者/订阅者的数量。



###### rostopic list --host

按主机名分组列表

```bash
rostopic list --host
```

![Screenshot from 2022-04-30 19-58-32](img/Screenshot%20from%202022-04-30%2019-58-32.png)

其中，方括号里是主机名。



##### 1.2.8 rostopic pub

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

###### rostopic pub -l/--latch

`-l`和`--latch`是一样的，代表`latching mode`

![Screenshot from 2022-05-02 22-00-02](img/Screenshot%20from%202022-05-02%2022-00-02.png)

发布者发布一次消息，并将最后一条消息保存等待，直到有新的订阅者连接，把保存的消息发给新的订阅者（每个新订阅者收到的都是这条保存的消息）



###### rostopic pub -r RATE

`rate mode`，`RATE`的单位是`Hz`。

![Screenshot from 2022-05-02 22-00-53](img/Screenshot%20from%202022-05-02%2022-00-53.png)

发布者按`10Hz`的频率不停发布消息，订阅者一直接收消息。



###### rostopic pub -1/--once

`-1`(注意是数字1) 和 `--once` 是一样的，代表`once mode`



###### rostopic pub -f FILE

通过YAML文件输入



##### 1.2.9 rostopic type

显示topic的消息类型

```bash
rostopic type <topic-name>
rostopic type /topic_name
```

![Screenshot from 2022-05-02 22-24-45](img/Screenshot%20from%202022-05-02%2022-24-45.png)



#### rosmsg 相关

```bash
rosmsg show 显示消息格式内容
rosmsg list 显示消息列表
rosmsg package 显示指定包中的所有消息列表
rosmsg packages 显示所有带有消息的包的列表
rosmsg md5 显示指定消息类型的 md5 总和
```



##### 1.2.10 rosmsg show

```bash
rosmsg show <message type>
rosmsg show std_msgs/String
```

显示 ROS 消息类型中的字段。

![Screenshot from 2022-06-12 20-03-27](img/Screenshot%20from%202022-06-12%2020-03-27.png)

如果不知道包名称，也可以只写消息类型，该命令会在所有包中匹配：

![Screenshot from 2022-06-12 20-11-50](img/Screenshot%20from%202022-06-12%2020-11-50.png)

**-r 选项**

显示消息原始文件中的所有内容，包括注释。

```bash
rosmsg show -r <message-type>
```

![Screenshot from 2022-06-12 20-21-41](img/Screenshot%20from%202022-06-12%2020-21-41.png)

##### 1.2.11 rosmsg list

显示所有消息列表

```
rosmsg list
```

![Screenshot from 2022-06-12 20-43-54](img/Screenshot%20from%202022-06-12%2020-43-54.png)

##### 1.2.12 rosmsg package

显示指定包中的所有消息列表

```bash
rosmsg package <package-name> 
rosmsg package mbot_communication
```

![Screenshot from 2022-06-17 22-15-15](img/Screenshot%20from%202022-06-17%2022-15-15.png)

-r选项

将消息列表显示在一行

```bash
rosmsg package mbot_communication -s
```

![Screenshot from 2022-06-17 22-31-28](img/Screenshot%20from%202022-06-17%2022-31-28.png)



##### 1.2.13 rosmsg packages

显示所有带有消息的包的列表。

```bash
rosmsg packages
```

![Screenshot from 2022-06-17 22-36-42](img/Screenshot%20from%202022-06-17%2022-36-42.png)

-r选项

将包列表显示在一行

```bash
rosmsg packages -s
```

![Screenshot from 2022-06-17 22-42-26](img/Screenshot%20from%202022-06-17%2022-42-26.png)



##### 1.2.14 rosmsg md5

显示指定消息类型的 md5 总和。如果编译的版本不匹配，会发出警告。

```bash
rosmsg md5 <message-type>
rosmsg md5 String
```

![Screenshot from 2022-06-17 22-50-49](img/Screenshot%20from%202022-06-17%2022-50-49.png)



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

#### rosservice

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



##### 2.2.1 rosservice call

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



##### 2.2.2 rosservice find

```bash
rosservice find <service-type>
rosservice find rospy_tutorials/AddTwoInts
```

按照特定的消息类型查找已发布的 `service`。

![Screenshot from 2022-06-03 21-42-12](img/Screenshot%20from%202022-06-03%2021-42-12.png)



##### 2.2.3 rosservice list

```bash
rosservice list
```

列出当前所有活跃的service

![Screenshot from 2022-06-05 13-58-20](img/Screenshot%20from%202022-06-05%2013-58-20.png)



```bash
rosservice list <namespace>
```

列出指定名空间下当前所有活跃的service

![Screenshot from 2022-06-05 14-00-43](img/Screenshot%20from%202022-06-05%2014-00-43.png)



```bash
-n选项：同时打印服务所在节点的名称
rosservice list -n
rosservice list <namespace> -n
```

![Screenshot from 2022-06-05 14-05-27](img/Screenshot%20from%202022-06-05%2014-05-27.png)

前面是服务名，后面是节点名。



##### 2.2.4 rosservice node

```bash
rosservice node <service-name>
rosservice node /add_two_ints 
```

![Screenshot from 2022-06-05 14-30-44](img/Screenshot%20from%202022-06-05%2014-30-44.png)



##### 2.2.5 rosservice uri

```bash
rosservice uri <service-name>
rosservice uri /add_two_ints 
```

打印服务的ROSRPC uri

![Screenshot from 2022-06-05 14-25-09](img/Screenshot%20from%202022-06-05%2014-25-09.png)



##### 2.2.6 rosservice type

```bash
rosservice type <service-name>
rosservice type /add_two_ints 
```

打印指定service的消息类型

![Screenshot from 2022-06-05 14-21-10](img/Screenshot%20from%202022-06-05%2014-21-10.png)



##### 2.2.7 rosservice args

```bash
rosservice args <service-name>
rosservice args /service_name
```

打印服务的参数列表，没有参数则没有打印

![Screenshot from 2022-06-03 15-21-02](img/Screenshot%20from%202022-06-03%2015-21-02.png)



##### 2.2.8 rosservice info

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



#### rossrv 相关

rossrv和rosmsg的用法完全相同，具体对照rosmsg

```bash
rossrv show 显示服务格式内容
rossrv list 显示服务列表
rossrv package 显示指定包中的所有服务列表
rossrv packages 显示所有带有服务的包的列表
rossrv md5 显示指定服务类型的 md5 总和
```









































 
