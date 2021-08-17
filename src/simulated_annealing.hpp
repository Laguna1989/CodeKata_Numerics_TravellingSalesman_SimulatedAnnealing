#ifndef CODE_KATA_SIMULATED_ANNEALING_HPP
#define CODE_KATA_SIMULATED_ANNEALING_HPP

#include <vector>
#include "point.hpp"

std::vector<Point> simulated_annealing(std::vector<Point> const& cities, double T0, uint32_t seed = 1);

#endif // CODE_KATA_SIMULATED_ANNEALING_HPP
