#include "calculate_total_travel_distance.hpp"
#include "create_cities.hpp"
#include "simulated_annealing.hpp"
#include <gtest/gtest.h>
#include <iterator>

TEST(StatisticsTest, SimulatedAnnealingSingleRun)
{
    auto const number_of_cities = 100;

    auto const cities = create_cities(number_of_cities);
    auto const optimized_cities = simulated_annealing(cities, 1.0);
    double const path_length_sum = calculate_total_travel_distance(optimized_cities);

    std::cout << number_of_cities << " " << path_length_sum << std::endl;
}

// long running test, enable only if needed
TEST(StatisticsTest, DISABLED_SimulatedAnnealingAveragePath)
{
    std::vector<std::size_t> const city_sizes { 3, 5, 10, 20, 50, 100 };
    std::size_t number_of_samples = 25;

    for (auto const number_of_cities : city_sizes) {
        double path_length_sum = 0.0;
        for (auto i = 0U; i != number_of_samples; ++i) {
            auto const cities = create_cities(number_of_cities, number_of_cities + i);
            auto const optimized_cities = simulated_annealing(cities, 1.0, number_of_cities + i);
            path_length_sum += calculate_total_travel_distance(optimized_cities);
        }
        std::cout << number_of_cities << " " << path_length_sum / number_of_samples << std::endl;
    }
}
