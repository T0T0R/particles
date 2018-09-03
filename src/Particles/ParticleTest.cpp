#include "ParticleTest.h"



ParticleTest::ParticleTest():
	Particle(9.2e-31, 1e-19, 0.0, 0.0, 0.0, 0.0) {

}

ParticleTest::ParticleTest(double PosX, double PosY, double PosZ) :
	Particle(9.2e-31, 1e-19, 0.0, PosX, PosY, PosZ) {
}


ParticleTest::~ParticleTest() {
}
