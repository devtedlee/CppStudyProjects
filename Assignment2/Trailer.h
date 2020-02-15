#pragma once

namespace assignment2
{
	class Trailer
	{
	public:
		Trailer(unsigned int weight);

		unsigned int GetWeight() const;
	private:
		unsigned int mWeight;
	};
}
