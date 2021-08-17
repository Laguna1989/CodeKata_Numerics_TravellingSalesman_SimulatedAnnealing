# Overview

This is a Code Nummy about the travelling salesman problem and the Simulated Annealing solution approach.

**Note**: For this Nummy It is highly recommended that you already solved
the [greedy solution](https://github.com/Laguna1989/CodeKata_Numerics_TravellingSalesman_Greedy). While this Nummy is
quite short, it relies on the already existing functionality from the greedy solution.

Please check out the other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

# Theory

## The Travelling Salesman problem

The Travelling Salesman Problem describes a salesman who wants to visit `N` cities. He must visit all the cities exactly
once and is looking for the shortest total travelling distance.

The Travelling Salesman Problem is a popular example for a certain class of optimization problems (so-called NP-hard
problems). There are many ways to find a good (though not necessarily optimal) solution.

Details:

* The cities are uniformly distributed on a two-dimensional euclidean plane with x,y in the range `[0,1]`.
* Travel time between two cities is equal to the distance between the two cities.
* There are special versions, in which the salesman has to end at the starting city, but for this Nummy this can be
  omitted.

## The Simulated Annealing Solution

The Greedy algorithm discussed previously results in reasonably good solutions. However, it will always end up in a
local minimum, which is most likely not the global minimum of the system.

Simulated annealing is based on a modified Monte Carlo algorithm.It uses an idea from materials science: An alloy is
cooled down slowly from a high temperature, and - during the cooling process - can heal possible defects. At the
beginning of the algorithm, the high temperature will allow for big changes in the system. I later stages, only
increasingly favourable changes are accepted.

Every Monte Carlo step consists of the following operations:

* Try to swap two random (not necessarily adjacent) cities in the path
* Check if the new total path length L1 after swapping is shorter than the previous path length L0
* If so, accept the swap as your new (improved) path.
* Otherwise
    * Calculate `LDiff = L1 - L0`
    * Calculate the exponent `exponent = -LDiff/T` where `T` is the current "temperature" of the system (T is roughly
      corresponding to the largest increase in length that is likely to be accepted by the swap)
    * Calculate the acceptance probability: `probability = exp(exponent)`
    * Draw a uniformly distributed random number `r`
    * If `r < probability`, accept the change (although it resembles an increase in total length)
    * Otherwise, discard the change and continue with the old path
* Decrease temperature `T`
* If temperature is below `1e-4`, assume that the path is sufficiently optimized and stop the annealing process.

# Exercise

Write your implementation in the file `src/simulated_annealing`.

* First Implement the Simulated Annealing solution for a Temperature of 0. This means that swaps which will increase the
  length are always rejected. Thus, only swaps that will decrease the length are allowed.
* Do some statistical sampling over 25 random configuration for N=3, 5, 10, 20, 50, 100 cities. Compare the random
  solution with the greedy algorithm and the "simulated annealing" solution.
* Now implement the cooling of the system. Start with `T0 = 1`. Decrease the temperature with `T1 = T0 × (0.999)^(1/N)`.
* For one run with 100 cities, print a file which contains T and the current path length for every 1000s Monte Carlo
  step.
* Compare the average path length produced by the simulated annealing solution with the greedy solution for 25 random
  configurations for N=3, 5, 10, 20, 50, 100 cities.  **Note**: This calculation will take some time, so make sure
  to build in release mode and to grab a cup of coffee.

# Brainteaser questions

* What happens when you cool down too rapidly, e.g. with `T1 = T0 × (0.5)^(1/N)`?
* Why is it important to make the cooling rate dependent on the number of cities?

# References

* [Travelling Salesman (wikipedia)](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
