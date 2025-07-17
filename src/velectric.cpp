#include "..\include\velectric.hpp"


inline double square(double x) {
    return x * x;
}

//Vec2
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
    : bottomLeft(botLeft), topRight(topRight), deltaX(deltaX) {
        timesteps = getTimesteps(deltaT);
        vectorFields.fill(zeroVectorField(botLeft, topRight, deltaX));
}

std::ostream &operator<<(std::ostream &out, const Scene &rhs) {
    // out << "Bounding vectors: " << rhs.bottomLeft << ", " << rhs.topRight << std::endl;
    out << "dx: " << rhs.deltaX << std::endl;
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

void Scene::flatten(Vec2*, std::vector<std::vector<Vec2>>) {
    ;
}

void Scene::unflatten(std::vector<std::vector<Vec2>>, Vec2*, size_t, size_t) {
    ;
}
//Scene