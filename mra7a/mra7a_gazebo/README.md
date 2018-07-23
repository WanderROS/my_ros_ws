# mra7a_gazebo package
**The mra7a_gazebo package is for launch the gazebo to simulation.**<br>
It includes the xacro and related setting for gazebo.<br>
The **config** folder contains some configuers for the gazebo controllers.<br>
the **launch** folder contains some lounch files for loading the gazebo world, controllers etc.<br>

**launch steps:**<br>
1. ***roslaunch mra7a_gazebo mra7a_bringup_gazebo.launch***  //launch gazebo world + spawn the robot model + launch gazebo controller.<br>
2. ***roslaunch mra7a_gazebo mra7a_bringup_rviz.launch***  //launch move_group.launch, moveit_rviz.launch and joint_state_publisher.<br>
