#include <cuda_runtime.h>
#include <iostream>
#include "include/velectric.hpp"

#define K 8.99E9

__device__ inline double square(double x) {
    return x * x;
}

__device__ inline double magnitude(std::array<double, 2> v) {
    return sqrt(square(v[0]) + square(v[1]));
}

__device__ inline std::array<double, 2> unitVector(std::array<double, 2> v) {
    return {v[0]/magnitude(v), v[1]/magnitude(v)};
}

__device__ inline std::array<double, 2> electricField(double charge, std::array<double, 2> r) {
    std::array<double, 2> eField = {0, 0};
    double magn = magnitude(r);
    std::array<double, 2> unitR = unitVector(r);
    eField[0] = (K * charge / square(magn)) * unitR[0];
    eField[1] = (K * charge / square(magn)) * unitR[1];
    return eField;
}

void Scene::compute() {
    // variable for current positions of charges, set to intial value
    // variable for current vel
    // variable for current accel
    // above variables must be in scene space with integer coordinates
    // For each timestep:
    //      Compute electric field due to each point charge at their position (cuda)
    //      add individual electric fields  (cuda)
    //      for each charge (cuda):
    //              determine acceleration using field, charge, mass
    //              determine velocity using previous velocity, previous acceleration, previous position, and time differential
    //              determine position using previous velocity, previous acceleration, previous position, and time differential
    //              update all variables and additionally add to positions list.
}

__global__ void addFields(std::array<double, 2>* sum, std::array<double, 2>* field1, std::array<double, 2>* field2) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;  // i is guaranteed to be between 0 and the capacity due to the threads we allocate
    sum[i][0] = field1[i][0] + field2[i][0];
    sum[i][1] = field1[i][1] + field2[i][1];
}

__global__ void computeField(std::array<double, 2>* field, std::array<size_t, 2> position) {

}

