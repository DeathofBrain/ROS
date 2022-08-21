#include "ros/ros.h"
#include "std_msgs/String.h"
/*
    订阅方：
    1.头文件
    2.初始化ROS节点
    3.实例化ROS句柄
    4.实例化订阅者对象
    5.处理订阅的消息（回调函数）
    6.设置循环调用回调函数
    7.spin()
*/
void doMsg(const std_msgs::String::ConstPtr &msg){
    //通过msg操作，订阅数据
    ROS_INFO("订阅到的数据：%s",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("topic",10,doMsg);
    ros::spin();
    return 0;
}
