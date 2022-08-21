#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/*
    服务端实现：解析客户端提交的数据，运算并响应
    1. 头文件
    2. 初始化节点，创建句柄
    3. 创建服务对象
    4. 处理请求，产生响应
    5. spin();

*/ 
bool doNums(plumbing_server_client::AddInts::Request &request, plumbing_server_client::AddInts::Response &response){
    //1. 处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到num1 : %d num2 : %d ",num1,num2);
    //2. 组织响应
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和结果：%d",sum);
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"server");//名称唯一
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addInts", doNums);
    ros::spin();
    return 0;
}
