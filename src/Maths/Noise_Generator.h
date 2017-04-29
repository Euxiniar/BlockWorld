﻿#pragma once

#include <cstdint>

namespace Noise
{
	struct Data
	{
		Data() = default;
		Data(int numOctaves, int ampMult, double rough, double smooth)
			: octaves(numOctaves)
			, amplitudeMultiplier(ampMult)
			, roughness(rough)
			, smoother(smooth) {}
		int octaves = 8;
		int amplitudeMultiplier = 240;
		double roughness = 0.48;
		double smoother = 190;
	};

	uint64_t getSeed();
	void setSeed(uint64_t newSeed);

	class Generator
	{
	public:
		static Generator& get();
		double getValue(int x, int z, int tileX, int tileZ) const;

		void setNoiseFunction(const Noise::Data& data);

		uint64_t getSeed();
		void setSeed(uint64_t newSeed);

	private:
		double findNoise1(int n) const;
		double findNoise2(double x, double z) const;
		double lerp(double a, double b, double z) const;
		double noise(double x, double z) const;


		Noise::Data m_noiseFunction;
		uint64_t m_seed;

	};
}