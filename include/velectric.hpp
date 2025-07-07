#pragma once
#include <array>
#include <iostream>
#include "../libs/Eigen/Dense"   

class PointCharge {
    private:
        const double q;
        const double m;
        const Eigen::Vector2d p0;
        const Eigen::Vector2d v0;
        const Eigen::Vector2d a0;
        const Eigen::Vector2d p;
        const Eigen::Vector2d v;
        const Eigen::Vector2d a;
    public:
        PointCharge(double, double, Eigen::Vector2d, Eigen::Vector2d, Eigen::Vector2d, Eigen::Vector2d, Eigen::Vector2d, Eigen::Vector2d);
        double getQ() const {return q;}
        double getM() const {return m;}
        Eigen::Vector2d getPosition0() const {return p0;}
        Eigen::Vector2d getVelocity0() const {return v0;}
        Eigen::Vector2d getAccel0() const {return a0;}
        Eigen::Vector2d getPosition() const {return p;}
        Eigen::Vector2d getVelocity() const {return v;}
        Eigen::Vector2d getAccel() const {return a;}
        
    
    friend std::ostream &operator<<(std::ostream&, const PointCharge&);
};

struct Scene {
    Scene(Eigen::Vector2d, Eigen::Vector2d, double, std::vector<size_t>);    // minimum constructor
    const Eigen::Vector2d bottomLeft;
    const Eigen::Vector2d topRight;
    const double deltaX;
    const std::vector<size_t> timesteps;                    // list of time values                    
    const std::vector<PointCharge> charges;                 // list of charges
    std::vector<std::vector<Eigen::Vector2d>> positions;    // positions of each charge
    std::vector<std::vector<std::vector<Eigen::Vector2d>>> vectorFields;

    static std::vector<std::vector<Eigen::Vector2d>> zeroVectorField(Eigen::Vector2d, Eigen::Vector2d, size_t, size_t);  // generate a field of zero vectors
    static std::vector<Eigen::Vector2d> flatten(std::vector<std::vector<Eigen::Vector2d>>);                              // flatten to 1D, static method
    static std::vector<std::vector<Eigen::Vector2d>> unflatten(std::vector<Eigen::Vector2d>, size_t, size_t);            // bring back to 2D

    Scene operator+(Scene) const;   // adding fields, appending charge & position list (check that timesteps, deltaX, and bounding vectors are equal)
    Scene operator*(double) const;  // scalar multiplication
    Scene &operator+=(Scene);
    Scene &operator*=(double);
    friend std::ostream &operator<<(std::ostream&, const Scene&);
    
};