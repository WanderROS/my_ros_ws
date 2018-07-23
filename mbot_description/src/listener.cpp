#include <ros/ros.h>
#include "std_msgs/String.h"
#include "mbot_description/msg.h"
void callback(const mbot_description::msg::ConstPtr &msg)
{
	ROS_INFO("id is %ld",msg->Num);
	ROS_INFO("Phone is {%s}",msg->Phome.c_str());
	ROS_INFO("Name is %s",msg->Name.c_str());
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"listener");
	ros::NodeHandle n;
	
	ros::Subscriber sub=n.subscribe("chat",1000,callback);
	
	ros::spin();
	return 0;
	
}