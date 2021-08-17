#include "create_cities.hpp"
#include <random>

std::vector<Point> create_cities(std::size_t N, uint32_t seed)
{
    std::uniform_real_distribution<double> dist { 0.0, 1.0 };
    std::default_random_engine rng { seed };

    std::vector<Point> cities {};
    for (auto i = 0U; i != N; ++i) {
        cities.push_back(Point { dist(rng), dist(rng) });
    }

    return cities;
}
