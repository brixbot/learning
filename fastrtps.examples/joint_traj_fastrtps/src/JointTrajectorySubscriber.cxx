// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file JointTrajectorySubscriber.cpp
 * This file contains the implementation of the subscriber functions.
 *
 * This file was generated by the tool fastcdrgen.
 */

#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/attributes/SubscriberAttributes.h>

#include <fastrtps/Domain.h>

#include "JointTrajectorySubscriber.h"


JointTrajectorySubscriber::JointTrajectorySubscriber() : 
    participant_(nullptr), subscriber_(nullptr) 
{
}

JointTrajectorySubscriber::~JointTrajectorySubscriber() 
{	
    Domain::removeParticipant(participant_);
}

bool JointTrajectorySubscriber::init()
{
	// Create RTPSParticipant
	ParticipantAttributes participantParam;
    participantParam.rtps.builtin.domainId = 0; //MUST BE THE SAME AS IN THE PUBLISHER
    participantParam.rtps.builtin.leaseDuration = c_TimeInfinite;
    participantParam.rtps.setName("Participant_subscriber"); //You can put the name you want
	participant_ = Domain::createParticipant(participantParam);
	if(participant_ == nullptr)
        return false;
	
	//Register the type
	Domain::registerType(participant_, (TopicDataType*) &myType_);		
			
	// Create Subscriber	
	SubscriberAttributes subscriberParam;
    subscriberParam.topic.topicKind = NO_KEY;
    subscriberParam.topic.topicDataType = myType_.getName(); //Must be registered before the creation of the subscriber
    subscriberParam.topic.topicName = "JointTrajectoryPubSubTopic";
	subscriber_ = Domain::createSubscriber(participant_, subscriberParam,(SubscriberListener*)&listener_);
	if(subscriber_ == nullptr)
		return false;

	return true;
}

void JointTrajectorySubscriber::SubListener::onSubscriptionMatched(Subscriber* sub,MatchingInfo& info)
{
	if (info.status == MATCHED_MATCHING)
	{
        matchedCnt_++;
		std::cout << "Subscriber matched" << std::endl;
	}
	else
	{
        matchedCnt_--;
		std::cout << "Subscriber unmatched" << std::endl;
	}
}

void JointTrajectorySubscriber::SubListener::onNewDataMessage(Subscriber* sub)
{
    // Take data
    MyMsg::JointTrajectory traj;
		
	if (sub->takeNextData(&traj, &info_))
	{
		if(info_.sampleKind == ALIVE)
		{
			// Print your structure data here.
			++msgCnt_;
			std::cout << "Sample received, count=" << msgCnt_ << std::endl;
            std::cout << "JointTrajectory Details:" << std::endl;
            printTraj(traj);
		}
	}
}

void JointTrajectorySubscriber::run()
{
	std::cout << "Waiting for Data, press Enter to stop the Subscriber. "<<std::endl;
	std::cin.ignore();
	std::cout << "Shutting down the Subscriber." << std::endl;
}

void JointTrajectorySubscriber::printTraj(MyMsg::JointTrajectory& traj)
{
    // print header
    std::cout << "  Frame ID: " << traj.header().frame_id() << std::endl;
    std::cout << "  Sequence: " << traj.header().seq() << std::endl;
    std::cout << "  Stamp: " << traj.header().stamp().sec() << "." 
        << traj.header().stamp().nsec() << std::endl;
    
    // print joint names
    const std::vector<std::string>& joints = traj.joint_names();
    std::cout << "  Joints: [";
    for (size_t i = 0; i < joints.size(); i++)
    {
        if (i != joints.size() - 1)
            std::cout << joints[i] << ", ";
        else
            std::cout << joints[i];
    }
    std::cout << "]" << std::endl;

    // print points
    const std::vector<MyMsg::JointTrajectoryPoint>& points = traj.points();
    for (size_t i = 0; i < points.size(); i++)
    {
        MyMsg::JointTrajectoryPoint point = points[i];

        std::cout << "  Point " << i << ":" << std::endl;

        // time from start
        std::cout << "  Time from start: " << point.time_from_start().sec() << "."
            << point.time_from_start().nsec() << std::endl;

        // positions
        const std::vector<double>& positions = point.positions();
        std::cout << "  Positions: ";
        for (size_t j = 0; j < positions.size(); j++)
        {
            if (j != positions.size() - 1)
                std::cout << std::setprecision(6) << positions[j] << ", ";
            else
                std::cout << std::setprecision(6) << positions[j];
        }
        std::cout << std::endl;

        // velocities
        const std::vector<double>& velocities = point.velocities();
        std::cout << "  Velocities: ";
        for (size_t j = 0; j < velocities.size(); j++)
        {
            if (j != velocities.size() - 1)
                std::cout << std::setprecision(6) << velocities[j] << ", ";
            else
                std::cout << std::setprecision(6) << velocities[j];
        }
        std::cout << std::endl;

        // accelerations
        const std::vector<double>& accelerations = point.accelerations();
        std::cout << "  Accelerations: ";
        for (size_t j = 0; j < accelerations.size(); j++)
        {
            if (j != accelerations.size() - 1)
                std::cout << std::setprecision(6) << accelerations[j] << ", ";
            else
                std::cout << std::setprecision(6) << accelerations[j];
        }
        std::cout << std::endl;

        // efforts
        const std::vector<double>& efforts = point.effort();
        std::cout << "  Efforts: ";
        for (size_t j = 0; j < efforts.size(); j++)
        {
            if (j != efforts.size() - 1)
                std::cout << std::setprecision(6) << efforts[j] << ", ";
            else
                std::cout << std::setprecision(6) << efforts[j];
        }
        std::cout << std::endl;

    }
}
