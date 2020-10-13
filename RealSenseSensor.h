#pragma once

#include "GlobalAppState.h"
#include "GlobalAppState.h"
#include "RGBDSensor.h"
#include "stdafx.h"

#ifdef REAL_SENSE

#include "RGBDSensor.h"

#include<iostream>
#include <librealsense2/rs.hpp>
#include<librealsense2\h\rs_sensor.h>
#include <string>

using namespace std;
using namespace rs2;

class RealSenseSensor : public RGBDSensor
{
public:
	//! Constructor; allocates CPU memory and creates handles
	RealSenseSensor();

	//! Destructor; releases allocated ressources
	~RealSenseSensor();

	//! Initializes the sensor
	void createFirstConnected();

	//! Processes the depth & color data
	bool processDepth();

	//! processing happends in processdepth()
	bool processColor() {
		return true;
	}

	string getSensorName() const {
		return "RealSense";
	}

	

private:
	rs2::pipeline pipe;
	rs2::colorizer map;

	unsigned int color_width;
	unsigned int color_height;
	unsigned int depth_width;
	unsigned int depth_height;
	unsigned int frame_rate;
	float m_depth_scale;

	// Define two align objects. One will be used to align
	// to depth viewport and the other to color.
	// Creating align object is an expensive operation
	// that should not be performed in the main loop
	//rs2::align align_to_depth(RS2_STREAM_DEPTH);
	//rs2::align align_to_color(RS2_STREAM_COLOR);	
};
#endif