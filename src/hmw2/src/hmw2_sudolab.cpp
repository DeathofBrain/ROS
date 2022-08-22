#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#define PI 3.14159265
/*
关键：找寻sudolab绘制路径


*/ 
void turn_left(geometry_msgs::Twist &twist){//左转
    twist.linear.x = 0;
    twist.angular.z = (PI/2);
}
void turn_right(geometry_msgs::Twist &twist){//右转
    twist.linear.x = 0;
    twist.angular.z = -(PI/2);
}
void forward(geometry_msgs::Twist &twist){//直行
    twist.linear.x = 0.5;
    twist.angular.z = 0;
}
void turn_back_left(geometry_msgs::Twist &twist){//左回头
    twist.linear.x = 0;
    twist.angular.z = (PI);
}
void turn_back_right(geometry_msgs::Twist &twist){//右回头
    twist.linear.x = 0;
    twist.angular.z = -(PI);
}
void right_half_cir(geometry_msgs::Twist &twist){//右半圆
    twist.linear.x = 1.75;
    twist.angular.z = -(PI);
}
void left_half_cir(geometry_msgs::Twist &twist){//左半圆
    twist.linear.x = 2;
    twist.angular.z = (PI);
}
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"draw_sudolab");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    ros::Rate loopRate(1);
    geometry_msgs::Twist twist;
    int count = 0;
    while (ros::ok())
    {
        count++;
        if (count == 2 || count == 4 || count == 6 || count == 8 || count == 10 || count == 12 || count == 15 || count == 17 || count == 22 || count == 25 || count == 28 || count == 30 || count == 33 || count == 36 || count == 39 || count == 42 || count == 44 || count == 47 || count == 49 || count == 51 || count == 53 || count == 55 || count == 58 || count == 60 || count == 62 || count == 64 || count == 66 || count == 68 || count == 70)
        {
            forward(twist);
        }
        if (count == 3 || count == 5 || count == 14 || count == 16 || count == 24 || count == 27 || count == 29 || count == 32 || count == 35 || count == 41 || count == 43 || count == 57 || count == 59 || count == 61 || count == 65 || count == 67 || count == 69)
        {
            turn_left(twist);
        }
        if (count == 7 || count == 9 || count == 11 || count == 19 || count == 46 || count == 48 || count == 50 || count == 54)
        {
            turn_right(twist);
        }
        if (count == 20)
        {
            right_half_cir(twist);
        }
        
        if (count == 21 || count == 38 || count == 52 || count == 63)
        {
            turn_back_right(twist);
        }
        if (count == 73)
        {
            ros::shutdown();
        }
        
        pub.publish(twist);
        ros::spinOnce();
        loopRate.sleep();
    }
    
    return 0;
}
