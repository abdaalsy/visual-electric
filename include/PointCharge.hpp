#include <array>

#ifndef CHARGE_H
#define CHARGE_H

class PointCharge {
    private:
        const double q;
        const double m;
        const std::array<double, 2> p0;
        const std::array<double, 2> v0;
        const std::array<double, 2> a0;
    public:
        double getQ() const {return q;}
        double getM() const {return m;}
        std::array<double, 2> getPosition0() const {return p0;}
        std::array<double, 2> getVelocity0() const {return v0;}
        std::array<double, 2> getAccel0() const {return a0;}
};

#endif