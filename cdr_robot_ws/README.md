# ROBOT ROS ARCHITECTURE

---

You could see the CDR Robot   
![](https://github.com/leonard-de-vinci/DaVinciBot-CDR_ATOM_FACTORY_2019/blob/FlorianQui/Divers/Rapports/ROS_CDR_Node_Graph.png)

See the [picture](https://github.com/leonard-de-vinci/DaVinciBot-CDR_ATOM_FACTORY_2019/blob/FlorianQui/Divers/Rapports/ROS_CDR_Node_Graph.png)

---

## Example with a dialog

- ROBOT_MASTER : Hello, I'm the master. I know the robot strategy.
- ROBOT_PATH_PLANNER : Hello, I'm the planner. I know where the robot has to go and which actions are needed.
- ROBOT_MOVE_CONTROLLER : Hello, I'm the move controller. I know how to go a point.
- ROBOT_PID_CONTROLLER : Hello, I'm the PID controller. I know how to drive the robot.

<br>

- ROBOT_MASTER : ROBOT_PATH_PLANNER I give you the strategy.
- ROBOT_PATH_PLANNER : Ok, let's go to the first pose and run the first action. ROBOT_MOVE_CONTROLLER could you go to this pose please.
- ROBOT_MOVE_CONTROLLER : Of course, I calculate the shortest path to go to this pose. Then, I publish my result to you ROBOT_PID_CONTROLLER.
- ROBOT_PID_CONTROLLER : Good, I'm listening to your result, and according to your result, I will drive the motor. I will publish the robot odometry as feedback.
- ROBOT_PID_CONTROLLER : That's fine, I reached the setpoint.
- ROBOT_MOVE_CONTROLLER : Nice ! I'll inform my boss.
- ROBOT_MOVE_CONTROLLER : ROBOT_PATH_PLANNER we reached the target pose.
- ROBOT_PATH_PLANNER : Ok, let's catch the cube. ..........
