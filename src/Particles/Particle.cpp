#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <cmath>

#include "../Time.h"
#include "Particle.h"


Particle::Particle():
	m_mass(0.0), m_charge(0.0), m_spin(0.0),
	m_speedX(0.0), m_speedY(0.0), m_speedZ(0.0),
	m_posX(0.0), m_posY(0.0), m_posZ(0.0),
	m_forcesX(0.0), m_forcesY(0.0), m_forcesZ(0.0),
	m_idParticle(m_nbParticles)
{
	m_nbParticles++;
}

Particle::Particle(double mass, double charge, double spin, double posX, double posY, double posZ) :
	m_mass(mass), m_charge(charge), m_spin(spin),
	m_speedX(0.0), m_speedY(0.0), m_speedZ(0.0),
	m_posX(posX), m_posY(posY), m_posZ(posZ),
	m_forcesX(0.0), m_forcesY(0.0), m_forcesZ(0.0),
	m_idParticle(m_nbParticles)
{
	m_nbParticles++;
	std::cout<<"debug **********"<<std::endl;
}

unsigned int Particle::m_nbParticles {0};


Particle::~Particle() {
}



double Particle::getPosX() const {return m_posX;}
double Particle::getPosY() const {return m_posY;}
double Particle::getPosZ() const {return m_posZ;}
double Particle::getSpeedX() const {return m_speedX;}
double Particle::getSpeedY() const {return m_speedY;}
double Particle::getSpeedZ() const {return m_speedZ;}
double Particle::getSpeedGlobal() {
	this->setSpeedGlobal(sqrt(m_speedX*m_speedX+m_speedY*m_speedY+m_speedZ*m_speedZ));   //Pythagore     V = sqrt(v_a^2+v_b^2+v_c^2)
	return m_speedGlobal;
}
double Particle::getGamma() const { return m_gamma; }
double Particle::getForcesX() const {return m_forcesX;}
double Particle::getForcesY() const {return m_forcesY;}
double Particle::getForcesZ() const {return m_forcesZ;}
double Particle::getCharge() const {return m_charge;}
double Particle::getMass() const {return m_mass;}
double Particle::getSpin() const {return m_spin;}

unsigned int Particle::getNbParticles() const {return m_nbParticles;}
unsigned int Particle::getID() const { return m_idParticle; }



void Particle::setPosX(double x) {m_posX = x;}
void Particle::setPosY(double y) {m_posY = y;}
void Particle::setPosZ(double z) {m_posZ = z;}
void Particle::setPos(double x, double y, double z) {
	m_posX = x;
	m_posY = y;
	m_posZ = z;
}
void Particle::setSpeedX(double speedX) {m_speedX = speedX;}
void Particle::setSpeedY(double speedY) {m_speedY = speedY;}
void Particle::setSpeedZ(double speedZ) {m_speedZ = speedZ;}
void Particle::setSpeed(double speedX, double speedY, double speedZ) {
	m_speedX = speedX;
	m_speedY = speedY;
	m_speedZ = speedZ;
}
void Particle::setSpeedGlobal(double speed) {m_speedGlobal = speed;}
void Particle::setGamma(double g) {m_gamma = g;}
void Particle::setSpin(float spin) {m_spin = spin;}

void Particle::addForceX(double force) {m_forcesX += force;}
void Particle::addForceY(double force) {m_forcesY += force;}
void Particle::addForceZ(double force) {m_forcesZ += force;}
void Particle::addForces(double X, double Y, double Z) {
	m_forcesX += X;
	m_forcesY += Y;
	m_forcesZ += Z;
}



/******METHODES******/


double Particle::distanceX(std::shared_ptr<Particle> other) const {
	//Returns the distance deltaX with another particle
	return m_posX - other->getPosX();
}
double Particle::distanceY(std::shared_ptr<Particle> other) const {
	return m_posY - other->getPosY();
}
double Particle::distanceZ(std::shared_ptr<Particle> other) const {
	return m_posZ - other->getPosZ();
}
double Particle::distance(std::shared_ptr<Particle> other) const {
	//Returns the distance in space with another particle
	double deltaX { m_posX - other->getPosX() };
	double deltaY { m_posY - other->getPosY() };
	double deltaZ { m_posZ - other->getPosZ() };
	return sqrt(deltaX*deltaX+deltaY*deltaY+deltaZ*deltaZ);
}


