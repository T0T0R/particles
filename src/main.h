#pragma once

#include <memory>
#include <vector>

#include "Time.h"
#include "./Particles/Particle.h"

 void analyse(std::vector<std::shared_ptr<Particle>> const& particles, Time time, std::ofstream& outputFile);