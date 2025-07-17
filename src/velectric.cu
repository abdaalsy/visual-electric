#include <cuda_runtime.h>
#include <iostream>
#include "include/velectric.hpp"

#define K 8.99E9

__host__ __device__ inline double square(double x) {
    return x * x;
}

__host__ __device__ inline double Vec2::magnitude() const {
    return sqrt(square(this->x) + square(this->y));
}

__host__ __device__ inline Vec2 Vec2::unitVector() const {
    const double mag = this->magnitude();
    return {this->x/mag, this->y/mag};
}

__device__ inline Vec2 electricField(double charge, Vec2 r) {
    Vec2 eField = {0, 0};
    const double magn = r.magnitude();
    Vec2 unitR = r.unitVector();
    eField.x = (K * charge / square(magn)) * unitR.x;
    eField.y = (K * charge / square(magn)) * unitR.y;
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

__global__ void addFields(Vec2* sum, Vec2* field1, Vec2* field2) {
    const int i = threadIdx.x + blockIdx.x * blockDim.x;  // i is guaranteed to be between 0 and the capacity due to the threads we allocate
    sum[i].x = field1[i].x + field2[i].x;
    sum[i].y = field1[i].y + field2[i].y;
}

__global__ void computeField(Vec2* field, Vec2 pos, double rows, double cols, Vec2 bottomRight, Vec2 bottomLeft, double charge) {
    /* charge is at row pos[0], column pos[1]. */
    
}

