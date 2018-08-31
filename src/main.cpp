#include <iostream>
#include <ctime>
#include <cstdlib>

#include <vector>

#include "main.h"
#include "./Particle/Particle.h"
#include "./Particle/Electron.h"
#include "./Particle/Proton.h"

int main(){
	std::srand(static_cast<unsigned int>(std::time(0)));
	int nbElectrons { 1000 };
	int nbProtons { 1000 };

	//std::cout<<"How many electrons ?" ;
	//std::cin>>nbElectrons;
	//std::cout<<"How many protons ?";
	//std::cin>>nbProtons;

	Time time = Time(0.0, 1.0E-3, 1.0E-5);

	std::vector<Particle> particles(nbElectrons + nbProtons);

	for (int i { 0 }; i<nbElectrons-1; i++) {
		double nbAleaX { 0.01*(std::rand()%100) };
		double nbAleaY { 0.01*(std::rand()%100) };
		double nbAleaZ { 0.01*(std::rand()%100) };

		//Add an electron
		particles.push_back(Electron(nbAleaX, nbAleaY, nbAleaZ, 0.0, 0.0, 0.0));
	}
	for (int i { 0 }; i<nbProtons-1; i++) {
		double nbAleaX { 0.01*(std::rand()%100) };
		double nbAleaY { 0.01*(std::rand()%100) };
		double nbAleaZ { 0.01*(std::rand()%100) };

		//Add a proton
		particles.push_back(Proton(nbAleaX, nbAleaY, nbAleaZ, 0.0, 0.0, 0.0));
	}
	

	//Gives nb of modelisation steps : nbMeasuresTotal = (finalTime - initialTime)/deltaTime
	unsigned int nbSteps { time.getNbMeasuresTotal() };

	for (unsigned int i { 0 }; i<nbSteps; i++) {
		time.nextTime();   //Etape suivante
		analyse(particles, time); //Particles behavior simulation
		std::cout<<""<<std::endl;
	}
	return 0;
}

void analyse(std::vector<Particle> particles, Time time) {

	//For each particle...
	for (unsigned int i { 0 }; i<particles.size(); i++) {
		//Apply changes between THIS particle and [every particle except THIS ONE]

		//Apply changes on objectA with objectB on [0 ; objectA[
		for (unsigned int j { 0 }; j<i; j++) {
			particles[i].interaction(particles[j]);
		}

		//Apply changes on objectA with objectB on ]obectA ; end]
		for (unsigned int j { i+1 }; j<particles.size(); j++) {
			particles[i].interaction(particles[j]);
		}

	}

	for (unsigned int i { 0 }; i<particles.size(); i++) {
		//std::cout<<"Datas at "<<std::to_string(i) << " : " << particles[i].toString()<<std::endl;    //Debug
		particles[i].convertForceSpeed(time);    //Le total des forces calcule plus haut est transforme en vitesse
		particles[i].convertSpeedPosition(time);     //La vitesse des particules est maintenant covertie en position

		particles[i].addForceX(-1*particles[i].getForcesX());    //Reset des forces en faisant     force = force - force = 0
		particles[i].addForceY(-1*particles[i].getForcesY());
		particles[i].addForceZ(-1*particles[i].getForcesZ());
		//std::cout<<"Datas at "<<std::to_string(i) << " : " << particles[i].toString()<<std::endl;    //Debug
	}
}