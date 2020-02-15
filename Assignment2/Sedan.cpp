#include <cassert>
#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTrailer(nullptr)
	{
		Vehicle::SetDrivePattern(5, 1);
	}

	Sedan::~Sedan()
	{
		if (mTrailer != nullptr)
		{
			delete mTrailer;
		}
	}

	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
	{
		if (mTrailer != nullptr)
		{
			delete mTrailer;
		}

		mTrailer = new Trailer(*(other.mTrailer));
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer != nullptr)
		{
			return false;
		}

		mTrailer = trailer;
		Vehicle::SetDrivePattern(5, 2);

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}

		delete mTrailer;
		mTrailer = nullptr;
		Vehicle::SetDrivePattern(5, 1);

		return true;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		int weight = Vehicle::GetPassangersWeight();
		if (mTrailer != nullptr)
		{
			weight += mTrailer->GetWeight();
		}

		unsigned int speed = 0;
		if (weight <= 80)
		{
			speed = 480;
		}
		else if (weight > 80 && weight <= 160)
		{
			speed = 458;
		}
		else if (weight > 160 && weight <= 260)
		{
			speed = 400;
		}
		else if (weight > 260 && weight <= 350)
		{
			speed = 380;
		}
		else if (weight > 350)
		{
			speed = 300;
		}

		return speed;
	}
}
