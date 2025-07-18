ROSLearning

# 一、ROS概览

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

在搜索框输入`software`，选择`Software & Updates`(紫色的那个)，勾选 `main`、`universe`、`restricted` 和 `multiverse`，然后在`Downlosd from`选择一个中国的服务器，我选的阿里的源，然后点 `Close` 关闭就行了。

![image-20240406165016593](img/image-20240406165016593.png)



![image-20240406165322878](img/image-20240406165322878.png)



#### 1.2.3.2 添加源

如果网速快，可以直接用官方源，打开terminal输入以下命令：

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

ROS有好几个安装模式，包含的功能有多有少，我选择的桌面完整版。
```bash
sudo apt install ros-noetic-desktop-full
```
更多安装模式如下：

##### 5.1 桌面版

仅包含ROS基础功能、机器人通用函数库、rqt工具箱和rviz可视化工具。

```bash
sudo apt install ros-noetic-desktop
```
##### 5.2 基础版

精简了机器人通用函数库、功能包和工具，仅保留了没有界面的基础功能（核心功能包、构建工具和通信机制），可以看作是ROS的最小系统，适合安装在对性能和空间要求较高的控制器上，比如嵌入式系统。

```bash
sudo apt install ros-noetic-ros-base
```
##### 5.3 独立功能包安装

由于不可能一次性把所有功能包都安装，当后期需要某些功能包时，可以使用如下命名单独安装：

```bash
sudo apt install ros-noetic-PACKAGE
```
其中，`PACKAGE` 是功能包名称。

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

![image-20240406165621521](img/image-20240406165621521.png)



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

```bash
# 1.进入src目录
cd ros_learning/src
# 2.初始化工作空间
catkin_init_workspace
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

其中，`rospy.init_node` 用于初始化节点，函数原型如下：

```Python
init_node(name, argv=None, anonymous=False, log_level=None, disable_rostime=False, disable_rosout=False, disable_signals=False, xmlrpc_port=0, tcpros_port=0)
```

其中，各参数说明如下：

- `name`：节点名字，type：str
- `argv`：命令行入参，type：str
- `anonymous`：以`name`为词干，为节点自动生成名字（True），type：bool
- `log_level`：设置日志等级（rospy.DEBUG, rospy.INFO, rospy.ERROR, rospy.WARN, rospy.FATAL），type：int
- `disable_rostime`：取消自动订阅rostime（True）（仅用于内部测试），type：bool
- `disable_rosout`：取消自动发布rosout（True）（仅用于内部测试），type：bool
- `disable_signals`：取消信号处理程序（True）。如果 `roslib.is_interactive()`为 True，则 `disable_signals` 强制为True。type：bool
- `xmlrpc_port`：设置xmlrpc的端口号。type：int
- `tcpros_port`：如果提供，TCPROS服务器将侦听此端口上的连接。type：int



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
- universe：全球范围的代码，由不同国家的ROS社区组织开发和维护。一种是库的代码，如OpenCV、PCL等；库的上一层是从功能角度提供的代码，如人脸识别，他们调用下层的库；最上层的代码是应用级的代码，让机器人完成某一确定的功能。

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

节点就是一些执行运算任务的进程。ROS利用规模可增长的方式是代码模块化：一个系统就是典型的由很多节点组成的。在这里，节点也可以被称之为“软件模块”。我们使用“节点”使得基于ROS的系统在运行的时候更加形象化：当许多节点同时运行时，可以很方便的将端对端的通讯绘制成一个图表，在这个图表中，进程就是图中的节点，而端对端的连接关系就是其中弧线连接。

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

ROS的控制器给ROS的节点存储了主题和服务的注册信息。节点与控制器通信从而报告它们的注册信息。当这些节点与控制器通信的时候，它们可以接收关于其他以注册及节点的信息并且建立与其它已注册节点之间的联系。当这些注册信息改变时控制器也会回馈这些节点，同时允许节点动态创建与新节点之间的连接。
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

### 2.1.1 话题通讯模型

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



### 2.1.2 Topic Hello World

万物始于Hello World，同样，使用Hello World介绍Topic的简单使用。

使用Topic传输数据时，需要注意以下几点：

- Topic名称
- 消息格式
- 发布者实现
- 订阅者实现

接下来实现一个简单的 `Topic` 话题通信，发布者发布 `Hello Word n` （n代表递增数列）字符串，订阅者接收到后输出到屏幕。

#### 2.1.2.1 创建并初始化功能包

（这一步不是必须，这里只是为了方便清晰的说明，也可以使用已有的包，在包里新增节点等方法）

首先创建 `topic_hello_world` 包，命令如下：

```bash
catkin_create_pkg topic_hello_world std_msgs roscpp rospy
```

创建后，文件结构如下：

![image-20231108230000306](img/image-20231108230000306.png)

#### 2.1.2.2 确定Topic名称及消息格式

Topic名称：/hello_world_topic

消息格式：std_msgs::String

消息文件路径：/opt/ros/noetic/share/std_msgs/msg/String.msg

消息文件内容：

```xml
string data
```

#### 2.1.2.3 实现发布者与订阅者（C++版）

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
    // 参数3 是注册到master的节点名称，是一个标识符，需要保证运行后，在 ROS 拓扑网络中唯一
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

#### 2.1.2.4 实现发布者与订阅者（Python版）

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



#### 2.1.2.5 关于Topic Hello World的注意

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



#### 拓展1：devel下其他文件与目录的作用

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



#### 拓展2：build 目录下各文件与目录的作用

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



### 2.1.3 自定义msg

在 ROS 通信协议中，数据是以约定好的结构传输的，即数据类型，比如Topic使用的msg，Service使用的srv，ROS 中的 std_msgs 封装了一些原生的数据类型，比如：Bool、Char、Float32、Int64、String等，但这些类型结构简单，常常不能满足我们的需要，这时我们可以使用自定义的消息类型。

比如我们创建一个自定义消息，定义一个机器人的ID，位置（x, y）。

#### 2.1.3.1 创建RobotPose.msg

我们仍然使用前文创建的 `topic_hello_world` 功能包，结构如下：

![image-20231108230000306](img/image-20231108230000306.png)

在`src`的同级目录创建 `msg` 目录，在`msg`目录创建 `RobotPose.msg` 文件，内容如下：

```xml
string id
float64 x
float64 y
float64 angle
```

#### 2.1.3.2 配置编译文件

需要对 `CMakeLists.txt` 作以下修改：

**1. 添加message_generation功能包**

`message_generation`功能包，在**构建时**根据`msg`和`srv`生成消息和服务的接口文件（比如C++头文件和Python包），以便在 ROS 节点中使用。

```cmake
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)
```

注意这里需要同时在`package.xml`中添加以下内容：

```xml
<build_depend>message_generation</build_depend>
```

**2. 添加msg文件**

添加自定义`msg`，该函数依赖`message_generation`功能包。

```cmake
add_message_files(
  FILES
  RobotPose.msg
)
```

**3. 配置依赖并生成接口文件**

添加处理`msg`或`srv`所需要的依赖，并生成接口文件，该函数依赖`message_generation`功能包。

```cmake
generate_messages(
  DEPENDENCIES
  std_msgs
)
```

**4 . 添加message_runtime依赖**

`message_runtime` 用于在运行时提供消息的序列化和反序列化支持。

这里注意，有时可能会看到没有显式添加 `message_runtime` 也能正常运行，这通常是因为其他依赖项（例如`roscpp` 或 `std_msgs`）可能已经隐含地包含了 `message_runtime`。在这种情况下，构建系统已经处理了消息生成的任务。

然而，为了确保你的软件包在所有情况下都能正常工作，最好显式添加 `message_runtime` 作为你的软件包的依赖项。这样可以确保你的消息定义在构建和运行时得到正确处理。

需要对 `CMakeLists.txt` 作以下修改：

```cmake
catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)
```

同时在`package.xml`中添加以下内容：

```xml
<exec_depend>message_runtime</exec_depend>
```

**节外生枝的小知识：**

> `catkin_package` 是在ROS软件包的 `CMakeLists.txt` 文件中用于配置Catkin软件包的一条命令。它主要用于描述ROS软件包的元信息，并在构建系统中定义软件包的依赖关系。以下是 `catkin_package` 的一般用途：
>
> 1. **软件包元信息配置：** `catkin_package` 允许你指定软件包的元信息，例如软件包的名称、版本、作者、描述等。这些信息将用于标识和描述你的ROS软件包。
>
>     ```
>    cmakeCopy codecatkin_package(
>       NAME your_package_name
>       VERSION 0.1.0
>       DESCRIPTION "Your package description"
>       AUTHOR "Your Name"
>     )
>    ```
> 
> 2. **设置软件包的依赖项：** `catkin_package` 允许你指定你的软件包依赖于其他ROS软件包的哪些部分。这些依赖项将在构建和运行时被解析和满足。
>
>     ```
>    cmakeCopy codecatkin_package(
>       ...
>       CATKIN_DEPENDS roscpp std_msgs message_runtime
>     )
>    ```
> 
> 3. **导出软件包的目标：** 通过 `${PROJECT_NAME}_EXPORTED_TARGETS` 这样的参数，你可以导出软件包的目标，以便其他软件包能够正确地依赖你的软件包，并包含所有必要的目标。
>
>     ```
>    cmakeCopy codecatkin_package(
>       ...
>       EXPORTED_TARGETS ${PROJECT_NAME}_EXPORTED_TARGETS
>     )
>    ```
> 
> 总体而言，`catkin_package` 提供了一个中心化的地方，用于指定ROS软件包的基本信息和配置，以便构建系统和其他软件包能够正确地使用和依赖你的软件包。在ROS中，它是配置软件包最重要的命令之一。

#### 2.1.3.3 实现发布者与订阅者（C++版）

在创建的 `topic_hello_world` 包路径的 `src` 目录中创建 `user_msg_pub.cpp` 以实现发布者，编辑内容如下：

```cpp
#include <ros/ros.h>
#include "topic_hello_world/RobotPose.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "user_msg_pub");
    ros::NodeHandle nh;

    ros::Publisher pose_pub = nh.advertise<topic_hello_world::RobotPose>("/robot_pose", 10);

    topic_hello_world::RobotPose pose;
    pose.id = "vbot";
    pose.x = 23.6;
    pose.y = 12.8;
    pose.angle = 90.0;

    while(ros::ok())
    {
        pose_pub.publish(pose);
        ROS_INFO("Pub robot: %s, pose(%lf, %lf, %lf)", pose.id.c_str(), pose.x, pose.y, pose.angle);
        ros::Duration(1).sleep();
        ros::spinOnce();
    }

    return 0;
}
```

创建 `user_msg_sub.cpp` 以实现订阅者，编辑内容如下：

```cpp
#include <ros/ros.h>
#include "topic_hello_world/RobotPose.h"

void robotPoseCallback(const topic_hello_world::RobotPose::ConstPtr &pose)
{
    ROS_INFO("Sub robot: %s, pose(%lf, %lf, %lf)", pose->id.c_str(), pose->x, pose->y, pose->angle);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "user_msg_sub");
    ros::NodeHandle nh;
    ros::Subscriber pose_sub = nh.subscribe<topic_hello_world::RobotPose>("/robot_pose", 10, robotPoseCallback);

    ros::spin();

    return 0;
}
```

修改 `CMakeLists.txt` ，只需添加如下内容：

```cmake
add_executable(${PROJECT_NAME}_user_msg_pub src/user_msg_pub.cpp)
add_executable(${PROJECT_NAME}_user_msg_sub src/user_msg_sub.cpp)
    
target_link_libraries(${PROJECT_NAME}_user_msg_pub
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}_user_msg_sub
  ${catkin_LIBRARIES}
)
```

**编译运行**

进入工作空间执行 `catkin_make` 命令编译工程，你可能会遇到如下错误：

![image-20231113221306577](img/image-20231113221306577.png)

这是因为上文提到的`message_generation`功能包，在它编译自定义msg生成对应接口文件之前，编译了c++源文件，但这时头文件`RobotPose.h`还没有生成，所以报错了。

到这里你有没有发现，如果各功能包间有依赖关系，他们的编译是有先后顺序的，那我们怎么控制这个先后顺序呢？答案是：不需要。哈哈，CMake已经替我们做了，我们只需告诉它哪个模块需要什么依赖，CMake内部会自动分析项目中的依赖关系，并根据这些依赖关系计算一个拓扑排序。然后，CMake会按照这个顺序处理各个功能包，以确保在构建过程中满足所有依赖关系。

我们可以在 `CMakeLists.txt`中使用 `add_dependencies()` 来添加这个依赖关系，语法如下：

```cmake
add_dependencies(target_name dependency_target_name)
```

其中，`target_name` 是要添加依赖关系的目标名称，`dependency_target_name` 是要添加的依赖目标名称。

例如，如果你有一个名为 `my_node` 的目标，你想要添加一个名为 `my_dependency` 的库作为其依赖项，可以使用以下命令：

```cmake
add_dependencies(my_node my_dependency)
```

**所以，为解决上述报错，我们在 `topic_hello_world/CMakeLists.txt`中添加如下内容：**

```cmake
# 注意他们要放在add_executable之后，即先告诉CMake是哪个节点，再告诉CMake它需要什么依赖
add_dependencies(${PROJECT_NAME}_user_msg_pub ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(${PROJECT_NAME}_user_msg_sub ${PROJECT_NAME}_generate_messages_cpp)
```

其中，第一项是我们生成的节点，第二项 `${PROJECT_NAME}_generate_messages_cpp` 是一个用于生成消息类型的C++文件的宏，它的作用是根据 `.msg` 和 `.srv` 文件生成对应的 `.h` 和 `.cpp` 文件。

**节外生枝的小知识：**

> 在ROS软件包的构建过程中，除了`${PROJECT_NAME}_generate_messages_cpp`，还有一些其他与消息生成和编译相关的宏。这些宏通常都是与 Catkin 工具链和 ROS 构建系统的一部分。
>
> 以下是一些常见的与消息生成相关的宏：
>
> 1. **`${PROJECT_NAME}_generate_messages`：** 这个宏表示生成所有与消息相关的任务。通常，在调用 `catkin_package(...)` 时，`CATKIN_DEPENDS` 部分会包含 `${PROJECT_NAME}_generate_messages`，以确保在构建软件包时执行消息生成任务。
>
>     ```cmake
>     catkin_package(
>       CATKIN_DEPENDS 
>       roscpp 
>       std_msgs 
>       message_runtime
>       ${PROJECT_NAME}_generate_messages
>     )
>     ```
>
> 2. **`${PROJECT_NAME}_generate_messages_py`：** 类似于 `${PROJECT_NAME}_generate_messages_cpp`，这个宏用于指定生成与消息相关的Python代码的路径。当你的ROS软件包包含使用Python编写的节点或服务时，可能会用到这个宏。
>
> 3. **`${PROJECT_NAME}_EXPORTED_TARGETS`：** 这个宏用于导出所有与软件包相关的目标，包括消息生成任务。通常，在调用 `catkin_package(...)` 时，`EXPORTED_TARGETS` 部分会包含 `${PROJECT_NAME}_EXPORTED_TARGETS`，以确保其他软件包能够正确地依赖你的软件包，并包括所有必要的目标。
>
>     ```cmake
>     cmakeCopy codecatkin_package(
>       ...
>       INCLUDE_DIRS include
>       LIBRARIES ${PROJECT_NAME}_library
>       CATKIN_DEPENDS roscpp std_msgs message_runtime
>       DEPENDS system_lib
>       EXPORTED_TARGETS ${PROJECT_NAME}_EXPORTED_TARGETS
>     )
>     ```
>
> 请注意，具体的宏可能会受到ROS版本、Catkin工具链版本和软件包的配置选项的影响。上述宏的名称中的 `${PROJECT_NAME}` 部分会根据你的软件包的名称而变化。

**编译成功后，使用如下命令依次启动发布者和订阅者。**

```bash
1. 启动ros master
roscore
2. 启动发布者
rosrun topic_hello_world topic_hello_world_user_msg_pub
3. 启动订阅者
rosrun topic_hello_world topic_hello_world_user_msg_sub
```

结果如下：

![image-20231113225303077](img/image-20231113225303077.png)

目前为止，**Topic Hello World** 的自定义msg已经成功了。

#### 2.1.3.4 实现发布者与订阅者（Python版）

在 `topic_hello_world` 包路径下的 `scripts` 目录中，创建 `user_msg_pub.py` 以实现发布者，编辑内容如下：

```python
#! /usr/bin python

import rospy
from topic_hello_world.msg import RobotPose


def main():
    rospy.init_node("user_msg_pub")
    pub = rospy.Publisher("/robot_pose", RobotPose, queue_size=10)
    msg = RobotPose()
    msg.id = "vbot"
    msg.x = 52.1
    msg.y = 12.6
    msg.angle = 180.0

    while not rospy.is_shutdown():
        pub.publish(msg)
        rospy.loginfo("Pub robot: {}, pose({}, {}, {})".format(msg.id, msg.x, msg.y, msg.angle))
        rospy.sleep(1)


if __name__ == "__main__":
    main()
```

在`scrips`中创建 `user_msg_sub.py` 以实现订阅者，编辑内容如下：

```python
#! /usr/bin python

import rospy
from topic_hello_world.msg import RobotPose


def robotPoseCallback(msg):
    rospy.loginfo("Sub robot: {}, pose({}, {}, {})".format(msg.id, msg.x, msg.y, msg.angle))


def main():
    rospy.init_node("user_msg_sub")
    rospy.Subscriber("/robot_pose", RobotPose, robotPoseCallback, queue_size=10)

    rospy.spin()


if __name__ == "__main__":
    main()
```

修改 `CMakeLists.txt` ，只需添加如下内容：

```cmake
catkin_install_python(PROGRAMS
  scripts/user_msg_pub.py
  scripts/user_msg_sub.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
```

**编译运行**

进入工作空间执行 `catkin_make` 命令编译工程，编译成功后，使用如下命令依次启动发布者和订阅者。

```bash
1. 启动ros master(如果已启动，无需再启动)
roscore
2. 启动发布者
rosrun topic_hello_world user_msg_pub.py
3. 启动订阅者
rosrun topic_hello_world user_msg_sub.py
```

结果如下：

![image-20231113232012306](img/image-20231113232012306.png)



## 2.2 服务通讯（Service）

服务通讯是基于**请求响应**模式的，是一种应答机制。

用于偶然的、对实时性有要求、有一定逻辑处理需求的数据传输场景。

### 2.2.1 服务通讯模型

服务是一种双向通讯方式，它通过请求和应答的方式传递消息，该模型涉及到三个角色：

- Master (管理者)
- Server（服务端）
- Client（客户端）

**Master** 负责保管 **Server** 和 **Client** 的注册信息，并匹配服务名称相同的 **Server** 和 **Client** ，帮助 他们建立连接，连接建立后，**Client** 可以发送请求信息， **Server** 收到请求后返回响应信息。

![02_服务通信模型](img/02_服务通信模型.png)

服务模型通讯流程：

- **0）advertise：服务端注册**

	服务端（Server）向管理者（Master）注册信息，包括RPC地址和Service名字。Master会将服务端的注册信息加入到注册表中。

- **1）客户端注册**

	客户端（Client）向管理者（Master）注册信息，包括Service名字。Master会将客户端（Client）的注册信息加入到注册表中。

- **2）Master匹配信息：牵线搭桥**

	管理者（Master）通过查询注册表发现有匹配的服务端（Server）和客户端（Client），则通过RPC向客户端（Client）发送服务端（Server）的 TCP/UDP 地址信息。

- **3）客户端发送请求信息**

	客户端根据服务端的 TCP/UDP 地址与服务端建立网络连接，并发送请求信息。

- **4）服务端响应请求**

    服务端收到请求数据后，通过处理产生响应数据，通过 TCP/UDP 返回给客户端。

> Note：
>
> 1. 上述实现流程中，前三步使用 RPC 协议，最后两步使用 TCP/UDP 协议，默认TCP。
> 2. 客户端请求时，必须保证服务端已经启动。
> 3. 服务名相同的客户端可以有多个，服务端只能有1个。
> 4. 与话题通信不同，服务通信过程中，ROS Master必须处于启动状态。



### 2.2.2 Service Hello World

万物始于Hello World，同样，使用Hello World介绍Service的简单使用。

使用Service传输数据时，需要注意以下几点：

- Service名称
- 消息格式（srv）
- 服务端实现
- 客户端实现

接下来实现一个简单的 `Service` 服务通信，客户端请求启动机器人，服务端启动机器人的各个模块，然后返回执行结果。

#### 2.2.2.1 创建并初始化功能包

首先创建 `service_hello_world` 包，命令如下：

```bash
catkin_create_pkg service_hello_world std_srvs roscpp rospy
```

创建后，文件结构如下：

![image-20231115222159774](img/image-20231115222159774.png)

#### 2.2.2.2 确定Service名称及消息格式

Service名称：/hello_world_service

消息格式：std_srvs::SetBool

消息文件路径：/opt/ros/noetic/share/std_srvs/srv/SetBool.srv

消息文件内容：

```xml
bool data # e.g. for hardware enabling / disabling
---
bool success   # indicate successful run of triggered service
string message # informational, e.g. for error messages
```

#### 2.2.2.3 实现服务端与客户端（C++版）

在创建的 `service_hello_world` 包路径下有一个 `src` 目录，在这里存储C++源码，我们创建 `service_hello_world_server.cpp` 以实现服务端，编辑内容如下：

```cpp
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

bool dealRobotSwitch(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &resp)
{
    bool flag = req.data;
    ROS_INFO("服务器收到 [%s] 机器人的指令.", flag ? "启动" : "关闭");

    // 逻辑处理
    if (flag)
    {
        ROS_INFO("正在启动机器人各模块...");
        ros::Duration(2).sleep();
        // 使用时间模拟随机成功与失败
        if (ros::Time::now().toNSec() % 2 == 0)
        {
            resp.success = true;
            resp.message = "Hello World.";
            ROS_INFO("机器人各模块启动成功.\n");
        }
        else
        {
            resp.success = false;
            resp.message = "再睡一会";
            ROS_INFO("机器人各模块启动失败.\n");
        }
    }
    else
    {
        ROS_INFO("正在关闭机器人各模块...");
        ros::Duration(2).sleep();
        // 模拟成功与失败
        if (ros::Time::now().toNSec() % 2 == 0)
        {
            resp.success = true;
            resp.message = "Good Night.";
            ROS_INFO("机器人各模块关闭成功.\n");
        }
        else
        {
            resp.success = false;
            resp.message = "我还能卷";
            ROS_INFO("机器人各模块关闭失败.\n");
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "service_hello_world_server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("/robotSwitch", dealRobotSwitch);
    ROS_INFO("robotSwitch 服务已启动...");
    ros::spin();
    return 0;
}
```

创建 `service_hello_world_client.cpp` 以实现客户端，编辑内容如下：

```cpp
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "service_hello_world_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<std_srvs::SetBool>("/robotSwitch");

    std_srvs::SetBool srv;
    if (strcmp(argv[1], "on") == 0)
    {
        srv.request.data = true;
    }
    else if (strcmp(argv[1], "off") == 0)
    {
        srv.request.data = false;
    }
    else
    {
        ROS_WARN("仅支持on和off");

        return 1;
    }

    // 等待服务启动
    // ros::service::waitForService("/robotSwitch");
    // client.waitForExistence();
    if (client.call(srv))
    {
        if (srv.response.success)
        {
            ROS_INFO("操作成功, %s", srv.response.message.c_str());
        }
        else
        {
            ROS_ERROR("操作失败, %s", srv.response.message.c_str());
        }
    }
    else
    {
        ROS_ERROR("操作失败, 未知错误!");
    }

    return 0;
}
```

修改 `CMakeLists.txt` ，只需添加如下内容：

```cmake
add_executable(${PROJECT_NAME}_client src/service_hello_world_client.cpp)
add_executable(${PROJECT_NAME}_server src/service_hello_world_server.cpp)

target_link_libraries(${PROJECT_NAME}_client
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}_server
  ${catkin_LIBRARIES}
)
```

**编译运行**

进入工作空间执行 `catkin_make` 命令编译工程，编译成功后，使用如下命令依次启动服务端和客户端。

```bash
1. 启动ros master
roscore
2. 启动服务端
rosrun service_hello_world service_hello_world_server
3. 启动客户端
rosrun service_hello_world service_hello_world_client
```

结果如下：

![image-20231116214633246](img/image-20231116214633246.png)

目前为止，**Service Hello World** 已经成功了。

#### 2.2.2.4实现服务端与客户端（Python版）

在创建的 `service_hello_world` 包路径下 `src` 目录的同级，创建一个 `scripts` 目录，在这里存储脚本（如python脚本），我们创建 `service_hello_world_server.py` 以实现服务端，编辑内容如下：

```python
import rospy
from std_srvs.srv import SetBool, SetBoolResponse


def dealRobotSwitch(req):
    flag = req.data
    rospy.loginfo("服务器收到 [%s] 机器人的指令.", "启动" if flag else "关闭")
    if flag:
        rospy.loginfo("正在启动机器人各模块...")
        if rospy.Time.now().to_nsec() % 2 == 0:
            rospy.loginfo("机器人各模块启动成功.\n")
            return SetBoolResponse(True, "Hello World.")
        else:
            rospy.logerr("机器人各模块启动失败.\n")
            return SetBoolResponse(False, "再睡一会")
    else:
        rospy.loginfo("正在关闭机器人各模块...")
        if rospy.Time.now().to_nsec() % 2 == 0:
            rospy.loginfo("机器人各模块关闭成功.\n")
            return SetBoolResponse(True, "Good Night.")
        else:
            rospy.logerr("机器人各模块关闭失败.\n")
            return SetBoolResponse(False, "我还能卷")


if __name__ == "__main__":
    rospy.init_node("service_hello_world_server")
    server = rospy.Service("/robotSwitch", SetBool, dealRobotSwitch)
    rospy.loginfo("robotSwitch 服务已启动...")
    rospy.spin()
```

创建 `service_hello_world_client.py` 以实现客户端，编辑内容如下：

```python
import sys
import rospy
from std_srvs.srv import SetBool, SetBoolRequest


if __name__ == "__main__":
    rospy.init_node("service_hello_world_client")

    if len(sys.argv) != 2:
        rospy.logerr("参数个数有误")
        sys.exit(1)

    flag = False
    if sys.argv[1] == "on":
        flag = True
    elif sys.argv[1] == "off":
        pass
    else:
        rospy.logwarn("仅支持on和off")
        sys.exit(1)

    rospy.loginfo("客户端请求 [%s] 机器人.", "启动" if flag else "关闭")
    client = rospy.ServiceProxy("/robotSwitch", SetBool)
    client.wait_for_service()
    req = SetBoolRequest()
    req.data = flag
    res = client.call(req)

    if res.success:
        rospy.loginfo("操作成功，%s", res.message)
    else:
        rospy.logerr("操作失败，%s", res.message)
```

修改 `CMakeLists.txt` ，只需添加如下内容：

```cmake
catkin_install_python(PROGRAMS
  scripts/service_hello_world_server.py
  scripts/service_hello_world_client.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
```

**编译运行**

进入工作空间执行 `catkin_make` 命令编译工程，编译成功后，使用如下命令依次启动服务端和客户端。

```bash
1. 启动ros master(如果已启动，无需再启动)
roscore
2. 启动服务端
rosrun service_hello_world service_hello_world_server.py
3. 启动客户端
rosrun service_hello_world service_hello_world_client.py
```

结果如下：

![image-20231117211133246](img/image-20231117211133246.png)



## 2.3 参数服务器（Param）

参数服务器在ROS中主要用于实现不同节点之间的数据共享。

参数服务器相当于是独立于所有节点的一个公共容器，可以将数据存储在该容器中，被不同的节点调用，当然不同的节点也可以往其中存储数据。

使用场景一般存储一些机器人的固有参数，如产品定义、全局配置等。

主要思想就是一个共享数据域，供不同节点使用。

### 2.3.1 参数服务器通讯模型

参数服务器模型涉及到三个角色：

- Master (管理者)
- Setter（设置者）
- User（使用者）

**Master** 负责管理参数与 **Setter/User** 的操作，**Setter** 可以向 **Master** 设置参数，**User** 可以从 **Master** 获取参数。

这里只是方便说明，实际上通讯方操作参数前不会向 **ROS Master** 注册身份信息，所以对  **ROS Master** 而言，没有 **Setter** 与 **User** 之分，每个访问参数服务器的通讯方都是使用者。

![03_参数服务器模型](img/03_参数服务器模型.png)

通讯流程：

- **1）Setter设置参数**

​	**Setter** 通过 **RPC** 向参数服务器设置参数(包括参数名与参数值)，**ROS Master** 将参数保存到参数列表中。

- **2）User获取参数**

​	**User** 通过 **RPC** 向参数服务器发送参数查找请求，请求中包含要查找的参数名。

- **3）ROS Master返回参数信息**

​	**ROS Master** 根据请求提供的参数名查找参数值，并将查询结果通过 **RPC** 发送给 **User**。

参数服务器使用 **XMLRPC** 数据格式存储参数，支持的数据类型如下：

- 32-bit integers
- booleans
- strings
- doubles
- iso8601 dates
- lists
- base64-encoded binary data



> Note：
>
> 



### 2.3.2 Param Hello World

万物始于Hello World，同样，使用Hello World介绍参数服务器的简单使用。

使用参数服务器，通讯方操作参数前没有向 **ROS Master** 注册身份信息，直接对参数进行操作。

接下来实现一个简单的参数操作，设置不同数据类型的参数，如机器人的`名字(name)`、`长(length)`、`宽(width)`、`高(height)`等，并对其进行读取删除等操作。

#### 2.3.2.1 创建并初始化功能包

（这一步不是必须，这里只是为了方便清晰的说明，也可以使用已有的包，在包里新增节点等方法）

首先创建 `param_hello_world` 包，命令如下：

```bash
catkin_create_pkg param_hello_world roscpp rospy
```

创建后，文件结构如下：

![image-20231119105051757](img/image-20231119105051757.png)

#### 2.3.2.2 操作参数（C++版）

**ROS** 为 **C++** 提供了两套 **API**，如下：

- 通过 `ros::NodeHandle` 对象调用
- 通过 `ros::param` 名空间调用

示例如下：

在创建的 `param_hello_world` 包路径下有一个 `src` 目录，在这里存储C++源码，我们创建 `param_hello_world_set.cpp` 和 `param_hello_world_get.cpp` ，修改 `CMakeLists.txt` ，添加如下内容：

```cmake
add_executable(${PROJECT_NAME}_set src/param_hello_world_set.cpp)
add_executable(${PROJECT_NAME}_get src/param_hello_world_get.cpp)

target_link_libraries(${PROJECT_NAME}_set
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}_get
  ${catkin_LIBRARIES}
)
```

编辑 `param_hello_world_set.cpp` 内容如下：

```cpp
#include <ros/ros.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_hello_world_set");
    ros::NodeHandle nh;

    std::cout << std::endl
              << "********** ros::NodeHandle **********" << std::endl;
    {
        std::string name = "vbot";
        std::string geometry = "rectangle";
        double wheel_radius = 0.1;
        int wheel_num = 4;
        bool vision = true;
        std::vector<double> base_size = {0.7, 0.6, 0.3};
        std::map<std::string, int> sensor_id = {{"camera", 0}, {"laser", 2}};

        // 设置参数
        std::cout << "-- 设置参数 --" << std::endl;
        nh.setParam("name", "vbot");               // 字符串, char*
        nh.setParam("geometry", geometry);         // 字符串, string
        nh.setParam("wheel_radius", wheel_radius); // double
        nh.setParam("wheel_num", wheel_num);       // int
        nh.setParam("vision", vision);             // bool
        nh.setParam("base_size", base_size);       // vector
        nh.setParam("sensor_id", sensor_id);       // map
        // 验证是否设置成功
        system("rosparam get name");
        system("rosparam get geometry");
        system("rosparam get wheel_radius");
        system("rosparam get wheel_num");
        system("rosparam get vision");
        system("rosparam get base_size");
        system("rosparam get sensor_id");
    }


    std::cout << std::endl
              << "********** ros::param **********" << std::endl;
    {
        std::string name = "vbot";
        std::string geometry = "rectangle";
        double wheel_radius = 0.1;
        int wheel_num = 4;
        bool vision = true;
        std::vector<double> base_size = {0.7, 0.6, 0.3};
        std::map<std::string, int> sensor_id = {{"camera", 0}, {"laser", 2}};
        // 设置参数
        std::cout << "-- 设置参数 --" << std::endl;
        ros::param::set("name_p", "vbot");               // 字符串, char*
        ros::param::set("geometry_p", geometry);         // 字符串, string
        ros::param::set("wheel_radius_p", wheel_radius); // double
        ros::param::set("wheel_num_p", wheel_num);       // int
        ros::param::set("vision_p", vision);             // bool
        ros::param::set("base_size_p", base_size);       // vector
        ros::param::set("sensor_id_p", sensor_id);       // map
        // 验证是否设置成功
        system("rosparam get name_p");
        system("rosparam get geometry_p");
        system("rosparam get wheel_radius_p");
        system("rosparam get wheel_num_p");
        system("rosparam get vision_p");
        system("rosparam get base_size_p");
        system("rosparam get sensor_id_p");
    }

    return 0;
}
```

编译运行，结果如下：

![image-20231119194648750](img/image-20231119194648750.png)

编辑 `param_hello_world_get.cpp` 内容如下：

```cpp
#include <ros/ros.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_hello_world_get");
    ros::NodeHandle nh;

    std::cout << std::endl
              << "********** ros::NodeHandle **********" << std::endl;
    {
        // 修改参数
        std::cout << std::endl
                  << "-- 修改参数 --" << std::endl;
        nh.setParam("name", "mybot");        // 字符串, char*
        nh.setParam("geometry", "circular"); // 字符串, char*
        nh.setParam("wheel_radius", 0.15);   // double
        nh.setParam("wheel_num", 2);         // int
        nh.setParam("vision", false);        // bool
        std::vector<double> base_size = {0.2, 0.04};
        nh.setParam("base_size", base_size); // vector
        std::map<std::string, int> sensor_id = {{"camera", 0}, {"laser", 2}};
        sensor_id.insert({"ultrasonic", 5});
        ros::param::set("sensor_id", sensor_id); // map

        // 获取参数
        std::cout << std::endl
                  << "-- 获取参数 --" << std::endl;
        std::string name;
        std::string geometry;
        double wheel_radius;
        int wheel_num;
        bool vision;
        nh.getParam("name", name);
        nh.getParam("geometry", geometry);
        nh.getParam("wheel_radius", wheel_radius);
        nh.getParam("wheel_num", wheel_num);
        nh.getParam("vision", vision);
        nh.getParam("base_size", base_size);
        nh.getParam("sensor_id", sensor_id);
        ROS_INFO("ros::NodeHandle getParam, name: %s, geometry: %s, wheel_radius: %lf, wheel: %d, vision: %s, base_size: (%lf, %lf)",
                 name.c_str(), geometry.c_str(), wheel_radius, wheel_num, vision ? "true" : "false",
                 base_size[0], base_size[1]);
        for (auto sensor : sensor_id)
        {
            ROS_INFO("ros::NodeHandle getParam, %s_id: %d", sensor.first.c_str(), sensor.second);
        }


        // 删除参数
        std::cout << std::endl
                  << "-- 删除参数 --" << std::endl;
        nh.deleteParam("vision");
        system("rosparam get vision");

        // 其他操作函数
        std::cout << std::endl
                  << "-- 其他操作函数 --" << std::endl;
        double wheel_radius1;
        wheel_radius1 = nh.param("wheel_radius", wheel_radius1);
        ROS_INFO("param, wheel_radius: %lf", wheel_radius1);

        nh.getParamCached("wheel_radius", wheel_radius1);

        std::vector<std::string> keys_v;
        nh.getParamNames(keys_v);
        for (auto key : keys_v)
        {
            ROS_INFO("getParamNames, key: %s", key.c_str());
        }

        if (nh.hasParam("vision"))
        {
            ROS_INFO("hasParam, 存在该参数");
        }
        else
        {
            ROS_INFO("hasParam, 不存在该参数");
        }

        std::string result;
        nh.searchParam("name", result);
        ROS_INFO("searchParam, result: %s", result.c_str());
    }


    std::cout << std::endl
              << "********** ros::param **********" << std::endl;
    {
        // 修改参数
        std::cout << std::endl
                  << "-- 修改参数 --" << std::endl;
        ros::param::set("name_p", "mybot");        // 字符串, char*
        ros::param::set("geometry_p", "circular"); // 字符串, char*
        ros::param::set("wheel_radius_p", 0.15);   // double
        ros::param::set("wheel_num_p", 2);         // int
        ros::param::set("vision_p", false);        // bool
        std::vector<double> base_size = {0.2, 0.04};
        ros::param::set("base_size_p", base_size); // vector
        std::map<std::string, int> sensor_id = {{"camera", 0}, {"laser", 2}};
        sensor_id.insert({"ultrasonic", 5});
        ros::param::set("sensor_id_p", sensor_id); // map

        // 获取参数
        std::cout << std::endl
                  << "-- 获取参数 --" << std::endl;
        std::string name;
        std::string geometry;
        double wheel_radius;
        int wheel_num;
        bool vision;
        ros::param::get("name_p", name);
        ros::param::get("geometry_p", geometry);
        ros::param::get("wheel_radius_p", wheel_radius);
        ros::param::get("wheel_num_p", wheel_num);
        ros::param::get("vision_p", vision);
        ros::param::get("base_size_p", base_size);
        ros::param::get("sensor_id_p", sensor_id);
        ROS_INFO("ros::param get, name: %s, geometry: %s, wheel_radius: %lf, wheel: %d, vision: %s, base_size: (%lf, %lf)",
                 name.c_str(), geometry.c_str(), wheel_radius, wheel_num, vision ? "true" : "false",
                 base_size[0], base_size[1]);
        for (auto sensor : sensor_id)
        {
            ROS_INFO("ros::param getParam, %s_id: %d", sensor.first.c_str(), sensor.second);
        }

        // 删除参数
        std::cout << std::endl
                  << "-- 删除参数 --" << std::endl;
        ros::param::del("vision_p");
        system("rosparam get vision_p");

        // 其他操作函数
        std::cout << std::endl
                  << "-- 其他操作函数 --" << std::endl;
        double wheel_radius1;
        wheel_radius1 = ros::param::param("wheel_radius", wheel_radius1);
        ROS_INFO("param, wheel_radius: %lf", wheel_radius1);

        ros::param::getCached("wheel_radius", wheel_radius1);

        std::vector<std::string> keys_v;
        ros::param::getParamNames(keys_v);
        for (auto key : keys_v)
        {
            ROS_INFO("getParamNames, key: %s", key.c_str());
        }

        if (ros::param::has("vision"))
        {
            ROS_INFO("has, 存在该参数");
        }
        else
        {
            ROS_INFO("has, 不存在该参数");
        }

        std::string result;
        ros::param::search("name", result);
        ROS_INFO("search, result: %s", result.c_str());
    }

    return 0;
}
```

编译运行，结果如下：

![2023-11-19_19-49-23](img/2023-11-19_19-49-23.png)

#### 2.3.2.3 其他操作参数的函数

除了上文提到的`setParam()`、`getParam()`、`deleteParam()` 函数，还有一些其他的参数操作函数，如下：

**这里只以通过 ros::NodeHandle 对象调用为例，通过 ros::param 名空间调用类似，只多了一个 unsubscribeCachedParam函数，后面说明**

**1.param**

获取 `param_name` 的值，如果 `param_name` 不存在，则返回 `default_val`

**原型： T param(const std::string& param_name, const T& default_val) const**

```cpp
double wheel_radius2;
wheel_radius2 = nh.param("wheel_radius", wheel_radius2);
ROS_INFO("param, wheel_radius: %lf", wheel_radius2);
```

**2.getParamCached()**

与`getParam()`使用方法一样。

首次调用会判断该参数是否获取过，如果获取过则从缓存读取，并向 `Master` 订阅该参数的变化，不再像`getParam()`一样通过 `RPC` 向 `Master`获取，以提高效率。

示例参考 `getParam()`。

**3.getParamNames()**

获取所有设置到 **Master** 的参数的键，并通过 **vector** 返回。

**原型：bool getParamNames(std::vector\<std::string\>& keys) const;**

```cpp
std::vector<std::string> keys_v;
nh.getParamNames(keys_v);
for (auto key : keys_v)
{
    ROS_INFO("getParamNames, key: %s", key.c_str());
}
```

 **4.hasParam()**

判断是否存在该参数

**原型：bool hasParam(const std::string& key) const;**

```cpp
if (nh.hasParam("vision"))
{
    ROS_INFO("存在该参数");
}
else
{
    ROS_INFO("不存在该参数");
}
```

**5.searchParam()**

搜索给定参数名，如果存在，返回键名，不存在返回空字符串。

**原型：bool searchParam(const std::string& key, std::string& result) const;**

```cpp
std::string result;
nh.searchParam("name", result);
ROS_INFO("searchParam, result: %s", result.c_str());
```

**6.unsubscribeCachedParam()   （ros::param特有）**

<font color="red">不明白该函数有什么具体作用，如果你知道欢迎交流（留言或加下方微信）。</font>

没有找到官方说明，源码及注释如下：

头文件：`param.h`

![image-20231119191344721](img/image-20231119191344721.png)

源文件：`param.cpp`

![image-20231119191444403](img/image-20231119191444403.png)

直译注释为：取消订阅master中的缓存参数

猜测和 `getCached()` 有关， `getCached()` 会订阅参数变化，`unsubscribeCachedParam`则是取消订阅，但验证未生效：

```cpp
// 设置参数
ros::param::set("wheel_radius", 0.15);

