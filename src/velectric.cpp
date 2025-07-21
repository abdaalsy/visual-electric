#include <velectric.hpp>
#include <Eigen/Dense>

inline double square(double x) {
    return x * x;
}

//Vec2
std::ostream &operator<<(std::ostream &out, Vec2 &v) {
    out << "[" << v.x << ", " << v.y << "]";
    return out;
}

inline double Vec2::magnitude() const {
    return sqrt(square(this->x) + square(this->y));
}

inline Vec2 Vec2::unitVector() const {
    const double mag = this->magnitude();
    return {this->x/mag, this->y/mag};
}
//Vec2

//PointCharge
PointCharge::PointCharge(double mass, double charge, Vec2 pos0, Vec2 vel0, Vec2 accel0)
    : q(charge), m(mass), p0(pos0), v0(vel0), a0(accel0) {
        if (mass < 0) {
            mass = -1 * mass;
        }
}

std::ostream &operator<<(std::ostream &out, const PointCharge &rhs) {
    out << rhs.getQ() << " C";
    return out;
}
//PointCharge

//Scene
Scene::Scene(Vec2 botLeft, Vec2 topRight, double deltaX, double deltaT)
    : bottomLeft(botLeft), topRight(topRight), dx(deltaX), dt(deltaT) {
        timesteps = getTimesteps(deltaT);
        vectorFields.fill(zeroVectorField(botLeft, topRight, deltaX));
}

std::ostream &operator<<(std::ostream &out, const Scene &rhs) {
    // out << "Bounding vectors: " << rhs.bottomLeft << ", " << rhs.topRight << std::endl;
    out << "dx: " << rhs.dx << std::endl;
    out << "timesteps: " << rhs.timesteps << std::endl;
    out << "charges: " << rhs.charges << std::endl;
    return out;
}

void Scene::addCharge(PointCharge pc) {
    this->charges.push_back(pc);
}

std::vector<double> Scene::getTimesteps(double deltaT) {
    Eigen::VectorXd v = Eigen::VectorXd::LinSpaced(numTimesteps, 0 + deltaT, numTimesteps * deltaT);
    std::vector<double> timesteps(numTimesteps, 0.0);
    for (size_t i=0; i < numTimesteps; i++) {
        timesteps[i] = v[i];
    }
    return timesteps;
}

std::vector<std::vector<Vec2>> Scene::zeroVectorField(Vec2 botLeft, Vec2 topRight, double delta) {
    std::vector<std::vector<Vec2>> field((int)((topRight.y - botLeft.y)/delta), std::vector<Vec2>((int)((topRight.x-botLeft.x)/delta), {0.0, 0.0}));
    return field; 
}

size_t Scene::flatten(Vec2* dest, std::vector<std::vector<Vec2>> &source) {
    // assume dest is adequately sized
    size_t i = 0;
    for (size_t row=0; row < source.size(); row++) {
        for (size_t col=0; col < source[row].size(); col++) {
            dest[i++] = source[row][col];
        }
    }
    return i;
}

void Scene::unflatten(std::vector<std::vector<Vec2>> &dest, Vec2* source, size_t length, size_t rows) {
    size_t row;
    size_t col;
    const size_t rowLen = length/rows;
    for (size_t i=0; i < length; i++) {
        row = i/rowLen;
        col = i%rowLen;
        dest[row][col] = source[i];
    }
}
//Scene