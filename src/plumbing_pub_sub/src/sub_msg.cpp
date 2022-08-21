#include "ros/ros.h"
#include "plumbing_pub_sub/Message.h"
/*
    订阅方
        1.头文件
        2.初始化，创建句柄
        3.创建订阅者对象
        4.创建回调函数处理消息
        5.spin();


*/
void doMsg(const plumbing_pub_sub::Message::ConstPtr &msg){
    ROS_INFO("姓名：%s,年龄：%d,身高：%.2f",msg->name.c_str(),msg->age,msg->height);
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("订阅方实现");
    ros::init(argc,argv,"sub_msg");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chat",10,doMsg);
    ros::spin();
    return 0;
}
