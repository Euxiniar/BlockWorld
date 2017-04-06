#include "Random_Maths.h"

namespace Maths
{
	Random::Random()
	{
		init();
	}

	void Random::setSeed(unsigned int seed)
	{
		gen.seed(seed);
	}

	int Random::getInteger(int low, int high)
	{
		std::uniform_int_distribution<int> dist(low, high);
		return dist(gen);
	}

	double Random::getDecimal(int low, double high)
	{
		std::uniform_real_distribution<double> dist(low, high);
		return dist(gen);
	}

	void Random::init()
	{
		gen.seed(std::random_device{}());
	}

}