// joint_traj_fastcdr.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <cassert>

#include "JointTrajectory.h"
#include "fastcdr/FastCdr.h"
#include "fastcdr/exceptions/Exception.h"

const int JOINTS_COUNT = 6;
const int POINTS_COUNT = 10;

void PrepareJointTrajectory(JointTrajectory& traj)
{
	time t;
	t.sec(1000);
	t.nsec(999);

	duration d;
	d.sec(1);
	d.nsec(0);

	Header hdr;
	hdr.frame_id("world");
	hdr.seq(1);
	hdr.stamp(t);

	std::vector<std::string> names;
	std::vector<double> positions, velocities, accelerations, efforts;
	for (int i = 0; i < JOINTS_COUNT; i++)
	{
		positions.push_back(1.0 + i);
		velocities.push_back(1.1 + i);
		accelerations.push_back(1.11 + i);
		efforts.push_back(1.111 + i);

		names.push_back(std::string("joint_") + std::to_string((long long)i));
	}

	std::vector<JointTrajectoryPoint> points;
	for (int i = 0; i < POINTS_COUNT; i++)
	{
		for (int j = 0; j < JOINTS_COUNT; j++)
		{
			positions[j] = (i + 1) * (1.0 + j);
			velocities[j] = (i + 1) * (1.1 + j);
			accelerations[j] = (i + 1) * (1.11 + j);
			efforts[j] = (i + 1) * (1.111 + j);
		}

		JointTrajectoryPoint p;
		p.positions(positions);
		p.velocities(velocities);
		p.accelerations(accelerations);
		p.effort(efforts);
		p.time_from_start(d);

		points.push_back(p);
	}

	traj.header(hdr);
	traj.joint_names(names);
	traj.points(points);
}

void PrintJointTrajectory(const JointTrajectory& traj)
{
	const std::vector<std::string> joints = traj.joint_names();
	const std::vector<JointTrajectoryPoint> points = traj.points();

	std::cout << "Joints: ";
	for (size_t i = 0; i < joints.size(); i++)
	{
		if (i < joints.size() -1)
			std::cout << joints[i] << ", ";
		else
			std::cout << joints[i];
	}
	std::cout << std::endl;

}

int main()
{
	eprosima::fastcdr::FastBuffer fastbuffer;
	eprosima::fastcdr::FastCdr ser(fastbuffer);

	// prepare the test data 
	JointTrajectory traj;
	PrepareJointTrajectory(traj);

	std::cout << "JointTrajectory before serialization" << std::endl;
	PrintJointTrajectory(traj);
	std::cout << std::endl;

	// Serialization.
	ser << traj;

	// Reset the reading position in the serializer object to start deserialization.
	ser.reset();

	// The buffer will be deserialized in the next structure.
	JointTrajectory receivedTraj;

	// Deserialization.
	ser >> receivedTraj;

	std::cout << "JointTrajectory after deserialization" << std::endl;
	PrintJointTrajectory(receivedTraj);
	std::cout << std::endl;

	system("pause");

    return 0;
}

