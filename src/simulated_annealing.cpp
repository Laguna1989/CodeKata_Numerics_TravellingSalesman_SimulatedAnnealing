#include "simulated_annealing.hpp"
#include "calculate_total_travel_distance.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>

std::vector<Point> simulated_annealing(std::vector<Point> const& cities, double T0, uint32_t seed)
{
    static std::default_random_engine rng { cities.size() };
    std::uniform_int_distribution<std::size_t> dist_int { 0, cities.size() - 1 };
    std::uniform_real_distribution<double> dist_real{0.0,1.0};

    double t_factor = std::pow(0.9999, 1.0/cities.size());


    double T = T0;

    std::vector<Point> optimized_cities{cities};

    while(T >= 1e-4)
    {
        // calculate old path length
        auto const L0 = calculate_total_travel_distance(optimized_cities);

        // find two cities to swap
        auto iter1 = optimized_cities.begin() + dist_int(rng);
        auto iter2 = optimized_cities.begin() + dist_int(rng);

        std::iter_swap(iter1, iter2);

        // calculate new path length
        auto const L1 = calculate_total_travel_distance(optimized_cities);

        // always accept if path is shorter
        if (L1 < L0)
        {
            continue;
        }

        // draw a random number and check if temperature allows for this swap
        double const probability = exp(-(L1 - L0) / T);
        double const r = dist_real(rng);

        // undo the change if r is bigger than probability
        if (r >= probability)
        {
            std::iter_swap(iter1, iter2);
        }

        // decrease temperature
        T *= t_factor;
    }
    return optimized_cities;
}
