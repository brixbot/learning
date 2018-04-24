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
 * @file JointTrajectoryPubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _JOINTTRAJECTORY_PUBSUBTYPES_H_
#define _JOINTTRAJECTORY_PUBSUBTYPES_H_

#include <fastrtps/TopicDataType.h>

using namespace eprosima::fastrtps;

#include "JointTrajectory.h"

/*!
 * @brief This class represents the TopicDataType of the type duration defined by the user in the IDL file.
 * @ingroup JOINTTRAJECTORY
 */
class durationPubSubType : public TopicDataType 
{
public:
	durationPubSubType();
	virtual ~durationPubSubType();
	bool serialize(void *data, SerializedPayload_t *payload);
	bool deserialize(SerializedPayload_t *payload, void *data);
    std::function<uint32_t()> getSerializedSizeProvider(void* data);
	void* createData();
	void deleteData(void * data);
};

/*!
 * @brief This class represents the TopicDataType of the type JointTrajectoryPoint defined by the user in the IDL file.
 * @ingroup JOINTTRAJECTORY
 */
class JointTrajectoryPointPubSubType : public TopicDataType 
{
public:
	JointTrajectoryPointPubSubType();
	virtual ~JointTrajectoryPointPubSubType();
	bool serialize(void *data, SerializedPayload_t *payload);
	bool deserialize(SerializedPayload_t *payload, void *data);
    std::function<uint32_t()> getSerializedSizeProvider(void* data);
	void* createData();
	void deleteData(void * data);
};

/*!
 * @brief This class represents the TopicDataType of the type time defined by the user in the IDL file.
 * @ingroup JOINTTRAJECTORY
 */
class timePubSubType : public TopicDataType 
{
public:
	timePubSubType();
	virtual ~timePubSubType();
	bool serialize(void *data, SerializedPayload_t *payload);
	bool deserialize(SerializedPayload_t *payload, void *data);
    std::function<uint32_t()> getSerializedSizeProvider(void* data);
	void* createData();
	void deleteData(void * data);
};

/*!
 * @brief This class represents the TopicDataType of the type Header defined by the user in the IDL file.
 * @ingroup JOINTTRAJECTORY
 */
class HeaderPubSubType : public TopicDataType 
{
public:
	HeaderPubSubType();
	virtual ~HeaderPubSubType();
	bool serialize(void *data, SerializedPayload_t *payload);
	bool deserialize(SerializedPayload_t *payload, void *data);
    std::function<uint32_t()> getSerializedSizeProvider(void* data);
	void* createData();
	void deleteData(void * data);
};

/*!
 * @brief This class represents the TopicDataType of the type JointTrajectory defined by the user in the IDL file.
 * @ingroup JOINTTRAJECTORY
 */
class JointTrajectoryPubSubType : public TopicDataType 
{
public:
	JointTrajectoryPubSubType();
	virtual ~JointTrajectoryPubSubType();
	bool serialize(void *data, SerializedPayload_t *payload);
	bool deserialize(SerializedPayload_t *payload, void *data);
    std::function<uint32_t()> getSerializedSizeProvider(void* data);
	void* createData();
	void deleteData(void * data);
};

#endif // _JointTrajectory_PUBSUBTYPE_H_