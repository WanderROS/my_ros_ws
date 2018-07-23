#include <ros/ros.h>
#include "mbot_description/service.h"
#include <std_msgs/String.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool client_call(mbot_description::service::Request &req,mbot_description::service::Response &res)
{
	stringstream stream;  
	res.sum=req.num1+req.num2;
	stream<<res.sum;
	res.name_id=req.name+stream.str();
	ROS_INFO("SER CALL");
	return true;
	
	
}


int main(int argc,char **argv)
{
	ros::init(argc,argv,"server");
	ros::NodeHandle n;
	ros::ServiceServer server=n.advertiseService("service_to_serve",client_call);
	ROS_INFO("Server begins to serve!");
	
	ros::spin();
	
	
	
	return 0;
}