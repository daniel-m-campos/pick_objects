#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>

#include "pick_objects/pick_objects.h"

int main(int argc, char** argv) {
  using namespace pick_objects;
  ros::init(argc, argv, "pick_objects");
  MoveBaseClient client("move_base", true);
  while (!client.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the pick_objects action server to come up");
  }
  geometry_msgs::Point position;
  position.x = -3.0;
  position.y = -1.2;
  geometry_msgs::Quaternion orientation;
  orientation.w = 1.0;
  SendGoal(client, MakeGoal(position, orientation));

  ros::Duration(5.0).sleep();

  position.x = -2.5;
  position.y = 3.5;
  orientation.z = 0.7;
  orientation.w = 0.7;
  SendGoal(client, MakeGoal(position, orientation));
  return 0;
}
