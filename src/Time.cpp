#include <iostream>
#include <memory>
#include <sstream>

#include "Time.h"



Time::Time():
	m_initialTime(0.0), m_finalTime(1.0), m_deltaTime(1.0E-1), m_actualTime(0.0),
	m_nbMeasuresTotal(static_cast<unsigned int>((m_finalTime - m_initialTime)/m_deltaTime))
{
	std::cout<<"Creation of a time object : initial = " << m_initialTime << " s, final = "<< m_finalTime <<" s, step = " << m_deltaTime << " s. Nb measures : " << m_nbMeasuresTotal<<std::endl;
}

Time::Time(double iTime, double fTime, double delta) :
	m_initialTime(iTime), m_finalTime(fTime), m_deltaTime(delta), m_actualTime(0.0),
	m_nbMeasuresTotal(static_cast<unsigned int>((m_finalTime - m_initialTime)/m_deltaTime))
{
	std::cout<<"Creation of a time object : initial = " << m_initialTime << " s, final = "<< m_finalTime <<" s, step = " << m_deltaTime << " s. Nb measures : " << m_nbMeasuresTotal<<std::endl;
}


Time::~Time() {
}


double Time::getInitialTime() const {return m_initialTime;}
double Time::getPreviousTime() const {return m_previousTime;}
double Time::getActualTime() const {return m_actualTime;}
double Time::getFinalTime() const {return m_finalTime;}
double Time::getDeltaTime() const {return m_deltaTime;}
unsigned int Time::getNbMeasuresTotal() const {return m_nbMeasuresTotal;}
unsigned int Time::getNbMeasuresActual() const {return m_nbMeasuresActual;}



void Time::setPreviousTime(double const timeP) {m_previousTime = timeP;}
void Time::setActualTime(double const timeA) {m_actualTime = timeA;}



double Time::nextTime() {
	//One time step ahead
	setPreviousTime(m_actualTime);
	setActualTime(m_actualTime + m_deltaTime);

	std::ostringstream streamObj;
	streamObj<<"New time ! : "<< m_actualTime<< " s \t -> "<< 100*(m_actualTime/m_finalTime) << "%";
	std::cout<<streamObj.str()<<std::endl;
	m_nbMeasuresActual++;
	return m_actualTime;
}

