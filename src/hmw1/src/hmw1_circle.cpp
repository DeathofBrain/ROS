#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
/*
    乌龟做圆周
        话题： /turtle1/cmd_vel
        消息: geometry_msgs/Twist
    1.头文件，节点，句柄
    2.创建发布对象
    3.发布逻辑事件
    4.spinOnce()  //可选


*/ 
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"circle");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    ros::Rate rate(10);
    //组织消息
    geometry_msgs::Twist twist;
    twist.linear.x = 1.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 1.0;
    //发布
    while (ros::ok())
    {
        pub.publish(twist);
        //休眠
        rate.sleep();//10hz
        //回头
        ros::spinOnce();
    }
    
    return 0;
}
