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

            getParamCached键,存储结果的变量)--提高变量获取效率
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
    
    return 0;
}
