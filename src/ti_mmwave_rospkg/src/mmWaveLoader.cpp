/*
 * mmWaveLoader.cpp
 *
 *
 * This file implements a ROS node which will load the mmWaveDataHdl and mmWaveCommSrv nodelets at runtime.
 * Use the following command to start this node:
 *
 * rosrun ti_mmwave_rospkg ti_mmwave_rospkg _data_port:=/dev/ttyACM1 _data_rate:=921600 _command_port:=/dev/ttyACM0 _command_rate:=115200
 *              
 * And replace the ports with the proper name on your system.
 *
 *                       
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
#include "ros/ros.h"
#include "nodelet/loader.h"

int main(int argc, char **argv)
{

  ros::init(argc, argv, "mmWave_Manager");
  
  nodelet::Loader manager(true);
  
  nodelet::M_string remap(ros::names::getRemappings());
  
  nodelet::V_string nargv;
  
//  manager.load("mmWaveCommSrv", "ti_mmwave_rospkg/mmWaveCommSrv", remap, nargv);
	std::string myNodeName = ros::this_node::getName();
	ROS_INFO("Node name is %s", myNodeName.c_str());
	ROS_INFO("Last char is %c", myNodeName[myNodeName.length()-1]);
	std::string path = "/mmWaveCommSrv_" + myNodeName.substr(myNodeName.length()-1);
	ROS_INFO("manager.load mmWaveCommSrv is %s", path.c_str());
	manager.load(path.c_str(), "ti_mmwave_rospkg/mmWaveCommSrv", remap, nargv);
  
//  manager.load("mmWaveDataHdl", "ti_mmwave_rospkg/mmWaveDataHdl", remap, nargv);
	path = "/mmWaveDataHdl_" + myNodeName.substr(myNodeName.length()-1);
	ROS_INFO("manager.load mmWaveDataHdl is %s", path.c_str());
	manager.load(path.c_str(), "ti_mmwave_rospkg/mmWaveDataHdl", remap, nargv);
  
  ros::spin();
  
  return 0;
  }
