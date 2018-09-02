#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include "Particle.h"
#include "Proton.h"



Proton::Proton() :
	Particle(9.109E-31, +1.602E-19, 0.5, 0.0, 0.0, 0.0), m_number(nbProtons)
{
	//std::cout<<"Creation of proton no "<< nbProtons<<std::endl;
	nbProtons++;
}

Proton::Proton(double PosX, double PosY, double PosZ) :
	Particle(9.109E-31, +1.602E-19, 0.5, PosX, PosY, PosZ), m_number(nbProtons)
{
	//std::cout<<"Creation of proton no "<< nbProtons<<std::endl;
	nbProtons++;
}

Proton::Proton(double PosX, double PosY, double PosZ, double vX, double vY, double vZ, double spin) :
	Particle(9.109E-31, +1.602E-19, spin, PosX, PosY, PosZ), m_number(nbProtons)
{
	m_speedX = vX;
	m_speedY = vY;
	m_speedZ = vZ;

	//std::cout<<"Creation of proton no "<< nbProtons<<std::endl;
	nbProtons++;
}

Proton::~Proton() {
}

unsigned int Proton::nbProtons { 0 };


unsigned int Proton::getNumber() const { return m_number; }

std::string Proton::toString() const {
	//Description
	std::ostringstream streamObj;
	streamObj<< "\tProton nb " + std::to_string(m_number) +
		" : mass=" <<m_mass<< "kg ; charge="<<m_charge<<"C ; spin="<<m_spin;
	return Particle::toString()+'\n'+streamObj.str();
}

