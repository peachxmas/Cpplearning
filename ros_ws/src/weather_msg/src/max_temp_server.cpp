#include <ros/ros.h>
#include <weather_msg/QueryMaxTemp.h>  
#include <vector>

std::map<std::string, std::vector<double>> city_temps;

// 从参数服务器读取实时温度
void updateTempCache(ros::NodeHandle& nh) {
    double beijing_temp, shanghai_temp;

    // 北京
    if (nh.getParam("/beijing_current_temp", beijing_temp)) {
        city_temps["Beijing"].push_back(beijing_temp);
        if (city_temps["Beijing"].size() > 10) {
            city_temps["Beijing"].erase(city_temps["Beijing"].begin());
        }
    }

    // 上海
    if (nh.getParam("/shanghai_current_temp", shanghai_temp)) {
        city_temps["Shanghai"].push_back(shanghai_temp);
        if (city_temps["Shanghai"].size() > 10) {
            city_temps["Shanghai"].erase(city_temps["Shanghai"].begin());
        }
    }
}

bool queryMaxTempCallback(weather_msg::QueryMaxTemp::Request& req,
                          weather_msg::QueryMaxTemp::Response& res) {
    ROS_INFO("收到查询请求：城市=%s", req.city_name.c_str());

    ros::NodeHandle nh;
    updateTempCache(nh);

    // 检查是否存在
    if (city_temps.find(req.city_name) == city_temps.end()|| city_temps[req.city_name].empty()) {
        res.success = false;
        res.error_msg = "城市不存在！支持的城市：Beijing、Shanghai";
        res.max_temperature = 0.0;
        return true;  
    }

    // 计算最高温
    std::vector<double> temps = city_temps[req.city_name];
    double max_temp = *std::max_element(temps.begin(), temps.end());
    res.success = true;
    res.error_msg = "查询成功";
    res.max_temperature = max_temp;
    res.query_time = ros::Time::now(); 

    ROS_INFO("查询结果：%s 最高温=%.1f℃", req.city_name.c_str(), max_temp);
    return true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "max_temp_server");
    ros::NodeHandle nh;
    // 创建服务端 
    ros::ServiceServer service = nh.advertiseService("/query_max_temp", queryMaxTempCallback);
    setlocale(LC_ALL, "");
    ROS_INFO("最高温查询服务已启动！等待客户端请求...");
    ros::spin();  

    return 0;
}