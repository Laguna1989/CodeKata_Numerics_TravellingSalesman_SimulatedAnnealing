#include "greedy_algorithm.hpp"
#include "calculate_distance.hpp"
#include "calculate_total_travel_distance.hpp"
#include "create_cities.hpp"

template <typename T>
void remove_at(std::vector<T>& v, typename std::vector<T>::size_type n)
{
    std::swap(v[n], v.back());
    v.pop_back();
}
std::vector<Point> greedy(std::vector<Point> const& cities)
{
    if (cities.size() <= 2) {
        return cities;
    }

    std::vector<Point> remaining_cities { cities };

    std::vector<Point> optimized_path { cities.at(0) };
    remove_at(remaining_cities, 0);

    while (!remaining_cities.empty()) {
        auto const current_city = optimized_path.back();
        size_t best_match_index { 0U };
        double distance = 99999.0;
        for (auto i = 0U; i != remaining_cities.size(); ++i) {
            auto test_city = remaining_cities.at(i);
            double actual_distance = calculate_distance(current_city, test_city);
            if (actual_distance < distance) {
                best_match_index = i;
                distance = actual_distance;
            }
        }
        optimized_path.emplace_back(remaining_cities.at(best_match_index));
        remove_at(remaining_cities, best_match_index);
    }
    return optimized_path;
}
