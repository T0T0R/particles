#pragma once

#include "../Time.h"
class Particle
{
public:
	Particle();
	Particle(double mass, double charge, double posX, double posY, double posZ);
	~Particle();


	double getPosX() const;
	double getPosY() const;
	double getPosZ() const;

	double getSpeedX() const;
	double getSpeedY() const;
	double getSpeedZ() const;
	double getSpeedGlobal();
	double getGamma() const;

	double getForcesX() const;
	double getForcesY() const;
	double getForcesZ() const;

	double getCharge() const;
	double getMass() const;
	double getSpin() const;

	void addForceX(double force);
	void addForceY(double force);
	void addForceZ(double force);
	void addForces(double X, double Y, double Z);


	double distanceX(Particle const& other) const;
	double distanceY(Particle const& other) const;
	double distanceZ(Particle const& other) const;
	double distance(Particle const& other) const;

	double forceGravitationalX(Particle const& other) const;
	double forceGravitationalY(Particle const& other) const;
	double forceGravitationalZ(Particle const& other) const;
	double forceGravitational(Particle const& other) const;

	double forceCoulombX(Particle const& other) const;
	double forceCoulombY(Particle const& other) const;
	double forceCoulombZ(Particle const& other) const;
	double forceCoulomb(Particle const& other) const;

	void interaction(Particle const& other);

	void convertForceSpeed(Time const& time);
	void convertSpeedPosition(Time const& time);

	void newGamma();

	std::string toString() const;

protected:
	void setPosX(double x);
	void setPosY(double y);
	void setPosZ(double z);
	void setPos(double x, double y, double z);

	void setSpeedX(double speedX);
	void setSpeedY(double speedY);
	void setSpeedZ(double speedZ);
	void setSpeed(double speedX, double speedY, double speedZ);
	void setSpeedGlobal(double speed);
	void setGamma(double g);

	void setSpin(float spin);



	double m_posX;
	double m_posY;
	double m_posZ;

	double m_forcesX;
	double m_forcesY;
	double m_forcesZ;

	double m_speedX;
	double m_speedY;
	double m_speedZ;
	double m_speedGlobal;

	double m_gamma;	//Relativistic factor

	const double m_mass;
	double m_charge;
	float m_spin;
};

