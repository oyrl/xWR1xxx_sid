# xWR1xxx_sid
Based on TI mmWave ROS Driver, Still In Development


# How to build
Please refer to TI mmWave ROS Driver Setup Guide

# How to run
+ Modify the tf arguments in src/ti_mmwave_rospkg/launch/multiple.launch
+ Modify the src/ti_mmwave_rospkg/launch/multiple/$(device_number).launch file, if default ports are not suitable
+ Modify src/ti_mmwave_rospkg/launch/multiple.launch and add the src/ti_mmwave_rospkg/launch/multiple/$(device_number).launch file to extend more device

`roslaunch ti_mmwave_rospkg multiple.launch`

# How to switch to a different configuration
+ Modify the value of range_cfg and dimension_cfg in multiple.launch file
+ Add the cfg file

NOTE: The EVM must be power cycled or reset when switching from a 3-D configuration to a
2-D configuration (or from 2-D to 3-D).

# Messages
## Sensor_msgs::PointCloud2 /mmwaveDataHdl_(device_number)/RScan
Three spatial coordinates (x,y,z) and intensity

## Sensor_msgs::PointCloud2 /mmwaveDataHdl_(device_number)/XYZV
Three spatial coordinates (x,y,z) and relative radial velocity
