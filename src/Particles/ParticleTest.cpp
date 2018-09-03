#include "ParticleTest.h"



ParticleTest::ParticleTest():
	Particle(9.109E-31, 0.0, 0.0, 0.0, 0.0, 0.0) {

}

ParticleTest::ParticleTest(double PosX, double PosY, double PosZ) :
	Particle(9.109E-31, 0.0, 0.0, PosX, PosY, PosZ) {
}


ParticleTest::~ParticleTest() {
}
