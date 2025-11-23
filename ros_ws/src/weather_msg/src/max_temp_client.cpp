#include <cstdlib>  
#include <locale.h> 
#include <string>
#include <ros/ros.h>
#include <weather_msg/QueryMaxTemp.h>  


int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "max_temp_client");
    ros::NodeHandle nh;

    // 检查是否传入了城市名
    if (argc != 2) {
        ROS_ERROR("用法：rosrun weather_msg max_temp_client <城市名>");
        return 1;
    }

    ros::ServiceClient client = nh.serviceClient<weather_msg::QueryMaxTemp>("/query_max_temp");
    // 构造请求数据
    weather_msg::QueryMaxTemp srv;
    srv.request.city_name = argv[1];  
    // 发送请求
    ROS_INFO("正在查询 %s 的最高温...", srv.request.city_name.c_str());
    if (client.call(srv)) { // 成功
        if (srv.response.success) {
            ROS_INFO("查询成功！");
            ROS_INFO("城市：%s", srv.request.city_name.c_str());
            ROS_INFO("最高温：%.1f℃", srv.response.max_temperature);
            ROS_INFO("查询时间：%.2f 秒", srv.response.query_time.toSec());
        } else {
            ROS_ERROR("查询失败：%s", srv.response.error_msg.c_str());
        }
    } else {  // 失败
        ROS_ERROR("调用服务失败！请检查服务端是否已启动。");
        return 1;
    }

    return 0;
}