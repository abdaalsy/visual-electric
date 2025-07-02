#include "..\include\velectric.hpp"

PointCharge::PointCharge(double mass, double charge, Eigen::Vector2d pos, Eigen::Vector2d vel, Eigen::Vector2d accel)
    : q(charge), m(mass), p0(pos), v0(vel), a0(accel) {
        if (mass < 0) {
            mass = -1 * mass;
        }
}

std::ostream &operator<<(std::ostream &out, const PointCharge &rhs) {
    out << "Mass: " << rhs.getM() << " kg" << std::endl;
    out << "Charge: " << rhs.getQ() << " C" << std::endl;
    out << "Initial Position: (" << rhs.getPosition0().x() << ", " << rhs.getPosition0().y() << ")" << std::endl;
    out << "Initial Velocity: (" << rhs.getVelocity0()[0] << ", " << rhs.getVelocity0()[1] << ")" << std::endl;
    out << "Initial Acceleration: (" << rhs.getAccel0()[0] << ", " << rhs.getAccel0()[1] << ")" << std::endl;
    return out;
}

// write function for computing coulomb's force from another PointCharge, maybe turn this into an operator
// write function for string representation
// write function for computing electric field on every point in space (use parallel processing)