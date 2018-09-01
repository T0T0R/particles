#pragma once

#include <memory>
#include <string>

#include "Particle.h"

class Electron : public Particle
{
public:
	Electron();
	Electron(double PosX, double PosY, double PosZ);
	Electron(double PosX, double PosY, double PosZ, double vX, double vY, double vZ, double spin=0.5);
	virtual ~Electron();

	unsigned int getNumber() const;

	virtual std::string toString() const;

private:
	static unsigned int m_nbElectrons;
	const unsigned int m_number;
};

