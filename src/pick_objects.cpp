#include "pick_objects/pick_objects.h"

#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>

move_base_msgs::MoveBaseGoal pick_objects::MakeGoal(
    const geometry_msgs::Point& position,
    const geometry_msgs::Quaternion& orientation) {
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position = position;
  goal.target_pose.pose.orientation = orientation;
  return goal;
}

void pick_objects::SendGoal(MoveBaseClient& client,
                            const move_base_msgs::MoveBaseGoal& goal) {
  ROS_INFO("Sending goal");
  client.sendGoal(goal);
  client.waitForResult();
  if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the Robot moved to the goal!");
  else
    ROS_INFO("Uh oh, Robot failed...");
}