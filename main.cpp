#include <iostream>
#include <string>
#include <array>
#include "include/parse.hpp"
#include "include/velectric.hpp"
#include "libs/Eigen/Dense"

using json = nlohmann::json;

int main() {
    std::cout << "Scene printing test:" << std::endl;
    PointCharge pc(3.4, -1.2E-6, {0, 0}, {0, 0}, {0, 0});
    Scene* scene = new Scene({0, 0}, {1, 1}, 0.01, 0.5);
    scene->addCharge(pc);
    scene->addCharge(pc);
    std::cout << *scene << std::endl;

    delete scene;
    scene = nullptr;

    return 0;
}