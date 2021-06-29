#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>

#include "pick_objects/pick_objects.h"

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>
    MoveBaseClient;

void SendGoal(MoveBaseClient& client, const move_base_msgs::MoveBaseGoal& goal);
move_base_msgs::MoveBaseGoal MakeGoal() {
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "robot_footprint";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = 1.0;
  goal.target_pose.pose.orientation.w = 1.0;
  return goal;
}

void SendGoal(MoveBaseClient& client,
              const move_base_msgs::MoveBaseGoal& goal) {
  ROS_INFO("Sending goal");
  client.sendGoal(goal);
  client.waitForResult();
  if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved 1 meter forward");
  else
    ROS_INFO("The base failed to move forward 1 meter for some reason");
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "pick_objects");
  MoveBaseClient client("move_base", true);
  while (!client.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  auto goal = MakeGoal();
  SendGoal(client, goal);
  return 0;
}