double Particle::forceGravitationalX(std::shared_ptr<Particle> other) const {
	//Computes the gravitational force between two particles along X-axis.
	// Fx = G*(mA*mB)*(Bx-Ax) / ((Bx-Ax)^2+(By-Ay)^2+(Bz-Az)^2)^(3/2)
	const double constGravitation { 6.67384e-11 };
	return ((constGravitation * m_mass*other->getMass() * distanceX(other)) / pow(distance(other), 3));
}
double Particle::forceGravitationalY(std::shared_ptr<Particle> other) const {
	const double constGravitation {6.67384e-11};
	return ((constGravitation * m_mass*other->getMass() * distanceY(other)) / pow(distance(other), 3));
}
double Particle::forceGravitationalZ(std::shared_ptr<Particle> other) const {
	const double constGravitation {6.67384e-11};
	return ((constGravitation * m_mass*other->getMass() * distanceZ(other)) / pow(distance(other), 3));
}
double Particle::forceGravitational(std::shared_ptr<Particle> other) const {
	//Computes the gravitational force between two particles
	// F = G*(mA*mB)/d^2
	const double constGravitation {6.67384e-11};
	return ((constGravitation * m_mass * other->getMass()) / pow(distance(other),2));
}


double Particle::forceCoulombX(std::shared_ptr<Particle> other) const {
	//Computes the electostatic force between two particles along X-axis.
	// Fx = k*(qA*qB)*(Bx-Ax) / ((Bx-Ax)^2+(By-Ay)^2+(Bz-Az)^2)^(3/2)
	const double kCoulomb { 8.9875517873681764e9 };
	return ((kCoulomb * m_charge*other->getCharge() * distanceX(other)) / pow(distance(other), 3));
	// +A -> Repulsion;   -A -> Attraction
}
double Particle::forceCoulombY(std::shared_ptr<Particle> other) const {
	const double kCoulomb {8.9875517873681764e9};
	return ((kCoulomb * m_charge*other->getCharge() * distanceY(other)) / pow(distance(other), 3));
}
double Particle::forceCoulombZ(std::shared_ptr<Particle> other) const {
	const double kCoulomb {8.9875517873681764e9};
	return ((kCoulomb * m_charge*other->getCharge() * distanceZ(other)) / pow(distance(other), 3));
}
double Particle::forceCoulomb(std::shared_ptr<Particle> other) const {
	//Computes the electrostatic force between two particles
	// F = k*(qA*qB)/d^2
	const double kCoulomb {8.9875517873681764e9};
	return ((kCoulomb * m_charge * other->getCharge()) / pow(distance(other),2));
}



void Particle::interaction(std::shared_ptr<Particle> other) {
	//Computes and apply the different interactions.
	addForces(forceCoulombX(other)-forceGravitationalX(other),
			  forceCoulombY(other)-forceGravitationalY(other),
			  forceCoulombZ(other)-forceGravitationalZ(other));
}

void Particle::convertForceSpeed(Time const& time) {
	//Euler method
	m_speedX = ((time.getActualTime()-time.getPreviousTime())*m_forcesX/m_mass)+m_speedX;
	m_speedY = ((time.getActualTime()-time.getPreviousTime())*m_forcesY/m_mass)+m_speedY;
	m_speedZ = ((time.getActualTime()-time.getPreviousTime())*m_forcesZ/m_mass)+m_speedZ;
}

void Particle::convertSpeedPosition(Time const& time) {
	//Euler again...
	m_posX += (time.getActualTime()-time.getPreviousTime())*m_speedX;
	m_posY += (time.getActualTime()-time.getPreviousTime())*m_speedY;
	m_posZ += (time.getActualTime()-time.getPreviousTime())*m_speedZ;
}



void Particle::newGamma() {
	//Change mass according to speed
	setGamma(1/(sqrt(1-(pow(getSpeedGlobal()/299792458.0 , 2)))));
}

std::string Particle::toString() const {
	//Description
	std::ostringstream streamObj;
	//Add double to stream
	streamObj <<"Particle nb "+std::to_string(m_idParticle)+
		" : position("  <<m_posX<< ", " << m_posY<< ", " << m_posZ<<
		"), speed(" << m_speedX <<", " <<m_speedY<< ", "<<m_speedZ<<
		"), force(" <<m_forcesX<< ", " << m_forcesY<< ", " << m_forcesZ<<");";

	// Get string from output string stream
	return streamObj.str();
}
