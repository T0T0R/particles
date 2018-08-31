#include <iostream>
#include <string>

#include "Particle.h"
#include "Proton.h"



Proton::Proton() :
	Particle(9.109E-31, +1.602E-19, 0.0, 0.0, 0.0), m_number(nbProtons)
{
	std::cout<<"Creation of proton no "<< nbProtons<<std::endl;
	nbProtons++;
}

Proton::Proton(double PosX, double PosY, double PosZ) :
	Particle(9.109E-31, +1.602E-19, PosX, PosY, PosZ), m_number(nbProtons)
{
	std::cout<<"Creation of proton no "<< nbProtons<<std::endl;
	nbProtons++;
}

Proton::Proton(double PosX, double PosY, double PosZ, double vX, double vY, double vZ) :
	Particle(9.109E-31, +1.602E-19, PosX, PosY, PosZ), m_number(nbProtons)
{
	m_speedX = vX;
	m_speedY = vY;
	m_speedZ = vZ;

	std::cout<<"Creation of proton no "<< nbProtons<<std::endl;
	nbProtons++;
}

Proton::~Proton() {
}

unsigned int Proton::nbProtons { 0 };


unsigned int Proton::getNumber() const { return m_number; }

std::string Proton::toString() const {
	//Description
	return "Proton number " + std::to_string(m_number) +
		" : position(" + std::to_string(m_posX) + ", " + std::to_string(m_posY) + ", " + std::to_string(m_posZ) +
		"), speed(" +	std::to_string(m_speedX) + ", " + std::to_string(m_speedY) + ", " + std::to_string(m_speedZ) +
		"), force(" + std::to_string(m_forcesX) + ", " + std::to_string(m_forcesY) + ", " + std::to_string(m_forcesZ) + ");";
}

