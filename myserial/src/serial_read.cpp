#include <ros/ros.h>
#include "std_msgs/String.h"

void serialCallback(const std_msgs::String::ConstPtr & msg)
{
	ROS_INFO("[%s]",msg->data.c_str());
}


int main(int argc,char ** argv)
{
	ros::init(argc,argv,"my_serial_read");
	ros::NodeHandle n;
	ros::Subscriber serial_sub=n.subscribe("read",1000,serialCallback);
	ros::spin();
	return 0;
}