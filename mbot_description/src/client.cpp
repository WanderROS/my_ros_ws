#include <ros/ros.h>
#include <std_msgs/String.h>
#include "mbot_description/service.h"
#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	ros::init(argc,argv,"client");
	
	ros::NodeHandle n;
	ros::ServiceClient client=n.serviceClient<mbot_description::service>("service_to_serve");
	mbot_description::service srv;
	int num1,num2;
	string name;
	cin>>num1>>num2>>name;
	srv.request.num1=num1;
	srv.request.num2=num2;
	srv.request.name=name;
	if(client.call(srv))
	{
		ROS_INFO("Response from server:{%s}",srv.response.name_id.c_str());
		
	}
	else
	{
		ROS_ERROR("connect to server failed!");
		ros::shutdown();
	}
	return 0;
}