#include <ros/ros.h>
#include <std_msgs/Float64.h>

void myCallback(const std_msgs::Float64 &message_holder) {
    // wakes up evry time a new message is published on "topic1"
    // does not consume CPU time polling for new data like publisher
    ROS_INFO("recieved value is: %f", message_holder.data);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "minimal-subscriber");
    ros::NodeHandle n;
    ros::Subscriber my_subscriber_object=n.subscribe("topic1",1,myCallback);

    ros::spin(); // this is like while(1) statement
    // but it forces refreshing wakeups upon new data arrival
    // main hangs here, but it must stay alive to keep the callback function alive

    return 0; // should never get here, unless roscore dies
}
