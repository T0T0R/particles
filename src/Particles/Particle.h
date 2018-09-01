#pragma once

#include <memory>

#include "../Time.h"
class Particle
{
public:
	Particle();
	Particle(double mass, double charge, double spin, double posX, double posY, double posZ);
	virtual ~Particle();


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

	unsigned int getNbParticles() const;
	unsigned int getID() const;


	void addForceX(double force);
	void addForceY(double force);
	void addForceZ(double force);
	void addForces(double X, double Y, double Z);


	double distanceX(std::shared_ptr<Particle> other) const;
	double distanceY(std::shared_ptr<Particle> other) const;
	double distanceZ(std::shared_ptr<Particle> other) const;
	double distance(std::shared_ptr<Particle> other) const;

	double forceGravitationalX(std::shared_ptr<Particle> other) const;
	double forceGravitationalY(std::shared_ptr<Particle> other) const;
	double forceGravitationalZ(std::shared_ptr<Particle> other) const;
	double forceGravitational(std::shared_ptr<Particle> other) const;

	double forceCoulombX(std::shared_ptr<Particle> other) const;
	double forceCoulombY(std::shared_ptr<Particle> other) const;
	double forceCoulombZ(std::shared_ptr<Particle> other) const;
	double forceCoulomb(std::shared_ptr<Particle> other) const;

	void interaction(std::shared_ptr<Particle> other);

	void convertForceSpeed(Time const& time);
	void convertSpeedPosition(Time const& time);

	void newGamma();

	virtual std::string toString() const;

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



	const double m_mass;
	double m_charge;
	double m_spin;

	double m_posX;
	double m_posY;
	double m_posZ;

	double m_speedX;
	double m_speedY;
	double m_speedZ;
	double m_speedGlobal;

	double m_forcesX;
	double m_forcesY;
	double m_forcesZ;

	double m_gamma;	//Lorentz factor

	static unsigned int m_nbParticles;
	const unsigned int m_idParticle;
};

