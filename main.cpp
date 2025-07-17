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
    std::cout << "Bottom left: (" << scene->bottomLeft.x << ", " << scene->bottomLeft.y << ")" << std::endl;
    std::cout << "top right: (" << scene->topRight.x << ", " << scene->topRight.y << ")" << std::endl;
    std::vector<std::vector<Vec2>> field = scene->zeroVectorField(scene->bottomLeft, scene->topRight, scene->deltaX);
    printVectorField(field);

    std::cout << scene->timesteps << std::endl;

    delete scene;
    scene = nullptr;

    return 0;
}