#include <iostream>
#include <memory>
#include <random>
#include <typeinfo>
#include <sstream>
#include <fstream>
#include <vector>

#include "main.h"
#include "./Particles/Particle.h"
#include "./Particles/Electron.h"
#include "./Particles/Proton.h"
#include "./Tools/ProgressBar.h"

int main(){
	std::random_device rd {};
	int nbElectrons { 4 };
	int nbProtons { 4 };
	
	
	std::ofstream outputFile("datas.txt", std::ofstream::out|std::ofstream::trunc);


	if (outputFile) {

		//std::cout<<"How many electrons ?" ;
		//std::cin>>nbElectrons;
		//std::cout<<"How many protons ?";
		//std::cin>>nbProtons;


		Time time = Time{0.0, 1.0, 1.0E-3};

		std::vector<std::shared_ptr<Particle>> particles;

		ProgressBar barCreation{0, static_cast<double>(nbElectrons+nbProtons), 100, true, true};
		barCreation.init();

		/*****CREATE PARTICLES*****/
		for (int i { 0 }; i<nbElectrons; i++) {
			//Random coordinates
			double nbAleaX { (rd()%10000) /10000.0 -0.5};
			double nbAleaY { (rd()%10000) /10000.0 -0.5};
			double nbAleaZ { (rd()%10000) /10000.0 -0.5};

			//Add an electron
			particles.push_back(std::shared_ptr<Electron>(new Electron{nbAleaX, nbAleaY, nbAleaZ, 0.0, 0.0, 0.0}));
			barCreation.update(static_cast<double>(particles.size()), " : Creation");
		}
		for (int i { 0 }; i<nbProtons; i++) {
			double nbAleaX { (rd()%10000) /10000.0  -0.5};
			double nbAleaY {(rd()%10000) /10000.0  -0.5};
			double nbAleaZ {(rd()%10000) /10000.0  -0.5};
			particles.push_back(std::shared_ptr<Proton>(new Proton(nbAleaX, nbAleaY, nbAleaZ, 0.0, 0.0, 0.0)));
			barCreation.update(static_cast<double>(particles.size()));
		}
		barCreation.~ProgressBar();

		unsigned int nbSteps { time.getNbMeasuresTotal() };	//Gives nb of modelisation steps

		outputFile << nbSteps << '\t' << particles.size() << std::endl;	//Write simulation infos in file for later data interpreting
		outputFile<<time.getActualTime();	//Writing initial state
		for (unsigned int i {0}; i<particles.size(); i++) {
			outputFile << '\t' << particles[i]->getPos();
		}

		ProgressBar barSim{time.getInitialTime(), time.getFinalTime(), 100, true, true};
		barSim.init();
		


		/*****SIMULATION*****/
		for (unsigned int i { 0 }; i<nbSteps; i++) {
			outputFile <<time.getActualTime();
			
			
			analyse(particles, time, outputFile); //Particles behavior simulation
			
			outputFile << std::endl;	//After each time step, skip a line in file
			time.nextTime();   //Next timestep
			barSim.update(time.getActualTime()," : Simulation");

		}
		barSim.~ProgressBar();

		return 0;


	} else {	//If outputFile won't open...
		std::cerr << "Failure opening " <<std::endl;
		return -1;
	}

}



void analyse(std::vector<std::shared_ptr<Particle>> const& particles, Time time, std::ofstream& outputFile) {
	//For each particle...
	for (unsigned int i { 0 }; i<particles.size(); i++) {
		//Apply changes between THIS particle and [every particle except THIS ONE]

		for (unsigned int j { i+1 }; j<particles.size(); j++) {
			particles[i]->interaction(particles[j]);
		}

	}
	for (unsigned int i { 0 }; i<particles.size(); i++) {
		outputFile << '\t' << particles[i]->getPos();

		particles[i]->convertForceSpeed(time);  
		particles[i]->convertSpeedPosition(time);

		particles[i]->addForceX(-1*particles[i]->getForcesX());    //Reset forces by doing	gorce = force - force = 0
		particles[i]->addForceY(-1*particles[i]->getForcesY());
		particles[i]->addForceZ(-1*particles[i]->getForcesZ());


	}
}