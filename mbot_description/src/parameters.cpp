#include <ros/ros.h>
 
int main(int argc, char** argv)
{
	ros::init(argc, argv, "param_demo");
	ros::NodeHandle n;
	ros::NodeHandle pn("~");
 
	std::string s;
	int num;
	
	n.param<std::string>("string_param", s, "haha");
	pn.param<int>("int_param", num, 666);
	
//设置参数的值
	n.setParam("string_param", "hehe");
	pn.setParam("int_param", 222);

	//设置循环的频率为1Hz
	ros::Rate loop_rate(0.1);	
 
	while(ros::ok())
	{	
		
		//获取参数的值
		if(!n.getParam("string_param", s))
		{
			ROS_ERROR("NOT IN THE Para ser");
		}
		//pn.getParam("int_param", num);
		pn.deleteParam("int_param");
		//输出参数
		ROS_INFO("string_param: %s", s.c_str());
		//ROS_INFO("int_param: %d", num);

		ros::spinOnce();
		loop_rate.sleep();
	}
	
	return 0;
}
