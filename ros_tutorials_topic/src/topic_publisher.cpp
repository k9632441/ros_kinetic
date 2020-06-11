#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"

int main(int argc, char* argv[])
{
	using namespace ros;
	init(argc, argv, "topic_publisher");
	NodeHandle nh;

	Publisher ros_tutorial_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg", 100);

	Rate loop_rate(10);

	ros_tutorials_topic::MsgTutorial msg;
	int count = 0;

	while(ok())
	{
		msg.stamp = Time::now();
		msg.data = count;

		ROS_INFO("send msg = %d", msg.stamp.sec);
		ROS_INFO("send msg = %d", msg.stamp.nsec);
		ROS_INFO("send msg = %d", msg.data);

		ros_tutorial_pub.publish(msg);

		loop_rate.sleep();

		count++;

	}
	return 0;
}