// 首次调用getCached，这里会订阅"wheel_radius"的变化
double wheel_radius;
ros::param::getCached("wheel_radius", wheel_radius);
ROS_INFO("before unsubscribeCachedParam, wheel_radius: %lf", wheel_radius);

// 调用unsubscribeCachedParam取消订阅
ros::param::unsubscribeCachedParam("wheel_radius");

// 修改master中的"wheel_radius"值
// 由于已取消参数变化的订阅，此次变化不会同步到缓存
// 所以master中的值是0.5，而缓存中的值是0.15
ros::param::set("wheel_radius", 0.5);

// 再次调用getCached，
// 理论上，再次调用getCached，会从缓存读取，此时缓存中的值是0.15
double wheel_radius1;
ros::param::getCached("wheel_radius", wheel_radius1);
ROS_INFO("after  unsubscribeCachedParam, wheel_radius1: %lf", wheel_radius1);
```

实际输出为：

```bash
before unsubscribeCachedParam, wheel_radius: 0.15
after  unsubscribeCachedParam, wheel_radius: 0.50
```

<font color="red">欢迎交流（留言或加下方微信）。</font>



#### 2.3.2.4 操作参数（Python版）

与 **C++** 不同，**ROS** 只为 **Python** 提供了一套操作参数的 **API**。

在创建的 `param_hello_world` 包路径下 `src` 目录的同级，创建一个 `scripts` 目录，在这里存储脚本（如python脚本），修改 `CMakeLists.txt` ，添加如下内容：

```cmake
catkin_install_python(PROGRAMS
  scripts/param_hello_world_set.py
  scripts/param_hello_world_get.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
```

在 `scripts` 中创建 `param_hello_world_set.py` 编辑内容如下：

```python
import rospy
import os


if __name__ == "__main__":
    rospy.init_node("param_hello_world_set")

    # 设置参数
    rospy.set_param("name", "vbot")                         # 字符串, string
    rospy.set_param("geometry", "rectangle")                # 字符串, string
    rospy.set_param("wheel_radius", 0.1)                    # double
    rospy.set_param("wheel_num", 4)                         # int
    rospy.set_param("vision", True)                         # bool
    rospy.set_param("base_size", [0.7, 0.6, 0.3])           # list
    rospy.set_param("sensor_id", {"camera": 0, "laser": 2}) # dictionary

    # 验证是否设置成功
    os.system("rosparam get name")
    os.system("rosparam get geometry")
    os.system("rosparam get wheel_radius")
    os.system("rosparam get wheel_num")
    os.system("rosparam get vision")
    os.system("rosparam get base_size")
    os.system("rosparam get sensor_id")

```

在 `scripts` 中创建 `param_hello_world_get.py` 编辑内容如下：

```python
import rospy


if __name__ == "__main__":
    rospy.init_node("param_hello_world_get")

    # 修改参数
    rospy.set_param("name", "mybot")             # 字符串, string
    rospy.set_param("geometry", "circular")      # 字符串, string
    rospy.set_param("wheel_radius", 0.15)        # double
    rospy.set_param("wheel_num", 2)              # int
    rospy.set_param("vision", False)             # bool
    rospy.set_param("base_size", [0.2, 0.04])    # list
    rospy.set_param("sensor_id", {"camera": 0, "laser": 2, "ultrasonic": 5}) # dictionary

    # 获取参数
    name = rospy.get_param("name")                    # 字符串, string
    geometry = rospy.get_param("geometry")            # 字符串, string
    wheel_radius = rospy.get_param("wheel_radius")    # double
    wheel_num = rospy.get_param("wheel_num")          # int
    vision = rospy.get_param("vision")                # bool
    base_size = rospy.get_param("base_size")          # list
    sensor_id = rospy.get_param("sensor_id")          # dictionary
    rospy.loginfo("get_param, name: {}, geometry: {}, wheel_radius: {}, wheel: {}, vision: {}, base_size: ({}, {})"
                  .format(name, geometry, wheel_radius, wheel_num, vision, base_size[0], base_size[1]))
    for key, value in sensor_id.items():
        rospy.loginfo("get_param, sensor: {}, id: {}".format(key, value))

    # 删除参数
    rospy.delete_param("vision")

    # 其他操作
    wheel_radius1 = rospy.get_param_cached("wheel_radius")

    keys = rospy.get_param_names()
    for key in keys:
        rospy.loginfo("get_param_names, key: {}".format(key))

    if rospy.has_param("vision"):
        rospy.loginfo("has_param, 存在该参数")
    else:
        rospy.loginfo("has_param, 不存在该参数")

    result = rospy.search_param("name")
    rospy.loginfo("search_param, result: {}".format(result))

```

编译执行结果如下：

![image-20231119204921754](img/image-20231119204921754.png)



## 2.4 动作通讯（Action）

严格来说，Action不是基本通讯模型，它的底层由Topic组成。

Action通讯和Service类似，但单次Service通讯是阻塞的，只有服务端将服务请求处理完成后，才会返回结果给客户端。而有些场景中，我们不仅需要知道请求的处理结果，还需要知道请求处理的进度或其他中间结果。

比如，要控制机器人到达目标点A，Service通讯方式收到请求后会执行任务直到成功或失败，过程中客户端不会收到任何关于该任务的信息；而Action通讯方式，首先客户端告诉服务端机器人要走到A；服务端确认添加任务；然后服务端开始执行任务；最后服务端返回任务执行结果。

### 2.4.1 动作通讯模型

Action是一种用于处理长时间运行任务的通信机制，采用客户端-服务器模型，主要由5个Topic实现：

![image-20250713205143771](img/image-20250713205143771.png)



|      Topic 名称       |            消息类型            |      方向       |   作用   |
| :-------------------: | :----------------------------: | :-------------: | :------: |
|   /action_name/goal   |      ActionNameActionGoal      | Client → Server | 发送目标 |
|  /action_name/cancel  |     actionlib_msgs/GoalID      | Client → Server | 取消请求 |
|  /action_name/status  | actionlib_msgs/GoalStatusArray | Server → Client | 状态更新 |
| /action_name/feedback |    ActionNameActionFeedback    | Server → Client | 进度反馈 |
|  /action_name/result  |     ActionNameActionResult     | Server → Client | 最终结果 |

### 2.4.2 动作通讯流程

主要分为添加、执行、完成三个阶段：

1. 任务添加阶段

​		由客户端向服务端发送目标的Topic，服务端接收后，向客户端发送确认的Topic

```mermaid
sequenceDiagram
    participant C as Client
    participant S as Server
    
    C->>S: 通过 /goal topic 发送 ActionGoal
    S->>C: 通过 /status topic 确认接收 (状态变为 ACTIVE)
```

2. 任务执行阶段

​		目标任务确认后，服务端开始执行任务，并周期性向客户端发送任务执行信息

```mermaid
sequenceDiagram
    participant C as Client
    participant S as Server
    
    loop 定期发送
        S->>C: 通过 /feedback topic 发送 ActionFeedback
    end
```



3. 任务完成阶段

​		任务成功、失败或取消，由服务端向客户端发送任务结果信息

```mermaid
sequenceDiagram
    participant C as Client
    participant S as Server
    
    alt 任务成功
        S->>C: 通过 /result topic 发送 ActionResult (状态: SUCCEEDED)
    else 任务失败
        S->>C: 通过 /result topic 发送 ActionResult (状态: ABORTED)
    else 任务取消
        C->>S: 通过 /cancel topic 发送取消请求
        S->>C: 通过 /result topic 发送 ActionResult (状态: PREEMPTED)
    end
```

### 2.4.3 Action Hello World

万物始于Hello World，同样，使用Hello World介绍Action的简单使用。

使用Action时，需要注意以下几点：

- Action名称
- 消息格式（.action，目标、最终结果、连续反馈）
- 客户端实现（发送目标，处理确认目标、定期任务信息、任务完成等各阶段的回调）
- 服务端实现（初始化服务器，发布定期任务信息，发布任务信息等）

为便于理解，我们使用Action实现一个查找n以内所有质数的功能。

#### 2.4.3.1 创建并初始化功能包

（这一步不是必须，这里只是为了方便清晰的说明，也可以使用已有的包，在包里新增节点等方法）

首先创建 `action_hello_world` 包，命令如下：

```bash
catkin_create_pkg action_hello_world actionlib roscpp rospy
```

创建后，文件结构如下：

![image-20250713234819490](img/image-20250713234819490.png)

#### 2.4.3.2 确定Action名称及消息格式

Action名称：/find_primes

消息文件名：FindPrimes.action

消息文件路径：在创建的 `action_hello_world` 包路径下创建一个 `action` 目录，将`FindPrimes.action`存放在该目录下

消息文件内容：

```xml
# 目标
int32 number # 查找 number 以内的质数
---
# 最终结果
int32 number 
int32[] primes # number 以内的质数
---
# 连续反馈
int32 number # 当前检查的数字
bool is_prime # 是否是质数
```

这里说明一下，Action的消息体由固定的 `目标`、`最终结果`、`连续反馈` 三部分组成，每一部分可以看做是一个`msg`消息体，依次对应前文 `动作通讯流程` 中的任务`添加`、`完成`、`执行`三个阶段。



#### 2.4.3.3 配置编译文件

**1. 添加message_generation功能包**

`message_generation`功能包，在构建时根据`action`、 `msg`和`srv`生成消息和服务的接口文件（比如C++头文件和Python包），以便在 ROS 节点中使用。

在`package.xml`中添加以下内容：

```xml
<build_depend>message_generation</build_depend>
```

>小知识：
>
>这里其实也需要在 `CMakeLists.txt` 添加，类似如下：
>
>```cmake
>find_package(catkin REQUIRED COMPONENTS
>      actionlib
>      roscpp
>      rospy
>      message_generation
>)
>```
>
>但由于`actionlib`已经隐式调用过了`message_generation`，所以这里不需要显式声明。

**2. 添加action文件**

在 `CMakeLists.txt` 添加自定义`action`，该函数依赖`message_generation`功能包。

```cmake
add_action_files(
  FILES
  FindPrimes.action
)
```

**3. 配置依赖并生成接口文件**

添加处理`action`、 `msg`或`srv`所需要的依赖，并生成接口文件，该函数依赖`message_generation`功能包。

```cmake
generate_messages(
  DEPENDENCIES
  actionlib
)
```

**4 . 添加message_runtime依赖**

`message_runtime` 用于在运行时提供消息的序列化和反序列化支持。

这里注意，有时可能会看到没有显式添加 `message_runtime` 也能正常运行，这通常是因为其他依赖项（例如`roscpp` 或 `std_msgs`）可能已经隐含地包含了 `message_runtime`。在这种情况下，构建系统已经处理了消息生成的任务。

然而，为了确保你的软件包在所有情况下都能正常工作，最好显式添加 `message_runtime` 作为你的软件包的依赖项。这样可以确保你的消息定义在构建和运行时得到正确处理。

需要对 `CMakeLists.txt` 作以下修改：

```cmake
catkin_package(
  CATKIN_DEPENDS roscpp rospy actionlib message_runtime
)
```

同时在`package.xml`中添加以下内容：

```xml
<exec_depend>message_runtime</exec_depend>
```



#### 2.4.3.4 实现服务端与客户端（C++版）

在创建的 `action_hello_world` 包路径下有一个 `src` 目录，在这里存储C++源码，我们创建 `action_hello_world_server.cpp` 以实现服务端，编辑内容如下：

```cpp
/*
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 Action服务器 对象
        5.实现服务任务（发布任务反馈、返回最终结果）
        6.启动 Action 服务器
*/

// 1.包含头文件
#include <cmath>
#include <actionlib/server/simple_action_server.h>
#include <action_hello_world/FindPrimesAction.h>

typedef actionlib::SimpleActionServer<action_hello_world::FindPrimesAction> Server;

// 判断给定数字是否是质数
bool isPrime(int n)
{
    bool ret = true;
    if (n <= 1)
    {
        ret = false;
    }
    else if (n % 2 == 0)
    {
        ret = (n == 2);
    }
    else
    {
        for (int i = 3;; i += 2)
        {
            if (i > n / i)
            {
                break;
            }
            else if (n % i == 0)
            {
                ret = false;
            }
        }
    }
    ROS_INFO("%d %s prime.", n, ret ? "is" : "is not");

    return ret;
}

// 5.实现服务任务（发布任务反馈、返回最终结果）
void execute(const action_hello_world::FindPrimesGoalConstPtr &goal, Server *server)
{
    action_hello_world::FindPrimesFeedback feedback;
    std::vector<int> primes; // 存放找到的质数
    for (size_t i = 0; i <= goal->number; i++)
    {
        feedback.number = i;
        feedback.is_prime = isPrime(i);
        server->publishFeedback(feedback); // 发布反馈
        // 存储找到的质数
        if (feedback.is_prime)
        {
            primes.push_back(i);
        }

        ros::Duration(0.5).sleep();
    }
    // 返回最终结果
    action_hello_world::FindPrimesResult result;
    result.number = goal->number;
    result.primes = primes;
    server->setSucceeded(result);
}

int main(int argc, char **argv)
{
    // 解决中文打印乱码
    setlocale(LC_ALL, "");
    // 2.初始化 ROS 节点:命名(唯一)
    ros::init(argc, argv, "action_hello_world_server");
    // 3.实例化 ROS 句柄
    ros::NodeHandle nh;
    // 4.实例化 Action服务器 对象
    Server server(nh, "/find_primes", boost::bind(&execute, _1, &server), false);
    // 6.启动服务器
    server.start();
    ros::spin();

    return 0;
}
```

创建 `action_hello_world_client.cpp` 以实现客户端，编辑内容如下：

```cpp
/*
    实现流程:
        1.包含头文件
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 Action客户端 对象
        4.等待服务端启动完成
        5.实例化目标对象
        6.发送目标任务到服务端
        7.等待任务完成
*/

// 1.包含头文件
#include <ros/ros.h>
#include <sstream>
#include <actionlib/client/simple_action_client.h>
#include <action_hello_world/FindPrimesAction.h>

typedef actionlib::SimpleActionClient<action_hello_world::FindPrimesAction> Client;

// 处理最终结果
void done_cb(const actionlib::SimpleClientGoalState &state, const action_hello_world::FindPrimesResultConstPtr &result)
{
    if (state.state_ == state.SUCCEEDED)
    {
        std::stringstream ss;
        for (const int n : result->primes)
        {
            ss << std::to_string(n) << " ";
        }
        ROS_INFO("%d 以内的质数有: [ %s]", result->number, ss.str().c_str());
    }
}

// 确认目标，服务激活
void active_cb()
{
    ROS_INFO("开始查找...");
}

// 处理连续反馈的定期任务信息
void feedback_cb(const action_hello_world::FindPrimesFeedbackConstPtr &feedback)
{
    ROS_INFO("当前数字: %d, %s质数", feedback->number, feedback->is_prime?"是":"不是");
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, ""); // 解决中文打印乱码

    // 2.初始化 ROS 节点:命名(唯一)
    ros::init(argc, argv, "action_hello_world_client");
    // 3.实例化 Action客户端 对象
    Client client("/find_primes", true);
    // 4.等待服务端启动完成
    client.waitForServer();
    ROS_INFO("添加任务前的状态: %s", client.getState().toString().c_str());
    // 5.实例化目标对象
    action_hello_world::FindPrimesGoal goal;
    goal.number = 12;
    ROS_INFO("查找 %d 以内的质数", goal.number);
    // 6.发送目标任务到服务端，并注册任务完成、确认目标、定期任务信息的回调函数
    client.sendGoal(goal, &done_cb, &active_cb, &feedback_cb);
    ROS_INFO("添加任务后的状态: %s", client.getState().toString().c_str());

    ros::Duration(1.0).sleep();
    ROS_INFO("执行任务时的状态: %s", client.getState().toString().c_str());
    // 7.等待任务完成
    client.waitForResult(ros::Duration(1000.0)); // 等待结果，1000秒超时
    ROS_INFO("任务执行完的状态: %s", client.getState().toString().c_str());

    return 0;
}
```

**编译运行**

进入工作空间执行 `catkin_make` 命令编译工程，编译成功后，使用如下命令依次启动服务器和客户端。

```bash
1. 启动ros master
roscore
2. 启动服务器
rosrun action_hello_world action_hello_world_server
3. 启动客户端
rosrun action_hello_world action_hello_world_client
```

结果如下：

![image-20250714004114997](img/image-20250714004114997.png)

目前为止，**Action Hello World** 已经成功了。

#### 2.4.3.5 实现服务端与客户端（Python版）

在创建的 `action_hello_world` 包路径下 `src` 目录的同级，创建一个 `scripts` 目录，在这里存储脚本（如python脚本），我们创建 `action_hello_world_server.py` 以实现服务端，编辑内容如下：

```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 1. 导入依赖包
import rospy
import math
import actionlib
from action_hello_world.msg import FindPrimesAction, FindPrimesResult, FindPrimesFeedback

# 判断给定数字是否是质数
def is_prime(n):
    if n <= 1:
        rospy.loginfo(f"{n} 不是质数")
        return False
    if n == 2:
        rospy.loginfo(f"{n} 是质数")
        return True
    if n % 2 == 0:
        rospy.loginfo(f"{n} 不是质数")
        return False
    
    # 检查从3到sqrt(n)的奇数因子
    ret = True
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            ret = False
            break
    
    status_str = "是" if ret else "不是"
    rospy.loginfo(f"{n} {status_str}质数")
    return ret

# 实现服务任务（发布任务反馈、返回最终结果）
def execute_cb(goal):
    primes = []  # 存放找到的质数
    target = goal.number
    
    # 创建反馈对象
    feedback = FindPrimesFeedback()
    
    # 从2开始检查到目标数字
    for num in range(2, target + 1):
        # 更新反馈信息
        feedback.number = num
        feedback.is_prime = is_prime(num)
        
        # 如果是质数则添加到结果列表
        if feedback.is_prime:
            primes.append(num)
        
        # 发布反馈
        server.publish_feedback(feedback)
        
        # 模拟处理时间
        rospy.sleep(0.5)
    
    # 返回最终结果
    result = FindPrimesResult()
    result.number = target
    result.primes = primes
    server.set_succeeded(result)

if __name__ == "__main__":
    # 2. 初始化ROS节点
    rospy.init_node("action_hello_world_server")

    # 3. 实例化Action服务器对象
    server = actionlib.SimpleActionServer(
        "/find_primes", 
        FindPrimesAction, 
        execute_cb, 
        auto_start=False
    )
    
    # 4. 启动服务器
    server.start()
    rospy.loginfo("质数查找服务器已启动...")
    
    # 保持节点运行
    rospy.spin()
```

创建 `action_hello_world_client.py` 以实现客户端，编辑内容如下：

```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 1. 导入依赖包
import rospy
import actionlib
from action_hello_world.msg import FindPrimesAction, FindPrimesGoal, FindPrimesResult, FindPrimesFeedback

def done_cb(state, result):
    """处理最终结果回调"""
    if state == actionlib.GoalStatus.SUCCEEDED:
        primes_str = " ".join(str(n) for n in result.primes)
        rospy.loginfo(f"{result.number} 以内的质数有: [ {primes_str} ]")

def active_cb():
    """目标激活回调"""
    rospy.loginfo("开始查找...")

def feedback_cb(feedback):
    """处理反馈回调"""
    status_str = "是" if feedback.is_prime else "不是"
    rospy.loginfo(f"当前数字: {feedback.number}, {status_str}质数")

if __name__ == "__main__":
    # 2. 初始化ROS节点
    rospy.init_node("action_hello_world_client")
    
    # 3. 实例化Action客户端对象
    client = actionlib.SimpleActionClient("/find_primes", FindPrimesAction)
    
    # 4. 等待服务端启动
    rospy.loginfo("等待服务端启动...")
    client.wait_for_server()
    rospy.loginfo(f"添加任务前的状态: {client.get_state()}")
    
    # 5. 实例化目标对象
    goal = FindPrimesGoal()
    goal.number = 12
    rospy.loginfo(f"查找 {goal.number} 以内的质数")
    
    # 6. 发送目标任务
    client.send_goal(goal, done_cb=done_cb, active_cb=active_cb, feedback_cb=feedback_cb)
    rospy.loginfo(f"添加任务后的状态: {client.get_state()}")
    
    rospy.sleep(1.0)
    rospy.loginfo(f"执行任务时的状态: {client.get_state()}")
    
    # 7. 等待任务完成
    client.wait_for_result(rospy.Duration(1000.0))  # 1000秒超时
    rospy.loginfo(f"任务执行完的状态: {client.get_state()}")
