#include "ros/ros.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hmw3_sudolab");
    ros::NodeHandle nh;
    //去除初始乌龟
    ros::ServiceClient kill_init_tur = nh.serviceClient<turtlesim::Kill>("/kill");
    turtlesim::Kill kill;
    kill.request.name = "turtle1";
    bool check1 = kill_init_tur.call(kill);
    if (check1)
    {
        ROS_INFO("删除了初始海龟");
    }
    else{
        ROS_INFO("初始海龟已经不存在");
    }
    //生成新海龟
    ros::ServiceClient spawn_tur = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn spawn;
    for (size_t i = 1; i <= 7; i++)
    {
        spawn.request.name = ("turtle_" + std::to_string(i));
        spawn.request.theta = 0.0;
        spawn.request.x = 1 + (i);
        if (i % 2 == 1)
        {
            spawn.request.y = 7;
        }
        else
        {
            spawn.request.y = 3;
        }
        spawn_tur.call(spawn);
    }
    ROS_INFO("有7个小海龟打赢了复活赛");
    return 0;
}
