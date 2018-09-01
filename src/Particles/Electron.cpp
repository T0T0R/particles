#include <iostream>
#include <string>

#include "Particle.h"
#include "Electron.h"



Electron::Electron():
	Particle(9.109E-31, -1.602E-19, 0.0, 0.0, 0.0), m_number(nbElectrons)
{
	std::cout<<"Creation of electron no "<< nbElectrons<<std::endl;
	nbElectrons++;
}

Electron::Electron(double PosX, double PosY, double PosZ) :
	Particle(9.109E-31, -1.602E-19, PosX, PosY, PosZ), m_number(nbElectrons)
{
	std::cout<<"Creation of electron no "<< nbElectrons<<std::endl;
	nbElectrons++;
}

Electron::Electron(double PosX, double PosY, double PosZ, double vX, double vY, double vZ) :
	Particle(9.109E-31, -1.602E-19, PosX, PosY, PosZ), m_number(nbElectrons) {
	m_speedX = vX;
	m_speedY = vY;
	m_speedZ = vZ;

	std::cout<<m_posX<<" ; "<<m_posY<<" ; "<<m_posZ<<std::endl;

	std::cout<<"Creation of electron no "<< nbElectrons<<std::endl;
	nbElectrons++;
}

unsigned int Electron::nbElectrons { 0 };


Electron::~Electron() {
}



unsigned int Electron::getNumber() const {return m_number;}

std::string Electron::toString() const {
	//Description
	return "Electron numero " + std::to_string(m_number) +
		" : position(" + std::to_string(m_posX) + ", " + std::to_string(m_posY) + ", " + std::to_string(m_posZ) +
		"), speed(" +	std::to_string(m_speedX) + ", " + std::to_string(m_speedY) + ", " + std::to_string(m_speedZ) + 
		"), force(" + std::to_string(m_forcesX) + ", " + std::to_string(m_forcesY) + ", " + std::to_string(m_forcesZ) + ");";
}

