#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <cstdlib>

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "beijing_weather_pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("/weather_info", 10);


    double publish_freq;
    if (!nh.hasParam("/beijing_publish_freq")) {
        nh.setParam("/beijing_publish_freq", 1.0);  // 默认 1Hz
        ROS_INFO("初始化参数：/beijing_publish_freq = 1.0 Hz");
    }

    ROS_INFO("北京气象站启动。动态修改采样频率参数名：/beijing_publish_freq");

    while (ros::ok()) {

        nh.getParam("/beijing_publish_freq", publish_freq);// 读取参数
        // 设置频率
        ros::Rate rate(publish_freq);

        float temp = 18.0 + (rand() % 10) - 5;
        float humi = 40.0 + (rand() % 20);

        nh.setParam("/beijing_current_temp", temp); //更新当前温度
        
        std_msgs::String msg;
        std::stringstream ss;

        ss << "城市:北京, 温度:" << temp << "℃, 湿度:" << humi << "%（频率：" << publish_freq << "Hz）";
        msg.data = ss.str();
        pub.publish(msg);
        ROS_INFO("北京发布：%s", msg.data.c_str());

        rate.sleep();  
        ros::spinOnce();  
    }

    return 0;
}