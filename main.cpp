#include <iostream>
#include <string>
#include <array>
#include "include/parse.hpp"
#include "include/velectric.hpp"
#include "libs/Eigen/Dense"

using json = nlohmann::json;

int main() {
    std::cout << "zero vector field test:" << std::endl;
    Scene* scene = new Scene({0.0, 0.0}, {11, 10}, 1.0, 0.1);
    std::cout << "Bottom left: (" << scene->bottomLeft[0] << ", " << scene->bottomLeft[1] << ")" << std::endl;
    std::cout << "top right: (" << scene->topRight[0] << ", " << scene->topRight[1] << ")" << std::endl;
    std::vector<std::vector<std::array<double, 2>>> field = scene->zeroVectorField(scene->bottomLeft, scene->topRight, scene->deltaX);
    printVectorField(field);

    std::cout << scene->timesteps << std::endl;

    delete scene;
    scene = nullptr;

    return 0;
}