#pragma once
#include <array>
#include <iostream>

class PointCharge {
    private:
        const double q;
        const double m;
        const std::array<double, 2> p0;
        const std::array<double, 2> v0;
        const std::array<double, 2> a0;
    public:
        PointCharge(double, double, std::array<double, 2>, std::array<double, 2>, std::array<double, 2>);
        double getQ() const {return q;}
        double getM() const {return m;}
        std::array<double, 2> getPosition0() const {return p0;}
        std::array<double, 2> getVelocity0() const {return v0;}
        std::array<double, 2> getAccel0() const {return a0;}
        
    
    friend std::ostream &operator<<(std::ostream&, const PointCharge&);
};

// TODO: write function for computing coulomb's force from another PointCharge, maybe turn this into an operator
// TODO: write function for string representation
// TODO: write function for computing electric field on every point in space (use parallel processing)