#include "ParticleTest.h"



ParticleTest::ParticleTest():
	Particle(0.0, -1.602E-19, 0.0, 0.0, 0.0, 0.0) {

}

ParticleTest::ParticleTest(double PosX, double PosY, double PosZ) :
	Particle(0.0, -1.602E-19, 0.0, PosX, PosY, PosZ) {
}


ParticleTest::~ParticleTest() {
}
