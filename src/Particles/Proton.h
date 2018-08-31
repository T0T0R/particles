#pragma once
#include <string>

#include "Particle.h"

class Proton: public Particle
{
public:
	Proton();
	Proton(double PosX, double PosY, double PosZ);
	Proton(double PosX, double PosY, double PosZ, double vX, double vY, double vZ);
	~Proton();

	unsigned int getNumber() const;

	std::string toString() const;

private:
	const unsigned int m_number;
	static unsigned int nbProtons;
};

