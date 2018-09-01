#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <typeinfo>
#include <memory>

#include <vector>

#include "main.h"
#include "./Particles/Particle.h"
#include "./Particles/Electron.h"
#include "./Particles/Proton.h"

int main(){
	std::random_device rd {};
	int nbElectrons { 1 };
	int nbProtons { 1 };

	//std::cout<<"How many electrons ?" ;
	//std::cin>>nbElectrons;
	//std::cout<<"How many protons ?";
	//std::cin>>nbProtons;

	std::cout<< (rd()%10000) /10000.0 <<std::endl;

	Time time = Time(0.0, 1.0E-3, 1.0E-5);

	std::vector<std::shared_ptr<Particle>> particles;

	particles.push_back(std::shared_ptr<Electron>(new Electron {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}));
	particles.push_back(std::shared_ptr<Proton>(new Proton {1.0e-3, 1.0e-3, 0.0, 0.0, 0.0, 0.0}));


	//for (int i { 0 }; i<nbElectrons; i++) {
	//	double nbAleaX { (rd()%10000) /100.0 };
	//	double nbAleaY { (rd()%10000) /100.0 };
	//	double nbAleaZ { (rd()%10000) /100.0 };

	//	//Add an electron
	//	particles.push_back(std::shared_ptr<Electron>(new Electron{nbAleaX, nbAleaY, nbAleaZ, 0.0, 0.0, 0.0}));
	//}
	//for (int i { 0 }; i<nbProtons; i++) {
	//	double nbAleaX { (rd()%10000) /100.0 };
	//	double nbAleaY { (rd()%10000) /100.0 };
	//	double nbAleaZ { (rd()%10000) /100.0 };
	//	particles.push_back(std::shared_ptr<Proton>(new Proton(nbAleaX, nbAleaY, nbAleaZ, 0.0, 0.0, 0.0)));
	//}
	

	//Gives nb of modelisation steps : nbMeasuresTotal = (finalTime - initialTime)/deltaTime
	unsigned int nbSteps { time.getNbMeasuresTotal() };

	for (unsigned int i { 0 }; i<nbSteps; i++) {
		time.nextTime();   //Next timestep
		analyse(particles, time); //Particles behavior simulation
		std::cout<<""<<std::endl;
	}
	return 0;
}




void analyse(std::vector<std::shared_ptr<Particle>> const& particles, Time time) {
	//For each particle...
	for (unsigned int i { 0 }; i<particles.size(); i++) {
		//Apply changes between THIS particle and [every particle except THIS ONE]

		//Apply changes on objectA with objectB on [0 ; objectA[
		for (unsigned int j { 0 }; j<i; j++) {
			particles[i]->interaction(particles[j]);
		}

		//Apply changes on objectA with objectB on ]obectA ; end]
		for (unsigned int j { i+1 }; j<particles.size(); j++) {
			particles[i]->interaction(particles[j]);
		}

	}
	for (unsigned int i { 0 }; i<particles.size(); i++) {
		std::cout<<"Datas at "<<std::to_string(i) << " : " << particles[i]->toString()<<std::endl;    //Debug
		particles[i]->convertForceSpeed(time);  
		particles[i]->convertSpeedPosition(time);

		particles[i]->addForceX(-1*particles[i]->getForcesX());    //Reset forces by doing	gorce = force - force = 0
		particles[i]->addForceY(-1*particles[i]->getForcesY());
		particles[i]->addForceZ(-1*particles[i]->getForcesZ());
		std::cout<<"Datas at "<<std::to_string(i) << " : " << particles[i]->toString()<<std::endl;    //Debug
	}
}