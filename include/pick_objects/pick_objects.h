#ifndef PICK_OBJECTS_H_
#define PICK_OBJECTS_H_

#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>

namespace pick_objects {

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>
    MoveBaseClient;

move_base_msgs::MoveBaseGoal MakeGoal();

void SendGoal(MoveBaseClient& client, const move_base_msgs::MoveBaseGoal& goal);

};  // namespace pick_objects

#endif  // PICK_OBJECTS_H_
