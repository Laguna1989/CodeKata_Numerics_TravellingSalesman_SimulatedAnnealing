#include "calculate_distance.hpp"
#include <cmath>

double calculate_distance(Point const& a, Point const& b)
{
    double const dx = a.x - b.x;
    double const dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}
