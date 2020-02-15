#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();
		Vehicle(const Vehicle& other);
		virtual Vehicle& operator=(const Vehicle& other);

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		int GetPassangersWeight() const;
		void SetDrivePattern(unsigned int runnableHours, unsigned int breakHours);
		void ResetTotalDriveHours();
		void AddTravelHour();
		unsigned int GetTotalTravelKilometer() const;
		bool MovePassenger(unsigned int i);
	private:
		const Person** mPassangers;
		unsigned int mPassengersCount;
		unsigned int mMaxPassengersCount;
		unsigned int mRunnableHours;
		unsigned int mBreakHours;
		unsigned int mTotalTravelHours;
	};
}
