
# Presentation
Project for the french cup of robotic 2019. 
### **[Link to the website of the Competition](https://www.coupederobotique.fr/lacoupe/)**

This ROS stack includes an Arduino library and a collection of ROS packages for controlling an Arduino-based robot using standard ROS messages and services.

Features of the stack include:
- Controller Speed and Position using ROS PID 
- Control servo motor
- Direct support for Ping sonar
- GUI Interface for debugging the robot 

TODO Season 2020 : 
- Sensor TOF Implementation
- ROS implementation
- Better controller PID
- Arduino --> STM32
- News motors : Faulhaber 2232SR

Robot 2018 / 2019 : 

CAD            |  Real Word Robot
:-------------------------:|:-------------------------:
![](robot_CAD.jpeg)  |  ![](the_robot.jpeg)

(CAO by [Johny Lin](https://github.com/JohnySparkFall))

Debugging Interfaces : 

<img src="GUI_Robot.png" width="70%" align="middle">

# Hardware : 

- [Pololu VNH5019](http://www.pololu.com/catalog/product/2502) 
- [Faulhaber 2642 cxr motor](https://www.faulhaber.com/fr/produits/series/2642cxr/)
- [Rotary encoder kubler](https://www.kuebler.com/en/products/measurement/encoders/product-finder/product-details/2400)
- [Nucleo ESP32](https://www.st.com/en/evaluation-tools/nucleo-f401re.html)
- Arduino Uno (ATMEGA 328p)
- Raspberry Pi 3
- Sensor TOF (future implementation in this repository)

# Installation Guide (Work in progress) 

First you need Ubuntu 16.04 (Ubuntu Mate 16.04 on the Raspberry Pi 3) with Ros Kinetic : [ROS kinetic](http://wiki.ros.org/kinetic)

    $ git clone https://github.com/gabi22top/ROS_FrenchCupRobotic2019.git
    $ cd ~/cdr_robot_ws/
    $ catkin_make

To launch the ros node pid quickly: 

    
     $ cd cdr_robot_ws/    
     $ source devel/setup.bash
     $ roslaunch deplacement base.launch
    
    
For the debugging GUI you will need PYQT5

    $ sudo apt-get install python3-pyqt5

And just run the gui : 

    $ cd /Project Interface
    $ Python3 ./MainWindows.py

# More about the project :
### **[Video of the cup 2019](https://www.youtube.com/watch?v=CekWTSOTMr8)**
### **[Association](http://davincibot.org/) (Project team of this competition 12 Members)**



