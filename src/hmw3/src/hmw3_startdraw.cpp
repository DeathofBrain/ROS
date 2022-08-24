#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#define PI 3.14159265


void turn_left(geometry_msgs::Twist &twist){//左转
    twist.linear.x = 0;
    twist.angular.z = (PI/2);
}
void turn_right(geometry_msgs::Twist &twist){//右转
    twist.linear.x = 0;
    twist.angular.z = -(PI/2);
}
void forward(geometry_msgs::Twist &twist){//直行
    twist.linear.x = 1;
    twist.angular.z = 0;
}
void turn_back(geometry_msgs::Twist &twist){//回头
    twist.linear.x = 0;
    twist.angular.z = (PI);
}
void right_half_cir(geometry_msgs::Twist &twist){//右半圆
    twist.linear.x = 1.75;
    twist.angular.z = -(PI);
}
void stop_draw(geometry_msgs::Twist &twist){//停下
    twist.linear.x = 0;
    twist.angular.z = 0;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hmw3_startdraw");
    ros::NodeHandle nh;
    
    ros::Publisher 
        pub1 = nh.advertise<geometry_msgs::Twist>("/turtle_1/cmd_vel",1000) ,
        pub2 = nh.advertise<geometry_msgs::Twist>("/turtle_2/cmd_vel",1000) ,
        pub3 = nh.advertise<geometry_msgs::Twist>("/turtle_3/cmd_vel",1000) ,
        pub4 = nh.advertise<geometry_msgs::Twist>("/turtle_4/cmd_vel",1000) ,
        pub5 = nh.advertise<geometry_msgs::Twist>("/turtle_5/cmd_vel",1000) ,
        pub6 = nh.advertise<geometry_msgs::Twist>("/turtle_6/cmd_vel",1000) ,
        pub7 = nh.advertise<geometry_msgs::Twist>("/turtle_7/cmd_vel",1000)
    ;
    int count = 0;
    geometry_msgs::Twist t1,t2,t3,t4,t5,t6,t7;
    ros::Rate loopRate(0.5);
    while (ros::ok())
    {
        ++count;

        if(count == 2)
        {
            forward(t1);
            turn_left(t3);
            forward(t5);
            forward(t7);
            turn_left(t2);
            turn_left(t4);
            forward(t6);
        }

        if(count == 3)
        {
            turn_left(t1);
            forward(t3);
            turn_left(t5);
            turn_left(t7);
            forward(t2);
            forward(t4);
            turn_left(t6);
        }

        if(count == 4)
        {
            forward(t1);
        }

        if(count == 5)
        {
            turn_left(t1);
        }

        if(count == 6)
        {
            forward(t1);
        }

        if(count == 7)
        {
            turn_right(t1);
        }

        if(count == 8)
        {
            forward(t1);
        }

        if(count == 9)
        {
            turn_right(t1);
        }

        if(count == 10)
        {
            forward(t1);
        }

        if(count == 11)
        {
            stop_draw(t1);
        }

        // if(count == 11)
        // {
        //     forward(t1);
        // }
        pub1.publish(t1);
        ros::Duration(0.5).sleep();
        pub2.publish(t2);
        ros::Duration(0.5).sleep();
        pub3.publish(t3);
        ros::Duration(0.5).sleep();
        pub4.publish(t4);
        ros::Duration(0.5).sleep();
        pub5.publish(t5);
        ros::Duration(0.5).sleep();
        pub6.publish(t6);
        ros::Duration(0.5).sleep();
        pub7.publish(t7);
        ros::Duration(0.5).sleep();
        ros::spinOnce();
        loopRate.sleep();
    }
    
    return 0;
}