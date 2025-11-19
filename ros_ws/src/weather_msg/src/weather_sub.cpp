#include <ros/ros.h>
#include <std_msgs/String.h>  // 和发布者用同一个内置消息

// 回调函数
void weatherCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("【监控中心】收到：%s", msg->data.c_str());
}

int main(int argc, char** argv) {
    // 初始化节点
    ros::init(argc, argv, "weather_monitor_sub");
    ros::NodeHandle nh;
    setlocale(LC_ALL, ""); // 解决中文输出问题
    // 创建订阅者
    ros::Subscriber sub = nh.subscribe<std_msgs::String>(
        "/weather_info", 10, weatherCallback
    );

    ROS_INFO("气象监控中心启动！等待接收数据...");
    ros::spin();

    return 0;
}
