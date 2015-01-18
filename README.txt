##############################################################

Group08

TAS CAR Project

by 

Martin Sundermeyer and Christian Werner

##############################################################


Launch instructions

1.) 	all:			roslaunch hardware.launch
2.)  lap/slalom:		roslaunch odom.launch
	with ekf:		roslaunch odom_imu.launch
3.)  	lap:	 		roslaunch move_base_lap.launch
	slalom:		roslaunch move_base_slalom.launch
	with ekf:		roslaunch move_base_imu.launch

remark: ekf works but doesn't improve results yet


Edited and additionally used packages:

added hector_mapping2 in order to create sensical odometry covariances for the robot pose ekf
/src/HectorMappingRos.cpp line 327 ff.

added imu_tools-master. Modified to prevent the IMU from drifting
/imu_filter_madgwick/src/imu_filter.cpp line 444 ff.

added simple_navigation_goals_lap to create sequential waypoints around the lab

added simple_navigation_goals_slalom to create sequential waypoints to execute the slalom task

edited tas_autonomous_control to make the servo velocity command dependent of the cmd_steeringAngle/cmd_linearVelocity
/tas_autnomous_control_node.cpp line 30 ff.

used hector_geotiff provided by ROS to create an improved map of the lab. See /launch/config/map_server/LSR_3ssg2.pgm

used robot_pose_ekf provided by ROS to include the IMU information to estimate the pose of the robot


Changes in tas

edited /shell_scripts/tas_rviz.rviz to enhance the visualization in rviz

edited /launch/hardware.launch to add some transforms

added /launch/move_base_lap.launch serious changes in AMCL configuration (changed meassurement model etc.), initial pose for lap, simple_navigation_goals_lap called

added /launch/move_base_slalom.launch serious changes in AMCL configuration, (changed meassurement model etc.), initial pose for slalom, simple_navigation_goals_slalom called

added /launch/move_base_imu.launch uses kalman filtered odometry information

edited /launch/odom.launch hector_geotiff added, laser_max_dist increased

added /launch/odom_imu.launch robot_pose_ekf node, imu_filter_node added and setting up required transforms


Changed yaml files

edited /launch/config/map_server/LSR_3.yaml adapt map resolution, reconfigure map to differentiate between passable and impassable sections

edited /launch/config/move_base/base_local_planner_params.yaml
critical local planner tuning: changed max_vel_x, goal_distance_bias, path_distance_bias, occdist_scale,..

edited /launch/config/move_base/costmap_common_params.yaml
obstacle treatment in local and global planner: obstacle_range, footprint, inflation_radius, cost_scaling_factor,..

edited /launch/config/move_base/global_costmap_params.yaml
map resolution adjusted

edited /launch/config/move_base/local_costmap_params.yaml
update frequencies increased, limit extent of local costmap
 


