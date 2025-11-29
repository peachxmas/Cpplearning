#include <ros/ros.h>
#include <std_msgs/String.h>

std_msgs::String navi_msg;

void NavResultCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_WARN("航点 %s 完成导航", navi_msg.data.c_str());

    int waypoint = std::stoi(navi_msg.data);
    navi_msg.data = (waypoint == 5) ? "1" : std::to_string(waypoint + 1);

    static ros::Publisher nav_pub = ros::NodeHandle().advertise<std_msgs::String>("/waterplus/navi_waypoint", 10);
    nav_pub.publish(navi_msg);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "wp_node");

    navi_msg.data = "1";

    ros::NodeHandle n;

    ros::Subscriber res_sub = n.subscribe("/waterplus/navi_result", 10, NavResultCallback);
    ros::Publisher nav_pub = n.advertise<std_msgs::String>("/waterplus/navi_waypoint", 10);

    ros::Duration(1.0).sleep();
    nav_pub.publish(navi_msg);

    ros::spin();

    return 0;
}