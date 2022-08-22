#include "ros/ros.h"
/*
    参数删除
    ros::NodeHandle
        deleteParam("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false

    ros::param
        del("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false

*/ 
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_del");
    ros::NodeHandle nh;
    //1.NodeHandle
    bool result = nh.deleteParam("radius");
    if (result)
    {
        ROS_INFO("删除成功");
    }else{
        ROS_INFO("删除失败");
    }
    //2. ros::param::del()
    bool result2 = ros::param::del("radius_param");
       if (result2)
    {
        ROS_INFO("删除成功");
    }else{
        ROS_INFO("删除失败");
    }
    
    return 0;
}
