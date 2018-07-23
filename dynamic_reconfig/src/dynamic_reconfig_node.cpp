#include "ros/ros.h"
#include <dynamic_reconfigure/server.h>
#include <dynamic_reconfig/dynamic_Config.h>
 
void callback(dynamic_reconfig::dynamic_Config &config, uint32_t level)
{
	ROS_INFO("Reconfigure Request: %d %f %s %s %d",
		config.int_a,
		config.double_a,
		config.str_a.c_str(),
		config.bool_a?"True":"False",
		config.size);
}
 
int main(int argc, char **argv)
{
	ros::init(argc, argv, "node_e_dynamic_reconfigure");
	dynamic_reconfigure::Server<dynamic_reconfig::dynamic_Config> server;
	dynamic_reconfigure::Server<dynamic_reconfig::dynamic_Config>::CallbackType f;
	f = boost::bind(&callback, _1, _2);
	server.setCallback(f);
	ros::spin();
	return 0;
}
