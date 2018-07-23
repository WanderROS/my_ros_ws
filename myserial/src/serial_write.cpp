#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>

int main(int argc,char **argv)
{
	ros::init(argc,argv,"myserial_write");
	ros::NodeHandle n;
	ros::Publisher myserial_pub=n.advertise<std_msgs::String>("write",1000);
	ros::Rate loop_rate(1000);
	int count=0;
	while(ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss<<"hello world"<<count<<std::endl;
		msg.data=ss.str();
		ROS_WARN("%s",msg.data.c_str());
		myserial_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}

return 0;

}