```

修改 `CMakeLists.txt` ，只需添加如下内容：

```cmake
catkin_install_python(PROGRAMS
  scripts/action_hello_world_server.py
  scripts/action_hello_world_client.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
```

**编译运行**

进入工作空间执行 `catkin_make` 命令编译工程，编译成功后，使用如下命令依次启动服务端和客户端。

```bash
1. 启动ros master(如果已启动，无需再启动)
roscore
2. 启动服务端
rosrun action_hello_world action_hello_world_server.py
3. 启动客户端
rosrun action_hello_world action_hello_world_client.py
```

结果如下：

![image-20250715232703250](img/image-20250715232703250.png)



# 三、ROS基础

## 3.1 ROS的计算图源命名

### 3.1.1 命名规则

ROS中的节点、参数、话题和服务统称为计算图源，其命名方式采用灵活的分层结构，便于在复杂的系统中集成和复用。以下是一些命名的示例：

```bash
/foo
/stanford/robot/name
/mq/node1
```

一个有效的命名应该具备以下特点：

1）首字符必须是字母（［a-z|A-Z］）、波浪线（~）或者左斜杠（/）。

2）后续字符可以是字母或数字（［0-9|a-z|A-Z］）、下划线（_）或者左斜杠（/）。



### 3.1.2 名称空间

计算图源命名是ROS封装的一种重要机制。每个资源都定义在一个名称空间内，该名称空间内还可以创建更多资源。但是处于不同名称空间内的资源不仅可以在所处名称空间内使用，还可以在全局范围内访问。这种命名机制可以有效避免不同名称空间内的命名冲突。

ROS提供以下几种设置名称空间的方法：

- 1）通过编码设置命令参数。调用 `ros::init()` 的ROS程序会接收名为 `__ns` 的命令行参数，可以为程序设置默认的名称空间，如下：

```cpp
std::map<std::string, std::string> map;
map["__ns"] = "namespace";
ros::init(map, "namespace_learning");
```

- 2）在launch文件中设置。在launch文件中可通过设置 `ns` 参数来确定默认名称空间：

```xml
<node pkg="package_name " type="file_name" name="node_name" ns="space_name" />
```

- 3）命令行中，使用 `rosrun` 命令参数 `__ns:=/xxx` 来指定名称空间：

```bash
rosrun package_name file_name __ns:=/new_namespace
```

- 4）使用环境变量设置。也可以在执行ROS程序的终端中设置默认名称空间的环境变量：

```bash
export ROS_NAMESPACE=default-namespace
```



### 3.1.3 名称解析

计算图源的名称可以分为以下四种，

- 1）基础（base）名称，例如：name。
- 2）全局（global）名称，例如：/global/name。
- 3）相对（relative）名称，例如：relative/name。
- 4）私有（private）名称，例如：~private/name。

**基础名称：**用来描述资源本身，可以看作相对名称的一个子类，上述示例中的name就是一个基础名称。

**全局名称：**首字符是左斜杠（/）的名称，由左斜杠分开一系列名称空间，示例中的名称空间为 global。全局名称之所以称为全局，是因为它的解析度最高，可以在全局范围内直接访问。

但是在系统中全局名称越少越好，因为过多的全局名称会直接影响功能包的可移植性。

**相对名称：**全局名称需要列出所有名称空间，在名称空间繁多的复杂系统中使用较为不便，所以可以使用相对名称代替。相对名称由ROS提供默认的名称空间，不需要带有开头的左斜杠。

例如在默认名称空间 `/relative` 内使用相对名称 `name`，解析到全局名称为 `/relative/name`。

相比全局名称，相对名称具备良好的移植性，用户可以直接将一个相对命名的节点移植到其他名称空间内，有效防止命名冲突。

**私有名称：**是一个节点内部私有的资源名称，只会在节点内部使用。私有名称以波浪线 `~` 开始，与相对名称一样，其并不包含本身所在的名称空间，需要ROS为其解析；但不同的是，**私有名称并不使用当前默认名称空间，而是用节点的全局名称作为名称空间**。

例如有一个节点的全局名称是 `/sim1/pubvel`，其中的私有名称 `~max_vel` 解析成全局名称即为 `/sim1/pubvel/max_vel`。

总结命名解析方式如下表：

|   节点    | 名称空间 |        相对名称        |       全局名称       |           私有名称            |
| :-------: | :------: | :--------------------: | :------------------: | :---------------------------: |
|  /node1   |    /     |      bar -> /bar       |     /bar -> /bar     |      ~bar -> /node1/bar       |
| /mq/node2 |   /mq    |     bar -> /mq/bar     |     /bar -> /bar     |     ~bar -> /mq/node2/bar     |
| /mq/node3 |   /mq    | foo/bar -> /mq/foo/bar | /foo/bar -> /foo/bar | ~foo/bar -> /mq/node3/foo/bar |



### 3.1.4 节点名称重映射

所有ROS节点内的资源名称都可以在节点启动时进行重映射。ROS这一强大的特性甚至可以支持我们同时打开多个相同的节点，而不会发生命名冲突。
与名称空间类似，ROS也为名称的设置提供了几种方法：

- 1）编码方式。

    - C++实现

    ```cpp
    // 指定重映射名称
    std::map<std::string, std::string> map;
    map["__name"] = "new_name";
    ros::init(map, "namespace_learning");
    
    // 随机重映射名称，会在原有名称后面加时间戳
    ros::init(argc, argv, "namespace_learning", ros::init_options::AnonymousName);
    ```

    - Python实现

    ```python
    rospy.init_node("namespace_learning", anonymous=True)
    ```


- 2）`rosrun` 命令行

    在节点启动时可以使用如下方式重映射命名：

    ```bash
    rosrun package_name file_name __name:=new_node_name
    或
    注意该方法不止会重映射节点名称，如有old_name名称的topic或service，也会被重映射
    rosrun package_name file_name old_name:=new_node_name
    ```

- 3）在launch文件中设置

    在launch文件中可通过设置 `name` 参数来设置节点名称：

    ```xml
    <node pkg="package_name" type="file_name" name="new_node_name" />
    ```



### 3.1.5 话题/服务名称重映射

对于话题和服务，通过编码只能设置名称，不能对名称重映射。

上文提到过，通过 `rosrun` 可以对话题和服务名称重映射：

```bash
rosrun package_name node_name old_name:=new_node_name
```

通过 launch 文件也可以对话题和服务名称重映射：

```xml
<node pkg="package_name" type="file_name" name="node_name">
    <remap from="old_name" to="new_name" />
</node>
```

注意，同一节点中，如果有相同名字的话题和服务，以上方法会同时对他们的名称重映射。



## 3.2 工作空间覆盖

ROS开发过程中，可能同时开发多个项目，或开发项目的工作空间和已有的工作空间重名。比如有两个工作空间`ws1`和`ws2`，他们中都有名为`pkg`的包，系统在搜索 `pkg` 时，要搜索哪个包呢？

ROS 会解析 `~/.bashrc` 文件，并生成 `ROS_PACKAGE_PATH` ROS包路径环境变量，该变量中存储了工作空间的搜索优先级。优先级和 `.bashrc` 的配置顺序刚好相反，即后配置的优先级更高。

> Note：
>
> 1. 配置工作空间时，要注意覆盖问题
> 2. 当在 .bashrc 文件中配置多个工作空间后，可能出现不在 ROS_PACKAGE_PATH 中生效的情况，此时，可以删除自定义工作空间的 build 与 devel 目录，重新 catkin_make，然后重新 source .bashrc 文件，问题解决。



## 3.3 ROS分布式多机通信

ROS是一个分布式系统，同一 ROS Master 可以同时管理分布在多台计算机上多个节点。根据系统的配置方式，任何节点可能随时需要与任何其他节点进行通信。

因此，ROS对网络配置有某些要求：

- 所有端口上的所有机器之间必须有完整的双向连接。
- 每台计算机必须通过所有其他计算机都可以解析的名称来广播自己。

配置方法如下：

### 3.3.1 保证计算机之间网络可连接

首先要保证多台计算机处于同一网络中，最好分别设置固定IP，如果为虚拟机，需要将网络适配器改为桥接模式。

### 3.3.2 配置host文件

与ROS2相比，其实ROS1是伪分布式的，它需要有一个 ROS Master 作为中心节点，所以对于多台计算机，需要指定一台作为主机来运行 ROS Master，其余计算机作为从机运行其他节点。

为了让多台计算机互相能够认识对方，需要告诉主机有哪些从机，告诉从机主机是谁。通过配置 ` /etc/hosts ` 文件实现，如下：

主机端：

```
从机1的IP    从机1的计算机名
从机2的IP    从机2的计算机名
从机3的IP    从机3的计算机名
...
```

从机端：

```
主机的IP    主机计算机名
```



### 3.3.3 配置ROS环境变量

需要把主机和从机的IP与名字告诉ROS，以便 ROS Master 进行管理。编辑 `~/.bashrc` 添加如下内容：

主机端：

```bash
export ROS_MASTER_URI=http://主机IP:11311
export ROS_HOSTNAME=主机IP
```

从机端：

```bash
export ROS_MASTER_URI=http://主机IP:11311
export ROS_HOSTNAME=从机IP
```

注意配置完 `~/.bashrc`后， 需要 `source` 或重启终端使配置生效。

如果，主从机之间可以互相订阅topic或调用service，那么多机通信就配置成功了。



# 四、ROS常用组件

## 4.1 launch文件

launch文件用于管理ros节点，它使用 XML 语法，可以同时启动多个节点，也可以对节点做一些配置。launch文件启动时，会判断是否启动了 roscore，如果启动了，则不再启动，否则，会自动调用 roscore。

下面介绍一些 launch 文件的标签：

### 4.1.1 \<launch\>

 launch 文件的根标签，充当其他标签的容器。

#### 4.1.1.1 属性

- deprecated

    告知用户当前 launch 文件已经弃用

    ```xml
    <launch deprecated="弃用声明"></launch>
    ```

#### 4.1.1.2 子级标签

所有其它标签都是launch的子级



### 4.1.2 \<node\>

用于操作 ROS 节点

> 注意：roslaunch 命令不能保证按照 node 的声明顺序来启动节点，因为节点的启动是多进程的

#### 4.1.2.1 属性

- pkg="package_name"（必选）

    指定节点所属的功能包

    ```xml
    <launch>
    	<node pkg="package_name" />
    </launch>
    ```

- type="file_name"（必选）

    节点可执行文件的名称

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" />
    </launch>
    ```

- name="node_name"（必选）

    节点名称，注册到Master的名称

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" />
    </launch>
    ```

- args="arg1 arg2 arg3"（可选）

    传递参数给节点

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" args="arg1 arg2 arg3" />
    </launch>
    ```

    有些节点需要传入参数，在使用 launch 文件启动给节点时，可以使用该属性传递参数给节点，如下：
    
    ```xml
    # 手动启动节点
    ./add_two_num 6 9
    
    # rosrun 启动节点
    rosrun add_two_nums add_two_nums 6 9
    
    # launch文件启动节点
    <launch>
    	<node pkg="add_two_nums" type="add_two_nums" name="add_two_nums" args="6 9" />
    </launch>
    ```
    
- machine="machine_name"（可选）

    在指定机器上启动节点，需要先使用 \<machine\> 指定机器。

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" machine="machine_name" />
    </launch>
    ```

- respawn="true|false"（可选）

    如果节点退出，是否自动重启，默认 false

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" respawn="true" />
    </launch>
    ```

- respawn_delay="10"（可选）

    如果 respawn 为 true, 那么延迟 N 秒后启动节点，默认为0

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" respawn="true" respawn_delay="10"/>
    </launch>
    ```

- required="true|false"（可选）

    该节点是否必须，如果为 true，那么如果该节点退出，将杀死整个 roslaunch，默认为 false

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" required="true" />
    </launch>
    ```

- ns="namespace_name"（可选）

    在指定命名空间中启动节点

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" ns="namespace_name" />
    </launch>
    ```

- clear_params="true|false"

    在启动前，删除节点的私有空间的所有参数，默认为 false

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" clear_params="true" />
    </launch>
    ```

- output="log|screen"

    日志发送目标，可以设置为 log 日志文件，或 screen 屏幕，默认是 log

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name" output="screen" />
    </launch>
    ```

- 更多属性见 [node Attributes](http://wiki.ros.org/roslaunch/XML/node)

#### 4.1.2.2 子级标签

- \<env\>

    为节点环境变量设置，属性：

    - name：环境变量的名字
    - value：环境变量的值

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name">
    		<env name="environment-variable-name" value="environment-variable-value" />
    	</node>
    </launch>
    ```

- \<remap\>

    为节点设置重新映射参数，属性：

    - from：重新映射的话题名称
    - to：重映射的新名称

    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name">
    		<remap from="/different_topic" to="/needed_topic" />
    	</node>
    </launch>
    ```

- \<rosparam\>

    设置参数，属性：
    
    - command="load|dump|delete" (optional, default=load)
    - file="$(find pkg-name)/path/foo.yaml" (load or dump commands)
    - param="param-name"
    
    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name">
    		<rosparam command="load" file="$(find rosparam)/example.yaml" />
    		<rosparam command="delete" param="my/param" />
            <rosparam param="a_list">[1, 2, 3, 4]</rosparam>
    	</node>
    </launch>
    ```
    
    - ns="namespace" (optional)
    - subst_value="True|False" (optional)
    
    ```xml
    <arg name="whitelist" default="[3, 2]"/>
    <rosparam param="whitelist" subst_value="True">$(arg whitelist)</rosparam>
    ```
    
- \<param\>

    设置参数，属性：

    - name="namespace/name"
    - value="value"(optional)
    - type="str|int|double|bool|yaml"(optional)
    - textfile="$(find pkg-name)/path/file.txt"(optional)
    - binfile="$(find pkg-name)/path/file"(optional)
    - command="command"(optional)
    
    ```xml
    <launch>
    	<node pkg="package_name" type="file_name" name="node_name">
            <param name="publish_frequency" type="double" value="10.0" />
    		<param name="params_a" type="yaml" command="cat '$(find roslaunch)/test/params.yaml'" />
            <rosparam command="load" file="FILENAME" />
    	</node>
    </launch>
    ```



### 4.1.3 \<machine\>

`<machine>` 标签声明可以运行 ROS 节点的机器。如果在本地启动所有节点，则不需要此标签。它主要用于声明远程计算机的 SSH 和 ROS 环境变量设置，但也可以使用它来声明有关本地计算机的信息。

#### 4.1.3.1 属性

- name="machine-name" （必选）

    分配给机器的名称。对应 `<node>` 标签标记的 `machine` 的名字。

- address="blah.willowgarage.com"（必选）

    机器的网络地址/主机名。

- env-loader="/opt/ros/fuerte/env.sh"  （**必选，Fuerte 新增功能**）

    指定远程计算机上的环境文件。环境文件必须是一个 shell 脚本，用于设置所有必需的环境变量，然后对提供的参数运行`exec`。

```xml
<launch>
  <machine name="foo" address="foo-address" env-loader="/opt/ros/noetic/env.sh" />
</launch>
```

- default="true|false|never"（可选）

    将此计算机设置为为其分配节点的默认计算机。默认设置仅适用于稍后在同一范围内定义的节点。注意：如果没有默认计算机，则使用本地计算机。可以通过设置 `default="never"` 来阻止选择机器，在这种情况下只能显式分配机器。

- user="username"（可选）

    用于登录机器的 SSH 用户名。如果不需要，可以省略。

- password="passwhat"（建议不要使用）

    SSH 密码。强烈建议配置 SSH 密钥和 SSH 代理，以便可以使用证书登录。

- timeout="10.0"（可选）

    本机上的 roslaunch 启动失败的超时时间。默认情况下，该时间为 10 秒。

```xml
<launch>
  <machine name="foo" address="foo-address" env-loader="/opt/ros/fuerte/env.sh" user="someone"/>
  <node machine="foo" name="footalker" pkg="test_ros" type="talker.py" />
</launch>
```



### 4.1.4 \<include\>

`<include>` 标签将另一个 roslaunch 文件导入到当前文件中。

#### 4.1.4.1 属性

- file="$(find pkg-name)/path/filename.xml"（必选）

    要包含的文件的名称。

- ns=“foo”（可选）

    在指定命名空间导入文件。

- clear_params=“true|false” （可选，默认值：false）

    在启动之前删除 `<include>` 命名空间中的所有参数。此功能非常危险，应谨慎使用。必须指定`ns`。默认值：`false`。

- pass_all_args="true|false" （可选，默认值：false，roslaunch 版本 1.11.17 新增）

    如果为 `true`，则当前上下文中设置的所有参数，都将添加到为处理包含的文件而创建的子上下文中。可以执行此操作，而不是显式列出要传递的每个参数。

```xml
<launch>
	<include file="$(find pkg-name)/path/filename.launch"/>
</launch>
```

#### 4.1.4.2 子级标签

- \<env\>

     设置环境变量，属性：

    - name：环境变量的名字
    - value：环境变量的值

    ```xml
    <launch>
    	<include file="$(find pkg-name)/path/filename.launch">
    		<env name="environment-variable-name" value="environment-variable-value" />
        </include>
    </launch>
    ```

- \<arg\> 

    将参数传递给被包含的文件，属性：

    - name="arg_name"：参数名称。
    - default="default value"（可选）：参数的默认值。不能与 `value` 属性组合。
    - value="value"（可选）：参数值。不能与 `default` 属性组合。
    - doc="description for this arg"（可选）：参数描述，可通过 `roslaunch` 命令的 `--ros-args` 参数来获取此信息。
    
    \<arg\>有三种使用方法：
    
    - \<arg name="foo" />
    
        声明 `foo` 的存在。`foo`必须作为命令行参数（如果是顶级）或通过`<include>`传递（如果包含）传递。
    
    - \<arg name="foo" default="1" />
    
        使用默认值声明`foo`。`foo` 可以通过命令行参数（如果是顶级）或通过`<include>`传递（如果包含）来覆盖。
    
    - \<arg name="foo" value="bar" />
    
        用常量值声明`foo`。`foo`的值不能被覆盖。这种用法可以实现启动文件的内部参数化，而无需在更高级别公开该参数化。
    
- 示例：

    有launch文件`1.launch`：

    ```xml
    <launch>
      <!-- declare arg to be passed in -->
      <arg name="hoge" /> 
    
      <!-- read value of arg -->
      <param name="param" value="$(arg hoge)"/>
    </launch>
    ```

    `2.launch` 引用 `1.launch`：

    ```xml
    <include file="included.launch">
      <!-- all vars that included.launch requires must be set -->
      <arg name="hoge" value="fuga" />
    </include>
    ```



### 4.1.5 \<remap\>

`<remap>` 可以对 topic 进行重映射

#### 4.1.5.1 属性

- from="original-name"（必选）

    要进行重映射的 topic 名字

- to="new-name"

    重映射的目标 topic 名字

#### 4.1.5.2 注意

- 重映射只会影响重映射之后启动的节点。重映射之前启动的节点不受影响。



### 4.1.6 \<group\>

`<group>`标签可以对节点分组，具有 ns 属性，可以让节点归属某个命名空间.

#### 4.1.6.1 属性

- ns="namespace"（可选）

    将节点组分配给指定的命名空间。命名空间可以是全局的或相对的，但不鼓励使用全局命名空间。

- clear_params="true|false"（可选）

    启动前删除组命名空间中的所有参数。此功能非常危险，应谨慎使用。必须指定`ns` 。

#### 4.1.6.2 子级标签

`<group>` 标签相当于顶级标签，只是充当其中标签的容器，这意味着您可以使用任何标签。

所以除了launch 标签外的其他标签，都是它的子级标签。



### 4.1.7 if和unless

所有标签都支持`if`和`unless`属性，它们根据值来评估包含或排除标签。“1”和“true”被视为真值。“0”和“false”被视为假值。其他值会报错。

- if=”value”

    如果`value`计算结果为 true，则包含标签及其内容。

- unless=”value”

    如果`value`计算结果为 true，则排除标签及其内容。

```xml
<group if="$(arg foo)">
  <!-- stuff that will only be evaluated if foo is true -->
</group>

<param name="foo" value="bar" unless="$(arg foo)" />  
<!-- This param won't be set when "unless" condition is met -->
```



### 4.1.8 Launch Hello World









## 4.2 TF坐标变换

在机器人系统中，有许多运动机构和传感器，为了描述他们之间的相对位姿关系，分别为他们定义了各自的坐标系，通过坐标系转换，就可以知道每个时刻各个组件的位姿。

ROS中通过TF包封装了常用的坐标系转换工具，目前ROS使用的是TF2，早在ROS Hydro以前，ROS使用的是TF。TF2相对TF，更加易用，效率更高，功能更加丰富。

在ROS中，tf 和 tf2 是两个不同的库，它们用于跟踪多个坐标帧之间的变换关系。以下是 tf 和 tf2 之间的主要区别：

**时间戳**

tf：tf库使用一个固定的时间窗口（通常是一秒钟）来存储坐标变换信息，这意味着你可以查询过去或未来的坐标变换，但范围有限。
tf2：tf2库可以查询任意时间点的坐标变换，因为它使用时间戳来存储变换信息。

**API设计**

tf：tf的API设计相对简单，但在某些方面可能不够灵活。
tf2：tf2的API设计更加现代化，提供了更多的功能和灵活性，例如可以处理非线性变换。

**数据结构**

tf：tf使用Transform和StampedTransform数据结构来存储坐标变换信息。
tf2：tf2使用Transform、StampedTransform和TimePoint数据结构，提供了更丰富的时间相关功能。

**缓冲机制**

tf：tf有一个缓冲区（Buffer），用于存储坐标变换信息。
tf2：tf2有两个缓冲区：BufferCore和Buffer。BufferCore是一个轻量级的缓冲区，只存储变换信息；而Buffer是一个更高级的缓冲区，提供了额外的功能，如时间缓存和回调机制。

**消息类型**

tf：tf使用tf::Transform和tf::StampedTransform消息类型。
tf2：tf2使用geometry_msgs::TransformStamped消息类型。

**性能**

tf2相较于tf在性能上有所提升，尤其是在处理大量坐标帧和变换时。

**功能**

tf2提供了一些tf没有的新功能，例如对加速度和速度的跟踪。

总的来说，tf2是tf的一个改进版本，它提供了更多的功能和更高的灵活性。



ROS中通过类似topic的形式发布（广播）与订阅（监听）各组件间的位姿关系，接下来我们介绍这一机制。

https://wiki.ros.org/tf

### 4.2.1 位姿描述

位姿，即位置和姿态角。在二维空间中，使用二维点和相对于x轴正向的夹角（弧度）描述一个位姿：
$$
Pose_{2D}=(x,y; \theta_{x})
$$
类似的，在三维空间中，应该使用三维点和相对于xyz三个轴的夹角（弧度）描述一个位姿：
$$
Pose_{3D}=(x,y,z; \theta_{x},\theta_{y},\theta_{z})
$$
但在执行三维位姿变换时，这种表示会有一些问题。其中相对三轴的角度表示方法我们称为欧拉角（该方法是数学家欧拉提出的），欧拉角变换，需要相对XYZ轴进行三次变换，如果第二次变换角为 $\pm90^\circ$ 时，第一次变换和第三次变换使用同一个轴，这就是欧拉角的万向锁问题。

所以欧拉角并不适用于三维变换计算，但由于其直观性，通常出现在人机交互场景，内部计算通常使用四元数。

四元数是复数空间的定义，即我们升了一个维度来表示三维旋转，一个四元数由一个实部和三个虚部组成：
$$
q=q_0+q_1i+q_2j+q_3k
$$
其中 $i,j,k$ 满足：
$$
\begin{cases}
\ i^2=j^2=k^2=-1\\
\ ij=-ji=k\\
\ jk=-kj=i\\
\ ki=-ik=j
\end{cases}
$$
ROS的TF2中提供了相关的消息体格式与计算接口。



### 4.2.2 消息体类型

常用的消息体有：`geometry_msgs/TransformStamped` 和 `geometry_msgs/PoseStamped`

`geometry_msgs/TransformStamped` 用于表示变换的信息（平移+旋转）

`geometry_msgs/PoseStamped` 用于表示坐标点的位姿（位置+姿态角）

#### 4.2.2.1 geometry_msgs/TransformStamped

`geometry_msgs/TransformStamped.msg` 的内容如下：

```yaml
Header header
string child_frame_id # the frame id of the child frame
Transform transform
```

说明：

它由三部分组成，`header`、`child_frame_id` 和 `transform` ，

其中，`header` 是 `std_msgs/Header` 类型，通常用于记录时间戳和坐标系id，结构如下：

```yaml
uint32 seq      # 序列号
time stamp      # 时间戳
string frame_id # 父坐标系id
```

`child_frame_id` 用于表示变换中的子坐标系id

`transform` 是该变换的信息，结构如下：

```yaml
Vector3 translation # 一个三维向量，表示平移
Quaternion rotation # 一个四元数，表示旋转
```

使用 `rosmsg info geometry_msgs/TransformStamped` 可以查看 `geometry_msgs/TransformStamped` 的全部信息，如下：

![image-20231210223406402](img/image-20231210223406402.png)

#### 4.2.2.2 geometry_msgs/PoseStamped

`geometry_msgs/PoseStamped` 的内容如下：

```yaml
Header header
Pose pose
```

说明：

它由两部分组成，`header`  和 `pose` ，

同样，`header`  用于记录时间戳和坐标系id，

`pose` 是坐标点的位姿，结构如下：

```yaml
Point position         # 一个三维坐标，表示位置
Quaternion orientation # 一个四元数，表示姿态角
```

同样，使用 `rosmsg info geometry_msgs/PoseStamped` 可以查看 `geometry_msgs/PoseStamped` 的全部信息，如下：

![image-20231210224421439](img/image-20231210224421439.png)



### 4.2.3 广播与监听位姿关系

如前文所述，ROS通过广播的形式告知各模块的位姿关系，接下来详述这一机制的代码实现。

模块间的位置关系有两种类型，一种是相对固定的，称为静态坐标变换，一种是相对不固定，随时变化的，称为动态坐标变换。

#### 4.2.3.1 静态坐标变换（C++）

所谓静态坐标变换，是指两个坐标系之间的相对位置是固定的。比如机器人底盘上安装了一个激光雷达，他和底盘组成一个刚体，它们的相对位姿不会随机器人的运动而变化，他们之间的坐标变换即属于静态坐标变换。

假设激光雷达相对于底盘的欧拉位姿为（0.5, 0.0, 0.3; 0.0, 0.0, 0.0）

雷达检测到的障碍物位置为（2.0, 2.5, 0.3）

若要计算障碍物和底盘的相对位置，就可以通过雷达到底盘的坐标变换来计算，步骤如下：

1. 雷达（laser）发布自己和底盘（base_link）的相对静态坐标
2. 避障模块监听雷达（laser）和底盘（base_link）的相对坐标关系，并通过`tf` 计算障碍物位置。



首先创建 `tf2_learning` 包，命令如下：（这一步不是必须，这里只是为了方便清晰的说明，也可以使用已有的包，在包里新增节点等方法）

```bash
catkin_create_pkg tf2_learning roscpp rospy geometry_msgs std_msgs tf2 tf2_geometry_msgs tf2_ros
```

创建后，文件结构如下：

![image-20231229223721024](img/image-20231229223721024.png)



在创建的 `tf2_learning` 包路径下有一个 `src` 目录，在这里存储C++源码，我们创建 `static_frame_broadcast.cpp` 和 `static_frame_listen.cpp` ，修改 `CMakeLists.txt` ，添加如下内容：

```cmake
add_executable(${PROJECT_NAME}_broadcast src/static_frame_broadcast.cpp)
add_executable(${PROJECT_NAME}_listen src/static_frame_listen.cpp)

target_link_libraries(${PROJECT_NAME}_broadcast
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}_listen
  ${catkin_LIBRARIES}
)
```

`static_frame_broadcast.cpp` 实现广播子坐标系相对于父坐标系的静态坐标，内容如下：

```cpp
#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char **argv)
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "static_frame_broadcast");

    // 创建静态坐标转换广播器
    tf2_ros::StaticTransformBroadcaster broadcaster;

    // 创建坐标系信息
    geometry_msgs::TransformStamped ts;
    // --设置头信息
    ts.header.seq = 100;
    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "base_link";
    // --设置子级坐标系
    ts.child_frame_id = "laser";
    // --设置子坐标系相对于父坐标系的平移偏移量
    ts.transform.translation.x = 0.5;
    ts.transform.translation.y = 0.0;
    ts.transform.translation.z = 0.3;
    // --设置子坐标系相对于父坐标系的旋转偏移量
    // --将欧拉角转换成四元数
    tf2::Quaternion qtn; // tf2的四元数类
    qtn.setRPY(0, 0, 0); // 设置欧拉角
    // 获取旋转的四元数值
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    // 广播器发布坐标系信息
    broadcaster.sendTransform(ts);

    ros::spin();

    return 0;
}
```

`static_frame_listen.cpp` 实现订阅静态坐标转换关系，并利用该关系将雷达坐标系的点转换到 base_link 坐标系，内容如下：

```cpp
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "static_frame_listen");

    ros::NodeHandle nh;

    // 创建 TF 订阅节点
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate rate(1);
    while (ros::ok())
    {
        // 生成一个坐标点, 模拟雷达检测到的障碍物坐标点(雷达坐标系下的坐标)
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id = "laser";
        point_laser.header.stamp = ros::Time::now();
        point_laser.point.x = 2.0;
        point_laser.point.y = 2.5;
        point_laser.point.z = 0.3;

        // 转换坐标点, 计算障碍物坐标点在 base_link 下的坐标
        try
        {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_laser, "base_link");
            ROS_INFO("point_base: (%.2f, %.2f, %.2f), frame: %s",
                     point_base.point.x, point_base.point.y, point_base.point.z,
                     point_base.header.frame_id.c_str());
        }
        catch (const std::exception &e)
        {
            ROS_ERROR("%s", e.what());
        }

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
```

编译后，执行 `rosrun tf2_learning tf2_learning_broadcast` 开始广播坐标，此时打开`rviz`订阅`TF`看到TF树模型，操作与结果如下：

- 输入命令：rviz
- 在启动的 rviz 中设置 `Fixed Frame` 为 `base_link`
- 点击左下的 `Add` 按钮，在弹出的窗口中选择 `TF` 组件，即可显示坐标关系。

![image-20231224221143279](img/image-20231224221143279.png)

继续执行命令`rosrun tf2_learning tf2_learning_listen`可以看到转换后的坐标，以及所属父坐标系，如下：

![image-20231230184519804](img/image-20231230184519804.png)

其中，`ERROR`是由于节点刚起来时，TF数据还未来得及写入缓存，导致`base_link`不存在，可以发现第二次调用就没有报错了，实际使用中，可以等待要操作的`frame`存在再做转换，如下：

```cpp
tf2_ros::Buffer buffer;
tf2_ros::TransformListener listener(buffer);
// _frameExists()返回指定frame是否存在于tf树中
if (!buffer._frameExists("base_link"))
{
    ROS_WARN("base_link frame does not exist.");
}
```

#### 4.2.3.2 静态坐标变换（Python）

在创建的 `tf2_learning` 包路径下 `src` 目录的同级，创建一个 `scripts` 目录，在这里存储脚本（如python脚本），我们创建 `tf2_learning_broadcast.py` 以实现坐标广播，编辑内容如下：

```python
#! /usr/bin/env python

import rospy
import tf
import tf2_ros
from geometry_msgs.msg import TransformStamped


if __name__ == "__main__":

    # 初始化 ROS 节点
    rospy.init_node("static_frame_broadcast_py")

    # 创建静态坐标广播器
    broadcaster = tf2_ros.StaticTransformBroadcaster()

    # 创建并组织被广播的消息
    tfs = TransformStamped()
    # -- 头信息
    tfs.header.frame_id = "base_link" # 父坐标系
    tfs.header.stamp = rospy.Time.now()
    tfs.header.seq = 101
    # -- 子坐标系
    tfs.child_frame_id = "laser"
    # -- 坐标系相对信息
    # ---- 相对于父坐标系的平移偏移量
    tfs.transform.translation.x = 0.5
    tfs.transform.translation.y = 0.0
    tfs.transform.translation.z = 0.3
    # ---- 相对于父坐标系的旋转偏移量
    # ---- 设置欧拉角，并将欧拉角转换成四元数
    qtn = tf.transformations.quaternion_from_euler(0, 0, 0)
    tfs.transform.rotation.x = qtn[0]
    tfs.transform.rotation.y = qtn[1]
    tfs.transform.rotation.z = qtn[2]
    tfs.transform.rotation.w = qtn[3]

    # 广播器发送消息
    broadcaster.sendTransform(tfs)

    # spin
    rospy.spin()
```

创建 `tf2_learning_broadcast.py` 以订阅静态坐标转换关系，并利用该关系将雷达坐标系的点转换到 base_link 坐标系，编辑内容如下：

```python
#! /usr/bin/env python

import rospy
import tf2_ros
# 不要使用 geometry_msgs,需要使用 tf2 内置的消息类型
from tf2_geometry_msgs import PointStamped
# from geometry_msgs.msg import PointStamped

if __name__ == "__main__":
    # 初始化 ROS 节点
    rospy.init_node("static_frame_listen")
    # 创建 TF 订阅对象
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        # 生成一个坐标点, 模拟雷达检测到的障碍物坐标点(雷达坐标系下的坐标)
        point_laser = PointStamped()
        point_laser.header.frame_id = "laser"
        point_laser.header.stamp = rospy.Time.now()
        point_laser.point.x = 2.0
        point_laser.point.y = 2.5
        point_laser.point.z = 0.3

        try:
            # 转换坐标点, 计算障碍物坐标点在 base_link 下的坐标
            point_base = buffer.transform(point_laser, "base_link")
            rospy.loginfo("point_base: (%.2f, %.2f, %.2f), frame: %s",
                          point_base.point.x,
                          point_base.point.y,
                          point_base.point.z,
                          point_base.header.frame_id)
        except Exception as e:
            rospy.logerr("%s", e)

        # spin
        rate.sleep()
```



#### 4.2.3.4 动态坐标变换（C++）

所谓动态坐标变换，是指两个坐标系之间的相对位置是变化的。比如机械臂末端执行器与 base_link 之间，移动机器人base_link与world之间。可以理解动态坐标关系是随时间变化的静态坐标关系（即静态是动态对时间的微分）。

我们使用ROS的 `turtlesim` 模拟一个移动机器人，通过`TF`发布它相对世界坐标系的坐标。

在创建的 `tf2_learning` 包路径下的 `src` 目录中创建 `dynamic_frame_broadcast.cpp` 和 `dynamic_frame_listen.cpp` ，修改 `CMakeLists.txt` ，添加如下内容：

```cmake
add_executable(${PROJECT_NAME}_dynamic_broadcast src/dynamic_frame_broadcast.cpp)
add_executable(${PROJECT_NAME}_dynamic_listen src/dynamic_frame_listen.cpp)

target_link_libraries(${PROJECT_NAME}_dynamic_broadcast
  ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}_dynamic_listen
  ${catkin_LIBRARIES}
)
```

`dynamic_frame_broadcast.cpp` 实现广播子坐标系相对于父坐标系的动态坐标关系，内容如下：

```cpp
/**
 * @file: dynamic_frame_broadcast.cpp
 * @brief: 动态的坐标系相对姿态发布
 * @author: 万俟淋曦(1055311345@qq.com)
 * @date: 2023-12-30 22:47:33
 * @modifier:
 * @date: 2023-12-30 22:47:33
 */

#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

void turtle1PoseCallback(const turtlesim::Pose::ConstPtr &pose)
{
    // 创建 TF 广播器
    static tf2_ros::TransformBroadcaster broadcaster;

    // 创建 广播的数据
    geometry_msgs::TransformStamped tfs;
    // --头设置
    tfs.header.frame_id = "world";
    tfs.header.stamp = ros::Time::now();
    // --坐标系id
    tfs.child_frame_id = "turtle1";
    // --坐标系相对信息设置
    tfs.transform.translation.x = pose->x;
    tfs.transform.translation.y = pose->y;
    tfs.transform.translation.z = 0.0; // 二维, z为0
    //  --欧拉角转四元数
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta); // 二维, 只有偏航角
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();

    // 广播器发布数据
    broadcaster.sendTransform(tfs);
}

int main(int argc, char **argv)
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "dynamic_frame_broadcast");

    // 创建 ROS 句柄
    ros::NodeHandle nh;

    // 创建订阅对象，订阅乌龟的世界位姿
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, turtle1PoseCallback);

    ros::spin();

    return 0;
}
```

`dynamic_frame_listen.cpp` 订阅动态坐标转换关系，并利用该关系将小乌龟坐标系下的坐标转换到 `world` 坐标系，编辑内容如下：

```cpp
/**
 * @file: dynamic_frame_listen.cpp
 * @brief: 订阅动态坐标系并转换相应坐标
 * @author: 万俟淋曦(1055311345@qq.com)
 * @date: 2023-12-31 11:55:40
 * @modifier:
 * @date: 2023-12-31 11:55:40
 */
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h" // 包含TF坐标转换方法

int main(int argc, char **argv)
{
    // 初始化 ROS 节点
    ros::init(argc, argv, "dynamic_frame_listen");
    ros::NodeHandle nh;

    // 创建 TF 订阅节点
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate r(1);
    while (ros::ok())
    {
        // 生成一个坐标点, 模拟末端执行器坐标系下的点坐标(小乌龟坐标系下的坐标)
        geometry_msgs::PointStamped point_turtle1;
        point_turtle1.header.frame_id = "turtle1";
        point_turtle1.header.stamp = ros::Time();
        point_turtle1.point.x = 1;
        point_turtle1.point.y = 1;
        point_turtle1.point.z = 0;

        // 转换坐标点, 计算小乌龟坐标系下的坐标点在 world 下的坐标
        try
        {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_turtle1, "world");
            ROS_INFO("point_base: (%.2f, %.2f, %.2f), frame: %s", 
                point_base.point.x, 
                point_base.point.y, 
                point_base.point.z,
                point_base.header.frame_id.c_str());
        }
        catch (const std::exception &e)
        {
            ROS_ERROR("%s", e.what());
        }

        r.sleep();
        ros::spinOnce();
    }

    return 0;
}
```

编译后，

- 首先开启小乌龟 `rosrun turtlesim turtlesim_node`
- 执行 `rosrun tf2_learning tf2_learning_dynamic_broadcast` 开始广播坐标，此时打开`rviz`订阅`TF`看到TF树模型

- 输入命令：rviz
- 在启动的 rviz 中设置 `Fixed Frame` 为 `world`
- 点击左下的 `Add` 按钮，在弹出的窗口中选择 `TF` 组件，即可显示坐标关系，如下：

![image-20231231122613284](img/image-20231231122613284.png)

继续执行命令`rosrun tf2_learning tf2_learning_listen`可以看到转换后的坐标，以及所属父坐标系

![image-20231231122932914](img/image-20231231122932914.png)

执行命令 `rosrun turtlesim turtle_teleop_key` 使用键盘控制小乌龟移动，可以看到 `rviz`以及转换后的坐标都在同步动态变化。

![Peek 2023-12-31 13-00](img/Peek 2023-12-31 13-00.gif)

#### 4.2.3.5 动态坐标变换（Python）

在创建的 `tf2_learning` 包路径下 `src` 目录的同级，创建一个 `scripts` 目录，在这里存储脚本（如python脚本），我们创建 `dynamic_frame_broadcast.py` 以实现坐标广播，编辑内容如下：

```python
#! /usr/bin/env python

import rospy
import tf2_ros
import tf
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped

# 回调函数处理
def turtle1PoseCallback(pose):
    # 创建 TF 广播器
    broadcaster = tf2_ros.TransformBroadcaster()
    # 创建 广播的数据(通过 pose 设置)
    tfs = TransformStamped()
    tfs.header.frame_id = "world"
    tfs.header.stamp = rospy.Time.now()
    tfs.child_frame_id = "turtle1"
    tfs.transform.translation.x = pose.x
    tfs.transform.translation.y = pose.y
    tfs.transform.translation.z = 0.0
    qtn = tf.transformations.quaternion_from_euler(0,0,pose.theta)
    tfs.transform.rotation.x = qtn[0]
    tfs.transform.rotation.y = qtn[1]
    tfs.transform.rotation.z = qtn[2]
    tfs.transform.rotation.w = qtn[3]
    # 广播器发布数据
    broadcaster.sendTransform(tfs)

if __name__ == "__main__":
    # 初始化 ROS 节点
    rospy.init_node("dynamic_frame_broadcast_py")
    # 订阅 /turtle1/pose 话题消息
    sub = rospy.Subscriber("/turtle1/pose", Pose, turtle1PoseCallback)
    rospy.spin()
```

创建 `dynamic_frame_listen.py` 以订阅静态坐标转换关系，并利用该关系将雷达坐标系的点转换到 world 坐标系，编辑内容如下：

```python
#! /usr/bin/env python

import rospy
import tf2_ros
# 不要使用 geometry_msgs,需要使用 tf2 内置的消息类型
from tf2_geometry_msgs import PointStamped
# from geometry_msgs.msg import PointStamped

if __name__ == "__main__":
    # 初始化 ROS 节点
    rospy.init_node("dynamic_frame_listen_py")
    # 创建 TF 订阅对象
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():    
    # 创建一个 radar 坐标系中的坐标点
        point_source = PointStamped()
        point_source.header.frame_id = "turtle1"
        point_source.header.stamp = rospy.Time.now()
        point_source.point.x = 10
        point_source.point.y = 2
        point_source.point.z = 3

        try:
            # 转换坐标点, 计算小乌龟坐标系下的坐标点在 world 下的坐标
            point_target = buffer.transform(point_source,"world",rospy.Duration(1))
            rospy.loginfo("point_target: (%.2f, %.2f, %.2f), frame: %s",
                            point_target.point.x,
                            point_target.point.y,
                            point_target.point.z,
                            point_target.header.frame_id)
        except Exception as e:
            rospy.logerr("%s", e)

        rate.sleep()
```



#### 4.2.3.6 TF树

在机器人系统中，存在运动学模型和动力学模型。对于刚体机器人，动力学模型基于刚体动力学，代表机器人系统在运动过程中力/力矩与其运动状态的变化关系。而运动学模型则由一系列固连在不同位置的坐标系来表示，仅仅代表机器人的运动状态。例如，对于多自由度机械臂，其运动学模型为末端位置到各个关节角的坐标变换关系；对于旋翼无人机，主要的运动学关系是机体固连坐标系与世界坐标系之间的变换。

TF树在ROS中的作用就是对应于这些不同位置固连坐标系之间的变换关系，以显示机器人的运动状态。TF树的广播器和监听器的基本书写形式可以通过实际例子进行分析，从中可以展示如何提取和应用TF变换的信息。总的来说，TF树是ROS中非常重要的一部分，它维护了整个机器人甚至地图的坐标转换关系。

对于一个完整的机器人来说，会有很多个坐标系，如下图：

![PR2坐标变换](img/PR2坐标变换.png)

每广播一个坐标关系，ROS都会把他加入到一个列表中维护起来，这个列表就是TF树。

它是ROS中管理坐标系变换关系的一种数据结构，它对应于机器人不同位置固连坐标系之间的变换关系，以显示机器人的运动状态。TF的本质是一个树状的数据结构，所以被称为TF树。

此外，TF库也是ROS中的一个重要组成部分，它允许用户随时记录并管理多个坐标系之间的变换关系。tf库维护了坐标系之间的关系，并在时间上缓冲这种关系，使用户能够在任何所需的时间点在任何两个坐标系之间转换点、向量等。



使用以下命令可以把TF树保存为pdf文档（如果没有安装 `tf2_tools` 需要先安装 `sudo apt install ros-noetic-tf2-tools`）：

```bash
rosrun tf2_tools view_frames.py

执行后会打印入下日志：
[INFO] [1704000786.800796]: Listening to tf data during 5 seconds...
[INFO] [1704000791.808397]: Generating graph in frames.pdf file...
```

实验步骤：

- 运行前文编译的静态坐标转换节点： `rosrun tf2_learning tf2_learning_broadcast`
- 运行前文编译的动态坐标转换节点：`rosrun tf2_learning tf2_learning_dynamic_broadcast`
- 启动小乌龟，发布小乌龟的世界坐标位姿：`rosrun turtlesim turtlesim_node`
- 保存TF树pdf文档：`rosrun tf2_tools view_frames.py`
- 查看pdf文档：`evince frames.pdf`（也可以直接双击打开文档）

![image-20231231133600028](img/image-20231231133600028.png)

可以发现，我们发布了两组坐标关系`bask_link -> laser` 和 `world -> turtle1` ，`base_link` 与 `world` 的坐标关系没有发布，所以有两棵TF树，现在我们发布`base_link` 与 `world` 的坐标关系来看看效果。

ROS为我们封装了单次发布坐标关系的节点，使用方法如下：

```bash
rosrun tf2_ros static_transform_publisher param0 param1 param2 param3 param4 param5 param6 param7
后面有8个参数，依次表示：
x偏移量 y偏移量 z偏移量 z偏航角度 y俯仰角度 x翻滚角度 父级坐标系 子级坐标系
```

我们发布 `base_link` 与 `world` 的坐标关系：

位置偏移量为：(0.5, 0.8, 0)

旋转偏移量为：(1.57, 0.0, 0.0)  角度单位为弧度

所以命令如下：

```bash
rosrun tf2_ros static_transform_publisher 0.5 0.8 0 0 0 1.5 /world /base_link
```

查看TF树如下：

![image-20231231140607453](img/image-20231231140607453.png)

rviz查看坐标关系如下：

![image-20231231142103939](img/image-20231231142103939.png)



## 4.3 rosbag

有时我们需要将 topic 中的数据保存下来以便后面分析，为了提供这一功能，ROS提供了 `rosbag` 工具集。

rosbag提供了API接口和命令行工具，其中常见的API包括C++和Python。

### 4.3.1 rosbag 命令行

常用命令行

```bash
rosbag check  	    检查一个包是否可以在当前系统中播放
rosbag compress  	压缩一个或多个bag文件
rosbag decompress  	解压缩一个或多个bag文件
rosbag filter  	    根据条件过滤bag文件内容
rosbag fix  	    修复bag文件中的消息，以便在当前系统中播放
rosbag info  	    查看bag文件简要信息
rosbag play  	    以时间同步的方式播放一个或多个bag文件的内容
rosbag record  	    记录一个包含指定topic内容的bag文件
rosbag reindex      重新索引一个或多个bag文件
```

#### 4.3.1.1 rosbag check

有时我们需要更新topic的msg，但对于已经录制的bag文件，它使用的是旧的msg，此时的bag文件会与系统的新msg发生冲突，ROS为了解决这一问题，设计了 `bag migration` [包迁移机制](http://wiki.ros.org/rosbag/migration) 。一个bag文件是否需要迁移则可以使用 `rosbag check` 命令检查。

![image-20240219153037017](img/image-20240219153037017.png)



#### 4.3.1.2 rosbag compress

压缩一个或多个bag文件

目前支持 `bz2`和`lz4` 格式，默认为 `bz2` ，使用 `--lz4` 选项可以选择 `lz4` 压缩格式。

另外，每次压缩文件之前，会备份每个包文件（扩展名为 .orig.bag），如果备份文件已存在（并且未指定 `-f` 选项），则该工具将不会压缩该文件。

该指令选项说明如下：

`compress <bag-files>`

使用`bz2` 格式压缩bag文件

```bash
rosbag compress *.bag
```


`--output-dir=DIR`

设置文件保存路径

```bash
rosbag compress --output-dir=compressed *.bag
```



`-f, --force`

强制重写备份文件

```bash
rosbag compress -f *.bag
```



`-q, --quiet`

抑制非关键信息

```bash
rosbag compress -q *.bag
```



`-j, --bz2`

使用bz2格式压缩数据

```bash
rosbag compress -j *.bag
```



`--lz4`

使用lz4格式压缩数据

```bash
rosbag compress --lz4 *.bag
```



#### 4.3.1.3 rosbag decompress  	

解压缩一个或多个bag文件

每次解压缩文件之前，会备份每个包文件（扩展名为 .orig.bag），如果备份文件已存在（并且未指定 `-f` 选项），则该工具将不会解压缩该文件。

该指令选项说明如下：

`decompress <bag-files>`

使用`bz2` 格式压缩bag文件

```bash
rosbag decompress *.bag
```



`--output-dir=DIR`

设置文件保存路径

```bash
rosbag decompress --output-dir=compressed *.bag
```



`-f, --force`

强制重写备份文件

```bash
rosbag decompress -f *.bag
```



`-q, --quiet`

抑制非关键信息

```bash
rosbag decompress -q *.bag
```



#### 4.3.1.4 rosbag filter

根据条件过滤bag文件内容

显示与指定python语法的逻辑表达式匹配的消息

```bash
rosbag filter input.bag output.bag "逻辑表达式"
rosbag filter input.bag output.bag "m.data=='foo'"
```

其中，`input.bag`表示过滤之前的bag文件，`output.bag`表示过滤之后的bag文件。

逻辑表达式中的 `m` 表示 `msg`，另外，还有 `topic` 表示 `topic`，`t` 表示 `timestamp`。

该命令的选项说明如下：

`--print=PRINT-EXPRESSION`

将逻辑表达式的匹配情况打印出来

```bash
rosbag filter --print="'%s @ %d.%d: %s' % (topic, t.secs, t.nsecs, m.data)" big.bag small.bag "topic == '/chatter'"
```



#### 4.3.1.5 rosbag fix  	    

修复bag文件中的消息，以便在当前系统中播放

如前`rosbag check` 所述，如果bag文件需要迁移，则可以使用 `rosbag fix` 修复。

```bash
rosbag fix old.bag repaired.bag myrules.bmr
```

其中，`old.bag`为修复之前的bag文件，`repaired.bag` 为修复之后的bag文件，`myrules.bmr`为修复规则，修复规则相关详见 [包迁移机制](http://wiki.ros.org/rosbag/migration) 。



#### 4.3.1.6 rosbag info  	    

查看bag文件简要信息

![image-20240219164709173](img/image-20240219164709173.png)

该命令的选项说明如下：

`-y, --yaml`

以 YAML 格式输出

```bash
rosbag info -y test.bag
```

![image-20240219165154308](img/image-20240219165154308.png)



`-k KEY, --key=KEY`

仅打印给定字段信息（需要配合`-y`选项使用）

![image-20240219165540989](img/image-20240219165540989.png)



#### 4.3.1.7 rosbag play  	    

以时间同步的方式播放一个或多个bag文件的内容

```bash
rosbag play test1.bag test2.bag
```

在播放时可以随时按 `空格键` 以暂停播放，同时暂停播放后，可以按 `s` 键以单步播放。

该命令的选项说明如下：
`-i, --immediate`

立即播放所有topic

```bash
rosbag play -i recorded1.bag
```



`--pause`

以暂停模式开始播放

```bash
rosbag play --pause recorded1.bag
```



`--queue=SIZE`

使用大小为SIZE的传出队列 (defaults to 0. As of 1.3.3 defaults to 100).

```bash
rosbag play --queue=1000 recorded1.bag
```



`--clock`

发布时钟时间

```bash
rosbag play --clock recorded1.bag
```



`--hz=HZ`

已指定频率Hz发布 (default: 100).

```bash
rosbag play --clock --hz=200 recorded1.bag
```



`-d SEC, --delay=SEC`

每次调用发布者后等待SEC秒，以等待订阅者连接

```bash
rosbag play -d 5 recorded1.bag
```



`-r FACTOR, --rate=FACTOR`

将发布频率乘以 FACTOR.

```bash
rosbag play -r 10 recorded1.bag
```



`-s SEC, --start=SEC`

开始SEC秒进入bag

```bash
rosbag play -s 5 recorded1.bag
```



`-u SEC, --duration=SEC`

仅播放包文件中的 SEC 秒。

```bash
rosbag play -u 240 recorded1.bag
```



`--skip-empty=SEC`

跳过包中超过 SEC 秒没有消息的区域。

```bash
rosbag play --skip-empty=1 recorded1.bag
```



`-l, --loop`

循环播放

```bash
rosbag play -l recorded1.bag
```



`-k, --keep-alive`

在包结束后保持活动状态（对于发布锁定的主题很有用）。

```bash
rosbag play -k recorded1.bag
```



`--try-future-version`

即使用户不知道版本号，仍然尝试打开包文件



`--topics`

指定要播放的主题

```bash
rosbag play recorded1.bag --topics /topic1 /topic2 /topic3
```



`--pause-topics`

播放期间暂停的主题



`--bags=BAGS`

打包要播放的文件



`--wait-for-subscribers`

发布前等待每个主题至少有一个订阅者



`--rate-control-topic=RATE_CONTROL_TOPIC`

观察给定主题，如果上次发布时间超过 <rate-control-max-delay> 之前，则等到该主题再次发布才能继续播放



`--rate-control-max-delay=RATE_CONTROL_MAX_DELAY`

暂停前与 <rate-control-topic> 的最大时间差



#### 4.3.1.8 rosbag record

记录一个包含指定topic内容的bag文件

如果以高带宽录制消息（例如来自摄像机），强烈建议在摄像机所在的同一台计算机上运行`rosbag record`，并将文件目标指定为本地计算机磁盘上。

可以指定多个topic

```bash
rosbag record rosout tf cmd_vel
```

该命令的选项说明如下：

`-a, --all`

记录所有topic，订阅topic是通过轮询master注册topic实现的，`rosbag record -a` 可能会错过某些topic的初始消息。

```bash
rosbag record -a
```



`-e, --regex`

通过正则匹配topic

```bash
rosbag record -e "/(.*)_stereo/(left|right)/image_rect_color"
```



`-p, --publish` **New in ROS Melodic**

排除与给定正则表达式匹配的主题（从`-a`或`-e`中减去）。

```bash
rosbag record -e "/wide_stereo(.*)" -x "(.*)/points(.*)"
```



`-d, --duration`

指定录制的包文件的最大持续时间。

```bash
rosbag record --duration=30 /chatter
rosbag record --duration=5m /chatter
rosbag record --duration=2h /chatter
```



`--max-splits=MAX_SPLITS` **New in ROS Kinetic**

最多拆分包 MAX_SPLITS 次，然后开始删除最旧的文件。这将创建固定大小或持续时间的记录。

```bash
rosbag record --split --size 1024 --max-splits 3 /chatter
rosbag record --split --duration 10m --max-splits 6 /chatter
```



`-b SIZE, --buffsize=SIZE`

使用 SIZE MB 的内部缓冲区（默认值：256，0 = 无限）。这是在消息传递到包之前记录器对象的消息队列。降低此值可能会导致消息在到达记录进程之前被丢弃。

```bash
rosbag record -b 1024 /chatter
```



`--chunksize=SIZE`

记录到 SIZE KB 的块（默认值：768）。这是包文件对象内的缓冲区。降低该值将导致更多的磁盘写入。

```bash
rosbag record --chunksize=1024 /chatter
```



`-l NUM, --limit=NUM`

每个topic仅记录 NUM 条消息。

```bash
rosbag record -l 1000 /chatter
```



`--node=NODE`

记录指定节点订阅的所有主题

```bash
rosbag record --node=/joy_teleop
```



`-j, --bz2`

使用 BZ2 压缩。详细信息请参见 rosbag compress

```bash
rosbag record -j /chatter
```



`--lz4`

使用LZ4压缩。详细信息请参见 rosbag compress

```bash
rosbag record --lz4 /chatter
```



`-tcpnodelay`

订阅主题时使用 TCP_NODELAY 传输提示



`--udp`

订阅主题时使用 UDP 传输提示



#### 4.3.1.9 rosbag reindex

用于修复损坏的包文件（或 ROS 版本 0.11 之前记录的包文件）。如果由于任何原因未完全关闭包，则索引信息可能会损坏。使用该工具重新读取消息数据并重建索引。

没有索引的bag文件通常不能直接通过时间戳来高效地查询特定消息，但你可以从头到尾顺序地读取它们。

请注意，使用未索引的bag文件可能会降低性能，并且在某些情况下可能会导致功能受限。因此，通常建议在处理bag文件之前先建立索引。

在重新索引包之前，会备份每个包文件（扩展名为`.orig.bag` ）。如果备份文件已存在（并且未指定`-f`选项），则该工具将不会重新索引该文件。

该命令的选项说明如下：

`--output-dir=DIR`

指定保存的路径

```bash
rosbag reindex --output-dir=reindexed *.bag
```



`-f, --force`

强制重写备份文件

```bash
rosbag reindex -f *.bag
```



`-q, --quiet`

抑制非关键信息

```bash
rosbag reindex -q *.bag
```



### 4.3.2 rosbag C++ API

rosbag 的 C++ API 主要有两个类，用于写bag文件的`Bag`类，和用于读bag文件的`View`类。

#### 4.3.2.1 rosbag::Bag

用于写bag文件。

头文件：bag.h

##### 常用接口

```cpp
# 打开bag文件
Bag (std::string const &filename, uint32_t mode=bagmode::Read)
   
# 打开bag文件
void open (std::string const &filename, uint32_t mode=bagmode::Read)

# 关闭bag文件
void close()

# 写bag文件
template<class T >
void write (std::string const &topic, ros::MessageEvent< T > const &event)

template<class T >
void write (std::string const &topic, ros::Time const &time, boost::shared_ptr< T > const &msg, boost::shared_ptr< ros::M_string > connection_header=boost::shared_ptr< ros::M_string >())

template<class T >
void write (std::string const &topic, ros::Time const &time, boost::shared_ptr< T const > const &msg, boost::shared_ptr< ros::M_string > connection_header=boost::shared_ptr< ros::M_string >())

template<class T >
void write (std::string const &topic, ros::Time const &time, T const &msg, boost::shared_ptr< ros::M_string > connection_header=boost::shared_ptr< ros::M_string >())
```

示例代码：

```cpp
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <ros/package.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "bag_write");

    std::string packagePath = ros::package::getPath("rosbag_learning");
    std::string bagsPath = packagePath + "/bags";

    ros::NodeHandle nh;
    // 创建bag对象
    rosbag::Bag bag;
    // 打开文件
    bag.open(bagsPath+"/test.bag", rosbag::BagMode::Write);
    // 写文件
    std_msgs::String msg;
    msg.data = "hello world";
    // 写入4帧
    for (size_t i = 0; i < 4; i++)
    {
        bag.write("/chatter", ros::Time::now(), msg);
    }
    // 关闭文件
    bag.close();

    return 0;
}
```

编译运行生成 `test.bag` 文件，查看该文件信息，结果如下：

![image-20240304224237679](img/image-20240304224237679.png)

可以看到成功写入了4帧数据。



##### 其他接口

```cpp
// bag文件是否被打开
bool isOpen() const;

// 获取文件名
std::string getFileName() const;

// 获取文件的打开模式，枚举如下
BagMode getMode() const; 
enum BagMode
{
    Write   = 1,
    Read    = 2,
    Append  = 4
};

// 获取rosbag文件的主版本号和次版本号
// ROS bag格式有很多版本，官方不保证不同版本之间的兼容性
// bag文件第一行记录了当前的版本号，格式如：#ROSBAG VX.Y
// 旧版本使用#ROSRECORD或#ROSLOG前缀
// 其中，X是主版本号，Y是次版本号
uint32_t getMajorVersion() const;                     
uint32_t getMinorVersion() const;  

// 获取文件大小
uint64_t getSize() const;    

// 设置/获取用于写入块的压缩方法，枚举如下
void setCompression(CompressionType compression); 
CompressionType getCompression() const;     
enum CompressionType
{
    Uncompressed = 0, // 不压缩
    BZ2          = 1, // BZ2格式
    LZ4          = 2, // LZ4格式
};

// 设置/获取 Bag 文件中每个块的最大字节数
// 在 ROS Bag 文件中，消息数据被划分为多个“块”(chunks)。每个块可能包含多个消息，并且块的大小是固定的。块的大小决定了 Bag 文件的读写效率和磁盘空间使用。
// 当向 Bag 文件中写入消息时，ROS 会尝试将消息放入当前的块。如果当前块的大小达到或超过 chunk_threshold，则 ROS 会开始一个新的块来存储后续的消息。
// 通过调整 chunk_threshold，你可以控制 Bag 文件的读写效率和磁盘空间使用。较小的 chunk_threshold 会导致更多的块，这可能会降低读写效率但可能会节省磁盘空间（因为每个块都有自己的元数据）。而较大的 chunk_threshold 则会提高读写效率，但可能会使用更多的磁盘空间。
void setChunkThreshold(uint32_t chunk_threshold); 
uint32_t getChunkThreshold() const;     

// 使用指定的加密插件加密bag文件
void setEncryptorPlugin(const std::string& plugin_name, const std::string& plugin_param = std::string());

// 交换当前bag对象与参数bag的内容
void swap(Bag&);
```



#### 4.3.2.2 rosbag::View

用于读bag文件。

头文件：view.h

##### 常用接口

```cpp
// 创建一个bag文件视图
// 将bag中的msg存到vector中，按时间升序排序
// bag：bag文件
// query：查询条件函数
// start_time：查询时间范围的开始时间
// end_time：查询时间范围的结束时间
// reduce_overlap：如果返回多个相同的消息，将它们合并为一条消息
View(bool const& reduce_overlap = false);
View(Bag const& bag, ros::Time const& start_time = ros::TIME_MIN, ros::Time const& end_time = ros::TIME_MAX, bool const& reduce_overlap = false);
View(Bag const& bag, boost::function<bool(ConnectionInfo const*)> query, ros::Time const& start_time = ros::TIME_MIN, ros::Time const& end_time = ros::TIME_MAX, bool const& reduce_overlap = false);

// 查询时间范围的开始/结束时间
ros::Time getBeginTime();
ros::Time getEndTime();

// 用于遍历vector中的msg
iterator begin();
iterator end();

// 获取vector大小（msg个数）
uint32_t size();

// 添加查询时间范围
// bag：bag文件
// query：查询条件函数
// start_time：查询时间范围的开始时间
// end_time：查询时间范围的结束时间
void addQuery(Bag const& bag, ros::Time const& start_time = ros::TIME_MIN, ros::Time const& end_time = ros::TIME_MAX);
void addQuery(Bag const& bag, boost::function<bool(ConnectionInfo const*)> query, ros::Time const& start_time = ros::TIME_MIN, ros::Time const& end_time = ros::TIME_MAX);

// 获取bag中topic的连接信息，每个topic一个结构体
// 其中返回结构体定义如下：
std::vector<const ConnectionInfo*> getConnections();
struct ROSBAG_STORAGE_DECL ConnectionInfo
{
    ConnectionInfo() : id(-1) { }

    uint32_t    id;        // topic id
    std::string topic;     // topic名字
    std::string datatype;  // topic数据类型，即topic的msg
    std::string md5sum;    // topic的MD5值
    std::string msg_def;   // msg的数据类型

    boost::shared_ptr<ros::M_string> header;
};

```



##### 代码示例

```cpp
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "bag_read");

    std::string packagePath = ros::package::getPath("rosbag_learning");
    std::string bagsPath = packagePath + "/bags";
    rosbag::Bag bag;
    bag.open(bagsPath+"/test.bag"); // BagMode is Read by default

    for (rosbag::MessageInstance const m : rosbag::View(bag))
    {
        std_msgs::String::ConstPtr i = m.instantiate<std_msgs::String>();
        if (i != nullptr)
        {
            ROS_INFO("%s", i->data.c_str());
        }
    }

    bag.close();

    return 0;
}
```

编译运行，读取上文生成的`test.bag` 文件，结果如下：

![image-20240306235605724](img/image-20240306235605724.png)



对于 `getConnections()` 函数，示例如下：

```cpp
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "bag_read");

    std::string packagePath = ros::package::getPath("rosbag_learning");
    std::string bagsPath = packagePath + "/bags";
    rosbag::Bag bag;
    bag.open(bagsPath+"/test.bag"); // BagMode is Read by default

    rosbag::View view(bag);
    std::vector<const rosbag::ConnectionInfo*> cInfo = view.getConnections();
    for (size_t i = 0; i < cInfo.size(); i++)
    {
        ROS_INFO("id: %d, topic: %s, dataType: %s, md5: %s, msg_def: %s", 
            cInfo[i]->id, cInfo[i]->topic.c_str(), cInfo[i]->datatype.c_str(),
            cInfo[i]->md5sum.c_str(), cInfo[i]->msg_def.c_str());
    }

    bag.close();

    return 0;
}
```

编译运行，结果如下：

![image-20240310225002063](img/image-20240310225002063.png)



### 4.3.3 rosbag Python API

rosbag 的 Python API 主要位于 `rosbag` 包的 `Bag` 类中，通过 `import rosbag` 导入。

`Bag` 类中的常用接口如下：

#### 4.3.3.1 构造函数与关闭文件

```python
class Bag(
    f: Any,
    mode: str = 'r',
    compression: str = Compression.NONE,
    chunk_threshold: int = 768 * 1024,
    allow_unindexed: bool = False,
    options: Any | None = None,
    skip_index: bool = False
)

class Compression:
    NONE = 'none'
    BZ2  = 'bz2'
    LZ4  = 'lz4'
    
close(self)
```

其中，

- `f`：bag文件

- `mode`：文件操作模式（r, w, a）

- `compression`：文件压缩模式，见如上 `Compression` ，默认`Compression.NONE`

- `chunk_threshold`：Bag 文件中每个块的最大字节数，默认 `768 * 1024`

- `allow_unindexed`：是否允许打开未建立索引的bag文件。说明：在实际使用中，如果你只是想查看或播放bag文件中的所有消息，而不需要基于时间戳进行精确查询，那么你可以将 `allow_unindexed` 设置为 `True`。但是，如果你打算对bag文件进行基于时间的查询或其他高级操作，最好先使用 `rosbag index` 命令建立索引，并确保在打开bag文件时 `allow_unindexed` 为 `False`（或者简单地省略该参数，因为它默认为 False）。

- `options`：字典格式，用于统一设置 `Bag` 的参数，目前只支持 `compression` 和 `chunk_threshold` ，源码处理如下：

    - ```python
        if options is not None:
            if type(options) is not dict:
            	raise ValueError('options must be of type dict')                
            if 'compression' in options:
            	compression = options['compression']
            if 'chunk_threshold' in options:
            	chunk_threshold = options['chunk_threshold']
        ```

- `skip_index`：打开bag文件时是否跳过文件的索引，这可以节省一些内存和加载时间，特别是在处理非常大的bag文件时。然而，这也意味着将无法使用基于索引的高级查询功能，比如按时间戳搜索特定的消息。



#### 4.3.3.2 属性值

```python
# 只能获取
options # 同上options
filename # bag文件名
version # rosbag的版本号
mode # 文件操作模式（r, w, a）
size # Bag文件的大小（bytes）

# 可设置可获取
compression # 文件压缩模式
chunk_threshold # Bag 文件中每个块的最大字节数
```



#### 4.3.3.3 写bag文件内容

```python
write(self, topic, msg, t=None, raw=False, connection_header=None)
```

其中，

- `topic`：写入的topic名称
- `msg`：写入的msg
- `t`：时间戳，默认None以当前时间为时间戳
- `raw`：是否已原始数据格式写入，通常不推荐这样做。
- `connection_header`：连接头信息，通常不需要手动设置。通常用于内部处理，不是常规用法的一部分。

代码示例：

```python
import rosbag
import rospkg
from std_msgs.msg import Int32, String


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

bag = rosbag.Bag(bags_path+'/pytest.bag', 'w')

try:
    s = String()
    s.string = 'hello'

    i = Int32()
    i.int = 42

    bag.write('/chatter', s)
    bag.write('/number', i)

finally:
    bag.close()
```



#### 4.3.3.4 读bag文件内容

```python
read_messages(self, 
              topics=None, 
              start_time=None, 
              end_time=None, 
              connection_filter=None, 
              raw=False, 
              return_connection_header=False)
```

其中，

- `topics`：指定读取的topic，可以是一个topic列表，如果不指定，默认读取全部topic（可选）
- `start_time`：通过时间戳过滤消息（消息的最早时间戳，rospy.Time对象）（可选）
- `end_time`：通过时间戳过滤消息（消息的最晚时间戳，rospy.Time对象）（可选）
- `connection_filter`：一个函数，用于过滤连接。它应该接受一个连接对象并返回一个布尔值，以决定是否保留该连接的消息。如果为 None，则不过滤连接。
- `raw`：一个布尔值，指定是否以原始字节形式返回消息。如果为 True，则返回原始字节数据；如果为 False（默认值），则返回解析后的 ROS 消息对象。
- `return_connection_header`： 一个布尔值，如果为 True，则返回的每条消息都会是一个元组，其中第二个元素是连接头信息。如果为 False（默认值），则只返回消息本身。
- 返回值：以（topic, message, timestamp）格式返回

代码示例：

```python
import rosbag
import rospkg

rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

bag = rosbag.Bag(bags_path+'/pytest.bag')

for topic, msg, t in bag.read_messages(topics=['/chatter', '/number']):
    print(f"Received message on topic {topic} at time {t}: {msg}")

bag.close()
```

结果如下：

![image-20240316234448791](img/image-20240316234448791.png)



#### 4.3.3.5 将bag文件缓存写入磁盘

```python
flush(self)
```

当你使用 `write()` 写入数据到 bag 文件时，数据可能不会立即被写入磁盘，而是会先被缓存起来以提高性能。调用 `flush()` 方法可以强制将这些缓存的数据写入到磁盘中，以确保所有挂起的数据都被写入到 bag 文件中。

它没有参数，并且执行后没有返回值。

在以下情况下，可能需要调用 `flush()` 方法：

- **确保数据持久化**：当你想要确保所有已经写入 rosbag.Bag 对象的数据都已经持久化到磁盘上时，可以调用 `flush()`。这在你准备关闭 bag 文件或程序即将退出时特别有用，以确保不会有数据丢失。

- **实时备份**：如果你正在实时记录数据到 bag 文件，并且想要定期备份这些数据，你可以在备份之前调用 `flush()`，以确保备份时所有需要的数据都已经写入到 bag 文件中。

代码示例：

```python
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
```

查看bag文件信息如下：

![image-20240317001208080](img/image-20240317001208080.png)



#### 4.3.3.6 重建 bag 文件索引

```python
reindex(self)
```

当使用 rosbag 记录或播放数据时，rosbag 会维护一个内部索引，以便能够高效地检索和访问数据。然而，有时索引可能会损坏或变得不一致，这时就需要使用 `reindex` 方法来重新构建索引。

`reindex(self)` 方法没有参数，它会对当前打开的 bag 文件执行索引重建操作。重建索引可能需要一些时间，具体取决于 bag 文件的大小和内容。

以下是可能需要使用 `reindex` 方法的一些场景：

- 索引损坏：如果你怀疑 bag 文件的索引已经损坏或不一致，导致无法正常访问数据，你可以尝试使用 `reindex` 方法来修复它。

- 添加新数据：如果你在 bag 文件关闭后向其中添加了新数据，但没有重新构建索引，那么这些新数据将不会被包含在旧的索引中。在这种情况下，你需要调用 `reindex` 方法来更新索引，以便能够访问这些新数据。

- 优化性能：有时，即使索引没有损坏，重新构建索引也可能有助于提高访问数据的性能。特别是当 bag 文件非常大或包含大量数据时，重建索引可以帮助优化数据结构，提高检索速度。

代码示例：

```python
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
```



#### 4.3.3.7 获取bag文件的压缩信息

```
get_compression_info(self)
```

这个方法返回一个tuple(str, int, int)，其中包含了关于 bag 文件压缩的详细信息，每一位表示如下：

- `tuple[0]`：压缩格式，例如 `none`（表示没有压缩）或 `bz2`（表示使用了 bzip2 压缩）。
- `tuple[1]`：未压缩的数据大小（以字节为单位）
- `tuple[2]`：压缩后的数据大小（以字节为单位）

代码示例：

```python
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
```



#### 4.3.3.8 获取bag文件的消息数量

```python
get_message_count(self, topic_filters=None)
```

这个方法允许你指定一个或多个话题过滤器（topic_filters），以便只计算特定话题的消息数。该参数接收一个字符串或字符串列表，用于指定要计算消息数的话题。如果未提供或设置为 None，则计算 bag 文件中所有话题的消息数。

代码示例：

```python
import rosbag
import rospkg 


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

# 打开一个存在的 bag 文件
with rosbag.Bag(bags_path+'/pytest.bag', 'r') as bag:

    # 定义我们想要计算消息数的话题过滤器列表
    topic_filters = ['/chatter', '/number']

    # 获取指定话题的消息数量
    message_counts = bag.get_message_count(topic_filters=topic_filters)
      
    # 打印话题的消息数量
    print(f"Message Count: {message_counts}")
```



#### 4.3.3.9 获取bag文件记录的起止时间

```python
get_start_time(self)
get_end_time(self)
```

`get_start_time` 函数的返回类型是 float，表示以秒为单位的时间戳，其中的小数部分，表示秒的分数。

代码示例：

```python
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
```

运行结果如下：

![image-20240317102534862](img/image-20240317102534862.png)



#### 4.3.3.10 获取话题信息与消息类型

```python
get_type_and_topic_info(self, topic_filters=None)
```

其中，`topic_filters` 用于过滤指定的话题，如果没有提供，则分析所有话题。

函数返回值类型如下：

```python
TypesAndTopicsTuple(dict(str, str), 
                    dict(str, TopicTuple(str, int, int, float)))
```

其中各值说明如下：

```python
TypesAndTopicsTuple(
    		msg_types{key:type name, val: md5hash}, 
            topics{key: topic name, 
                   value: TopicTuple(msg_type: msg type (Ex. "std_msgs/String"),
                   message_count: the number of messages of the particular type,
                   connections: the number of connections,
                   frequency: the data frequency)})
```

其中，

- `msg_types`：是一个字典，key为msg类型，value为msgMD5值。
- `topics`：是一个字典，key为topic名称，value是一个元组，其中：
    - `msg_type`：该topic的消息类型
    - `message_count`：该topic的消息数量
    - `connections`：该topic的连接数量
    - `frequency`：该topic的数据频率

代码示例：

```python
import rosbag
import rospkg
from datetime import datetime


rospack = rospkg.RosPack()
package_path = rospack.get_path('rosbag_learning')
bags_path = package_path + "/bags"

# 打开一个存在的 bag 文件
with rosbag.Bag(bags_path+'/pytest.bag', 'r') as bag:

    topic_filters = ['/chatter', '/number']
    msg_types, topics = bag.get_type_and_topic_info(topic_filters)
    print("Message Types:")
    for type_name, md5_hash in msg_types.items():
        print(f"  {type_name}: {md5_hash}")

    print("Topics:")
    for type_name, topic_info in topics.items():
        print("  Topic: {}, Type: {}, MessageCount: {}, Connections: {}, Frequency: {}".format(
            type_name, 
            topic_info.msg_type, 
            topic_info.message_count, 
            topic_info.connections,
            topic_info.frequency))
```

运行结果：

![image-20240317113052497](img/image-20240317113052497.png)



## 4.3 rqt可视化工具箱

`rqt`是`ROS`的一个软件框架，以插件的形式实现各种GUI工具。可以在 `rqt` 中将所有现有的 GUI 工具作为子窗口运行，也可以以独立方法运行，但 `rqt` 可以更轻松地同时管理屏幕上的所有各种窗口。用户可以使用Python或C++创建自己的 rqt 插件。

在终端输入`rqt` 即可运行（也可以输入 `rosrun rqt_gui rqt_gui`），如下：

![image-20240317214700717](img/image-20240317214700717.png)

可以在 `Plugins` 中选择需要的插件。



### 4.3.1 日志工具

#### 4.3.1.1 Console

`Console` 可以通过图形化查看发布到 `rosout` 的消息，他会不停的收集信息并提供日志过滤功能。

**启动方法：**在 `rqt` 窗口依次点击 `Plugins` -> `Logging` -> `Console` 启动，或直接在终端输入命令 `rqt_console` 启动。

界面如下图：

![image-20240317224113426](img/image-20240317224113426.png)

其中，每列说明如下：

|  #   | Message  | Severity |      Node      | Stamp  | Topics |    Location    |
| :--: | :------: | :------: | :------------: | :----: | :----: | :------------: |
| 序号 | 日志内容 | 日志等级 | 发布日志的节点 | 时间戳 |  话题  | 打印日志的位置 |

另外，也可以通过条件过滤日志，即下方的 `Exclude Messages` 和 `Highlight Messages` ，分别可以通过指定条件（右侧的绿色加号）排除和高亮符合的日志。

示例如下：

![image-20240317225908998](img/image-20240317225908998.png)

如上，排除了日志中包含`In`（区分大小写）和指定位置的日志，并高亮了日志等级为 `Fatal` 的日志。

其中条件可选如下：

![image-20240317230247133](img/image-20240317230247133.png)

分别为：

|       条件        |              说明              |
| :---------------: | :----------------------------: |
|    …containing    |            内容包含            |
| …with serverities |            日志等级            |
|    …from node     |            所属节点            |
| ..from time range |            时间范围            |
|    …from topic    |            所属话题            |
|  …from location   | 日志位置（在哪个文件的第几行） |
|      Custom       |         用户自定义条件         |

#### 4.3.1.2 Logger Level

`Logger Level` 可以通过可视化界面设置指定的日志级别。

**启动方法：**在 `rqt` 窗口依次点击 `Plugins` -> `Logging` -> `Logger Level` 启动，或直接在终端输入命令 `rqt_logger_level` 启动。

界面如下：

![image-20240323095337280](img/image-20240323095337280.png)

其中，每列说明如下：

| Nodes  |  Loggers   |  Levels  |
| :----: | :--------: | :------: |
| 节点名 | 日志记录器 | 日志等级 |

其中，

- `Nodes`：通过如下接口设置

    - ```
        ros::init(argc, argv, "rqt_console_node"); // C++
        rospy.init_node('rqt_console_node')  # Python
        ```

- `Loggers`：日志记录器（loggers）是用于输出诊断信息、调试信息和运行时消息的工具。每个日志记录器通常与特定的ROS包或库相关联，并允许开发者控制不同级别的日志消息的输出。以下对这些日志记录器进行说明：
    - **ros**
        - 这个日志记录器是ROS核心的一部分，它记录了整个系统范围内的重要信息。
    - **ros.roscpp**
        - 这个日志记录器与ROS的C++库（roscpp）相关，记录了roscpp库的操作和事件。
    - **ros.roscpp.roscpp_internal**
        - 这个日志记录器专门用于roscpp库的内部操作。它可能会记录关于库内部工作方式的细节，但以"info"级别进行记录，这意味着默认情况下这些信息不会非常详细。
    - **ros.roscpp.roscpp_internal.connections**
        - 这个日志记录器可能用于记录roscpp库内部的网络连接和通信相关的信息。这包括节点之间的通信和连接状态的变化。
    - **ros.roscpp.superdebug**
        - 这是一个特殊的日志记录器，通常用于更详细的调试。
    - **ros.rqt_learning**
        - 这个日志记录器是特定于名为 `rqt_learning` 的ROS包的。

- `Levels`：日志等级，各等级说明如下：
    - `Debug`：这是最低级别的日志，用于记录开发过程中的详细信息，通常仅在需要调试时使用。这对于开发者来说非常有用，尤其是在开发和测试阶段。
    - `Info`：此级别用于记录程序正常运行时的一般信息，比DEBUG级别略高，它包含的信息对日常操作和问题诊断有价值。
    - `Warn`：警告级别用来指示可能的问题，但不一定会导致程序出错。这通常意味着某些事情不如预期，但程序可以继续运行。
    - `Error`：此级别用于报告错误情况，这些错误可能会影响程序的功能。
    - `Fatal`：最高级别的日志，表示出现了严重的错误，程序可能会因此终止运行。

**使用方法：** 依次选择要设置的节点、日志记录器后，直接点选日志等级即可设置。

该可视化界面和如下命令有同样的效果：

```
rosservice call /<node_name>/get_loggers
rosservice call /<node_name>/set_logger_level 
```

如下图：

![image-20240323115228400](img/image-20240323115228400.png)



### 4.3.2 Topic 工具

#### 4.3.2.1 Message Publisher

`Message Publisher` 可以通过可视化界面发布topic。

**启动方法：**在 `rqt` 窗口依次点击 `Plugins` -> `Topics` -> `Message Publisher` 启动。

界面如下：

![image-20240323160424912](img/image-20240323160424912.png)

可以依次设置`Topic`名字（可自定义）、`Type`（只能选择）、发布频率`Freq`，然后点击`+`添加，如下图：

![image-20240323161401603](img/image-20240323161401603.png)

展开`topic` 列右侧的箭头可现实详细的`msg`信息，并且双击`exoression` 中的项可以设置`msg`中对应字段的值，如下图：

![image-20240323161820059](img/image-20240323161820059.png)

设置好后，选择`topic`列中的方框，即可发布`topic`，如下图：

![image-20240323162142766](img/image-20240323162142766.png)



#### 4.3.2.2 Message Type Browser

`Message Type Browser` 用于查询`msg`的类型及一些具体信息。

**启动方法：**在 `rqt` 窗口依次点击 `Plugins` -> `Topics` -> `Message Type Browser` 启动。

界面如下：

![image-20240323163115657](img/image-20240323163115657.png)

可以选择某个`package`里的某个`msg`，点击加号查看具体信息，如下图：

![image-20240323163434587](img/image-20240323163434587.png)

其中，

- `Tree`：是该msg的变量输。
- `Type`：是该msg的类型。
- `Path`：是msg和变量在变量树的路径。

另外，选择msg后，右键，有更多选项：

![image-20240323163929128](img/image-20240323163929128.png)

其中，

- `View Text`：查看msg变量树全部展开后的 test 形式，如下：

![image-20240323164413497](img/image-20240323164413497.png)

这和命令 `rosmsg show actionlib/TestAction` 效果一样：

![image-20240323164548173](img/image-20240323164548173.png)

- `View Raw`：查看msg文件的内容，如下：

![image-20240323165002891](img/image-20240323165002891.png)

这和命令 `rosmsg show -r actionlib/TestAction` 效果一样：

![image-20240323165237108](img/image-20240323165237108.png)

- `Remove message`：删掉当前msg的type查询。



#### 4.3.2.3 Topic Monitor

`Topic Monitor` 用于监测topic信息。

**启动方法：**在 `rqt` 窗口依次点击 `Plugins` -> `Topics` -> `Topic Monitor` 启动，或直接在终端输入命令 `rqt_topic` 启动。

界面如下：

![image-20240323170953723](img/image-20240323170953723.png)

可以监测的信息包括：`Topic`名称、`Type`、带宽（Bandwidth）、频率（Hz）、变量值。

结合上文介绍的`Message Publisher`给出示例如下：

![image-20240323170843889](img/image-20240323170843889.png)



### 4.3.3 Service工具

#### 4.3.3.1 Service Caller

`Service Caller` 是一个用于调用ROS服务的工具，它提供了一个图形界面，允许用户轻松地与ROS服务进行交互，它简化了服务的调用过程，使得用户可以不编写代码就能快速测试和调试服务。

**启动方法：**在 `rqt` 窗口依次点击 `Plugins` -> `Topics` -> `Service Caller` 启动。

界面如下：

![image-20240323174308197](img/image-20240323174308197.png)

选择service后，在下面的 `Request` 一栏中会显示对应的请求数据，可以按需修改。然后点击 `Call` ，在 `Response`中显示服务端的回复数据。

设置日志等级：

![image-20240323175018858](img/image-20240323175018858.png)

获取日志等级：

![image-20240323175113355](img/image-20240323175113355.png)



#### 4.3.3.2 Service Type Browser

`Service Type Browser` 是一个用于显示和调用ROS服务的图形界面工具。提供了一个树状结构，展示了当前ROS系统中所有可用的服务类型。用户可以浏览这些服务，查看它们的详细信息，包括服务名称、请求和响应的数据类型等。

**启动方法：**在 `rqt` 窗口依次点击 `Plugins` -> `Topics` -> `Service Type Browser` 启动。

界面如下：

![image-20240323175347791](img/image-20240323175347791.png)

可以选择某个`package`里的某个`srv`，点击加号会同时显示`Request`和 `Response`的具体信息，如下图：

![image-20240323175532802](img/image-20240323175532802.png)

其中，

- `Tree`：是该srv的变量输。
- `Type`：是该srv的类型。
- `Path`：是srv和变量在变量树的路径。

另外，选择srv后，右键，有更多选项：

![image-20240323163929128](img/image-20240323163929128.png)

其中，

- `View Text`：查看srv变量树全部展开后的 test 形式，如下：

![image-20240323180301458](img/image-20240323180301458.png)

这和命令 `rossrv show map_msgs/GetPointMap` 效果一样：

![image-20240323180450863](img/image-20240323180450863.png)

- `View Raw`：查看srv文件的内容，如下：

![image-20240323180633736](img/image-20240323180633736.png)

这和命令 `rossrv show -r map_msgs/GetPointMap` 效果一样：

![image-20240323180804918](img/image-20240323180804918.png)

- `Remove message`：删掉当前srv的type查询。

### 4.3.4 Action工具

#### 4.3.4.1 Action Type Browser

`Action Type Browser` 与 `Service Type Browser` 类似，请参考 [Service Type Browser](#4.3.3.2 Service Type Browser) 



### 4.3.5 其他常用rqt工具

#### 4.3.5.1 Node Graph

`Node Graph` 是一个用于显示计算图网络的工具。

**启动方法：**在 `rqt` 窗口依次点击 `Plugins` -> `Introspection` -> `Node Graph` 启动，或直接在终端输入命令 `rqt_graph` 启动。

界面如下：

![image-20240331220138074](img/image-20240331220138074.png)

其中，图中椭圆为节点，矩形为话题，通过左上角的下拉框可以选择图中要显示的对象类型：

|          选项          |         描述         |
| :--------------------: | :------------------: |
|       Nodes Only       |      只显示节点      |
| Nodes/Topics（active） | 显示活动的节点与话题 |
|  Nodes/Topics（all）   |  显示所有节点与话题  |

还支持通过名称过滤节点与话题。









# 五、机器人建模与仿真

由于种种原因，有时我们不能直接使用真实的机器人进行调试，这时就需要对机器人进行建模与仿真，在虚拟世界中实现对机器人的控制。

常见的机器人仿真系统有多种，比如 [Webots](https://cyberbotics.com/)、[V-REP](https://www.coppeliarobotics.com/)、[MuJoCo](https://mujoco.org/)、[PyBullet](https://pybullet.org/wordpress/) 以及 [Gazebo](https://gazebosim.org/home) 等。

由于ROS官方默认推荐 Gazebo，我们这里仅以 Gazebo为例介绍机器人的建模与仿真。



## 5.1 URDF 建模



### 5.1.1 URDF 建模介绍

URDF（Unified Robot Description Format，统一机器人描述格式）是ROS中一个非常重要的机器人模型描述格式，是一个标准的 XML格式，它可以反映机器人各个组件之间的位置关系。ROS同时也提供了URDF文件的C++解析器，可以解析URDF文件中使用XML格式描述的机器人模型。可以在任何文本编辑器中创建URDF文件，如果已经存在机器人的 CAD 模型，则可以使用一些工具将 CAD 模型转换为 URDF。

URDF描述机器人有一个基本思想，就是一切实体皆连杆（link），实体间的相对运动关系为称为关节（joint）。

#### 5.1.1.1 一个简单的实体

首先，感受一下rviz中的显示，我们写一个简单的URDF文件来描述一个圆柱体，如下：

```xml
<?xml version="1.0"?>
<robot name="mbot">
    <link name="base_link">
        <visual>
            <geometry>
                <cylinder length="0.1" radius="0.2"/>
            </geometry>
        </visual>
    </link>
</robot>
```

使用rviz查看如下图：

![image-20240411233025927](img/image-20240411233025927.png)



#### 5.1.1.2 rivz显示URDF模型

rviz是怎么找到所指定的URDF模型的呢？

通过向参数服务器查询，没错，URDF模型是储存在参数服务器中的，需要我们写入。

一般是通过 launch 文件写入，如下：

```xml
<launch>
    <param name="urdf_hello_world" textfile="$(find simulation_learning)/urdf/hello_world.urdf" />
</launch>
```

其中，`urdf_hello_world` 是参数名字，后面供rviz查询模型；`textfile` 代表从文件写入参数，值为文件路径，`$(find simulation_learning)` 是查找`simulation_learning`功能包的路径。

执行上述launch文件即可将你的URDF文件写入ROS参数服务器。

然后打开rviz，初始界面如下图：

![image-20240412203041970](img/image-20240412203041970.png)

然后点击`Add`添加视图，选择`By display type` 中的 `RobotModel` ，如下图：

![image-20240412203333726](img/image-20240412203333726.png)

添加后会发现有报错，查看报错信息如下：

![image-20240412204454038](img/image-20240412204454038.png)

参数 `robot_description` 不存在，这是rviz RobotModel 默认的参数名，我们需要将`Robot Description`一项改成自己设置的参数名，如下图：

![image-20240412205252245](img/image-20240412205252245.png)

可以发现，修改后，模型显示出来了，但仍有报错，报错为 `base_link` 和 `map` 没有转换关系。我们的模型实体名称为 `base_link` ，rviz中设置的固定参考系（Fixed Frame）是 `map`，我们没有告知系统我们的模型在map中的位置，所以会报这个错。将固定参考系设置为我们的 `base_link` 即可，如下图：

![image-20240412212509495](img/image-20240412212509495.png)

#### 5.1.1.3 保存与加载rviz配置

每次用rviz加载模型都需要配置信息，甚至更多，为了方便，我们可以导出rviz配置，下次打开直接加载即可。

导出配置：依次选择 `File` -> `Save Config As` ，然后选择你要保存的位置即可。

加载配置：依次选择 `File` -> `Open Config` ，然后选择你的配置文件即可。

![image-20240412223328474](img/image-20240412223328474.png)



#### 5.1.1.4 launch文件快速启动

有时不仅会使用rviz打开模型并加载配置，还会发布模型位置信息，有时甚至还会打开多个模型，这时手动打开rviz就显得过于笨拙了，我们使用launch文件可以快速执行上述任务，如下是打开 `hello_world`模型并加载rviz配置的launch内容：

```xml
<launch>
    <param name="urdf_hello_world" textfile="$(find simulation_learning)/urdf/hello_world.urdf" />
    <node pkg="rviz" type="rviz" name="rviz" args="-d $(find simulation_learning)/config/hello_world.rviz"/> 
</launch>
```

其中，`hello_world.rviz` 导出的rviz配置。



#### 5.1.1.5 package结构

工程中，我们一般把上述文件存放在package结构中，需要时可以作为一个功能包发布，

![image-20240412231113596](img/image-20240412231113596.png)

其中，

- `config` ：存放rviz配置文件
- `launch` ：存放launch文件
- `meshes` ：存放模型渲染文件
- `urdf` ：存放URDF模型文件
- `src与include` ：存放源文件和头文件



### 5.1.2 URDF 语法

URDF文件中使用XML格式描述的机器人模型，下面介绍URDF的XML标签。

#### 5.1.2.1 robot标签

机器人描述文件中的根元素必须是**robot**，所有其他元素必须封装在其中。

**属性**

- name：主文件必须具有名称属性。 name属性在包含的文件中是可选的。如果在附加包含文件中指定属性名称，则其值必须与主文件中的值相同。

**子标签**

| 标签   | 描述                         |
| ------ | ---------------------------- |
| link   | 连杆                         |
| joint  | 关节，描述连杆之间的运动关系 |
| gazebo | 用于描述在gazebo中模拟的信息 |

**示例**

```xml
<robot name="mbot">
    <link> ... </link>
    <joint> ... </joint>
</robot>
```



#### 5.1.2.2 link标签

link 元素用于描述具有惯性、视觉特征和碰撞属性的刚体。

![惯性.png](img/urdf_inertial.png)

**属性**

- name：link的名称。

**子标签**

注：`<…>` 代表标签，`xyz` 等代表属性，`++` 等代表下一级。

| 标签或属性                   | 描述                                                         | 示例        |
| ---------------------------- | ------------------------------------------------------------ | ----------- |
| \<inertial>                  | 描述连杆的质量、质心位置及其中心惯性属性（如果未指定，则默认为零质量和零惯性） |             |
| + \<origin>                  | 该姿态（平移、旋转）描述了连杆质心坐标系 C 相对于连杆坐标系 L 的位置和方向。 |             |
| ++ xyz                       | 从 Lo（连杆坐标系原点）到 Co（连杆质心）的位置向量，表示为 **xL̂x + yL̂y + zL̂z**，其中**L̂x、L̂y、L̂z**是连杆坐标系 L 的正交单位向量。默认为零向量 | 2.0 0 -3    |
| ++ rpy                       | 质心 C 的单位向量 **(Ĉx, Ĉy, Ĉz)** 相对于连杆系 L的方向，表示为以弧度表示的欧拉旋转 (rpy) 序列。注意：**(Ĉx, Ĉy, Ĉz)** 不需要与连杆的惯性主轴对齐。 | 0.1 1 0.5   |
| + \<mass>                    | 连杆的质量，由该元素的**value**属性表示                      |             |
| ++ value                     | 质量数值，单位：kg                                           | 2.5         |
| + \<inertia>                 | 对于固定在质心坐标系 C 上的单位向量 **(Ĉx, Ĉy, Ĉz)** ，该连杆的惯性矩**ixx、iyy、izz**以及关于 Co（连杆质心）的惯性积 **ixy、ixz、iyz。** |             |
| ++ ixx<br/>++ iyy<br/>++ izz | 惯性矩                                                       |             |
| ++ ixy<br/>++ ixz<br/>++ iyz | 惯性积                                                       |             |
|                              |                                                              |             |
| \<visual>                    | 连杆的视觉属性。该元素指定对象的形状（box、cylinder等）以用于可视化。**注意：**同一个连杆可以存在多个 \<visual> 实例，连杆的最终形状由他们定义的几何图形融合决定。 |             |
| + name                       | 指定连杆几何图形的名称。用于外部引用连杆几何形状。 可选      |             |
| + \<origin>                  | 视觉元素的参考系相对于连杆参考系的位姿。可选                 |             |
| ++ xyz                       | 平移                                                         |             |
| ++ rpy                       | 固定轴旋转角                                                 |             |
| + \<geometry>                | 视觉对象的几何形状，选择如下之一                             |             |
| ++ \<box>                    | 立方体，原点位于几何中心                                     |             |
| +++ size                     | 长宽高，单位：m                                              |             |
| ++ \<cylinder>               | 圆柱体，原点位于几何中心                                     |             |
| +++ length                   | 高，单位：m                                                  |             |
| +++ radius                   | 半径，单位：m                                                |             |
| ++ \<sphere>                 | 球体，，原点位于几何中心                                     |             |
| +++ radius                   | 半径，单位：m                                                |             |
| ++ \<mesh>                   | 外部导入的网格模型                                           |             |
| +++ filename                 | 模型文件路径，建议使用 `package://<packagename>/<path>` 格式，以便可以自动查找特定包下的模型文件。文件推荐 `.dae` 格式。 |             |
| + \<material>                | 视觉元素的材质。允许在 `robot` 元素中枚举所需材质，然后在 `link` 元素中按名称引用。 |             |
| ++ name                      | 名称                                                         |             |
| ++ \<color>                  | 颜色                                                         |             |
| +++ rgba                     | 红绿蓝和透明度，数值范围为 [0,1]                             | 0.2 0 0.8 1 |
| +++ \<texture>               | 外部导入的外观图片                                           |             |
| +++ filename                 | 文件路径                                                     |             |
|                              |                                                              |             |
| \<collision>                 | 连杆的碰撞属性，注意：这可能与连杆的视觉属性不同，例如，通常使用更简单的碰撞模型来减少计算时间。 同一连杆可以存在多个 \<collision> 实例。连杆的最终碰撞模型由他们定义的几何图形融合决定。 |             |
| + name                       | 指定连杆碰撞模型的名称。用于外部引用。 可选                  |             |
| + \<origin>                  | 同\<visual>的\<origin>                                       |             |
| + \<geometry>                | 同\<visual>的\<geometry>                                     |             |

**示例**

```xml
<robot name="physics">

    <material name="blue">
        <color rgba="0 0 0.8 1"/>
    </material>
    <material name="black">
        <color rgba="0 0 0 1"/>
    </material>
    <material name="white">
        <color rgba="1 1 1 1"/>
    </material>

    <link name="base_link">
        <visual>
            <geometry>
                <cylinder length="0.6" radius="0.2"/>
            </geometry>
            <material name="blue"/>
        </visual>
        <collision>
            <geometry>
                <cylinder length="0.6" radius="0.2"/>
            </geometry>
        </collision>
        <inertial>
            <mass value="10"/>
            <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
        </inertial>
    </link>

</robot>
```



#### 5.1.2.3 joint标签

joint 描述关节的运动学和动力学属性，并指定了关节的安全极限。

![关节.png](img/urdf_joint.png) 



**属性**

- name：指定关节的唯一名称（必选）。
- type：指定关节的类型，可以是以下之一：

| 关节类型   | 描述                                                         |
| ---------- | ------------------------------------------------------------ |
| revolute   | 沿轴转动的铰链关节，其范围由 lower 和 upper 指定。见 limit 标签 |
| continuous | 绕轴旋转的连续铰链关节，没有上下限。                         |
| prismatic  | 沿轴滑动的滑动关节，其范围由 lower 和 upper 指定。           |
| fixed      | 这并不是真正的关节，因为它不能移动。所有自由度均被锁定。这种类型的关节不需要\<axis>、\<calibration>、\<dynamics>、\<limits>或\<safety_controller>等标签。 |
| floating   | 该关节允许所有 6 个自由度的运动。                            |
| planar     | 该关节允许在垂直于轴的平面上运动。                           |

**子标签**

| 标签或属性           | 描述                                                         | 示例      |
| -------------------- | ------------------------------------------------------------ | --------- |
| \<origin>            | 从父连杆到子连杆的转换。关节位于子连杆的原点，如上图。可选   |           |
| + xyz                | x、y、z 偏移，单位：m                                        | 2.0 0 -3  |
| + rpy                | 绕固定轴的旋转：首先绕x滚动，然后绕y俯仰，最后绕z偏航。单位：弧度 | 0.1 1 0.5 |
|                      |                                                              |           |
| \<parent>            | 指定关节的父连杆，必选                                       |           |
| + link               | 父连杆名称                                                   |           |
| \<child>             | 指定关节的子连杆，必选                                       |           |
| + link               | 子连杆名称                                                   |           |
|                      |                                                              |           |
| \<axis>              | 关节框架中指定的关节轴。这是旋转关节的旋转轴、滑动关节的平移轴以及平面关节的表面法线。该轴在关节参考系中指定。固定关节和浮动关节不使用该字段。默认为 (1,0,0) |           |
| + xyz                | 轴向量，应该被归一化。                                       |           |
|                      |                                                              |           |
| \<calibration>       | 关节的参考位置，用于校准关节的绝对位置。                     |           |
| + rising             | 当关节正方向移动时，该参考位置将触发上升沿。                 |           |
| + falling            | 当关节正方向移动时，该参考位置将触发下降沿。                 |           |
|                      |                                                              |           |
| \<dynamics>          | 指定关节的物理属性                                           |           |
| + damping            | 关节的物理阻尼值（对于滑动关节，以牛顿秒每米[ *N* ∙ *s* / m ] 为单位；对于旋转关节，以牛顿米秒每弧度[ *N* ∙ *m* ∙ *s* / *rad* ] 为单位） |           |
| + friction           | 关节的物理静摩擦值（对于滑动关节，单位为牛顿[ N ]；对于旋转关节，单位为牛顿米[ *N* ∙ *m* ]） |           |
|                      |                                                              |           |
| \<limit>             | 安全限制（仅旋转关节和滑动关节需要）                         |           |
| + lower              | 指定关节下限的属性（对于旋转关节以弧度为单位，对于滑动关节以米为单位）。如果关节是连续的则省略。可选 |           |
| + upper              | 指定关节上限的属性（对于旋转关节以弧度为单位，对于滑动关节以米为单位）。如果关节是连续的则省略。可选 |           |
| + effort             | 限制关节最大受力（$|F_{real}|<|F_{effort}|$），单位：N，必选 |           |
| + velocity           | 限制关节最大速度（对于旋转关节，以弧度每秒[ *rad* / *s ] 为单位，对于棱柱关节，以米每秒[ *m* / *s* ] 为单位），必选 |           |
|                      |                                                              |           |
| \<mimic>             | 该标签用于指定定义的关节模仿另一个现有关节。该关节的值可以计算为*value = multiplier \* other_joint_value + offset*。可选 |           |
| + joint              | 指定要模仿的关节的名称，必选                                 |           |
| + multiplier         | 指定上述公式中的乘法因子，可选                               |           |
| + offset             | 指定要在上述的公式中添加的偏移量。默认为 0（旋转关节为弧度，滑动关节为米） |           |
|                      |                                                              |           |
| \<safety_controller> | 安全控制器，可选                                             |           |
| + soft_lower_limit   | 指定安全控制器开始限制关节位置的下边界。该限制需要大于 limit 的 lower |           |
| + soft_upper_limit   | 指定安全控制器开始限制关节位置的上边界。该限制需要小于 limit 的 upper |           |
| + k_position         | 指定位置和速度限制之间的关系                                 |           |
| + k_velocity         | 指定受力和速度限制之间的关系                                 |           |

**示例**

```xml
<joint name="my_joint" type="floating">
    <origin xyz="0 0 1" rpy="0 0 3.1416"/>
    <parent link="link1"/>
    <child link="link2"/>

    <calibration rising="0.0"/>
    <dynamics damping="0.0" friction="0.0"/>
    <limit effort="30" velocity="1.0" lower="-2.2" upper="0.7" />
    <safety_controller k_velocity="10" k_position="15" soft_lower_limit="-2.0" soft_upper_limit="0.5" />
</joint>
```



### 5.1.3 URDF建模实践



https://blog.csdn.net/qq_43279579/article/details/114991696



前文介绍了URDF建模与URDF语法，接下来介绍怎么使用URDF从零构建一个机器人模型并在rviz中显示。



#### 5.1.3.1 机器人结构组成

最终效果如下图：

![image-20240427195129404](img/image-20240427195129404.png)

机器人由如下部分组成：

- 底盘 * 1
- 主动轮 * 2
- 从动轮（脚轮）* 2
- 激光雷达 * 1
- RGB相机 * 1



#### 5.1.3.2 新建功能包

为面向零基础的同学，使教学清晰，新建一个功能包用于学习该章节，新建功能包方法见前文，功能包结构如下：

![image-20240427224342123](img/image-20240427224342123.png)

其中，

- `config` ：存放rviz配置文件
- `launch` ：存放launch文件
- `meshes` ：存放模型渲染文件
- `models` ：存放模型文件
- `src与include` ：存放源文件和头文件

关于ROS工作空间与功能包的创建，详见[1.3 ROS Hello World](#1.3 ROS Hello World)



#### 5.1.3.3 编写launch文件

如前文所述，rviz显示urdf模型需要先把模型参数注册到参数服务器，然后打开rviz，在rviz中配置好后才能正常显示模型。这些步骤可以手动一步一步完成，也可以编写launch文件快速执行。

另外，对于包含多个`link`的模型，需要发布`link`间的`joint`和`tf`关系，以使rviz可以确定`link`间的空间位置。ROS提供了 `joint_state_publisher` 和 `robot_state_publisher` 两个功能包来实现`link`间`joint`和`tf`关系的发布，如没有安装这两个功能包，可以使用如下命令安装（以noetic为例）：

```bash
sudo apt install ros-noetic-joint-state-publisher
sudo apt install ros-noetic-robot-state-publisher
```

launch文件内容如下：

```xml
<launch>
    <param name="robot_description" textfile="$(find simulation_learning)/models/urdf/mbot_base.urdf" />

    <!-- 设置GUI参数，显示关节控制插件 -->
    <param name="use_gui" value="true" />

    <!-- 运行joint_state_publisher节点，发布机器人的关节状态  -->
    <node name="joint_state_publisher" pkg="joint_state_publisher" type="joint_state_publisher" />

    <!-- 运行robot_state_publisher节点，发布tf  -->
    <node name="robot_state_publisher" pkg="robot_state_publisher" type="robot_state_publisher" />

    <!-- 运行rviz可视化界面，并加载配置 -->
    <node name="rviz" pkg="rviz" type="rviz" args="-d $(find simulation_learning)/config/mbot_urdf.rviz" required="true" />
</launch>
```

关于`launch`文件的具体描述，见[4.1 launch文件](#4.1 launch文件)



#### 5.1.3.4 创建底盘

在`models/urdf`中创建`mbot_base.urdf`文件，用于编写urdf模型。

底盘是一个圆柱体，半径为 `0.2m`，高为`0.16m`，urdf代码如下：

```xml
<?xml version="1.0"?>
<robot name="mbot">
    <link name="base_link">
        <visual>
            <origin xyz=" 0 0 0" rpy="0 0 0" />
            <geometry>
                <cylinder length="0.16" radius="0.20" />
            </geometry>
            <material name="yellow">
                <color rgba="1 0.4 0 1" />
            </material>
        </visual>
    </link>
</robot>
```

运行 `launch` 文件，结果如下：

![image-20240427231402039](img/image-20240427231402039.png)

这里注意`base_link`的原点位于圆柱体的几何中心，即有一半圆柱体是位于地面以下的，这一点到最后会解决，目前先把机器人模型搭建起来。



#### 5.1.3.5 添加轮子

轮子是小一点的圆柱体，半径为 `0.06m`，高为`0.025m`。

现在有了两个实体，底盘和一个轮子，需要使用`joint`说明他们之间的几何与运动关系，否则rviz解析urdf时会报错。

urdf代码如下：

```xml
<!-- 底盘实体描述 -->
<link name="base_link">
    <visual>
        <origin xyz=" 0 0 0" rpy="0 0 0" />
        <geometry>
            <cylinder length="0.16" radius="0.20" />
        </geometry>
        <material name="yellow">
            <color rgba="1 0.4 0 1" />
        </material>
    </visual>
</link>

<!-- 左轮与底盘的关节描述 -->
<joint name="left_wheel_joint" type="continuous">
    <origin xyz="0 0.19 -0.05" rpy="0 0 0" />
    <parent link="base_link" />
    <child link="left_wheel_link" />
    <axis xyz="0 1 0" />
</joint>

<!-- 左轮实体描述 -->
<link name="left_wheel_link">
    <visual>
        <origin xyz="0 0 0" rpy="1.5707 0 0" />
        <geometry>
            <cylinder radius="0.06" length="0.025" />
        </geometry>
        <material name="white">
            <color rgba="1 1 1 0.9" />
        </material>
    </visual>
</link>
```

其中，`joint`中的`type`描述了关节类型（机械中的运动副），该类型为旋转类型（机械中的旋转副），`origin`表示左轮原点相对于底盘原点的空间位姿偏移，`parent`和`child`分别表示该关节的父实体和子实体，由于该关节为旋转关节，使用`axis`定义旋转轴。关于`joint`的具体描述见[5.1.2.3 joint标签](#5.1.2.3 joint标签)。

运行 `launch` 文件，结果如下：

![image-20240430165341427](img/image-20240430165341427.png)



#### 5.1.3.6 添加其他部件

其他部件同理，添加实体与相应的关节描述。

完整的urdf代码如下：

```xml
<?xml version="1.0"?>
<robot name="mbot">

    <!-- 底盘实体描述 -->
    <link name="base_link">
        <visual>
            <origin xyz=" 0 0 0" rpy="0 0 0" />
            <geometry>
                <cylinder length="0.16" radius="0.20" />
            </geometry>
            <material name="yellow">
                <color rgba="1 0.4 0 1" />
            </material>
        </visual>
    </link>

    <!-- 左轮与底盘的关节描述 -->
    <joint name="left_wheel_joint" type="continuous">
        <origin xyz="0 0.19 -0.05" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="left_wheel_link" />
        <axis xyz="0 1 0" />
    </joint>

    <!-- 左轮实体描述 -->
    <link name="left_wheel_link">
        <visual>
            <origin xyz="0 0 0" rpy="1.5707 0 0" />
            <geometry>
                <cylinder radius="0.06" length="0.025" />
            </geometry>
            <material name="white">
                <color rgba="1 1 1 0.9" />
            </material>
        </visual>
    </link>

    <!-- 右轮与底盘的关节描述 -->
    <joint name="right_wheel_joint" type="continuous">
        <origin xyz="0 -0.19 -0.05" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="right_wheel_link" />
        <axis xyz="0 1 0" />
    </joint>

    <!-- 右轮实体描述 -->
    <link name="right_wheel_link">
        <visual>
            <origin xyz="0 0 0" rpy="1.5707 0 0" />
            <geometry>
                <cylinder radius="0.06" length="0.025" />
            </geometry>
            <material name="white">
                <color rgba="1 1 1 0.9" />
            </material>
        </visual>
    </link>

    <!-- 前脚轮实体描述 -->
    <joint name="front_caster_joint" type="continuous">
        <origin xyz="0.18 0 -0.095" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="front_caster_link" />
        <axis xyz="0 1 0" />
    </joint>

    <!-- 前脚轮和底盘的关节描述 -->
    <link name="front_caster_link">
        <visual>
            <origin xyz="0 0 0" rpy="0 0 0" />
            <geometry>
                <sphere radius="0.015" />
            </geometry>
            <material name="black">
                <color rgba="0 0 0 0.95" />
            </material>
        </visual>
    </link>

    <!-- 后脚轮实体描述 -->
    <joint name="back_caster_joint" type="continuous">
        <origin xyz="-0.18 0 -0.095" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="back_caster_link" />
        <axis xyz="0 1 0" />
    </joint>

    <!-- 后脚轮和底盘的关节描述 -->
    <link name="back_caster_link">
        <visual>
            <origin xyz="0 0 0" rpy="0 0 0" />
            <geometry>
                <sphere radius="0.015" />
            </geometry>
            <material name="black">
                <color rgba="0 0 0 0.95" />
            </material>
        </visual>
    </link>

    <!-- 激光雷达实体描述 -->
    <link name="laser_link">
        <visual>
            <origin xyz=" 0 0 0 " rpy="0 0 0" />
            <geometry>
                <cylinder length="0.05" radius="0.05" />
            </geometry>
            <material name="gray">
                <color rgba="0.25 0.25 0.25 0.95" />
            </material>
        </visual>
    </link>

    <!-- 激光雷达和底盘的关节描述 -->
    <joint name="laser_joint" type="fixed">
        <origin xyz="0 0 0.105" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="laser_link" />
    </joint>

    <!-- 相机实体描述 -->
    <link name="camera_link">
        <visual>
            <origin xyz=" 0 0 0 " rpy="0 1.57 0" />
            <geometry>
                <cylinder radius="0.02" length = "0.05"/>
            </geometry>
            <material name="gray">
                <color rgba="0.25 0.25 0.25 0.95"/>
            </material>
        </visual>
    </link>

    <!-- 相机和底盘的关节描述 -->
    <joint name="camera_joint" type="fixed">
        <origin xyz="0.18 0 0.055" rpy="0 0 0"/>
        <parent link="base_link"/>
        <child link="camera_link"/>
    </joint>

</robot>
```

运行 `launch` 文件，结果如下：

![image-20240501091828865](img/image-20240501091828865.png)



#### 5.1.3.7 解决部分实体位于地面以下的问题

首先明确我们的 `Fixed Frame` 是`base_link`， `Fixed Frame` 可以理解为世界坐标系，对于我们的设置就是`base_link`即当前的世界，`rviz`默认一切都是从世界中心诞生。

实体位于地面以下，是由于我们设置的其他实体都是以世界中心为参考而又认为地面在轮子下方，但`rviz`认为地面原点在世界中心，所以看起来和我们的认知有些冲突。

解决办法有多种，但基本都是改变`base_link`或其他实体与世界中心的关系。

**方法一：**

比较常见的一种：新增`floor_link`作为 `Fixed Frame` 世界坐标系，`base_link`作为他的子级。这种方法对现有已经完成的模型修改最少。

在urdf文件中新增如下内容即可：

```xml
<!-- 地面实体描述 -->
<link name="floor_link">
    <visual>
        <origin xyz="0 0 0" rpy="0 0 0" />
        <geometry>
            <!-- 圆柱体高度尽量小，以达到可忽略的精度 -->
            <cylinder length="0.000001" radius="0.20" />
        </geometry>
        <material name="floor">
            <color rgba="1 0.4 0 0" />
        </material>
    </visual>
</link>

<!-- 底盘与地面的关节关系描述 -->
<joint name="base_joint" type="continuous">
    <origin xyz="0 0 0.11" rpy="0 0 0" />
    <parent link="floor_link" />
    <child link="base_link" />
    <axis xyz="0 1 0" />
</joint>
```

结果如下：

![image-20240501103614922](img/image-20240501103614922.png)

使用`rviz`查看`TF`关系如下：

![image-20240501103908541](img/image-20240501103908541.png)

新增的`floor_link`如图中框选，但这种方法在工程上很难测量`base_link`的实际位置，所以就有了方法二。



**方法二：**

将`floor_link`直接命名为`base_link`，其他实体都以它为基准，但位置描述都要作相应的修改，这种方法对于现有已经完成的模型修改较多，对新工程比较友好，各实体的实际位置也很容易通过测量得到。

修改后的`TF`树如下，此时`base_link`位于世界原点，也是机器人底盘原点在地面的投影点。

![image-20240501105939843](img/image-20240501105939843.png)

机器人的外观显示和方法一一样：

![image-20240501161856688](img/image-20240501161856688.png)



## 5.2 Xacro 建模

可以发现 urdf 不支持模块化编程，无法实现代码复用，也不支持数学计算， 代码可读性及复用性非常差，效率极低。

为了解决这一问题，ROS提供了 Xacro ，它是 XML Macros 的缩写，即 XML 宏，是可编程的 XML，支持使用变量、函数、数学公式计算、条件/循环流程控制等。



### 5.2.1 Xacro 语法

使用 Xacro 时，根标签 `robot` 中必须包含命名空间声明 `xmlns:xacro = "http://wiki.ros.org/xacro"`

```xml
<robot name = "xxx" xmlns:xacro="http://wiki.ros.org/xacro">
	...
</robot>
```



#### 5.2.1.1 属性与属性块

属性可以理解为变量，属性块可以理解为结构体。

属性示例，将会一个圆柱体的半径和高封装到变量里：

```xml
<!-- 定义属性 -->
<xacro:property name="the_radius" value="2.1" />
<xacro:property name="the_length" value="4.5" />

<!-- 调用属性 -->
<geometry type="cylinder" radius="${the_radius}" length="${the_length}" />
```

同样，可以使用属性块封装一个实体，在需要的地方调用：

```xml
<!-- 定义属性块 -->
<xacro:property name="front_left_origin">
  	<origin xyz="0.3 0 0" rpy="0 0 0" />
</xacro:property>

<pr2_wheel name="front_left_wheel">
    <!-- 调用属性块 -->
  	<xacro:insert_block name="front_left_origin" />
</pr2_wheel>
```



#### 5.2.1.2 数学表达式

Xacro支持基本的数学表达式运算，格式如下：

```xml
${ 数学表达式 }
```

示例如下：

```xml
<xacro:property name="radius" value="4.3" />
<circle diameter="${2 * radius}" />
```

在ROS Jade版本中，Xacro引入了python解析数学表达式，所以，Xacro数学表达式中可以使用Python math包中的函数与常量。示例如下：

```xml
<xacro:property name="R" value="2" />
<xacro:property name="alpha" value="${30/180*pi}" />
<circle circumference="${2 * pi * R}" pos="${sin(alpha)} ${cos(alpha)}" />
<limit lower="${radians(-90)}" upper="${radians(90)}" effort="0" velocity="${radians(75)}" />
```



#### 5.2.1.3 宏

Xacro 宏可以理解为函数，目的是提高代码复用率，优化代码结构，提高安全性。

使用 `macro` 标记定义宏，并指定宏名称和参数列表，参数列表应以空格分隔。

##### 1. 宏的基本使用

```xml
<!-- 定义宏 -->
<xacro:macro name="add_wheels" params="name flag">
    <link name="${name}_wheel">
        <visual>
            <geometry>
                <cylinder radius="${wheel_radius}" length="${wheel_length}" />
            </geometry>
            <origin xyz="0.0 0.0 0.0" rpy="${PI / 2} 0.0 0.0" />
            <material name="black" />
        </visual>
    </link>

    <joint name="${name}_wheel2base_link" type="continuous">
        <parent link="base_link" />
        <child link="${name}_wheel" />
        <origin xyz="0 ${flag * base_link_radius} ${-(earth_space + base_link_length / 2 - wheel_radius) }" />
        <axis xyz="0 1 0" />
    </joint>
</xacro:macro>

<!-- 调用宏 -->
<xacro:add_wheels name="left" flag="1" />
<xacro:add_wheels name="right" flag="-1" />
```

该实例定义了一个 `add_wheels` 的宏，它接受两个参数： `name` 和 `flag` ，分别是轮子的名字和方向。



##### 2. 属性块做为宏的入参

```xml
<!-- 定义宏 -->
<xacro:macro name="pr2_caster" params="suffix *origin">
    <joint name="caster_${suffix}_joint">
        <axis xyz="0 0 1" />
    </joint>
    <link name="caster_${suffix}">
        <xacro:insert_block name="origin" />
    </link>
</xacro:macro>

<!-- 调用宏 -->
<xacro:pr2_caster suffix="front_left">
    <pose xyz="0 1 0" rpy="0 0 0" />
</xacro:pr2_caster>
```

该示例声明了一个宏 `pr2_caster`，它接受两个参数： `suffix` 和 `origin`。请注意， `origin` 带 `*` 。这表明 `origin` 是一个块参数。调用时在子级标签中声名块参数，多个块参数时，按插入顺序处理，如下：

```xml
<!-- 定义宏 -->
<xacro:macro name="pr2_caster" params="suffix *origin *color *mass">
    <joint name="caster_${suffix}_joint">
        <axis xyz="0 0 1" />
    </joint>
    <link name="caster_${suffix}">
        <xacro:insert_block name="origin" />        
        <xacro:insert_block name="color" />        
        <xacro:insert_block name="mass" />
    </link>
</xacro:macro>

<!-- 调用宏 -->
<xacro:pr2_caster suffix="front_left">
    <pose xyz="0 1 0" rpy="0 0 0" /> <!-- origin -->
    <color name="yellow"/> <!-- color -->
    <mass>0.1</mass> <!-- mass -->
</xacro:pr2_caster>
```



##### 3. 任意数量元素做为宏的入参

```xml
<!-- 定义宏 -->
<xacro:macro name="pr2_caster" params="suffix *origin **content **anothercontent">
    <joint name="caster_${suffix}_joint">
        <axis xyz="0 0 1" />
    </joint>
    <link name="caster_${suffix}">
        <xacro:insert_block name="origin" />
        <xacro:insert_block name="content" />
        <xacro:insert_block name="anothercontent" />
    </link>
</xacro:macro>

<!-- 调用宏 -->
<xacro:pr2_caster suffix="front_left">
    <!-- origin -->
    <pose xyz="0 1 0" rpy="0 0 0" />
    <!-- content -->
    <container>
        <color name="yellow"/>
        <mass>0.1</mass>
    </container>
    <!-- anothercontent -->
    <another>
        <inertial>
            <origin xyz="0 0 0.5" rpy="0 0 0"/>
            <mass value="1"/>
            <inertia ixx="100"  ixy="0"  ixz="0" iyy="100" iyz="0" izz="100" />
        </inertial>
    </another>
</xacro:pr2_caster>
```

该示例声明了一个宏 `pr2_caster`，除了前文讲到的参数 `suffix` 和 `origin`，还有`content`和`anothercontent`，他们前面都带`**`，表明他们允许插入任意数量的元素。按照块元素插入顺序，他们分别为 `container` 和 `another`，在他们的子级可以插入任意数量的元素。



##### 4. 指定多个块元素的处理顺序

上文宏定义中 `xacro:insert_block` 用于指定插入的块元素，插入的顺序即处理顺序

```xml
<!-- 定义宏 -->
<xacro:macro name="reorder" params="*first *second">
    <xacro:insert_block name="second"/>
    <xacro:insert_block name="first"/>
</xacro:macro>

<!-- 调用宏 -->
<xacro:reorder>
    <first/>
    <second/>
</xacro:reorder>
```

处理顺序为 `second` -> `first`



##### 5. 宏嵌套

宏嵌套即一个宏内调用其他宏，这种宏在被调用时，各宏从外部到内部依次处理。

```xml
<!-- 定义宏 foo -->
<xacro:macro name="foo" params="x">
    <in_foo the_x="${x}" />
</xacro:macro>

<!-- 定义宏 bar -->
<xacro:macro name="bar" params="y">
    <in_bar>
        <xacro:foo x="${y}" />
    </in_bar>
</xacro:macro>

<!-- 调用宏 bar -->
<xacro:bar y="12" />
```

调用宏`bar`并传入`12`，先展开宏`bar`，再展开宏`foo`，如下：

```xml
<in_bar>
    <in_foo the_x="12" />
</in_bar>
```



##### 6. 默认参数

宏的入参可以有默认值，如下使用海象运算符 `:=` ：

```xml
<xacro:macro name="foo" params="x:=${x} y:=${2*y} z:=0"/>
```

如果默认值包含表达式，则它们将在实例化时进行计算。

```xml
<xacro:macro name="foo" params="p1 p2:=expr_a p3:=^ p4:=^|expr_b">
```

符号 `^` 表示使用外部属性的值（具有相同名称）。管道 `|` 表示如果属性未在外部范围中定义，则使用给定的后备值。



##### 7. 局部属性

在宏中定义的属性和宏是该宏的局部属性和宏，即在外部不可见。使用可选字段 `scope="parent | global"`，可以将属性定义导出到宏的父范围（或全局范围）。



#### 5.2.1.4 Rospack 命令

Xacro 允许使用某些 rospack 命令：

```xml
<foo value="$(find xacro)" />
<foo value="$(arg myvar)" />
```



#### 5.2.1.5 包含其他 xacro 文件

可以使用 `xacro:include` 标签包含其他 xacro 文件：

```xml
<xacro:include filename="$(find package)/other_file.xacro" />
<xacro:include filename="other_file.xacro" />
<xacro:include filename="$(cwd)/other_file.xacro" />
```

为了避免各个包含文件的属性和宏之间发生名称冲突，可以为包含的文件指定命名空间 - 提供属性 ns：

```xml
<xacro:include filename="other_file.xacro" ns="namespace"/>
```

通过在前面添加命名空间（用点分隔）可以访问命名空间的宏和属性：

```xml
${namespace.property}
```



#### 5.2.1.6 条件语句

Xacro同样支持条件语句，示例如下：

```xml
<xacro:if value="<expression>">
	<... some xml code here ...>
</xacro:if>
<xacro:unless value="<expression>">
  	<... some xml code here ...>
</xacro:unless>
```

其中 `<expression>` 表达式的结果必须是 `0`、`1`、`false`、`true` ，否则会报错。

在 ROS Jade 版本中，Xacro引入了python解析表达式，所以，任何计算结果为布尔值的 Python 表达式都是合法的。

```xml
<xacro:property name="var" value="useit"/>
<xacro:if value="${var == 'useit'}"/>
<xacro:if value="${var.startswith('use') and var.endswith('it')}"/>

<xacro:property name="allowed" value="${[1,2,3]}"/>
<xacro:if value="${1 in allowed}"/>
```



#### 5.2.1.7 YAML 支持

属性也可以是字典或列表 - 使用 python 语法声明，如下所示：

```xml
<xacro:property name="props" value="${dict(a=1, b=2, c=3)}"/>
<xacro:property name="props_alt" value="${dict([('1a',1), ('2b',2), ('3c',3)])}"/>
<xacro:property name="numbers" value="${[1,2,3,4]}"/>
```

或者从 YAML 文件加载，如下所示：

```xml
<xacro:property name="yaml_file" value="$(find package)/config/props.yaml" />
<xacro:property name="props" value="${load_yaml(yaml_file)}"/>
```

从 YAML 文件加载的 xacro 属性被视为字典。 因此，如果`props.yaml`被加载到`props` xacro 属性中（如上所述）并且包含如下内容：

```yaml
val1: 10
val2: 20
```

则可以使用如下方法读取：

```xml
<xacro:property name="val1" value="${props['val1']}" />
```



#### 5.2.1.8 从 CMakeLists.txt 构建

以下代码片段展示了如何在包的 make 调用期间使用 xacro：

```cmake
# Generate .world files from .world.xacro files
find_package(xacro REQUIRED)
# You can also add xacro to the list of catkin packages:
#   find_package(catkin REQUIRED COMPONENTS ... xacro)

# Xacro files
file(GLOB xacro_files ${CMAKE_CURRENT_SOURCE_DIR}/worlds/*.world.xacro)

foreach(it ${xacro_files})
  # remove .xacro extension
  string(REGEX MATCH "(.*)[.]xacro$" unused ${it})
  set(output_filename ${CMAKE_MATCH_1})

  # create a rule to generate ${output_filename} from {it}
  xacro_add_xacro_file(${it} ${output_filename})

  list(APPEND world_files ${output_filename})
endforeach(it)

# add an abstract target to actually trigger the builds
add_custom_target(media_files ALL DEPENDS ${world_files})
```

虽然此 cmake 代码提供了对目标名称和构建顺序的完全控制，但也有一个便捷宏：

```cmake
file(GLOB xacro_files worlds/*.world.xacro)
xacro_add_files(${xacro_files} TARGET media_files)
```

如果希望生成 `.urdf` 文件，可以提供以 `.urdf.xacro` 结尾的输入文件，CMake 函数将删除 `.xacro` 后缀。



#### 5.2.1.9 处理顺序

通常的方法是，xacro 首先加载所有 `<include>` 的内容，然后处理所有属性和宏定义，最后实例化宏并计算表达式。因此，**后面的属性或宏定义将覆盖前面的**。此外，条件标签 `<if>` 和 `<unless>` 对宏或属性定义以及附加文件的 `<include>` 没有影响。

**Jade 中的新功能**：

自 ROS Jade 以来，xacro 提供了命令行选项 `--inorder`，允许按读取顺序处理整个文档。因此，将使用**最后读取的**属性或宏。还允许一些不错的新功能：

- 如果将 `<include>` 标签分别放在宏或条件标签内，则可以推迟或完全抑制文件的包含。
- 可以通过属性或宏参数指定包含文件名。
- 通过在全局范围内改变属性，如果在宏中使用这些属性，宏的实例化可以产生不同的结果。
- 属性定义可以是有条件的。
- 宏可以在内部定义属性而不影响外部的东西。

因为 `--inorder` 处理功能更加强大，在 Jade 之后的未来版本中，它成为了默认方式，所以应该检查 xacro 文件的兼容性。通常，两种处理方式会给出相同的结果。可以像这样检查：

```bash
rosrun xacro xacro file.xacro > /tmp/old.xml
rosrun xacro xacro --inorder file.xacro > /tmp/new.xml
diff /tmp/old.xml /tmp/new.xml
```

如果两个文件有任何差异，应该检查并调整 xacro 文件。一个常见原因是校准数据（作为属性）加载较晚，在这种情况下，只需将它们移到前面，即使用之前。为了方便搜索错误放置的属性定义，可以使用选项 `--check-order` 运行 xacro 。如果有任何有问题的属性，将在 stderr 上列出：

```bash
Document is incompatible to --inorder processing.
The following properties were redefined after usage:
foo redefined in issues.xacro
```

使用命令行选项 `-vv` 或 `-vvv` 可以增加详细级别来记录所有属性的定义。



#### 5.2.1.10 调试语法错误

要获得更详细的语法错误输出，可以运行以下命令，该命令将 xacro 转成 urdf 并检查语法错误，如果没有安装该命令，可以使用 `sudo apt install liburdfdom-tools` 安装

```bash
cd <path_to_xacro_file>
check_urdf <(xacro model.xacro)
```

或

```bash
xacro model.urdf.xacro > tmp.urdf && check_urdf tmp.urdf && rm tmp.urdf
```



### 5.2.2 使用 Xacro 优化 URDF 模型

对于前文介绍的 urdf 模型，我们可以使用 xacro 来优化，使其更易于维护。

优化点：
1. 多次用到的尺寸用常量定义
2. 计算使用公式表示，增加可读性
3. 重复结构用宏定义
4. 可复用的结构模块用单独文件编写，使用时在其他文件 include


#### 5.2.2.1 使用属性表示常量

对于一些多次用到的常量，可以使用属性表示，以实现更好的可读性与可维护性。

```xml
<!-- 属性列表 -->
<xacro:property name="M_PI" value="3.1415926"/>
<xacro:property name="base_radius" value="0.20"/>
<xacro:property name="base_length" value="0.16"/>

<xacro:property name="wheel_radius" value="0.06"/>
<xacro:property name="wheel_length" value="0.025"/>
<xacro:property name="wheel_joint_y" value="0.19"/>
<xacro:property name="wheel_joint_z" value="0.05"/>

<xacro:property name="caster_radius" value="0.015"/> 
<xacro:property name="caster_joint_x" value="0.18"/>
```

#### 5.2.2.2 使用公式

需要计算的地方，在urdf中一般是计算好后，将结果填入用的地方，但这样就隐藏掉了计算过程，无论是可读性还是维护性都不好。
从 ROS Jade 开始，Xacro支持了 Python 表达式的解析，可以使用 Python 表达式编写计算公式，使代码复用性更强。
比如计算底盘与地面的joint，可以根据常量脚轮半径（caster_radius）与 底盘高（base_length）计算，如下：
```xml
<joint name="base_footprint_joint" type="fixed">
    <origin xyz="0 0 ${base_length/2 + caster_radius*2}" rpy="0 0 0" />
    <parent link="base_footprint" />
    <child link="base_link" />
</joint>
```

#### 5.2.2.3 使用宏定义

使用宏可以封装复杂计算、通用结构等，比如左右轮子、前后脚轮等都可以抽象为一个宏，通过不同入参生成不同对象。

```xml
<!-- 轮子宏定义 -->
<xacro:macro name="wheel" params="prefix reflect">
    <joint name="${prefix}_wheel_joint" type="continuous">
        <origin xyz="0 ${reflect*wheel_joint_y} ${-wheel_joint_z}" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="${prefix}_wheel_link" />
        <axis xyz="0 1 0" />
    </joint>

    <link name="${prefix}_wheel_link">
        <visual>
            <origin xyz="0 0 0" rpy="${M_PI/2} 0 0" />
            <geometry>
                <cylinder radius="${wheel_radius}" length="${wheel_length}" />
            </geometry>
            <material name="gray" />
        </visual>
    </link>
</xacro:macro>

<!-- 脚轮宏定义 -->
<xacro:macro name="caster" params="prefix reflect">
    <joint name="${prefix}_caster_joint" type="continuous">
        <origin xyz="${reflect*caster_joint_x} 0 ${-(base_length/2 + caster_radius)}"
            rpy="0 0 0" />
        <parent link="base_link" />
        <child link="${prefix}_caster_link" />
        <axis xyz="0 1 0" />
    </joint>

    <link name="${prefix}_caster_link">
        <visual>
            <origin xyz="0 0 0" rpy="0 0 0" />
            <geometry>
                <sphere radius="${caster_radius}" />
            </geometry>
            <material name="black" />
        </visual>
    </link>
</xacro:macro>
```

#### 5.2.2.4 include 其他文件

有时同一个实体可能被多个机器人使用，比如传感器，这是可以将传感器单独用一个 xacro 文件表示，然后在其他文件中 include。

比如相机，先写一个单独的相机xacro文件 `camera.xacro`：
```xml
<?xml version="1.0"?>
<robot name="camera" xmlns:xacro="http://www.ros.org/wiki/xacro">

    <xacro:macro name="usb_camera" params="prefix:=camera">
        <link name="${prefix}_link">
            <visual>
                <origin xyz=" 0 0 0 " rpy="0 1.57 0" />
                <geometry>
                    <cylinder radius="0.02" length="0.05" />
                </geometry>
                <material name="gray">
                    <color rgba="0.25 0.25 0.25 0.95" />
                </material>
            </visual>
        </link>
    </xacro:macro>

</robot>
```

然后在机器人本体的xacro文件中include这个 `camera.xacro`：
```xml
<?xml version="1.0"?>
<robot name="mbot_with_camera" xmlns:xacro="http://www.ros.org/wiki/xacro">

    <xacro:include filename="$(find simulation_learning)/models/xacro/base.xacro" />
    <xacro:include filename="$(find simulation_learning)/models/xacro/sensors/camera.xacro" />

    <xacro:property name="camera_offset_x" value="0.18" />
    <xacro:property name="camera_offset_y" value="0" />
    <xacro:property name="camera_offset_z" value="0.055" />

    <!-- 调用base宏 -->
    <xacro:mbot_base />

    <!-- Camera -->
    <joint name="camera_joint" type="fixed">
        <origin xyz="${camera_offset_x} ${camera_offset_y} ${camera_offset_z}" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="camera_link" />
    </joint>

    <!-- 调用Camera宏 -->
    <xacro:usb_camera prefix="camera" />

</robot>
```

这里注意，Xacro的 `xacro:include` 会把被include的文件内容解析展开到 `xacro:include` 的位置，所以在被include的文件中，如果有宏调用等语句，也会在 `xacro:include` 的地方生效。



#### 5.2.2.5 优化实践

对于纯urdf实现的模型，用xacro优化后如下：

优化前，完整的urdf代码：

```xml
<?xml version="1.0"?>
<robot name="mbot">

    <!-- 底盘实体描述 -->
    <link name="base_link">
        <visual>
            <origin xyz=" 0 0 0" rpy="0 0 0" />
            <geometry>
                <cylinder length="0.16" radius="0.20" />
            </geometry>
            <material name="yellow">
                <color rgba="1 0.4 0 1" />
            </material>
        </visual>
    </link>

    <!-- 左轮与底盘的关节描述 -->
    <joint name="left_wheel_joint" type="continuous">
        <origin xyz="0 0.19 -0.05" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="left_wheel_link" />
        <axis xyz="0 1 0" />
    </joint>

    <!-- 左轮实体描述 -->
    <link name="left_wheel_link">
        <visual>
            <origin xyz="0 0 0" rpy="1.5707 0 0" />
            <geometry>
                <cylinder radius="0.06" length="0.025" />
            </geometry>
            <material name="white">
                <color rgba="1 1 1 0.9" />
            </material>
        </visual>
    </link>

    <!-- 右轮与底盘的关节描述 -->
    <joint name="right_wheel_joint" type="continuous">
        <origin xyz="0 -0.19 -0.05" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="right_wheel_link" />
        <axis xyz="0 1 0" />
    </joint>

    <!-- 右轮实体描述 -->
    <link name="right_wheel_link">
        <visual>
            <origin xyz="0 0 0" rpy="1.5707 0 0" />
            <geometry>
                <cylinder radius="0.06" length="0.025" />
            </geometry>
            <material name="white">
                <color rgba="1 1 1 0.9" />
            </material>
        </visual>
    </link>

    <!-- 前脚轮实体描述 -->
    <joint name="front_caster_joint" type="continuous">
        <origin xyz="0.18 0 -0.095" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="front_caster_link" />
        <axis xyz="0 1 0" />
    </joint>

    <!-- 前脚轮和底盘的关节描述 -->
    <link name="front_caster_link">
        <visual>
            <origin xyz="0 0 0" rpy="0 0 0" />
            <geometry>
                <sphere radius="0.015" />
            </geometry>
            <material name="black">
                <color rgba="0 0 0 0.95" />
            </material>
        </visual>
    </link>

    <!-- 后脚轮实体描述 -->
    <joint name="back_caster_joint" type="continuous">
        <origin xyz="-0.18 0 -0.095" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="back_caster_link" />
        <axis xyz="0 1 0" />
    </joint>

    <!-- 后脚轮和底盘的关节描述 -->
    <link name="back_caster_link">
        <visual>
            <origin xyz="0 0 0" rpy="0 0 0" />
            <geometry>
                <sphere radius="0.015" />
            </geometry>
            <material name="black">
                <color rgba="0 0 0 0.95" />
            </material>
        </visual>
    </link>

    <!-- 激光雷达实体描述 -->
    <link name="laser_link">
        <visual>
            <origin xyz=" 0 0 0 " rpy="0 0 0" />
            <geometry>
                <cylinder length="0.05" radius="0.05" />
            </geometry>
            <material name="gray">
                <color rgba="0.25 0.25 0.25 0.95" />
            </material>
        </visual>
    </link>

    <!-- 激光雷达和底盘的关节描述 -->
    <joint name="laser_joint" type="fixed">
        <origin xyz="0 0 0.105" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="laser_link" />
    </joint>

    <!-- 相机实体描述 -->
    <link name="camera_link">
        <visual>
            <origin xyz=" 0 0 0 " rpy="0 1.57 0" />
            <geometry>
                <cylinder radius="0.02" length = "0.05"/>
            </geometry>
            <material name="gray">
                <color rgba="0.25 0.25 0.25 0.95"/>
            </material>
        </visual>
    </link>

    <!-- 相机和底盘的关节描述 -->
    <joint name="camera_joint" type="fixed">
        <origin xyz="0.18 0 0.055" rpy="0 0 0"/>
        <parent link="base_link"/>
        <child link="camera_link"/>
    </joint>

</robot>
```

rviz中显示结果如下：

![image-20240501091828865](img/image-20240501091828865.png)



使用xacro优化后：

分成四个文件：`camera.xacro`、`laser.xacro`、`base.xacro` 和 `mbot_base_with_laser_camera.xacro`

camera.xacro：

```xml
<?xml version="1.0"?>
<robot name="camera" xmlns:xacro="http://www.ros.org/wiki/xacro">

    <xacro:macro name="usb_camera" params="prefix:=camera">
        <link name="${prefix}_link">
            <visual>
                <origin xyz="0 0 0 " rpy="0 1.57 0" />
                <geometry>
                    <cylinder radius="0.02" length="0.05" />
                </geometry>
                <material name="black" />
            </visual>
        </link>
    </xacro:macro>

</robot>
```

laser.xacro：

```xml
<?xml version="1.0"?>
<robot name="laser" xmlns:xacro="http://www.ros.org/wiki/xacro">

    <xacro:macro name="laser" params="prefix:=laser">
        <link name="${prefix}_link">
            <visual>
                <origin xyz="0 0 0 " rpy="0 0 0" />
                <geometry>
                    <cylinder length="0.05" radius="0.05" />
                </geometry>
                <material name="black" />
            </visual>
        </link>
    </xacro:macro>

</robot>
```

base.xacro：

```xml
<?xml version="1.0"?>
<robot name="base" xmlns:xacro="http://www.ros.org/wiki/xacro">

    <!-- 属性列表 -->
    <xacro:property name="M_PI" value="3.1415926" />
    <xacro:property name="base_radius" value="0.20" />
    <xacro:property name="base_length" value="0.16" />

    <xacro:property name="wheel_radius" value="0.06" />
    <xacro:property name="wheel_length" value="0.025" />
    <xacro:property name="wheel_joint_y" value="0.19" />

    <xacro:property name="caster_radius" value="0.015" />
    <xacro:property name="caster_joint_x" value="0.18" />

    <!-- 颜色列表 -->
    <material name="yellow">
        <color rgba="1 0.4 0 1" />
    </material>
    <material name="black">
        <color rgba="0 0 0 0.95" />
    </material>
    <material name="gray">
        <color rgba="0.25 0.25 0.25 0.95" />
    </material>
    <material name="white">
        <color rgba="1 1 1 0.9" />
    </material>

    <!-- 轮子宏定义 -->
    <xacro:macro name="wheel" params="prefix reflect">
        <joint name="${prefix}_wheel_joint" type="continuous">
            <origin xyz="0 ${reflect*wheel_joint_y} ${wheel_radius}" rpy="0 0 0" />
            <parent link="base_link" />
            <child link="${prefix}_wheel_link" />
            <axis xyz="0 1 0" />
        </joint>

        <link name="${prefix}_wheel_link">
            <visual>
                <origin xyz="0 0 0" rpy="${M_PI/2} 0 0" />
                <geometry>
                    <cylinder radius="${wheel_radius}" length="${wheel_length}" />
                </geometry>
                <material name="white" />
            </visual>
        </link>
    </xacro:macro>

    <!-- 脚轮宏定义 -->
    <xacro:macro name="caster" params="prefix reflect">
        <joint name="${prefix}_caster_joint" type="continuous">
            <origin xyz="${reflect*caster_joint_x} 0 ${caster_radius}"
                rpy="0 0 0" />
            <parent link="base_link" />
            <child link="${prefix}_caster_link" />
            <axis xyz="0 1 0" />
        </joint>

        <link name="${prefix}_caster_link">
            <visual>
                <origin xyz="0 0 0" rpy="0 0 0" />
                <geometry>
                    <sphere radius="${caster_radius}" />
                </geometry>
                <material name="black" />
            </visual>
        </link>
    </xacro:macro>

    <!-- 底盘宏定义 -->
    <xacro:macro name="mbot_base">

        <link name="base_link">
            <visual>
                <origin xyz="0 0 ${2*caster_radius + base_length/2}" rpy="0 0 0" />
                <geometry>
                    <cylinder length="${base_length}" radius="${base_radius}" />
                </geometry>
                <material name="yellow" />
            </visual>
        </link>

        <!-- 调用轮子宏 -->
        <xacro:wheel prefix="left" reflect="-1" />
        <xacro:wheel prefix="right" reflect="1" />

        <!-- 调用脚轮宏 -->
        <xacro:caster prefix="front" reflect="-1" />
        <xacro:caster prefix="back" reflect="1" />
    </xacro:macro>

</robot>
```

mbot_base_with_laser_camera.xacro：

```xml
<?xml version="1.0"?>
<robot name="mbot_with_laser_camera" xmlns:xacro="http://www.ros.org/wiki/xacro">

    <xacro:include filename="$(find simulation_learning)/models/xacro/base.xacro" />
    <xacro:include filename="$(find simulation_learning)/models/xacro/sensors/laser.xacro" />
    <xacro:include filename="$(find simulation_learning)/models/xacro/sensors/camera.xacro" />

    <xacro:property name="laser_offset_x" value="0" />
    <xacro:property name="laser_offset_y" value="0" />
    <xacro:property name="laser_offset_z" value="${2*caster_radius + base_length + laser_length/2}" />

    <xacro:property name="camera_offset_x" value="0.18" />
    <xacro:property name="camera_offset_y" value="0" />
    <xacro:property name="camera_offset_z" value="0.165" />

    <!-- 调用base宏 -->
    <xacro:mbot_base />

    <!-- laser_joint -->
    <joint name="laser_joint" type="fixed">
        <origin xyz="${laser_offset_x} ${laser_offset_y} ${laser_offset_z}" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="laser_link" />
    </joint>

    <!-- 调用laser宏 -->
    <xacro:laser prefix="laser" />

    <!-- camera_joint -->
    <joint name="camera_joint" type="fixed">
        <origin xyz="${camera_offset_x} ${camera_offset_y} ${camera_offset_z}" rpy="0 0 0" />
        <parent link="base_link" />
        <child link="camera_link" />
    </joint>

    <!-- 调用Camera宏 -->
    <xacro:usb_camera prefix="camera" />

</robot>
```

rviz中显示结果为：

![image-20240601204434924](img/image-20240601204434924.png)



## 5.3 控制机器人

前面讲了机器人的建模，是静态的，接下来介绍对机器人的仿真控制，让你的机器人动起来。



### 5.3.1 Arbotix

Arbotix 是一款控制电机、舵机的硬件控制板，并提供相应的 ros 功能包，是一款基于 ROS的机器人控制系统，它旨在为小型机器人提供硬件控制和传感器接口，以便于机器人的运动和感知。它不仅可以驱动真实的 arbotix 控制板，还提供一个差速控制器，通过接收速度控制指令更新机器人的 joint 状态，从而帮助我们实现机器人在仿真环境中的运动。

它的源代码可以在这个里得到：[https://github.com/vanadiumlabs/arbotix_ros](https://github.com/vanadiumlabs/arbotix_ros)

`arbotix_ros` 源码包含如下几部分：

![image-20240608183118287](img/image-20240608183118287.png)

其中，

- `arbotix_controllers`：控制器，现已合并到 `arbotix_python` 中。
- `arbotix_firmware`：处理与 ArbotiX-ROS 绑定通信的固件源代码。
- `arbotix_msgs`：ArbotiX 的消息和服务定义。
- `arbotix_python`：驱动程序、用于与驱动程序交互的 GUI 以及用于设置伺服电器的终端工具。
- `arbotix_sensors`：包含几个传感器模块，可在 arbotix_python 的基本结构上添加额外的 ROS 接口层。

我们主要使用 `arbotix_python` 的驱动程序模块 `arbotix_driver` 中的差速底盘控制器 `diff_controller`。

更多关于 `Arbotix` 的信息见 [https://wiki.ros.org/arbotix](https://wiki.ros.org/arbotix)

关于 `diff_controller` 的信息见 [http://wiki.ros.org/arbotix_python/diff_controller](http://wiki.ros.org/arbotix_python/diff_controller)



#### 5.3.1.1 安装Arbotix

对于 ROS1 ，有两种安装方法，命令行和源码安装。

1. 命令行安装

    ```bash
    sudo apt install ros-<<VersionName()>>-arbotix*
    ```

2. 源码安装

    首先在你的工作空间的 `src` 目录下下载源代码：

    ```bash
    git clone https://github.com/vanadiumlabs/arbotix_ros.git
    ```

    然后编译即可使用 `Arbotix`

    ```
    catkin_make # 编译
    ```
    

#### 5.3.1.2 配置Arbotix控制器

Arbotix 针对不同的机器人，需要配置不同的控制器，配置文件为 `yaml` 格式，如下：

```yaml
# 该文件是控制器配置,一个机器人模型可能有多个控制器，比如: 底盘、机械臂、夹持器(机械手)....
# 因此，根 name 是 controllers
controllers: {
    # 单控制器设置
    base_controller: {
        # 类型: 差速控制器
        type: diff_controller,
        # 参考坐标
        base_frame_id: base_link,
        # 两个轮子之间的间距，单位：m
        base_width: 0.38,
        # 机器人每移动一米，电机编码器所记录的脉冲数
        ticks_meter: 2000,
        # PID控制参数，使机器人车轮快速达到预期速度
        Kp: 12,
        Kd: 12,
        Ki: 0,
        Ko: 50,
        # 加速度限制
        accel_limit: 1.0
    }
}
```



#### 5.3.1.3 配置launch启动文件

启动时 Arbotix 会作为一个节点加入到 ROS Master 中，我们使用 launch 文件配置快速启动。

```xml
<node name="arbotix" pkg="arbotix_python" type="arbotix_driver" output="screen">
    <rosparam file="$(find simulation_learning)/config/mbot_arbotix.yaml" command="load" />
    <param name="sim" value="true"/>
</node>
```

其中，节点名注册为 `arbotix`，包名为 `arbotix_python`，节点可执行文件名为 `arbotix_driver`；`rosparam` 一行是载入上文的 `Arbotix` 配置文件；`Arbotix` 不仅可以用于真实控制板，也可以用于仿真环境，如用于仿真，需将参数 `sim` 设置为 `true`。



#### 5.3.1.4 数据交互接口

该节点订阅一个话题：/cmd_vel，用于接收对机器人的速度控制信息

消息格式为：geometry_msgs/Twist

```xml
geometry_msgs/Vector3 linear  # 机器人三轴线速度
  float64 x
  float64 y
  float64 z
geometry_msgs/Vector3 angular  # 机器人三轴角速度
  float64 x
  float64 y
  float64 z
```

发布一个话题：/odom，用于发布机器人里程计信息，包括定位与速度等信息

消息格式为：nav_msgs/Odometry

```xml
std_msgs/Header header
  uint32 seq  # 消息序列号
  time stamp  # 时间戳
  string frame_id  # 消息帧id
string child_frame_id
geometry_msgs/PoseWithCovariance pose
  geometry_msgs/Pose pose
    geometry_msgs/Point position  # 机器人位置坐标
      float64 x
      float64 y
      float64 z
    geometry_msgs/Quaternion orientation # 机器人方向的四元数表示
      float64 x
      float64 y
      float64 z
      float64 w
  float64[36] covariance  # 6x6协方差矩阵的行主表示
geometry_msgs/TwistWithCovariance twist
  geometry_msgs/Twist twist
    geometry_msgs/Vector3 linear  # 机器人三轴线速度
      float64 x
      float64 y
      float64 z
    geometry_msgs/Vector3 angular  # 机器人三轴角速度
      float64 x
      float64 y
      float64 z
  float64[36] covariance  # 6x6协方差矩阵的行主表示
```

其中6x6协方差矩阵，用于量化位姿估计不确定性。这个矩阵对角线上的元素分别代表了位置与方向估计值的方差，而矩阵的非对角线元素则表示了位置与方向各估计值之间的协方差。矩阵各向量依次表示 （x，y，z，绕x轴旋转，绕y轴旋转，围绕z轴旋转）的估计不确定性。

有了这两个话题，我们就可以控制并获取机器人的位姿了。



#### 5.3.1.5 在rviz中仿真控制机器人

使用前文 [5.1.3 URDF建模实践](#5.1.3 URDF建模实践) 创建的机器人模型，在 launch 文件中添加 Arbotix 节点的启动配置，启动后如下图：

![image-20240608201952156](img/image-20240608201952156.png)



##### 5.3.1.5.1 直接发topic控制

发布 /cmd_vel 话题控制机器人移动，并订阅 /odom 显示机器人的实时位置与速度信息：

![Peek 2024-06-08 20-37](img/2024-06-08 20-37.gif)

##### 5.3.1.5.2 使用键盘控制

运行ROS提供的键盘控制包，控制机器人移动：

![Peek 2024-06-08 20-51](img/2024-06-08 20-51.gif)

##### 5.3.1.5.3 编写代码控制机器人移动

写两个节点，一个发布速度，一个订阅里程计，如下：

move.cpp 用于发布速度：

```cpp
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

geometry_msgs::Twist moveRobot(const double& linear, const double& angular)
{
    geometry_msgs::Twist msg;
    msg.linear.x = linear;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = angular;
    ROS_INFO("moveRobot, linear: %.3lf, angular: %.1lf", linear, angular*180/M_PI);

    return msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_robot");
    ros::NodeHandle nh;
    ros::Publisher velPub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    ros::Rate r(1);

    while (ros::ok())
    {
        velPub.publish(moveRobot(0.5, -0.3));
        ros::Duration(3.0).sleep();
        velPub.publish(moveRobot(-0.5, -0.3));
        ros::Duration(3.0).sleep();

        r.sleep();
    }

    return 0;
}
```

odom.cpp 用于订阅里程计：

```cpp
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    geometry_msgs::Quaternion q = msg->pose.pose.orientation;
    ROS_INFO("pose: [%.2lf, %.2lf, %.1lf], linear: %.2lf, angular: %.2lf", 
        msg->pose.pose.position.x, msg->pose.pose.position.y, 
        std::atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))*180/M_PI, 
        msg->twist.twist.linear.x, msg->twist.twist.angular.z*180/M_PI);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "robot_odom");
    ros::NodeHandle nh;
    ros::Subscriber odomSub = nh.subscribe<nav_msgs::Odometry>("/odom", 10, odomCallback);
    ros::spin();

    return 0;
}
```

CMakeList.txt 中添加内容：

```cmake
add_executable(move_robot_node src/move.cpp)
add_executable(robot_odom_node src/odom.cpp)

target_link_libraries(move_robot_node
  ${catkin_LIBRARIES}
)

target_link_libraries(robot_odom_node
  ${catkin_LIBRARIES}
)
```

启动 rviz 后，运行 `move_robot_node` 和 `robot_odom_node` ，如下：

![Peek 2024-06-08 22-32](img/2024-06-08 22-32.gif)



### 5.3.2 ros_control

官方文档：http://wiki.ros.org/ros_control

`ros_control` 是一个 ROS 功能包，是一个通用的机器人控制框架，用于实现机器人硬件接口、控制器管理和控制器接口。它提供了一套用于控制各种类型机器人（如移动机器人、机械臂等）的工具和接口。`ros_control` 的设计目的是为开发者提供一个灵活且可扩展的框架，使得控制算法能够独立于具体的硬件平台运行，并且可以轻松地在不同的机器人之间移植。

#### 5.3.2.1 ros_control 架构

`ros_control` 架构图如下：

![2024-06-09_10-37](img/2024-06-09_10-37.png)

`ros_control` 由以下几个主要组件组成：

- hardware_interface：硬件底层接口
- combined_robot_hw：硬件包
- controller_interface：controller接口
- controller_manager：controller管理器
- controller_manager_msgs：controller管理器的消息类型
- joint_limits_interface：joints限制接口
- transmission_interface：传动接口
- realtime_tools：实时控制工具



##### 5.3.2.1.1 hardware_interface

`hardware_interface` 提供了一套硬件抽象接口，使得控制器可以独立于具体的硬件实现。



##### 5.3.2.1.2 combined_robot_hw

`combined_robot_hw` 由 `CombinedRobotHW` 类实现，`CombinedRobotHW` 是一个硬件抽象类，允许将多个硬件接口组合在一起，从而让多个独立的硬件模块作为一个整体被控制器管理器控制。



##### 5.3.2.1.3 controller_interface

`controller_interface` 提供了定义控制器的基础接口，用于实现具体的控制器。控制器需要继承 `controller_interface::Controller` 类，并实现控制逻辑。



##### 5.3.2.1.4 controller_manager

`controller_manager` 负责管理控制器的生命周期，包括加载、启动、停止和卸载控制器。它提供了服务和话题接口，用于与控制器进行交互。



##### 5.3.2.1.5 controller_manager_msgs

`controller_manager_msgs` 包含了与控制器管理器交互的消息类型和服务类型，例如加载、启动和停止控制器。



##### 5.3.2.1.6 joint_limits_interface

`joint_limits_interface` 提供了一套接口，用于管理关节的限制条件（例如位置、速度、加速度和力矩限制），以确保关节在安全范围内运行。



##### 5.3.2.1.7 transmission_interface

`transmission_interface` 提供了传动装置的抽象接口，用于处理关节和电机之间的传动关系。它定义了传动装置的结构和方法，以便在控制器中正确处理关节和电机的转换。



##### 5.3.2.1.8 realtime_tools

`realtime_tools` 提供了一些实用工具，用于实现实时控制，包括实时缓冲区和周期性任务管理。



#### 5.3.2.2 ros_controllers

`ros_controllers` 也是一个 ROS 功能包，提供了一组预定义的控制器，这些控制器已经为各种常见的机器人控制任务进行了优化和实现，可以用于控制不同类型的机器人，如移动机器人、机械臂和其他多关节系统。



##### 5.3.2.2.1 控制器列表

目前主要包含以下控制器：

- joint_state_controller
    - JointStateController：从硬件接口获取关节状态，并将这些状态信息发布到 `/joint_states` 话题
- [joint_trajectory_controller](https://wiki.ros.org/joint_trajectory_controller)
    - JointTrajectoryController：接收轨迹信息（即一系列期望的关节位置、速度和加速度），并控制机器人的关节按照这些轨迹运动。该控制器适用于需要精确轨迹跟踪的任务，如路径规划和任务执行。
- gripper_action_controller
    - GripperActionController：控制机械手夹具的开闭位置
- [diff_drive_controller](https://wiki.ros.org/diff_drive_controller)
    - DiffDriveController：控制差速驱动的机器人
- effort_controllers
    - JointEffortController：控制单个关节的力/力矩。通过设定期望的力/力矩，使关节达到所需状态。
    - JointPositionController：控制单个关节的位置，通过力/力矩控制算法使关节达到设定的位置。
    - JointVelocityController：控制单个关节的速度，通过力/力矩控制算法使关节达到设定的速度。
    - JointGroupEffortController：控制一组关节的力/力矩。通过设定多个关节的力/力矩，使它们达到所需状态。
    - JointGroupPositionController：控制一组关节的位置，通过力/力矩控制算法使这些关节达到设定的位置。
- velocity_controllers
    - JointVelocityController：用于控制机器人单个关节的速度
    - JointPositionController：通过PID控制速度以达到设置的位置
    - JointGroupVelocityController：用于控制机器人多个关节的速度
- position_controllers
    - JointPositionController：直接控制单个关节的位置
    - JointGroupPositionController：直接控制一组关节的位置
- imu_sensor_controller
    - IMUSensorController：发布 IMU 传感器的数据
- force_torque_sensor_controller
    - ForceTorqueSensorController：发布力矩传感器的数据
- forward_command_controller
    - ForwardCommandController：用于将单个关节的命令直接传递到硬件接口
    - ForwardJointGroupCommandController：用于将一组关节的命令直接传递到硬件接口
- [ackermann_steering_controller](https://wiki.ros.org/ackermann_steering_controller)
    - AckermannSteeringController：接收线速度和转向角度指令，然后根据 Ackermann 转向几何原理计算并控制各个车轮的转向角和速度，使车辆能够按照预定轨迹运动
- four_wheel_steering_controller
    - FourWheelSteeringController：接收线速度和转向角度指令，然后根据四轮转向几何原理计算并控制各个车轮的转向角和速度，使车辆能够按照预定轨迹运动



##### 5.3.2.2.2 配置控制器

通过将参数加载到ROS参数服务器来配置控制器，一般先将配置写入 `yaml` 文件，再通过文件加载到ROS参数服务器，然后 `ros_control` 会解析特定参数。控制器配置示例如下：

```yaml
my_robot:
	joint_state_controller:
       type: joint_state_controller/JointStateController
       publish_rate: 50

    position_trajectory_controller:
       type: position_controllers/JointTrajectoryController
       joints:
          - joint1
          - joint2
       constraints:
          goal_time: 5.0
          joint1:
              trajectory: 0.60
              goal:       0.15
          joint2:
              trajectory: 0.60
              goal:       0.15
```

不同控制器的参数不同，详见 [http://wiki.ros.org/ros_controllers](http://wiki.ros.org/ros_controllers)  https://index.ros.org/p/ros_controllers/#noetic



#### 5.3.2.3 硬件抽象接口

https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/index.html

ros_control 的最大优点就是把上层业务与底层硬件隔离开，使业务层不依赖于特定的硬件，为此， ros_control 提供了硬件抽象接口，控制器通过硬件接口和硬件交互数据。

目前 ros_control 实现的硬件接口有：

- [JointCommandInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/joint__command__interface_8h_source.html)：支持命令关节阵列的硬件接口，他有三个派生类：
    - EffortJointInterface：用于控制基于力/力矩的关节
    - PositionJointInterface：用于控制基于速度的关节
    - VelocityJointInterface：用于控制基于位置的关节
- [JointStateInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/joint__state__interface_8h_source.html)：读取关节的状态，每个关节都具有一定的位置、速度和力（或扭矩）
- [ActuatorStateInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/actuator__state__interface_8h_source.html)：读取执行器的状态，每个执行器都具有一定的位置、速度和力（或扭矩）
- [ActuatorCommandInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/actuator__command__interface_8h_source.html)
    - EffortActuatorInterface
    - VelocityActuatorInterface
    - PositionActuatorInterface
- [PosVelJointInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/posvel__command__interface_8h_source.html)：通过位置、速度控制关节
- [PosVelAccJointInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/posvelacc__command__interface_8h_source.html)：通过位置、速度和加速度来控制关节
- [ForceTorqueSensorInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/force__torque__sensor__interface_8h_source.html)：读取力矩传感器的状态
- [ImuSensorInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/imu__sensor__interface_8h_source.html)：读取 IMU 传感器的状态
- [JointModeInterface](https://docs.ros.org/en/melodic/api/hardware_interface/html/c++/joint__mode__interface_8h_source.html)：控制关节模式的切换

各接口类继承关系如下：

![2024-06-28_21-51-22](img/2024-06-28_21-51-22.png)

各 `Interface` 实例将对应的 `Handel` 实例注册到硬件资源管理器，在硬件资源管理器统一管理所有抽象硬件。

如`ros_control` 架构图所示，上层 `Controller` 通过各 `Interface` 与抽象硬件交互数据，进而对实际硬件进行读写数据。



#### 5.3.2.4 命令行工具

##### 5.3.2.4.1 controller_manager

管理控制器生命周期：

```bash
rosrun controller_manager controller_manager <command> <name1> <name2> ...
```

其中，`<command>` 可选如下：

- `load`：加载控制器（构造和初始化）
- `unload`：卸载控制器（析构）
- `start`：启动控制器
- `stop`：停止控制器
- `spawn`：加载并启动控制器
- `kill`：停止并卸载控制器

`<name1> <name2>` 为控制器的名称。



获取控制器的状态：

```bash
rosrun controller_manager controller_manager <command>
```

其中，`<command>` 可选如下：

- `list`：按执行顺序列出所有控制器，并给出每个控制器的状态
- `list-types`：列出控制器管理器知道的所有控制器类型。如果控制器不在此列表中，将无法生成。
- `reload-libraries`：重新加载所有可用作插件的控制器库。当新开发控制器并想要测试新的控制器代码时，这很方便，而无需每次都重新启动机器人。这不会重新启动之前运行的控制器。
- `reload-libraries --restore`：重新加载所有可用作插件的控制器库，并将所有控制器恢复到其原始状态。



##### 5.3.2.4.2 spawner

自动加载并启动一组控制器，并自动停止并卸载相同的控制器：

```
rosrun controller_manager spawner [--stopped] <name1> <name2> ...
```

当运行 spawner 时，列出的控制器将被加载并启动，如果加上 `--stopped` 参数，控制器只会被加载不会被启动。在控制器启动时，spawner 将继续运行，当终止 spawner（如：ctrl-c）时，它将自动停止并卸载它最初启动的所有控制器。



##### 5.3.2.4.3 unspawner

停止控制器，但不卸载

```bash
rosrun controller_manager unspawner <name1> <name2> ...
```



##### 5.3.2.4.4 controller_group （melodic 新增）

`controller_manager` 允许开发人员在运行时切换控制器，但是当出于某些特殊目的想要从一组控制器切换到另一组控制器时，它就不那么方便了。如果在 ROS 参数 `controller_groups` 中定义了这样的组，`controller_group` 脚本就可以让这变得简单。它知道所有涉及的控制器，然后知道在从一个组切换到另一个组时需要停止和启动的控制器。因此，不同的组可以共享一些控制器。

控制器分组配置，和控制器配置一样要先加载到ROS参数服务器：

```xml
controller_groups:
  production:
    - prod_controller_1
    - prod_controller_2
  development:
    - devel_controller_1
    - devel_controller_2
    - shared_controller_3
  diagnostics:
    - diag_controller_1
    - diag_controller_2
    - shared_controller_3
```

运行 `controller_group` ：

```bash
rosrun controller_manager controller_group <command> <args>
```

其中，`<command>` 可选如下：

- `list` ：列出在 `controller_groups` 参数中找到的所有组定义
- `spawn <group>` ：加载并启动名为 `<group>` 的组中包含的所有控制器。这通常在 ROS 启动文件中使用
- `switch <group>` ：切换到名为 `<group>` 的组。这将停止那些在其他组中定义但未在本组中运行的控制器，并启动本组中定义的未运行的控制器。



#### 5.3.2.5 加载配置并管理控制器

启动控制器时要注意，运行 `controller_manager` 来从启动文件中启动控制器时，即使启动文件被删除，控制器也会继续运行。建议使用 `spawner` 工具从启动文件中自动加载、启动、停止和卸载控制器，当启动 `spawner` 时，将加载并启动控制器。当停止 `spawner` 时（启动文件被删除或停止运行），将停止并卸载控制器。

```xml
<launch>
   <!-- 加载配置文件 --> 
	<rosparam file="$(find rrbot_control)/config/rrbot_control.yaml" command="load"/>

    <!-- 启动控制器 -->
 	<node name="controller_spawner" pkg="controller_manager" type="spawner" respawn="false" output="screen" ns="/my_robot" args="joint_state_controller position_trajectory_controller"/>
</launch>
```



图形化管理控制器：

rqt_controller_manager是一个 rqt 插件，允许以图形方式加载、卸载、启动和停止控制器，以及显示有关已加载控制器的信息。

它可以从 rqt 的插件菜单启动，或者作为独立可执行文件启动：

```bash
rosrun rqt_controller_manager rqt_controller_manager
```



#### 5.3.2.6 ROS API

为了与其他 ROS 节点的控制器交互，控制器管理器提供了五个服务供调用：

##### 5.3.2.6.1 controller_manager/load_controller

加载指定控制器

消息体：[controller_manager_msgs/LoadController](http://docs.ros.org/en/api/controller_manager_msgs/html/srv/LoadController.html) 



##### 5.3.2.6.2 controller_manager/unload_controller

卸载控制器，控制器仅在停止状态下才可卸载。

消息体：[controller_manager_msgs/UnloadController](http://docs.ros.org/en/api/controller_manager_msgs/html/srv/UnloadController.html)



##### 5.3.2.6.3 controller_manager/switch_controller

启动/停止 控制器

消息体：[controller_manager_msgs/SwitchController](http://docs.ros.org/en/api/controller_manager_msgs/html/srv/SwitchController.html)



##### 5.3.2.6.4 controller_manager/list_controllers

获取当前已加载的所有控制器

消息体：[controller_manager_msgs/ListControllers](http://docs.ros.org/en/api/controller_manager_msgs/html/srv/ListControllers.html)



##### 5.3.2.6.5 controller_manager/list_controller_types

获取已知的所有控制器类型

消息体：[controller_manager_msgs/ListControllerTypes](http://docs.ros.org/en/api/controller_manager_msgs/html/srv/ListControllerTypes.html)



##### 5.3.2.6.6 controller_manager/reload_controller_libraries

重新加载所有可用作插件的控制器库

消息体：[controller_manager_msgs/ReloadControllerLibraries](http://docs.ros.org/en/api/controller_manager_msgs/html/srv/ReloadControllerLibraries.html)



### 5.3.3 使用 ros_control 控制差速轮式机器人

http://wiki.ros.org/diff_drive_controller

ros_control 提供了多种控制器，其中 `diff_drive_controller` 用于控制差速驱动轮式机器人。

#### 5.3.3.1 差速轮式机器人

差速轮式机器人是一种移动机器人，其运动基于机器人身体两侧的两个独立驱动轮。因此，它可以通过改变轮子的相对旋转速度来改变方向，不需要额外的转向运动。具有这种驱动器的机器人通常有一个或多个脚轮，以防止车辆倾斜。

如果两个轮子以相同的方向和速度驱动，机器人将沿直线行驶。如果两个轮子以相同的速度朝相反的方向转动，如所示图所示，机器人将绕轴的中心点旋转。否则，根据旋转速度和方向，旋转中心可能落在由两个轮胎接触点定义的线上的任何位置。当机器人沿直线行驶时，旋转中心距离机器人无限远。由于机器人的方向取决于两个驱动轮的旋转速度和方向，因此应精确感测和控制这些量。

<img src="img/image-20240623192426694.png" alt="image-20240623192426694" style="zoom:50%;" />

差速转向机器人与汽车中使用的差速 齿轮类似，两个车轮可以有不同的转速，但与差速齿轮系统不同，差速转向系统将为两个车轮提供动力。差速轮式机器人在机器人技术中得到广泛应用，因为它们的运动易于编程并且可以很好地控制。当今市场上几乎所有的消费机器人都使用差速转向，主要是因为它成本低且简单。



#### 5.3.3.2 差速驱动机器人运动学模型

如下图为轮式机器人的差速驱动运动学模型示意图：

<img src="img/image-20240623192426693.png" alt="image-20240623192426693" style="zoom:50%;" />



其中，
$$
V - 机器人线速度\\
\omega - 机器人角速度\\
XOY - 世界坐标系\\
X_BY_B - 机器人坐标系\\
\varphi - 机器人在世界坐标系的角度\\
r - 车轮半径\\
b - 轮距\\
ICR - 瞬时旋转中心\\
R - 瞬心到机器人中心的距离\\
v_L,v_R - 左右轮接地点切向线速度\\
\omega_L,\omega_R - 左右轮角速度
$$

有如下关系：
$$
\omega \cdot (R + b/2) = v_R\\
\omega \cdot (R - b/2) = v_L
$$
解这两个方程可得 $\omega$ 和 $R$ ：
$$
\omega = (v_R-v_L)/b\\
R = b/2 \cdot(v_R+v_L)/(v_R-v_L)
$$
利用角速度方程可得机器人瞬时速度 $V$ ：
$$
V = \omega \cdot R = (v_R+v_L)/2
$$
车轮切向速度也可以写成：
$$
v_R = r \cdot \omega_R\\
v_L = r \cdot \omega_L
$$
则机器人在本体坐标系中的运动学模型为：
$$
\begin{bmatrix} \dot{x}_B  \\ \dot{y}_B  \\ \dot{\varphi} \end{bmatrix} 
= \begin{bmatrix} v \cdot x_B  \\ v \cdot y_B  \\ \omega \end{bmatrix}
\overbrace{=}^{v=r\omega} \begin{bmatrix} \frac r2 & \frac r2  \\ 0 & 0 \\ -\frac rb & \frac rb \end{bmatrix}
\begin{bmatrix} \omega_L  \\ \omega_R  \end{bmatrix}
$$
再通过坐标变换，最终可以得到机器人在世界坐标中的运动学模型：
$$
\begin{bmatrix} \dot{x} \\ \dot{y} \\ \dot{\varphi} \end{bmatrix} 
=  \begin{bmatrix} \cos\varphi & 0 \\ \sin\varphi & 0 \\ 0 & 1 \end{bmatrix}
\begin{bmatrix} V  \\ \omega  \end{bmatrix}
$$
其中，$V$ 和 $\omega$ 为控制变量。

通常我们需要通过机器人的速度和结构参数逆解出左右轮的转速，用于控制电机。在这种情况下，可以很容易地重新表述前面提到的方程。使用如下方程：
$$
R = V/\omega\\
\omega_R = v_R/r\\
\omega_L = v_L/r
$$
可得左右轮角速度方程：
$$
\omega_R = \frac{V+\omega \cdot b/2}{r} \\
\omega_L = \frac{V-\omega \cdot b/2}{r}
$$

#### 5.3.3.3 对外接口

 `diff_drive_controller` 主要通过订阅速度命令作为模块的输入，然后解析运动学模型控制电机，达到控制机器人的目的。

##### 5.3.3.3.1 输入接口

- cmd_vel（geometry_msgs/Twist）

    位于控制器的命名空间下，给机器人发布速度

##### 5.3.3.3.2 输出接口

- odom（nav_msgs/Odometry）

    位于控制器的命名空间下，根据硬件反馈计算的里程计信息

- /tf（tf/tfMessage）

    从 odom 转换为 base_link

- cmd_vel_out（geometry_msgs/TwistStamped）

    当 `publish_cmd` 参数设置为 `True` 时可用。在控制器的输入上应用限制器后的 Twist。



#### 5.3.3.4 控制器参数

 `diff_drive_controller` 提供了一些参数，用于配置机器人控制。

| 参数                              | 数据类型            | 说明                                                         |
| --------------------------------- | ------------------- | ------------------------------------------------------------ |
| left_wheel                        | string /string[...] | 左轮关节名称或关节名称列表                                   |
| right_wheel                       | string /string[...] | 右轮关节名称或关节名称列表                                   |
| pose_covariance_diagonal          | double[6]           | 用于里程计位姿发布的协方差矩阵的对角线                       |
| twist_covariance_diagonal         | double[6]           | 用于里程计 twist 发布的协方差矩阵的对角线                    |
| publish_rate                      | double              | 发布里程计的频率，用于 tf 和 odom（单位：Hz，默认值： 50.0） |
| wheel_separation                  | double              | 轮距，左轮和右轮之间的距离。如果未指定此参数，diff_drive_controller 将尝试从 URDF 读取值 |
| wheel_separation_multiplier       | double              | 轮距参数的系数。用于解释机器人模型和真实机器人之间的差异。（默认值：1.0） |
| wheel_radius                      | double              | 车轮半径。默认两侧车轮都具有相同的尺寸。如果未指定此参数，diff_drive_controller 将尝试从 URDF 读取值。 |
| wheel_radius_multiplier           | double              | 车轮半径参数的系数。用于解释机器人模型和真实机器人之间的差异。（默认值：1.0） |
| cmd_vel_timeout                   | double              | 两个连续速度命令之间允许的时间间隔。此延迟后，将向车轮发送零速命令。（单位：s，默认值：0.5） |
| base_frame_id                     | string              | 用于填充Odometry消息和TF的child_frame_id（默认值：“base_link”） |
| linear                            | object              | 线性速度配置参数                                             |
| + x                               | object              | x轴，两轮差速机器人线速度只有x轴                             |
| ++ has_velocity_limits            | bool                | 控制器是否限制线速度。（默认值： false）                     |
| ++ max_velocity                   | double              | 最大线速度（单位：m/s）                                      |
| ++ min_velocity                   | double              | 最小线速度（单位：m/s）。未指定时，使用max_velocity          |
| ++ has_acceleration_limits        | bool                | 控制器是否限制线加速度。（默认值： false）                   |
| ++ max_acceleration               | double              | 最大线加速度（单位：m/s^2）                                  |
| ++ min_acceleration               | double              | 最小线加速度（单位：m/s^2）。未指定时，使用max_acceleration  |
| ++ has_jerk_limits                | bool                | 控制器是否限制线加速度的变化快慢（默认值： false）           |
| ++ max_jerk                       | double              | 最大 jerk（单位：m/s^3）                                     |
| angular                           | object              | 角速度配置参数                                               |
| + z                               | object              | z轴，两轮差速机器人角速度只有z轴                             |
| ++ has_velocity_limits            | bool                | 控制器是否应该限制角速度（默认值： false）                   |
| ++ max_velocity                   | double              | 最大角速度（单位：rad/s）                                    |
| ++ min_velocity                   | double              | 最小角速度（单位：rad/s）。将其设置为 0.0 将禁用逆时针旋转。未指定时，将使用max_velocity |
| ++ has_acceleration_limits        | bool                | 控制器是否应该限制角加速度（默认值： false）                 |
| ++ max_acceleration               | double              | 最大角加速度（单位：rad/s^2）                                |
| ++ min_acceleration               | double              | 最小角加速度（单位为 rad/s^2）。未指定时，使用max_acceleration。 |
| ++ has_jerk_limits                | bool                | 控制器是否限制角加速度的变化快慢（默认值： false）           |
| ++ max_jerk                       | double              | 最大 jerk（单位：rad/s^3）                                   |
| enable_odom_tf                    | bool                | 是否直接发布到 TF（默认值： true ）                          |
| odom_frame_id                     | string              | 里程计的frame_id（默认值：“/odom”）                          |
| publish_cmd                       | bool                | 发布要执行的速度命令。用于监控限制器对控制器输入的影响。（默认值： False） |
| allow_multiple_cmd_vel_publishers | bool                | 将其设置为 true 将允许输入接口 ~/cmd_vel 有多个发布者。如果将其设置为 false，则如果 ~/cmd_vel 有多个发布者，则会导致控制器停止运行。（默认值： False） |
| velocity_rolling_window_size      | int                 | 用于计算里程计 twist.linear.x 和 twist.angular.z 速度的平均速度样本数量（默认值： 10） |



#### 5.3.3.5 配置控制器参数

最小配置示例（即必要配置项）：

```yaml
diff_drive_controller:
    type: "diff_drive_controller/DiffDriveController"
    left_wheel: "left_wheel_joint"
    right_wheel: "right_wheel_joint"
    pose_covariance_diagonal: [0.001, 0.001, 0.001, 0.001, 0.001, 0.03]
    twist_covariance_diagonal: [0.001, 0.001, 0.001, 0.001, 0.001, 0.03]
```



该差速轮式机器人完整配置：

```yaml
# 用于控制器硬件接口配置
hardware_interface:
  joints:
    - left_wheel_joint
    - right_wheel_joint
    - front_caster_joint
    - back_caster_joint

# joint_state_controller 控制器，用于发布各关节状态
joint_state_controller:
  type: "joint_state_controller/JointStateController"
  publish_rate: 50

# diff_drive_controller 控制器
diff_drive_controller:
  type: "diff_drive_controller/DiffDriveController"
  left_wheel: "left_wheel_joint"
  right_wheel: "right_wheel_joint"
  publish_rate: 50
  pose_covariance_diagonal: [0.001, 0.001, 0.001, 0.001, 0.001, 0.03]
  twist_covariance_diagonal: [0.001, 0.001, 0.001, 0.001, 0.001, 0.03]
  cmd_vel_timeout: 100
  velocity_rolling_window_size: 1

  publish_cmd: true
  base_frame_id: base_link
  enable_odom_tf: true
  odom_frame_id: odom

  # 轮间距和轮半径
  wheel_separation: 0.38
  wheel_radius: 0.06
  wheel_separation_multiplier: 1.0
  wheel_radius_multiplier: 1.0

  # 速度和加速度限制
  linear:
    x:
      has_velocity_limits: true
      max_velocity: 1.0 # m/s
      has_acceleration_limits: true
      max_acceleration: 3.0 # m/s^2
  angular:
    z:
      has_velocity_limits: true
      max_velocity: 2.0 # rad/s
      has_acceleration_limits: true
      max_acceleration: 6.0 # rad/s^2
```



#### 5.3.3.6 编写硬件抽象接口

下面写一个两轮差速硬件接口，使用速度控制接口 `VelocityJointInterface` 控制 joint 的速度，使用 `JointStateInterface` 获取 joint 的位置、速度、力等信息。

硬件抽象接口头文件：diff_drive_hardware_interface.h

```cpp
#ifndef DIFF_DRIVE_HARDWARE_INTERFACE_H
#define DIFF_DRIVE_HARDWARE_INTERFACE_H

#include <ros/ros.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <controller_manager/controller_manager.h>

class DiffDriveHWInterface : public hardware_interface::RobotHW
{
public:
    struct JointInfo
    {
        std::string name;
        double cmd;
        double pos;
        double vel;
        double eff;

        JointInfo() : name(""), cmd(0.0), pos(0.0), vel(0.0), eff(0.0)
        {}

        JointInfo(std::string name_) 
            : name(name_), cmd(0.0), pos(0.0), vel(0.0), eff(0.0)
        {}

        JointInfo(std::string name_, double cmd_, double pos_, double vel_, double dff_) 
            : name(name_), cmd(cmd_), pos(pos_), vel(vel_), eff(dff_)
        {}

    };
    
public:
    DiffDriveHWInterface(ros::NodeHandle &nh);
    void init();
    void read(const ros::Duration &period);
    void write(const ros::Duration &period);

private:
    ros::NodeHandle m_nh;
    hardware_interface::JointStateInterface m_jnt_state_interface;
    hardware_interface::VelocityJointInterface m_jnt_vel_interface;
    std::vector<JointInfo> m_joints;
};

#endif // DIFF_DRIVE_HARDWARE_INTERFACE_H
```

源文件：diff_drive_hardware_interface.cpp

```cpp
#include "diff_drive_control/diff_drive_hardware_interface.h"

DiffDriveHWInterface::DiffDriveHWInterface(ros::NodeHandle &nh) : m_nh(nh)
{
}

/**
 * @brief 初始化关节信息
 *        注册抽象硬件接口
 * 
 */
void DiffDriveHWInterface::init()
{
    std::vector<std::string> joint_names;
    m_nh.getParam("/hardware_interface/joints", joint_names);
    for (std::string name : joint_names)
    {
        m_joints.push_back(JointInfo(name));
    }

    for (auto &joint : m_joints)
    {
        ROS_INFO("get joint: %s", joint.name.c_str());

        // Initialize hardware interface
        hardware_interface::JointStateHandle state_handle(joint.name, &joint.pos, &joint.vel, &joint.eff);
        m_jnt_state_interface.registerHandle(state_handle);

        hardware_interface::JointHandle vel_handle(m_jnt_state_interface.getHandle(joint.name), &joint.cmd);
        m_jnt_vel_interface.registerHandle(vel_handle);
    }

    registerInterface(&m_jnt_state_interface);
    registerInterface(&m_jnt_vel_interface);
}

void DiffDriveHWInterface::read(const ros::Duration &period)
{
    // Read the state of the hardware (e.g., from sensors)
}

void DiffDriveHWInterface::write(const ros::Duration &period)
{
    // Send the command to the hardware (e.g., to actuators)
    for (auto &joint : m_joints)
    {
        joint.pos += joint.vel * period.toSec();
        // if (joint.vel != joint.cmd)
        // {
        //     ROS_INFO("write, joint: %s, cmd: %lf", joint.name.c_str(), joint.cmd);
        // }
        joint.vel = joint.cmd;
    }
}
```

控制节点：diff_drive_control_node.cpp

```cpp
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include "diff_drive_control/diff_drive_hardware_interface.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "diff_drive_control_node");
    ros::NodeHandle nh;

    DiffDriveHWInterface diff_drive(nh);
    diff_drive.init();

    controller_manager::ControllerManager cm(&diff_drive, nh);

    ros::Rate rate(50.0);
    ros::AsyncSpinner spinner(1);
    spinner.start();

    while (ros::ok())
    {
        ros::Duration period = rate.expectedCycleTime();
        diff_drive.write(period);
        cm.update(ros::Time::now(), period);
        rate.sleep();
    }

    return 0;
}
```



#### 5.3.3.7 控制机器人移动

机器人模型与硬件接口都准备好了，接下来开始编写业务代码控制机器人。

我们仅给机器人发送速度指令，模拟机器人移动任务，如下：

```cpp
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

geometry_msgs::Twist moveRobot(const double& linear, const double& angular)
{
    geometry_msgs::Twist msg;
    msg.linear.x = linear; // 线速度
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = angular; // 角速度
    ROS_INFO("moveRobot, linear: %.3lf, angular: %.1lf", linear, angular*180/M_PI);

    return msg;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "diff_drive_business");
    ros::NodeHandle nh;
    ros::Publisher velPub = nh.advertise<geometry_msgs::Twist>("/diff_drive_controller/cmd_vel", 10);

    ros::Rate rate(10);

    while (ros::ok())
    {
        velPub.publish(moveRobot(0.5, 0));
        ros::Duration(3.0).sleep();
        velPub.publish(moveRobot(0, 1.57));
        ros::Duration(1.0).sleep();

        rate.sleep();
    }

    return 0;
}
```

编译执行该节点，在rviz中的可视化结果如下：

![Peek 2024-06-29 16-36](img/Peek 2024-06-29 16-36.gif)

[项目源码](https://gitee.com/vistary/ros_control_demos)



## 5.4 Gazebo 介绍与使用

Gazebo是一个功能丰富的开源机器人仿真平台，具备以下特点和功能：

- 动力学仿真：Gazebo支持多种高性能的物理引擎，如ODE、Bullet、SimBody和DART，能够进行精确的动力学计算和仿真。
- 三维可视化环境：它提供了一个逼真的三维环境，包括光线、纹理和影子，使得仿真场景更加接近现实。
- 传感器仿真：Gazebo支持模拟多种传感器，如激光雷达、相机等，并能模拟传感器噪声，这对于开发和测试机器人感知系统非常重要。
- 可扩展插件：用户可以通过开发自定义插件来扩展Gazebo的功能，满足特定的仿真需求。
- 支持多种机器人模型：Gazebo官方提供了多种机器人模型，如PR2、Pioneer2 DX、TurtleBot等，用户也可以使用自己创建的模型。
- 网络通信：Gazebo支持TCP/IP传输，可以实现远程仿真，后台仿真和前台显示通过网络通信。
- 云仿真：Gazebo仿真可以在云平台上运行，如Amazon、Softlayer等，方便进行大规模或分布式仿真。



Gazebo通常与机器人操作系统（ROS）结合使用。以下是一些基本的使用方法：

- 安装Gazebo：一般安装完整版的ROS会一起安装 Gazebo，如果没有安装 Gazebo，可以使用以下方法安装（以gazebo11为例）：

    ```
    1.添加源
    sudo sh -c 'echo "deb http://packages./gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
    
    2.设置秘钥
    wget https://packages./gazebo.key -O - | sudo apt-key add -
    
    3.更新源
    sudo apt update
    
    4.安装
    sudo apt install gazebo11 
    sudo apt install libgazebo11-dev
    ```

    

- 导入模型：在使用Gazebo时，需要导入机器人和环境的模型。这些模型通常是以 `urdf/sdf` 格式存在的，Gazebo支持这两种格式的文件，并且提供了一些常用的[模型库](https://github.com/osrf/gazebo_models)供用户下载和使用。

- URDF和SDF文件：URDF（Unified Robot Description Format）和SDF（Simulation Description Format）是用于描述机器人和仿真环境的两种文件格式。URDF主要用于描述机器人模型，而SDF则用于描述仿真世界。Gazebo可以处理这两种格式的文件，并且用户可以在这两种格式之间进行转换。





































# 其他



## 关于ROS的网络通讯方式TCP/UDP

### TCP与UDP

TCP/IP协议族为传输层指明了两个协议：TCP和UDP，它们都是作为应同程序和网络操作的中介物。

**TCP（Transmission Control Protocol）协议全称是传输控制协议，是一种面向连接的、可靠的、基于字节流的传输层通信协议，由IETF的RFC793定义。**TCP是面向连接的、可靠的流协议，提供超时重发，丢弃重复数据，检验数据，流量控制等功能，保证数据能从一端传到另一端。

TCP传输数据稳定可靠，适用于对网络通讯质量要求较高的场景，需要准确无误的传输给对方，比如，传输文件，发送邮件，浏览网页等等。在传输数据前，双方会先建立一条虚拟的通道，可以减少数据传输差错。

传输流程类似下图：

![01fbaa31de51e304fe54d418df4fa1](img/01fbaa31de51e304fe54d418df4fa1.png)

**UDP（User Datagram Protocol）协议全称是用户数据报协议，在网络中它与TCP协议一样用于处理数据包，是一种无连接的协议。**位于OSI模型中第四层——传输层，处于IP协议的上一层。UDP有不提供数据包分组、组装和不能对数据包进行排序的缺点。由于UDP在传输数据报前不用在客户和服务器之间建立一个连接，且没有超时重发等机制，故而传输速度很快。

UDP的优点是速度快，但是可能产生丢包，所以适用于对实时性要求较高但是对少量丢包并没有太大要求的场景。比：域名查询，语音通话，视频直播等。在数据传输时，每个数据段都是一个独立的信息，包括完整的源地址和目的地，因此，数据能否被对方接收、数据到达的实践和内容的完整性有序性都无法得到保证。

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

如不使用 `-w` 选项，报告的平均速率是从开始通信以来所有通信的平均速率，如使用 `-w` 则为最近 `WINDOW_SIZE` 次通信的平均速率。

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
rostopic list <namespace>    # 列出指定名称空间中的topic
rostopic list -b <bag_file>  # 列出bag文件中的topic
rostopic list -p  # 只列出发布者
rostopic list -s  # 只列出订阅者
rostopic list -v  # 详细模式
rostopic list --host  # 按主机名分组列表
```



###### rostopic list \<namespace\>

列出指定名称空间中的topic，关于ROS的名称空间，见 [ROS WiKi/Names/Graph Resource Names](http://wiki.ros.org/ROS/Concepts#Names.Names)

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



## ros::NodeHandle









































 
