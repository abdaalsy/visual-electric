#include <cuda_runtime.h>
#include <iostream>
#include <velectric.hpp>
#include <velectric.cuh>

#define K 8.99E9

__host__ __device__ inline double square(double x) {
    return x * x;
}

// Vec2
__device__ __host__ Vec2 Vec2::operator*(double a) const {
    return {x * a, y * a};
}

__device__ __host__ Vec2 Vec2::operator+(const Vec2 &other) const {
    return {x + other.x, y + other.y};
}

__device__ __host__ Vec2 Vec2::operator-(const Vec2 &final) const {
    return {*this + (final)*(-1)};
}

__device__ __host__ void Vec2::operator*=(double a){
    *this = *this * a;
}

__host__ __device__ inline double Vec2::magnitude() const {
    return sqrt(square(this->x) + square(this->y));
}

__host__ __device__ inline Vec2 Vec2::unitVector() const {
    const double mag = this->magnitude();
    return {this->x/mag, this->y/mag};
}
// Vec2

__device__ inline Vec2 electricField(double charge, Vec2 r) {
    Vec2 eField = {0, 0};
    const double magn = r.magnitude();
    Vec2 unitR = r.unitVector();
    eField.x = (K * charge / magn*magn) * unitR.x;
    eField.y = (K * charge / magn*magn) * unitR.y;
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

__global__ void computeField(Vec2* &field, Vec2 bottomLeft, double charge, size_t chargeRow, size_t chargeCol, double dx, size_t length, size_t rows) {
    // computes the electric field at every point in scene space, but stores those values in real space
    const size_t rowLen = length/rows;
    const size_t i = threadIdx.x + blockIdx.x * blockDim.x;
    // don't do anything if at the same point as the field
    if (i == rowLen*(chargeRow)+chargeCol) {
        return;
    }
    const size_t row = i/rowLen;
    const size_t col = i%rowLen;
    Vec2 op = {bottomLeft.x + col*dx, bottomLeft.y + row*dx};
    Vec2 oq = {bottomLeft.x + chargeCol*dx, bottomLeft.y + chargeRow*dx};
    field[i] = electricField(charge, op - oq);
}

