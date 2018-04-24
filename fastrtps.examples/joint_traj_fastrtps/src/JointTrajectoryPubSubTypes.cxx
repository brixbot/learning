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
 * @file JointTrajectoryPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include "JointTrajectoryPubSubTypes.h"

durationPubSubType::durationPubSubType() 
{
    setName("duration");
    m_typeSize = (uint32_t)MyMsg::duration::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
}

durationPubSubType::~durationPubSubType() 
{
}

bool durationPubSubType::serialize(void *data, SerializedPayload_t *payload) 
{
    MyMsg::duration *msg = (MyMsg::duration*) data;
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload->data, payload->max_size); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        msg->serialize(ser); // Serialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    payload->length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
    return true;
}

bool durationPubSubType::deserialize(SerializedPayload_t* payload, void* data) 
{
    MyMsg::duration* msg = (MyMsg::duration*) data; 	//Convert DATA to pointer of your type
    eprosima::fastcdr::FastBuffer fastbuffer((char*)payload->data, payload->length); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that deserializes the data.
    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        msg->deserialize(deser); //Deserialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> durationPubSubType::getSerializedSizeProvider(void* data) 
{
    return [data]() -> uint32_t
    {
        return (uint32_t)MyMsg::duration::getCdrSerializedSize(*static_cast<MyMsg::duration*>(data)) + 4 /*encapsulation*/;
    };
}

void* durationPubSubType::createData() 
{
    return (void*)new MyMsg::duration();
}

void durationPubSubType::deleteData(void* data) 
{
    delete((MyMsg::duration*)data);
}

JointTrajectoryPointPubSubType::JointTrajectoryPointPubSubType() 
{
    setName("JointTrajectoryPoint");
    m_typeSize = (uint32_t)MyMsg::JointTrajectoryPoint::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
}

JointTrajectoryPointPubSubType::~JointTrajectoryPointPubSubType() 
{
}

bool JointTrajectoryPointPubSubType::serialize(void *data, SerializedPayload_t *payload) 
{
    MyMsg::JointTrajectoryPoint *msg = (MyMsg::JointTrajectoryPoint*) data;
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload->data, payload->max_size); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        msg->serialize(ser); // Serialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    payload->length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
    return true;
}

bool JointTrajectoryPointPubSubType::deserialize(SerializedPayload_t* payload, void* data) 
{
    MyMsg::JointTrajectoryPoint* msg = (MyMsg::JointTrajectoryPoint*) data; 	//Convert DATA to pointer of your type
    eprosima::fastcdr::FastBuffer fastbuffer((char*)payload->data, payload->length); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that deserializes the data.
    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        msg->deserialize(deser); //Deserialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> JointTrajectoryPointPubSubType::getSerializedSizeProvider(void* data) 
{
    return [data]() -> uint32_t
    {
        return (uint32_t)MyMsg::JointTrajectoryPoint::getCdrSerializedSize(*static_cast<MyMsg::JointTrajectoryPoint*>(data)) + 4 /*encapsulation*/;
    };
}

void* JointTrajectoryPointPubSubType::createData() 
{
    return (void*)new MyMsg::JointTrajectoryPoint();
}

void JointTrajectoryPointPubSubType::deleteData(void* data) 
{
    delete((MyMsg::JointTrajectoryPoint*)data);
}

timePubSubType::timePubSubType() 
{
    setName("time");
    m_typeSize = (uint32_t)MyMsg::time::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
}

timePubSubType::~timePubSubType() 
{
}

bool timePubSubType::serialize(void *data, SerializedPayload_t *payload) 
{
    MyMsg::time *msg = (MyMsg::time*) data;
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload->data, payload->max_size); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        msg->serialize(ser); // Serialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    payload->length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
    return true;
}

bool timePubSubType::deserialize(SerializedPayload_t* payload, void* data) 
{
    MyMsg::time* msg = (MyMsg::time*) data; 	//Convert DATA to pointer of your type
    eprosima::fastcdr::FastBuffer fastbuffer((char*)payload->data, payload->length); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that deserializes the data.
    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        msg->deserialize(deser); //Deserialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> timePubSubType::getSerializedSizeProvider(void* data) 
{
    return [data]() -> uint32_t
    {
        return (uint32_t)MyMsg::time::getCdrSerializedSize(*static_cast<MyMsg::time*>(data)) + 4 /*encapsulation*/;
    };
}

void* timePubSubType::createData() 
{
    return (void*)new MyMsg::time();
}

void timePubSubType::deleteData(void* data) 
{
    delete((MyMsg::time*)data);
}

HeaderPubSubType::HeaderPubSubType() 
{
    setName("Header");
    m_typeSize = (uint32_t)MyMsg::Header::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
}

HeaderPubSubType::~HeaderPubSubType() 
{
}

bool HeaderPubSubType::serialize(void *data, SerializedPayload_t *payload) 
{
    MyMsg::Header *msg = (MyMsg::Header*) data;
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload->data, payload->max_size); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        msg->serialize(ser); // Serialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    payload->length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
    return true;
}

bool HeaderPubSubType::deserialize(SerializedPayload_t* payload, void* data) 
{
    MyMsg::Header* msg = (MyMsg::Header*) data; 	//Convert DATA to pointer of your type
    eprosima::fastcdr::FastBuffer fastbuffer((char*)payload->data, payload->length); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that deserializes the data.
    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        msg->deserialize(deser); //Deserialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> HeaderPubSubType::getSerializedSizeProvider(void* data) 
{
    return [data]() -> uint32_t
    {
        return (uint32_t)MyMsg::Header::getCdrSerializedSize(*static_cast<MyMsg::Header*>(data)) + 4 /*encapsulation*/;
    };
}

void* HeaderPubSubType::createData() 
{
    return (void*)new MyMsg::Header();
}

void HeaderPubSubType::deleteData(void* data) 
{
    delete((MyMsg::Header*)data);
}

JointTrajectoryPubSubType::JointTrajectoryPubSubType() 
{
    setName("JointTrajectory");
    m_typeSize = (uint32_t)MyMsg::JointTrajectory::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
}

JointTrajectoryPubSubType::~JointTrajectoryPubSubType() 
{
}

bool JointTrajectoryPubSubType::serialize(void *data, SerializedPayload_t *payload) 
{
    MyMsg::JointTrajectory *msg = (MyMsg::JointTrajectory*) data;
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload->data, payload->max_size); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that serializes the data.
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        msg->serialize(ser); // Serialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    payload->length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
    return true;
}

bool JointTrajectoryPubSubType::deserialize(SerializedPayload_t* payload, void* data) 
{
    MyMsg::JointTrajectory* msg = (MyMsg::JointTrajectory*) data; 	//Convert DATA to pointer of your type
    eprosima::fastcdr::FastBuffer fastbuffer((char*)payload->data, payload->length); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that deserializes the data.
    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        msg->deserialize(deser); //Deserialize the object:
    }
    catch(eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> JointTrajectoryPubSubType::getSerializedSizeProvider(void* data) 
{
    return [data]() -> uint32_t
    {
        return (uint32_t)MyMsg::JointTrajectory::getCdrSerializedSize(*static_cast<MyMsg::JointTrajectory*>(data)) + 4 /*encapsulation*/;
    };
}

void* JointTrajectoryPubSubType::createData() 
{
    return (void*)new MyMsg::JointTrajectory();
}

void JointTrajectoryPubSubType::deleteData(void* data) 
{
    delete((MyMsg::JointTrajectory*)data);
}
