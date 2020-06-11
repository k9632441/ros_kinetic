#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"

void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr &msg)
{
	ROS_INFO("receive msg = %d", msg->stamp.sec);
	ROS_INFO("receive msg = %d", msg->stamp.nsec);
	ROS_INFO("receive msg = %d", msg->data);

}

int main(int argc, char *argv[])
{
	using namespace ros;
	init(argc, argv, "topic_subscriber");

	NodeHandle nh;

	Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);

	spin();

	return 0;
}