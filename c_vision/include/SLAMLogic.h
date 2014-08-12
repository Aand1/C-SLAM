/*
 * c_vision,
 *
 *
 * Copyright (C) 2014 Davide Tateo
 * Versione 1.0
 *
 * This file is part of c_vision.
 *
 * c_vision is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * c_vision is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with c_vision.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SLAMLOGIC_H_
#define SLAMLOGIC_H_

#include <image_transport/image_transport.h>
#include <image_transport/camera_subscriber.h>
#include <message_filters/cache.h>
#include <image_geometry/pinhole_camera_model.h>
#include <c_tracking/TrackedObject.h>

#include "ParameterServer.h"

class SLAMLogic
{
public:
	SLAMLogic(ros::NodeHandle n, ParameterServer& parameters);
	void handleCamera(const sensor_msgs::ImageConstPtr& msg,
				const sensor_msgs::CameraInfoConstPtr& info_msg);
	void handleTrack(const c_tracking::TrackedObject& track);

private:
	//Ros management
	image_transport::ImageTransport it;
	image_transport::CameraSubscriber cameraSubscriber;

	message_filters::Cache<sensor_msgs::CameraInfo> infoCache;
	message_filters::Cache<sensor_msgs::Image> imageCache;

	ros::Subscriber trackSubscriber;

};

#endif /* SLAMLOGIC_H_ */