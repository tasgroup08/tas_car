/**
 * This node sends fixed goals to move base via ROS Action API and receives feedback via callback functions.
 */

#include <iostream>
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <move_base_msgs/MoveBaseActionResult.h>
#include <actionlib/client/simple_action_client.h>

using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

/**
 * Callback function
 */
void doneCb(const actionlib::SimpleClientGoalState& state, const move_base_msgs::MoveBaseResultConstPtr& result) {
    ROS_INFO("Finished in state [%s]", state.toString().c_str());
}

/**
 * Callback function, called once when the goal becomes active
 */
void activeCb() {
    ROS_INFO("Goal just went active");
}

/**
 * Callback function, called every time feedback is received for the goal
 */
void feedbackCb(const move_base_msgs::MoveBaseFeedbackConstPtr& feedback) {
    ROS_INFO("[X]:%f [Y]:%f [W]: %f [Z]: %f", feedback->base_position.pose.position.x,feedback->base_position.pose.position.y,feedback->base_position.pose.orientation.w, feedback->base_position.pose.orientation.z);
}

/**
 * Main function
 */
int main(int argc, char** argv){
    ros::init(argc, argv, "simple_navigation_goals"); // init and set name
    std::vector<geometry_msgs::Pose> waypoints; // vector of goals, with position and orientation
int doslalom=1;

if(doslalom==0){


//    geometry_msgs::Pose waypoint11;
//    waypoint11.position.x = 11.535;
//    waypoint11.position.y = 21.31;
//    waypoint11.position.z = 0.000;
//    waypoint11.orientation.x = 0.000;
//    waypoint11.orientation.y = 0.000;
//    waypoint11.orientation.z = 0.99801;
//    waypoint11.orientation.w = -0.062977;
//    waypoints.push_back(waypoint11);

     geometry_msgs::Pose waypoint1;
     waypoint1.position.x = 10.7;
     waypoint1.position.y = 19.5;
     waypoint1.position.z = 0.000;
     waypoint1.orientation.x = 0.000;
     waypoint1.orientation.y = 0.000;
     waypoint1.orientation.z = -0.70124;
     waypoint1.orientation.w = 0.71292;
     waypoints.push_back(waypoint1);
// geometry_msgs::Pose waypoint15;
  //    waypoint15.position.x = 10.834;
   //    waypoint15.position.y = 9.8763;
   //    waypoint15.position.z = 0.000;
   //    waypoint15.orientation.x = 0.000;
   //    waypoint15.orientation.y = 0.000;
    //   waypoint15.orientation.z = -0.71346;
   //    waypoint15.orientation.w = 0.70069;
   //    waypoints.push_back(waypoint15);

//   geometry_msgs::Pose waypoint15;
//    waypoint15.position.x = 10.834;
//    waypoint15.position.y = 9.8763;
//    waypoint15.position.z = 0.000;
//    waypoint15.orientation.x = 0.000;
//    waypoint15.orientation.y = 0.000;
//    waypoint15.orientation.z = -0.71346;
//    waypoint15.orientation.w = 0.70069;
//    waypoints.push_back(waypoint15);

//    geometry_msgs::Pose waypoint16;
//    waypoint16.position.x = 11.406;;
//    waypoint16.position.y = 8.278;
//    waypoint16.position.z = 0.000;
//    waypoint16.orientation.x = 0.000;
//    waypoint16.orientation.y = 0.000;
//    waypoint16.orientation.z = -0.074978;
//    waypoint16.orientation.w = 0.99719;
//    waypoints.push_back(waypoint16);

    geometry_msgs::Pose waypoint2;
    waypoint2.position.x = 12.599;
    waypoint2.position.y = 8.1894;
    waypoint2.position.z = 0.000;
    waypoint2.orientation.x = 0.000;
    waypoint2.orientation.y = 0.000;
    waypoint2.orientation.z = -0.0037051;
    waypoint2.orientation.w =  0.99999;
    waypoints.push_back(waypoint2);

    geometry_msgs::Pose waypoint3;
    waypoint3.position.x = 24.429;
    waypoint3.position.y = 11.824;
    waypoint3.orientation.x = 0.000;
    waypoint3.orientation.y = 0.000;
    waypoint3.orientation.z =0.71139;
    waypoint3.orientation.w = 0.7028;
    waypoints.push_back(waypoint3);
    
    geometry_msgs::Pose waypoint4;
    waypoint4.position.x = 24.194;
    waypoint4.position.y =  21.536;
    waypoint4.orientation.x = 0.000;
    waypoint4.orientation.y = 0.000;
    waypoint4.orientation.z = 0.72375;
    waypoint4.orientation.w =  0.69006;
    waypoints.push_back(waypoint4);
}

else{

    geometry_msgs::Pose waypoint1;
    waypoint1.position.x = 24.417;
    waypoint1.position.y =  9.0297;
    waypoint1.position.z = 0.000;
    waypoint1.orientation.x = 0.000;
    waypoint1.orientation.y = 0.000;
    waypoint1.orientation.z = 0.99996;
    waypoint1.orientation.w = -0.0094345;
    waypoints.push_back(waypoint1);

   /** geometry_msgs::Pose waypoint15;
    waypoint15.position.x = 10.834;
    waypoint15.position.y = 9.8763;
    waypoint15.position.z = 0.000;
    waypoint15.orientation.x = 0.000;
    waypoint15.orientation.y = 0.000;
    waypoint15.orientation.z = -0.71346;
    waypoint15.orientation.w = 0.70069;
    waypoints.push_back(waypoint15);

    geometry_msgs::Pose waypoint16;
    waypoint16.position.x = 11.406;;
    waypoint16.position.y = 8.278;
    waypoint16.position.z = 0.000;
    waypoint16.orientation.x = 0.000;
    waypoint16.orientation.y = 0.000;
    waypoint16.orientation.z = -0.074978;
    waypoint16.orientation.w = 0.99719;
    waypoints.push_back(waypoint16);*/

    geometry_msgs::Pose waypoint2;
    waypoint2.position.x = 22.474;
    waypoint2.position.y = 9.2368;
    waypoint2.position.z = 0.000;
    waypoint2.orientation.x = 0.000;
    waypoint2.orientation.y = 0.000;
    waypoint2.orientation.z = 0.99916;
    waypoint2.orientation.w =  0.041073;
    waypoints.push_back(waypoint2);

    geometry_msgs::Pose waypoint3;
    waypoint3.position.x = 20.838;
    waypoint3.position.y =  8.3539;
    waypoint3.orientation.x = 0.000;
    waypoint3.orientation.y = 0.000;
    waypoint3.orientation.z = 0.99992;
    waypoint3.orientation.w =  0.03561;
    waypoints.push_back(waypoint3);

    geometry_msgs::Pose waypoint4;
    waypoint4.position.x = 19.141;
    waypoint4.position.y =  9.1977;
    waypoint4.orientation.x = 0.000;
    waypoint4.orientation.y = 0.000;
    waypoint4.orientation.z = 0.99937;
    waypoint4.orientation.w =  0.03561;
    waypoints.push_back(waypoint4);

    geometry_msgs::Pose waypoint5;
    waypoint5.position.x = 17.445;
    waypoint5.position.y =  8.3607;
    waypoint5.orientation.x = 0.000;
    waypoint5.orientation.y = 0.000;
    waypoint5.orientation.z = 0.99972;
    waypoint5.orientation.w =  0.02364;
    waypoints.push_back(waypoint5);
}

    MoveBaseClient ac("move_base", true); // action client to spin a thread by default

    while (!ac.waitForServer(ros::Duration(5.0))) { // wait for the action server to come up
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map"; // set target pose frame of coordinates

    for(int i = 0; i < waypoints.size(); ++i) { // loop over all goal points, point by point
        goal.target_pose.header.stamp = ros::Time::now(); // set current time
        goal.target_pose.pose = waypoints.at(i);
        ROS_INFO("Sending goal");
        ac.sendGoal(goal, &doneCb, &activeCb, &feedbackCb); // send goal and register callback handler
        ac.waitForResult(); // wait for goal result

        if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
            ROS_INFO("The base moved to %d goal", i);
        } else {
            ROS_INFO("The base failed to move to %d goal for some reason", i);
        }
    }
    return 0;
}
