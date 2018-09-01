#pragma once

#include <memory>

class Time
{
public:
	Time();
	Time(double iTime, double fTime, double delta);
	~Time();

	double getInitialTime() const;
	double getPreviousTime() const;
	double getActualTime() const;
	double getFinalTime() const;
	double getDeltaTime() const;
	unsigned int getNbMeasuresTotal() const;
	unsigned int getNbMeasuresActual() const;

	void setPreviousTime(double const tempsP);
	void setActualTime(double const tempsA);

	double nextTime();

protected:
	double m_initialTime;
	double m_previousTime;
	double m_actualTime;
	double m_deltaTime; //Intervalle de temps
	double m_finalTime; //Fin de la mesure

	const unsigned int m_nbMeasuresTotal;
	unsigned int m_nbMeasuresActual;
};

