#pragma once
#include <string>

#include "Particle.h"

class Electron : public Particle
{
public:
	Electron();
	Electron(double PosX, double PosY, double PosZ);
	Electron(double PosX, double PosY, double PosZ, double vX, double vY, double vZ);
	virtual ~Electron();

	unsigned int getNumber() const;

	virtual std::string toString() const;

private:
	const unsigned int m_number;
	static unsigned int nbElectrons;
};

