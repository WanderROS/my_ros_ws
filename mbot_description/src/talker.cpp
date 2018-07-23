#include <ros/ros.h>
#include "std_msgs/String.h"
#include "mbot_description/msg.h"



int main(int argc,char **argv)
{
	ros::init(argc,argv,"talker");
	ros::NodeHandle n;
	ros::Publisher chat_pub=n.advertise<mbot_description::msg>("chat",1000);
	ros::Rate loop(10);
	while(ros::ok())
	{
		mbot_description::msg msg1;
		msg1.Num=100;
		msg1.Name=("hello");
		msg1.Phome="1232131231";
		chat_pub.publish(msg1);
		ros::spinOnce();
		loop.sleep();
		
	}
	
	
}