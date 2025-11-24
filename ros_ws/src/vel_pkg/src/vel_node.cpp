#include <ros/ros.h>
#include <geometry_msgs/Twist.h>


int main(int argc,char *argv[])
{
    ros::init(argc,argv,"vel_node");
    ros::NodeHandle nh;
    ros::Publisher vel_pub=nh.advertise<geometry_msgs::Twist>("cmd_vel",10);

    geometry_msgs::Twist vel_msg;//创建速度消息包vel_msg
    vel_msg.linear.x=0.0;//设置线速度为0.5m/s
    vel_msg.linear.y=0.0;
    vel_msg.linear.z=0.0;
    vel_msg.angular.x=0.0;
    vel_msg.angular.y=0.0;
    vel_msg.angular.z=0.5;

    ros::Rate rate(1);//设置发布频率1Hz
    while(ros::ok())
    {
        vel_pub.publish(vel_msg);//发布速度消息
        rate.sleep();
    }
    return 0;
}