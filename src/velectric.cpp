#include "..\include\velectric.hpp"

//PointCharge
PointCharge::PointCharge(double mass, double charge, std::array<double, 2> pos0, std::array<double, 2> vel0, std::array<double, 2> accel0)
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
Scene::Scene(std::array<double, 2> botLeft, std::array<double, 2> topRight, double deltaX, double deltaT)
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

std::vector<std::vector<std::array<double, 2>>> Scene::zeroVectorField(std::array<double, 2> botLeft, std::array<double, 2> topRight, double delta) {
    std::vector<std::vector<std::array<double, 2>>> field((int)((topRight[1] - botLeft[1])/delta), std::vector<std::array<double, 2>>((int)((topRight[0]-botLeft[0])/delta), {0.0, 0.0}));
    return field; 
}

void Scene::flatten(std::array<double, 2>*, std::vector<std::vector<std::array<double, 2>>>) {
    ;
}

void Scene::unflatten(std::vector<std::vector<std::array<double, 2>>>, std::array<double, 2>*, size_t, size_t) {
    ;
}
//Scene