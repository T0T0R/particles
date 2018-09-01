#pragma once

#include <memory>
#include <string>

#include "Particle.h"

class Proton: public Particle
{
public:
	Proton();
	Proton(double PosX, double PosY, double PosZ);
	Proton(double PosX, double PosY, double PosZ, double vX, double vY, double vZ, double spin=0.5);
	virtual ~Proton();

	unsigned int getNumber() const;

	virtual std::string toString() const;

private:
	static unsigned int nbProtons;
	const unsigned int m_number;
};

