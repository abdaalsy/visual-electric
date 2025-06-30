#include <array>

#include "..\include\PointCharge.hpp"

PointCharge::PointCharge(double mass, double charge, std::array<double, 2> pos, std::array<double, 2> vel, std::array<double, 2> accel)
    : q(charge), m(mass), p0(pos), v0(vel), a0(accel) {
        if (mass < 0) {
            mass = -1 * mass;
        }
}