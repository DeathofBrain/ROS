#include "ros/ros.h"
/*
    实现参数的新增或修改
    需求：首先设置机器人的共享参数，类型，半径（0.15m），再修改半径（0.20m）
    实现
        ros::NodeHandle
            setParam("键", 值)
        ros::param
            set("键", 值)
*/ 
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_param");
    ros::NodeHandle nh;
    
    //参数增加
    //方案1：nh.setParam()
    nh.setParam("type", "Yellow");
    nh.setParam("radius", 0.15);
    //方案2：ros::param::set()
    ros::param::set("type_param", "White");
    ros::param::set("radius_param", 0.15);
    //参数改(保证键的存在)
    //1. nh.setParam()
    nh.setParam("radius", 0.20);
    //2. ros::param::set()
    ros::param::set("radius_param", 0.25);
    return 0;
}
