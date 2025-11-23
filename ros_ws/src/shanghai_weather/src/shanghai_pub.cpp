#include <cstdlib>    
#include <ctime>      
#include <locale.h> 
#include <sstream>    
#include <string> 
#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "shanghai_weather_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("/weather_info", 10);

    double publish_freq;
    if (!nh.hasParam("/shanghai_publish_freq")) {
        nh.setParam("/shanghai_publish_freq", 1.0);
        ROS_INFO("初始化参数：/shanghai_publish_freq = 1.0 Hz");
    }

    ROS_INFO("上海气象站启动！支持动态修改采样频率（参数名：/shanghai_publish_freq）");

    while (ros::ok()) {
        nh.getParam("/shanghai_publish_freq", publish_freq);
        ros::Rate rate(publish_freq);

        float temp = 20.0 + (rand() % 8) - 3;
        float humi = 50.0 + (rand() % 25);

        nh.setParam("/shanghai_current_temp", temp);  // 上海实时温度参数

        std_msgs::String msg;
        std::stringstream ss;
        ss << "城市:上海, 温度:" << temp << "℃, 湿度:" << humi << "%（频率：" << publish_freq << "Hz）";
        msg.data = ss.str();
        pub.publish(msg);
        ROS_INFO("上海发布：%s", msg.data.c_str());

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}