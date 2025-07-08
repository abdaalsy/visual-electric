#pragma once
#include <array>
#include <iostream>
#include "../libs/Eigen/Dense"   

template <typename T>
std::ostream &operator<<(std::ostream& out, std::vector<T> rhs) {
    out << "[";
    out << rhs[0];
    for (size_t i=1; i < rhs.size(); i++)
    {
        out << ", ";
        out << rhs[i];
    }
    out << "]";
    return out;
}

class PointCharge {
    private:
        const double q;
        const double m;
        const std::array<double, 2> p0;
        const std::array<double, 2> v0;
        const std::array<double, 2> a0;
    public:
        PointCharge(double, double, std::array<double, 2>, std::array<double, 2>, std::array<double, 2>); // std::array<double, 2>, std::array<double, 2>, std::array<double, 2>);
        double getQ() const {return q;}
        double getM() const {return m;}
        std::array<double, 2> getPosition0() const {return p0;}
        std::array<double, 2> getVelocity0() const {return v0;}
        std::array<double, 2> getAccel0() const {return a0;}
    
    friend std::ostream &operator<<(std::ostream&, const PointCharge&);
};

struct Scene {
    private:
        static const size_t numTimesteps = 10;
    public:
        Scene(std::array<double, 2>, std::array<double, 2>, double, double);    // minimum constructor
        const std::array<double, 2> bottomLeft;
        const std::array<double, 2> topRight;
        const double deltaX;
        std::vector<double> timesteps;                    // list of time values                    
        std::vector<PointCharge> charges;                 // list of charges
        std::array<std::vector<std::array<double, 2>>, numTimesteps> positions; // positions of each charge in real space, will be filled as scene is computed
        std::array<std::vector<std::vector<std::array<double, 2>>>, numTimesteps> vectorFields;

        void addCharge(PointCharge);
        static std::vector<double> getTimesteps(double);
        static std::vector<std::vector<std::array<double, 2>>> zeroVectorField(std::array<double, 2>, std::array<double, 2>, double);  // generate a field of zero vectors
        static std::vector<std::vector<double>> Scene::zeroScalarField(std::array<double, 2>, std::array<double, 2>, double);
        static void flatten(std::array<double, 2>*, std::vector<std::vector<std::array<double, 2>>>);                              // flatten to 1D, static method
        static void unflatten(std::vector<std::vector<std::array<double, 2>>>, std::array<double, 2>*, size_t, size_t);            // bring back to 2D
        void compute();     // use all information to compute positions and vector field at each timestep

        friend std::ostream &operator<<(std::ostream&, const Scene&);

};