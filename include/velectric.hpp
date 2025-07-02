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
    public:
        PointCharge(double, double, Eigen::Vector2d, Eigen::Vector2d, Eigen::Vector2d);
        double getQ() const {return q;}
        double getM() const {return m;}
        Eigen::Vector2d getPosition0() const {return p0;}
        Eigen::Vector2d getVelocity0() const {return v0;}
        Eigen::Vector2d getAccel0() const {return a0;}
        
    
    friend std::ostream &operator<<(std::ostream&, const PointCharge&);
};

struct Scene {
    const Eigen::Vector2d bottomLeft;
    const Eigen::Vector2d topRight;
    const std::vector<double> timesteps;
    const std::vector<PointCharge> charges;
    std::vector<std::vector<Eigen::Vector2d>> positions;
    std::vector<std::vector<std::vector<Eigen::Vector2d>>> vectorFields;

    std::vector<std::vector<Eigen::Vector2d>> zeroVectorField(Eigen::Vector2d, Eigen::Vector2d, size_t, size_t) const;
    std::vector<Eigen::Vector2d> flatten(std::vector<std::vector<Eigen::Vector2d>>) const;
    std::vector<std::vector<Eigen::Vector2d>> unflatten(std::vector<Eigen::Vector2d>, size_t, size_t) const;
};