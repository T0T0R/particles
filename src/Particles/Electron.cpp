#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include "Particle.h"
#include "Electron.h"



Electron::Electron():
	Particle(9.109E-31, -1.602E-19, 0.5, 0.0, 0.0, 0.0), m_number(m_nbElectrons)
{
	std::cout<<"Creation of electron no "<< m_nbElectrons<<std::endl;
	m_nbElectrons++;
}

Electron::Electron(double PosX, double PosY, double PosZ) :
	Particle(9.109E-31, -1.602E-19, 0.5, PosX, PosY, PosZ), m_number(m_nbElectrons)
{
	std::cout<<"Creation of electron no "<< m_nbElectrons<<std::endl;
	m_nbElectrons++;
}

Electron::Electron(double PosX, double PosY, double PosZ, double vX, double vY, double vZ, double spin) :
	Particle(9.109E-31, -1.602E-19, spin, PosX, PosY, PosZ), m_number(m_nbElectrons) {
	m_speedX = vX;
	m_speedY = vY;
	m_speedZ = vZ;

	std::cout<<"Creation of electron no "<< m_nbElectrons<<std::endl;
	m_nbElectrons++;
}

unsigned int Electron::m_nbElectrons { 0 };


Electron::~Electron() {
}



unsigned int Electron::getNumber() const {return m_number;}

std::string Electron::toString() const {
	//Description
	std::ostringstream streamObj;
	streamObj<< "\tElectron nb " + std::to_string(m_number) +
		" : mass=" <<m_mass<< "kg ; charge="<<m_charge<<"C ; spin="<<m_spin;
	return Particle::toString()+'\n'+streamObj.str();
}

