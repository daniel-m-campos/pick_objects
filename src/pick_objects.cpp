#include "pick_objects/pick_objects.h"

#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>

move_base_msgs::MoveBaseGoal pick_objects::MakeGoal() {
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "robot_footprint";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = 1.0;
  goal.target_pose.pose.orientation.w = 1.0;
  return goal;
}

void pick_objects::SendGoal(MoveBaseClient& client,
                            const move_base_msgs::MoveBaseGoal& goal) {
  ROS_INFO("Sending goal");
  client.sendGoal(goal);
  client.waitForResult();
  if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved 1 meter forward");
  else
    ROS_INFO("The base failed to move forward 1 meter for some reason");
}