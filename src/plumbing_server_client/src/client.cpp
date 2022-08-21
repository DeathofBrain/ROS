#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/*
    客户端：提交两个整数，处理响应结果
    1. 头文件 初始化节点，创建节点句柄
    2. 创建客户端对象
    3. 提交请求，处理响应

    实现参数的动态提交：
    1. 格式： rosrun 包名 节点 参数1 参数2...
    2. 节点执行时，需要获取命令中的参数，并整合到request中
*/ 
int main(int argc, char *argv[])
{
    /*
        优化
        获取命令中参数
    */
   
    setlocale(LC_ALL,"");
    if (argc != 3)
    {
        ROS_INFO("参数数量错误！");
        return 1;
    }
    
    ros::init(argc,argv,"client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("成功！");
        ROS_INFO("结果：%d",ai.response.sum);
    }
    else{
        ROS_INFO("失败！");
    }
    return 0;
}
