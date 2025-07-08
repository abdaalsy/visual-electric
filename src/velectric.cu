#include <cuda_runtime.h>
#include <iostream>
#include "include/velectric.hpp"

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

