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

        // double wheel_radius3;
        // ros::param::getCached("wheel_radius", wheel_radius3);
        // ROS_INFO("before unsubscribeCachedParam, wheel_radius: %lf", wheel_radius3);
        // ros::param::unsubscribeCachedParam();
        // ros::Duration(1).sleep();
        // ros::param::set("wheel_radius", 0.5);
        // double wheel_radius4;
        // ros::param::getCached("wheel_radius", wheel_radius4);
        // ROS_INFO("after  unsubscribeCachedParam, wheel_radius: %lf", wheel_radius4);
    }

    return 0;
}
