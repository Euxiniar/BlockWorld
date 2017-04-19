#pragma once
#include <random>

namespace Maths
{
	class Random
	{
	public:
		Random();
		void setSeed(unsigned int seed);
		int getInteger(int low, int high);
		double getDecimal(int low, double high);

	private:
		std::minstd_rand gen;
		void init();
	};
}