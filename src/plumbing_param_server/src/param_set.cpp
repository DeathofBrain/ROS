#include "ros/ros.h"
/*
    实现参数的新增或修改
    需求：首先设置机器人的共享参数，类型，半径（0.15m），再修改半径（0.20m）
    实现L
        ros::NodeHandle
            setParam()
        ros::param
            set()
*/ 
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_param");
    ros::NodeHandle nh;
    
    return 0;
}
