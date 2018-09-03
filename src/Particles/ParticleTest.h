#pragma once

#include <memory>
#include <string>

#include "Particle.h"

class ParticleTest : public Particle
{
public:
	ParticleTest();
	ParticleTest(double PosX, double PosY, double PosZ);
	virtual ~ParticleTest();
};

