#include "ros/ros.h"
#include "std_msgs/String.h"//ROS中文本类型
#include <sstream>
/*
    发布方实现
        1.包含头文件
        2.初始化ROS节点
        3.创建节点句柄
        4.创建发布者对象
        5.编写发布逻辑并发布数据
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化ROS节点
    ros::init(argc,argv,"pub");
    //3.创建节点句柄
    ros::NodeHandle nh;
    //4.创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("topic",10);
    //5.编写发布逻辑并发布数据
    //先创建被发布的消息
    std_msgs::String msg;
    //要求发布方以10HZ的频率发布文本消息，文本后添加编号
    //频率
    ros::Rate rate(10);
    //编号
    int count = 0;
    //编写循环，循环中发布数据
    
    while (ros::ok())
    {
        count++;
        //实现字符串拼接
        std::stringstream ss;
        ss<< "hello! --" << count;
        msg.data = ss.str();
        pub.publish(msg);
        ROS_INFO("发送消息：%s",msg.data.c_str());
        rate.sleep();
        // ros::spinOnce(); 官方建议添加，处理回调函数
    }
    
    return 0;
}
