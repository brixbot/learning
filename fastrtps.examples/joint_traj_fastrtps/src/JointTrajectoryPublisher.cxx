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
 * @file JointTrajectoryPublisher.cpp
 * This file contains the implementation of the publisher functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/attributes/PublisherAttributes.h>

#include <fastrtps/Domain.h>

#include <fastrtps/utils/eClock.h>

#include "JointTrajectoryPublisher.h"
#include <assert.h>  
#include <time.h>


JointTrajectoryPublisher::JointTrajectoryPublisher() : 
    participant_(nullptr), publisher_(nullptr) 
{
}

JointTrajectoryPublisher::~JointTrajectoryPublisher() 
{	
    Domain::removeParticipant(participant_);
}

bool JointTrajectoryPublisher::init()
{
	// Create RTPSParticipant
	ParticipantAttributes participantParam;
    participantParam.rtps.builtin.domainId = 0;
    participantParam.rtps.builtin.leaseDuration = c_TimeInfinite;
    participantParam.rtps.setName("Participant_publisher");  //You can put here the name you want
	participant_ = Domain::createParticipant(participantParam);
	if (participant_ == nullptr)
		return false;
	
	//Register the type
	Domain::registerType(participant_,(TopicDataType*) &myType_);
	
	// Create Publisher
	PublisherAttributes publisherParam;
    publisherParam.topic.topicKind = NO_KEY;
    publisherParam.topic.topicDataType = myType_.getName();  //This type MUST be registered
    publisherParam.topic.topicName = "JointTrajectoryPubSubTopic";
	publisher_ = Domain::createPublisher(participant_, publisherParam, (PublisherListener*)&listener_);
	if (publisher_ == nullptr)
		return false;

	std::cout << "Publisher created, waiting for Subscribers." << std::endl;

	return true;
}

void JointTrajectoryPublisher::PubListener::onPublicationMatched(Publisher* pub, MatchingInfo& info)
{
	if (info.status == MATCHED_MATCHING)
	{
		matched_++;
		std::cout << "Publisher matched" << std::endl;
	}
	else
	{
		matched_--;
		std::cout << "Publisher unmatched" << std::endl;
	}
}

void JointTrajectoryPublisher::run()
{
	while (listener_.matched_ == 0)
		eClock::my_sleep(250); // Sleep 250 ms
	
	// Publication code
	MyMsg::JointTrajectory traj;
    fillTraj(traj);
	
	/* Initialize your structure here */
	int msgsent = 0;
	char ch = 'y';
	do
	{
		if(ch == 'y')
		{
			publisher_->write(&traj);  
            ++msgsent;
			std::cout << "Sending sample, count=" << msgsent << ", send another sample?(y-yes,n-stop): ";
		}
		else if(ch == 'n')
		{
			std::cout << "Stopping execution " << std::endl;
			break;
		}
		else
		{
			std::cout << "Command " << ch << " not recognized, please enter \"y/n\":";
		}
	}while(std::cin >> ch);
}

void JointTrajectoryPublisher::fillTraj(MyMsg::JointTrajectory& traj)
{
    static uint32_t sequence = 0;

    struct timespec ts;
    timespec_get(&ts, TIME_UTC);

    MyMsg::time t;
    t.sec((uint32_t)ts.tv_sec);
    t.nsec((uint32_t)ts.tv_nsec);

    MyMsg::Header hdr;
    hdr.seq(sequence++);
    hdr.frame_id(std::to_string(10000 + sequence));
    hdr.stamp(t);

    const size_t POINTS_CNT = 10;
    const size_t JOINTS_CNT = 6;

    std::vector<std::string> jointsName;
    for (size_t i = 0; i < JOINTS_CNT; i++)
        jointsName.push_back(std::string("joint_") + std::to_string(i));

    std::vector<MyMsg::JointTrajectoryPoint> points;
    
    for (size_t i = 0; i < POINTS_CNT; i++)
    {
        std::vector<double> positions(JOINTS_CNT);
        std::vector<double> velocities(JOINTS_CNT);
        std::vector<double> accelerations(JOINTS_CNT);
        std::vector<double> effort(JOINTS_CNT);

        for (size_t j = 0; j < JOINTS_CNT; j++)
        {
            positions[j] = i * 10 + j * 0.1;
            velocities[j] = i + j * 0.1;
            accelerations[j] = i * 0.1  * j * 0.1;
            effort[j] = (double)j;
        }

        MyMsg::duration d;
        d.sec((uint32_t)i);
        d.nsec(0);

        MyMsg::JointTrajectoryPoint pt;
        pt.positions(positions);
        pt.velocities(velocities);
        pt.accelerations(accelerations);
        pt.effort(effort);

        pt.time_from_start(d);

        points.push_back(pt);
    }

    traj.header(hdr);
    traj.joint_names(jointsName);
    traj.points(points);
}