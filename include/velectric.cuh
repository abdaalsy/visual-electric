#include <cuda_runtime.h>
#include <velectric.hpp>

__host__ __device__ inline double square(double);
__device__ inline Vec2 electricField(double, Vec2);
__global__ void addFields(Vec2*, Vec2*, Vec2*);
__global__ void computeField(Vec2*, Vec2, double, size_t, size_t, size_t, size_t, size_t);