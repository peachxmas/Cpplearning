#include <ros/ros.h>
#include <weather_msg/QueryMaxTemp.h>  
#include <vector>

// 模拟数据
std::map<std::string, std::vector<double>> city_temps = {
    {"Beijing", {18.5, 19.2, 20.1, 17.8, 21.3}},  
    {"Shanghai", {22.3, 23.1, 21.5, 24.0, 22.8}} 
};

bool queryMaxTempCallback(weather_msg::QueryMaxTemp::Request& req,
                          weather_msg::QueryMaxTemp::Response& res) {
    ROS_INFO("收到查询请求：城市=%s", req.city_name.c_str());

    // 检查是否存在
    if (city_temps.find(req.city_name) == city_temps.end()) {
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