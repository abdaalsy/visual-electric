#pragma once
#include <array>
#include <iostream>
#include <vector>

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

struct Vec2 {
    double x, y;
    double magnitude() const;
    Vec2 unitVector() const;
    Vec2 operator+(Vec2&) const;
    Vec2 operator*(double) const;
    Vec2 operator-(Vec2&) const;
    void operator*=(double);
};

inline void printVectorField(std::vector<std::vector<Vec2>> &field) {
    for (auto &row : field)
    {
        for (auto &vec : row)
        {
            std::cout << "[" << vec.x << ", " << vec.y << "]" << "  ";
        }
        std::cout << std::endl;
    }
}

class PointCharge {
    private:
        const double q;
        const double m;
        const Vec2 p0;
        const Vec2 v0;
        const Vec2 a0;
    public:
        PointCharge(double, double, Vec2, Vec2, Vec2);
        double getQ() const {return q;}
        double getM() const {return m;}
        Vec2 getPosition0() const {return p0;}
        Vec2 getVelocity0() const {return v0;}
        Vec2 getAccel0() const {return a0;}
    
    friend std::ostream &operator<<(std::ostream&, const PointCharge&);
};

struct Scene {
    private:
        static const size_t numTimesteps = 10;
        static std::vector<double> getTimesteps(double);
    public:
        Scene(Vec2, Vec2, double, double);    // minimum constructor
        const Vec2 bottomLeft;
        const Vec2 topRight;
        const double dx;
        const double dt; 
        std::vector<double> timesteps;                    // list of time values                    
        std::vector<PointCharge> charges;                 // list of charges
        std::array<std::vector<Vec2>, numTimesteps> positions; // positions of each charge in real space, will be filled as scene is computed
        std::array<std::vector<std::vector<Vec2>>, numTimesteps> vectorFields;

        void addCharge(PointCharge);
        static std::vector<std::vector<Vec2>> zeroVectorField(Vec2, Vec2, double);  // generate a field of zero vectors
        static size_t flatten(Vec2*, std::vector<std::vector<Vec2>>&);                              // flatten to 1D, static method
        static void unflatten(std::vector<std::vector<Vec2>>&, Vec2*, size_t, size_t);            // bring back to 2D
        void compute();     // use all information to compute positions and vector field at each timestep

        friend std::ostream &operator<<(std::ostream&, const Scene&);
};

