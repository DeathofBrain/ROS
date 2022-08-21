#include "ros/ros.h"
#include "plumbing_pub_sub/Message.h"
/*
    发布方：发布自定义消息
        1.包含头文件
        2.初始化节点
        3.创建句柄
        4.创建发布者对象
        5.编写发布逻辑，发布数据
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("消息发布中...");
    ros::init(argc,argv,"pub_msg");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Message>("chat",10);
    //1.创建被发布的数据
    plumbing_pub_sub::Message person;
    person.name = "张三";
    person.age = 24;
    person.height = 1.73;
    //2.设置发布频率
    ros::Rate rate(1);
    //3.循环发布
    while (ros::ok())
    {
        //数据发布
        pub.publish(person);
        ROS_INFO("发布的消息：%s，%d,%.2f",person.name.c_str(),person.age,person.height);
        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
