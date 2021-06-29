#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>

#include "pick_objects/pick_objects.h"

int main(int argc, char** argv) {
  using namespace pick_objects;
  ros::init(argc, argv, "pick_objects");
  MoveBaseClient client("move_base", true);
  while (!client.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  auto goal = MakeGoal();
  SendGoal(client, goal);
  return 0;
}
