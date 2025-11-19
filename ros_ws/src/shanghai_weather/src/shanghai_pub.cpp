#include <ros/ros.h>
#include <std_msgs/String.h>
#include <cstdlib>

int main(int argc, char** argv) {
    ros::init(argc, argv, "shanghai_weather_pub");
    ros::NodeHandle nh;
    setlocale(LC_ALL, "");
    ros::Publisher pub = nh.advertise<std_msgs::String>("/weather_info", 10);
    ros::Rate rate(1);

    ROS_INFO("上海气象站启动！开始发布数据...");

    while (ros::ok()) {
        std_msgs::String msg;
        std::stringstream ss;

        // 上海数据：温度17~25℃，湿度50~75%
        float temp = 20.0 + rand()%8 - 3;
        float humi = 50.0 + rand()%25;

        ss << "城市:上海, 温度:" << temp << "℃, 湿度:" << humi << "%";
        msg.data = ss.str();

        pub.publish(msg);
        ROS_INFO("上海发布：%s", msg.data.c_str());

        rate.sleep();
    }
    return 0;
}