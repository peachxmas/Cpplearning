#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
ros::Publisher vel_pub;
int nCount=0;
void LidarCallback(const sensor_msgs::LaserScan msg)
{
    float fMidDist=msg.ranges[180];
    ROS_INFO("前方测距 ranges[180]: %.2f m",fMidDist);

    if(nCount>0)
    {
        nCount--;
        return;
    }
    geometry_msgs::Twist vel_cmd;
    if(fMidDist<1.0)
    {
        vel_cmd.linear.x=0.0;
        vel_cmd.angular.z=0.5;
        nCount=50;
        ROS_INFO("障碍物靠近，停止前进，原地转圈");
    }
    else
    {
        vel_cmd.linear.x=0.5;
        vel_cmd.angular.z=0.0;
        ROS_INFO("前方安全，继续前进");
    }
    vel_pub.publish(vel_cmd);
}

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"lidar_node");

    ros::NodeHandle nh;
    ros::Subscriber lidar_sub=nh.subscribe("/scan",10,&LidarCallback);
    vel_pub=nh.advertise<geometry_msgs::Twist>("cmd_vel",10);
    ros::spin();
    return 0;
}