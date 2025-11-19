#include <ros/ros.h>
#include <geometry_msgs/Twist.h>  // 小海龟速度消息类型

int main(int argc, char** argv) {
    // 1. 初始化 ROS 节点
    ros::init(argc, argv, "turtle_circle_node");  // 节点名：turtle_circle_node
    // 2. 创建节点句柄
    ros::NodeHandle nh;

    // 3. 创建发布者：发布 /turtle1/cmd_vel 话题
    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);//10 是队列长度

    // 4. 设置发布频率：10Hz（
    ros::Rate rate(10);
    setlocale(LC_ALL, ""); // 解决中文输出问题
    ROS_INFO("Turtle circle node started! 开始");

    // 5. 循环发布速度指令
    while (ros::ok()) {
        geometry_msgs::Twist vel_msg;  // 创建速度消息对象
        // 画圆逻辑：线速度 x 方向=1.0（前进），角速度 z 方向=0.5（逆时针转）
        vel_msg.linear.x = 1.0;        // 线速度（x 方向前进，y/z 为 0）
        vel_msg.angular.z = 0.5;       // 角速度（z 方向旋转，x/y 为 0）
        vel_pub.publish(vel_msg);      // 发布速度指令

        rate.sleep();  // 按 10Hz 频率等待，控制循环速度
    }

    return 0; 
}