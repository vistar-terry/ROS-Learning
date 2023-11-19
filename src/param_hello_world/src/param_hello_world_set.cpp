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
