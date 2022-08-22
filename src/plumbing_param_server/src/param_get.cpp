#include "ros/ros.h"
/*
参数查询
    实现
        ros::NodeHandle
            param(键,默认值) 
                存在，返回对应结果，否则返回默认值

            getParam(键,存储结果的变量)
                存在,返回 true,且将值赋值给参数2
                若果键不存在，那么返回值为 false，且不为参数2赋值

            getParamCached(键,存储结果的变量)--提高变量获取效率
                存在,返回 true,且将值赋值给参数2
                若果键不存在，那么返回值为 false，且不为参数2赋值

            getParamNames(std::vector<std::string>)
                获取所有的键,并存储在参数 vector 中 

            hasParam(键)
                是否包含某个键，存在返回 true，否则返回 false

            searchParam(参数1，参数2)
                搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
        ros::param
            同NodeHandle
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param");
    ros::NodeHandle nh;
    //--------
    //1. param(键,默认值)
    double radius = nh.param("radius", 0.5);
    ROS_INFO("通过param()获得的radius = %.2f", radius);

    //2. getParam
    double radius_2;
    bool result = nh.getParam("radius", radius_2);
    if (result)
    {
        ROS_INFO("通过getParam()获得的radius = %.2f", radius_2);
    }
    else{
        ROS_INFO("查询变量不存在");
    }

    //3. getParamCached
    //同2，仅性能提升

    //4. getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("遍历的元素：%s",name.c_str());
    }
    
    //5. hasParam
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxx");
    ROS_INFO("radius存在吗？%d",flag1);
    ROS_INFO("radiusxx存在吗？%d",flag2);

    //6.searchParam
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果：%s",key.c_str());

    //ros::param::～ ~对应上面的函数
    return 0;
}
