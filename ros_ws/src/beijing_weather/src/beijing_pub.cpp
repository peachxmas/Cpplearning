#include <ros/ros.h>
#include <std_msgs/String.h> 
#include <cstdlib>  // 随机

int main(int argc, char** argv) 
{
    //  初始化节点
    ros::init(argc, argv, "beijing_weather_pub");
    ros::NodeHandle nh;
    setlocale(LC_ALL, "");
    //创建发布者跨包：两个发布者和订阅者都用同一个 Topic 名
    ros::Publisher pub = nh.advertise<std_msgs::String>("/weather_info", 10);

    ros::Rate rate(1);

    ROS_INFO("北京气象站启动！开始发布数据...");

    while (ros::ok()) {

        std_msgs::String msg;
        std::stringstream ss; //字符串流

        // 生成随机温度（13~23℃）、湿度（40~60%）
        float temp = 18.0 + rand()%10 - 5;
        float humi = 40.0 + rand()%20;

        ss << "城市:北京, 温度:" << temp << "℃, 湿度:" << humi << "%";
        msg.data = ss.str();  // 把拼接好的字符串存入消息

        // 发布
        pub.publish(msg);

        // 打印日志
        ROS_INFO("北京发布：%s", msg.data.c_str());

        rate.sleep();  
    }
    return 0;
}