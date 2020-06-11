#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char *argv[])
{
	
	using namespace ros;
	init(argc, argv, "hello_world_node");
	NodeHandle nh;
	Publisher chatter_pub = nh.advertise<std_msgs::String>("say_hello_world", 1000);
	Rate loop_rate(10);
	int count = 0;

	while(ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world!" << count;
		msg.data = ss.str();
		ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);
		spinOnce();
		loop_rate.sleep();
		count++;
	}
	return 0;
}
