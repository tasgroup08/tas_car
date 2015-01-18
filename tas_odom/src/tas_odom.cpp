/**
 * This node forwards the hector pose of the robot. It generates the estimated
 * hector slam position and the velocities  of the robot (based on the kinematic
 * equations for an Ackermann-steered vehicle) and publishes tf messages to
 * topic /tf and odom messages to topic /odom.
 */

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Pose2D.h>
//#include <razor_imu_9dof/RazorImu.h>

// define macros
#define WHEELBASE 0.36 // distance between the rear axel and front one in m
#define CONVERSION_FACTOR 1./3.6 // factor to convert velocities from km/h to m/s

nav_msgs::Odometry t_odom;
/**
 * Callback function to receive the estimated position from the hector node.
 */

void hectorPoseCallback(const nav_msgs::Odometry::ConstPtr& hector_msg) {

    t_odom=*hector_msg;
}


/**
 * Main function
 */

int main(int argc, char** argv) {
    ros::init(argc, argv, "hector_odometry"); // init and set name
    ROS_INFO("hector_odometry node started!");
    ros::NodeHandle nh;

    // set up subscriber and publisher
    ros::Subscriber hector_odom_subscriber = nh.subscribe("scanmatch_odom", 1, hectorPoseCallback); // buffer only 1 slam_out_pose message
    ros::Publisher wheel_odom_pub = nh.advertise<nav_msgs::Odometry>("vo", 50); // buffer last 50 odom frames
    //    ros::Publisher visual_odom_pub = nh.advertise<nav_msgs::Odometry>("visual_odom", 50); // buffer last 50 odom frames

    tf::TransformBroadcaster odom_broadcaster;

     //declare and initialize messages
     geometry_msgs::TransformStamped odom_trans;
     odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    // declare and initialize messages
    nav_msgs::Odometry wheel_odom;
    wheel_odom.header.frame_id = "odom";
    wheel_odom.child_frame_id = "base_link";


    // declare and initialize state space variables


    // initialize node parameters from launch file
    int rate; // frequency in Hz
    ros::NodeHandle private_nh("~");
    private_nh.getParam("rate", rate); // frequency

    ros::Rate r(rate); // set up ROS loop rate

    // initialize time variables
    ros::Time current_time;
    current_time = ros::Time::now();
//    last_time = ros::Time::now();

    while(nh.ok())
    {
        ros::spinOnce(); // check for incoming messages
        current_time = ros::Time::now();
        wheel_odom=t_odom;

         //publish the transform over tf
       odom_trans.header.stamp = current_time;
        odom_trans.transform.translation.x = t_odom.pose.pose.position.x;
         odom_trans.transform.translation.y = t_odom.pose.pose.position.y;
      odom_trans.transform.translation.z = 0.0;
       odom_trans.transform.rotation = t_odom.pose.pose.orientation;
        odom_broadcaster.sendTransform(odom_trans);	// send transform


        wheel_odom.twist.covariance=t_odom.pose.covariance;// *10 high covariance is always better than nothing same nonzero elements


        wheel_odom.twist.covariance[0] = 5000;
        wheel_odom.twist.covariance[7] = 5000;
        wheel_odom.twist.covariance[35] = 5000;

        wheel_odom.twist.covariance[1] = 5000;
        wheel_odom.twist.covariance[6] = 5000;

        wheel_odom.twist.covariance[5] = 5000;
        wheel_odom.twist.covariance[30] = 5000;
        wheel_odom.twist.covariance[14] = 0.01;
        wheel_odom.twist.covariance[11] = 5000;
         wheel_odom.twist.covariance[21] = 0.01;
        wheel_odom.twist.covariance[28] = 0.01;
        wheel_odom.twist.covariance[31] = 5000;


        wheel_odom.pose.covariance[14] = 0.01;

         wheel_odom.pose.covariance[21] = 0.01;
        wheel_odom.pose.covariance[28] = 0.01;





        wheel_odom_pub.publish(wheel_odom);	//publish message



        r.sleep();
    }
}


