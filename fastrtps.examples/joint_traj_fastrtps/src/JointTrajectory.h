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
 * @file JointTrajectory.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _JointTrajectory_H_
#define _JointTrajectory_H_

// TODO Poner en el contexto.

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(JointTrajectory_SOURCE)
#define JointTrajectory_DllAPI __declspec( dllexport )
#else
#define JointTrajectory_DllAPI __declspec( dllimport )
#endif // JointTrajectory_SOURCE
#else
#define JointTrajectory_DllAPI
#endif
#else
#define JointTrajectory_DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}

namespace MyMsg
{

    /*!
     * @brief This class represents the structure duration defined by the user in the IDL file.
     * @ingroup JOINTTRAJECTORY
     */
    class duration
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport duration();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~duration();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object duration that will be copied.
         */
        eProsima_user_DllExport duration(const duration &x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object duration that will be copied.
         */
        eProsima_user_DllExport duration(duration &&x);

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object duration that will be copied.
         */
        eProsima_user_DllExport duration& operator=(const duration &x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object duration that will be copied.
         */
        eProsima_user_DllExport duration& operator=(duration &&x);

        /*!
         * @brief This function sets a value in member sec
         * @param _sec New value for member sec
         */
        inline eProsima_user_DllExport void sec(int32_t _sec)
        {
            m_sec = _sec;
        }

        /*!
         * @brief This function returns the value of member sec
         * @return Value of member sec
         */
        inline eProsima_user_DllExport int32_t sec() const
        {
            return m_sec;
        }

        /*!
         * @brief This function returns a reference to member sec
         * @return Reference to member sec
         */
        inline eProsima_user_DllExport int32_t& sec()
        {
            return m_sec;
        }
        /*!
         * @brief This function sets a value in member nsec
         * @param _nsec New value for member nsec
         */
        inline eProsima_user_DllExport void nsec(int32_t _nsec)
        {
            m_nsec = _nsec;
        }

        /*!
         * @brief This function returns the value of member nsec
         * @return Value of member nsec
         */
        inline eProsima_user_DllExport int32_t nsec() const
        {
            return m_nsec;
        }

        /*!
         * @brief This function returns a reference to member nsec
         * @return Reference to member nsec
         */
        inline eProsima_user_DllExport int32_t& nsec()
        {
            return m_nsec;
        }

        /*!
         * @brief This function returns the maximum serialized size of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function returns the serialized size of a data depending on the buffer alignment.
         * @param data Data which is calculated its serialized size.
         * @param current_alignment Buffer alignment.
         * @return Serialized size.
         */
        eProsima_user_DllExport static size_t getCdrSerializedSize(const duration& data, size_t current_alignment = 0);


        /*!
         * @brief This function serializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

        /*!
         * @brief This function deserializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



        /*!
         * @brief This function returns the maximum serialized size of the Key of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function tells you if the Key has been defined for this type
         */
        eProsima_user_DllExport static bool isKeyDefined();

        /*!
         * @brief This function serializes the key members of an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

    private:
        int32_t m_sec;
        int32_t m_nsec;
    };
    /*!
     * @brief This class represents the structure JointTrajectoryPoint defined by the user in the IDL file.
     * @ingroup JOINTTRAJECTORY
     */
    class JointTrajectoryPoint
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport JointTrajectoryPoint();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~JointTrajectoryPoint();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object JointTrajectoryPoint that will be copied.
         */
        eProsima_user_DllExport JointTrajectoryPoint(const JointTrajectoryPoint &x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object JointTrajectoryPoint that will be copied.
         */
        eProsima_user_DllExport JointTrajectoryPoint(JointTrajectoryPoint &&x);

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object JointTrajectoryPoint that will be copied.
         */
        eProsima_user_DllExport JointTrajectoryPoint& operator=(const JointTrajectoryPoint &x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object JointTrajectoryPoint that will be copied.
         */
        eProsima_user_DllExport JointTrajectoryPoint& operator=(JointTrajectoryPoint &&x);

        /*!
         * @brief This function copies the value in member positions
         * @param _positions New value to be copied in member positions
         */
        inline eProsima_user_DllExport void positions(const std::vector<double> &_positions)
        {
            m_positions = _positions;
        }

        /*!
         * @brief This function moves the value in member positions
         * @param _positions New value to be moved in member positions
         */
        inline eProsima_user_DllExport void positions(std::vector<double> &&_positions)
        {
            m_positions = std::move(_positions);
        }

        /*!
         * @brief This function returns a constant reference to member positions
         * @return Constant reference to member positions
         */
        inline eProsima_user_DllExport const std::vector<double>& positions() const
        {
            return m_positions;
        }

        /*!
         * @brief This function returns a reference to member positions
         * @return Reference to member positions
         */
        inline eProsima_user_DllExport std::vector<double>& positions()
        {
            return m_positions;
        }
        /*!
         * @brief This function copies the value in member velocities
         * @param _velocities New value to be copied in member velocities
         */
        inline eProsima_user_DllExport void velocities(const std::vector<double> &_velocities)
        {
            m_velocities = _velocities;
        }

        /*!
         * @brief This function moves the value in member velocities
         * @param _velocities New value to be moved in member velocities
         */
        inline eProsima_user_DllExport void velocities(std::vector<double> &&_velocities)
        {
            m_velocities = std::move(_velocities);
        }

        /*!
         * @brief This function returns a constant reference to member velocities
         * @return Constant reference to member velocities
         */
        inline eProsima_user_DllExport const std::vector<double>& velocities() const
        {
            return m_velocities;
        }

        /*!
         * @brief This function returns a reference to member velocities
         * @return Reference to member velocities
         */
        inline eProsima_user_DllExport std::vector<double>& velocities()
        {
            return m_velocities;
        }
        /*!
         * @brief This function copies the value in member accelerations
         * @param _accelerations New value to be copied in member accelerations
         */
        inline eProsima_user_DllExport void accelerations(const std::vector<double> &_accelerations)
        {
            m_accelerations = _accelerations;
        }

        /*!
         * @brief This function moves the value in member accelerations
         * @param _accelerations New value to be moved in member accelerations
         */
        inline eProsima_user_DllExport void accelerations(std::vector<double> &&_accelerations)
        {
            m_accelerations = std::move(_accelerations);
        }

        /*!
         * @brief This function returns a constant reference to member accelerations
         * @return Constant reference to member accelerations
         */
        inline eProsima_user_DllExport const std::vector<double>& accelerations() const
        {
            return m_accelerations;
        }

        /*!
         * @brief This function returns a reference to member accelerations
         * @return Reference to member accelerations
         */
        inline eProsima_user_DllExport std::vector<double>& accelerations()
        {
            return m_accelerations;
        }
        /*!
         * @brief This function copies the value in member effort
         * @param _effort New value to be copied in member effort
         */
        inline eProsima_user_DllExport void effort(const std::vector<double> &_effort)
        {
            m_effort = _effort;
        }

        /*!
         * @brief This function moves the value in member effort
         * @param _effort New value to be moved in member effort
         */
        inline eProsima_user_DllExport void effort(std::vector<double> &&_effort)
        {
            m_effort = std::move(_effort);
        }

        /*!
         * @brief This function returns a constant reference to member effort
         * @return Constant reference to member effort
         */
        inline eProsima_user_DllExport const std::vector<double>& effort() const
        {
            return m_effort;
        }

        /*!
         * @brief This function returns a reference to member effort
         * @return Reference to member effort
         */
        inline eProsima_user_DllExport std::vector<double>& effort()
        {
            return m_effort;
        }
        /*!
         * @brief This function copies the value in member time_from_start
         * @param _time_from_start New value to be copied in member time_from_start
         */
        inline eProsima_user_DllExport void time_from_start(const duration &_time_from_start)
        {
            m_time_from_start = _time_from_start;
        }

        /*!
         * @brief This function moves the value in member time_from_start
         * @param _time_from_start New value to be moved in member time_from_start
         */
        inline eProsima_user_DllExport void time_from_start(duration &&_time_from_start)
        {
            m_time_from_start = std::move(_time_from_start);
        }

        /*!
         * @brief This function returns a constant reference to member time_from_start
         * @return Constant reference to member time_from_start
         */
        inline eProsima_user_DllExport const duration& time_from_start() const
        {
            return m_time_from_start;
        }

        /*!
         * @brief This function returns a reference to member time_from_start
         * @return Reference to member time_from_start
         */
        inline eProsima_user_DllExport duration& time_from_start()
        {
            return m_time_from_start;
        }

        /*!
         * @brief This function returns the maximum serialized size of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function returns the serialized size of a data depending on the buffer alignment.
         * @param data Data which is calculated its serialized size.
         * @param current_alignment Buffer alignment.
         * @return Serialized size.
         */
        eProsima_user_DllExport static size_t getCdrSerializedSize(const JointTrajectoryPoint& data, size_t current_alignment = 0);


        /*!
         * @brief This function serializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

        /*!
         * @brief This function deserializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



        /*!
         * @brief This function returns the maximum serialized size of the Key of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function tells you if the Key has been defined for this type
         */
        eProsima_user_DllExport static bool isKeyDefined();

        /*!
         * @brief This function serializes the key members of an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

    private:
        std::vector<double> m_positions;
        std::vector<double> m_velocities;
        std::vector<double> m_accelerations;
        std::vector<double> m_effort;
        duration m_time_from_start;
    };
    /*!
     * @brief This class represents the structure time defined by the user in the IDL file.
     * @ingroup JOINTTRAJECTORY
     */
    class time
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport time();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~time();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object time that will be copied.
         */
        eProsima_user_DllExport time(const time &x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object time that will be copied.
         */
        eProsima_user_DllExport time(time &&x);

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object time that will be copied.
         */
        eProsima_user_DllExport time& operator=(const time &x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object time that will be copied.
         */
        eProsima_user_DllExport time& operator=(time &&x);

        /*!
         * @brief This function sets a value in member sec
         * @param _sec New value for member sec
         */
        inline eProsima_user_DllExport void sec(uint32_t _sec)
        {
            m_sec = _sec;
        }

        /*!
         * @brief This function returns the value of member sec
         * @return Value of member sec
         */
        inline eProsima_user_DllExport uint32_t sec() const
        {
            return m_sec;
        }

        /*!
         * @brief This function returns a reference to member sec
         * @return Reference to member sec
         */
        inline eProsima_user_DllExport uint32_t& sec()
        {
            return m_sec;
        }
        /*!
         * @brief This function sets a value in member nsec
         * @param _nsec New value for member nsec
         */
        inline eProsima_user_DllExport void nsec(uint32_t _nsec)
        {
            m_nsec = _nsec;
        }

        /*!
         * @brief This function returns the value of member nsec
         * @return Value of member nsec
         */
        inline eProsima_user_DllExport uint32_t nsec() const
        {
            return m_nsec;
        }

        /*!
         * @brief This function returns a reference to member nsec
         * @return Reference to member nsec
         */
        inline eProsima_user_DllExport uint32_t& nsec()
        {
            return m_nsec;
        }

        /*!
         * @brief This function returns the maximum serialized size of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function returns the serialized size of a data depending on the buffer alignment.
         * @param data Data which is calculated its serialized size.
         * @param current_alignment Buffer alignment.
         * @return Serialized size.
         */
        eProsima_user_DllExport static size_t getCdrSerializedSize(const time& data, size_t current_alignment = 0);


        /*!
         * @brief This function serializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

        /*!
         * @brief This function deserializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



        /*!
         * @brief This function returns the maximum serialized size of the Key of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function tells you if the Key has been defined for this type
         */
        eProsima_user_DllExport static bool isKeyDefined();

        /*!
         * @brief This function serializes the key members of an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

    private:
        uint32_t m_sec;
        uint32_t m_nsec;
    };
    /*!
     * @brief This class represents the structure Header defined by the user in the IDL file.
     * @ingroup JOINTTRAJECTORY
     */
    class Header
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport Header();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~Header();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object Header that will be copied.
         */
        eProsima_user_DllExport Header(const Header &x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object Header that will be copied.
         */
        eProsima_user_DllExport Header(Header &&x);

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object Header that will be copied.
         */
        eProsima_user_DllExport Header& operator=(const Header &x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object Header that will be copied.
         */
        eProsima_user_DllExport Header& operator=(Header &&x);

        /*!
         * @brief This function sets a value in member seq
         * @param _seq New value for member seq
         */
        inline eProsima_user_DllExport void seq(uint32_t _seq)
        {
            m_seq = _seq;
        }

        /*!
         * @brief This function returns the value of member seq
         * @return Value of member seq
         */
        inline eProsima_user_DllExport uint32_t seq() const
        {
            return m_seq;
        }

        /*!
         * @brief This function returns a reference to member seq
         * @return Reference to member seq
         */
        inline eProsima_user_DllExport uint32_t& seq()
        {
            return m_seq;
        }
        /*!
         * @brief This function copies the value in member stamp
         * @param _stamp New value to be copied in member stamp
         */
        inline eProsima_user_DllExport void stamp(const time &_stamp)
        {
            m_stamp = _stamp;
        }

        /*!
         * @brief This function moves the value in member stamp
         * @param _stamp New value to be moved in member stamp
         */
        inline eProsima_user_DllExport void stamp(time &&_stamp)
        {
            m_stamp = std::move(_stamp);
        }

        /*!
         * @brief This function returns a constant reference to member stamp
         * @return Constant reference to member stamp
         */
        inline eProsima_user_DllExport const time& stamp() const
        {
            return m_stamp;
        }

        /*!
         * @brief This function returns a reference to member stamp
         * @return Reference to member stamp
         */
        inline eProsima_user_DllExport time& stamp()
        {
            return m_stamp;
        }
        /*!
         * @brief This function copies the value in member frame_id
         * @param _frame_id New value to be copied in member frame_id
         */
        inline eProsima_user_DllExport void frame_id(const std::string &_frame_id)
        {
            m_frame_id = _frame_id;
        }

        /*!
         * @brief This function moves the value in member frame_id
         * @param _frame_id New value to be moved in member frame_id
         */
        inline eProsima_user_DllExport void frame_id(std::string &&_frame_id)
        {
            m_frame_id = std::move(_frame_id);
        }

        /*!
         * @brief This function returns a constant reference to member frame_id
         * @return Constant reference to member frame_id
         */
        inline eProsima_user_DllExport const std::string& frame_id() const
        {
            return m_frame_id;
        }

        /*!
         * @brief This function returns a reference to member frame_id
         * @return Reference to member frame_id
         */
        inline eProsima_user_DllExport std::string& frame_id()
        {
            return m_frame_id;
        }

        /*!
         * @brief This function returns the maximum serialized size of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function returns the serialized size of a data depending on the buffer alignment.
         * @param data Data which is calculated its serialized size.
         * @param current_alignment Buffer alignment.
         * @return Serialized size.
         */
        eProsima_user_DllExport static size_t getCdrSerializedSize(const Header& data, size_t current_alignment = 0);


        /*!
         * @brief This function serializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

        /*!
         * @brief This function deserializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



        /*!
         * @brief This function returns the maximum serialized size of the Key of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function tells you if the Key has been defined for this type
         */
        eProsima_user_DllExport static bool isKeyDefined();

        /*!
         * @brief This function serializes the key members of an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

    private:
        uint32_t m_seq;
        time m_stamp;
        std::string m_frame_id;
    };
    /*!
     * @brief This class represents the structure JointTrajectory defined by the user in the IDL file.
     * @ingroup JOINTTRAJECTORY
     */
    class JointTrajectory
    {
    public:

        /*!
         * @brief Default constructor.
         */
        eProsima_user_DllExport JointTrajectory();

        /*!
         * @brief Default destructor.
         */
        eProsima_user_DllExport ~JointTrajectory();

        /*!
         * @brief Copy constructor.
         * @param x Reference to the object JointTrajectory that will be copied.
         */
        eProsima_user_DllExport JointTrajectory(const JointTrajectory &x);

        /*!
         * @brief Move constructor.
         * @param x Reference to the object JointTrajectory that will be copied.
         */
        eProsima_user_DllExport JointTrajectory(JointTrajectory &&x);

        /*!
         * @brief Copy assignment.
         * @param x Reference to the object JointTrajectory that will be copied.
         */
        eProsima_user_DllExport JointTrajectory& operator=(const JointTrajectory &x);

        /*!
         * @brief Move assignment.
         * @param x Reference to the object JointTrajectory that will be copied.
         */
        eProsima_user_DllExport JointTrajectory& operator=(JointTrajectory &&x);

        /*!
         * @brief This function copies the value in member header
         * @param _header New value to be copied in member header
         */
        inline eProsima_user_DllExport void header(const Header &_header)
        {
            m_header = _header;
        }

        /*!
         * @brief This function moves the value in member header
         * @param _header New value to be moved in member header
         */
        inline eProsima_user_DllExport void header(Header &&_header)
        {
            m_header = std::move(_header);
        }

        /*!
         * @brief This function returns a constant reference to member header
         * @return Constant reference to member header
         */
        inline eProsima_user_DllExport const Header& header() const
        {
            return m_header;
        }

        /*!
         * @brief This function returns a reference to member header
         * @return Reference to member header
         */
        inline eProsima_user_DllExport Header& header()
        {
            return m_header;
        }
        /*!
         * @brief This function copies the value in member joint_names
         * @param _joint_names New value to be copied in member joint_names
         */
        inline eProsima_user_DllExport void joint_names(const std::vector<std::string> &_joint_names)
        {
            m_joint_names = _joint_names;
        }

        /*!
         * @brief This function moves the value in member joint_names
         * @param _joint_names New value to be moved in member joint_names
         */
        inline eProsima_user_DllExport void joint_names(std::vector<std::string> &&_joint_names)
        {
            m_joint_names = std::move(_joint_names);
        }

        /*!
         * @brief This function returns a constant reference to member joint_names
         * @return Constant reference to member joint_names
         */
        inline eProsima_user_DllExport const std::vector<std::string>& joint_names() const
        {
            return m_joint_names;
        }

        /*!
         * @brief This function returns a reference to member joint_names
         * @return Reference to member joint_names
         */
        inline eProsima_user_DllExport std::vector<std::string>& joint_names()
        {
            return m_joint_names;
        }
        /*!
         * @brief This function copies the value in member points
         * @param _points New value to be copied in member points
         */
        inline eProsima_user_DllExport void points(const std::vector<JointTrajectoryPoint> &_points)
        {
            m_points = _points;
        }

        /*!
         * @brief This function moves the value in member points
         * @param _points New value to be moved in member points
         */
        inline eProsima_user_DllExport void points(std::vector<JointTrajectoryPoint> &&_points)
        {
            m_points = std::move(_points);
        }

        /*!
         * @brief This function returns a constant reference to member points
         * @return Constant reference to member points
         */
        inline eProsima_user_DllExport const std::vector<JointTrajectoryPoint>& points() const
        {
            return m_points;
        }

        /*!
         * @brief This function returns a reference to member points
         * @return Reference to member points
         */
        inline eProsima_user_DllExport std::vector<JointTrajectoryPoint>& points()
        {
            return m_points;
        }

        /*!
         * @brief This function returns the maximum serialized size of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function returns the serialized size of a data depending on the buffer alignment.
         * @param data Data which is calculated its serialized size.
         * @param current_alignment Buffer alignment.
         * @return Serialized size.
         */
        eProsima_user_DllExport static size_t getCdrSerializedSize(const JointTrajectory& data, size_t current_alignment = 0);


        /*!
         * @brief This function serializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

        /*!
         * @brief This function deserializes an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



        /*!
         * @brief This function returns the maximum serialized size of the Key of an object
         * depending on the buffer alignment.
         * @param current_alignment Buffer alignment.
         * @return Maximum serialized size.
         */
        eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

        /*!
         * @brief This function tells you if the Key has been defined for this type
         */
        eProsima_user_DllExport static bool isKeyDefined();

        /*!
         * @brief This function serializes the key members of an object using CDR serialization.
         * @param cdr CDR serialization object.
         */
        eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

    private:
        Header m_header;
        std::vector<std::string> m_joint_names;
        std::vector<JointTrajectoryPoint> m_points;
    };

}

#endif // _JointTrajectory_H_