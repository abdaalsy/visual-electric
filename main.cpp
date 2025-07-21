#include <iostream>
#include <string>
#include <array>
#include <parse.hpp>
#include <velectric.hpp>
#include <Eigen/Dense>

using json = nlohmann::json;

int main() {
    std::cout << "zero vector field test:" << std::endl;
    Vec2 bottomLeft = {0.0, 0.0};
    Vec2 topRight = {5, 4};
    double dx = 1.0;
    double dt = 0.1;
    Scene* scene = new Scene(bottomLeft, topRight, dx, dt);
    std::cout << "Bottom left: (" << scene->bottomLeft.x << ", " << scene->bottomLeft.y << ")" << std::endl;
    std::cout << "top right: (" << scene->topRight.x << ", " << scene->topRight.y << ")" << std::endl;
    std::vector<std::vector<Vec2>> field = scene->zeroVectorField(scene->bottomLeft, scene->topRight, scene->dx);
    printVectorField(field);

    std::cout << scene->timesteps << std::endl;

    std::cout << std::endl << "vector field flattening test:" << std::endl;
    Vec2 flatField[5*4];
    std::cout << "Length: " << Scene::flatten(flatField, field) << std::endl;
    for (auto &vec : flatField)
    {
        std::cout << "[" << vec.x << ", " << vec.y << "]  ";
    }

    std::cout << std::endl << "vector field unflattening test:" << std::endl;
    std::vector<std::vector<Vec2>> unflatField(4, std::vector<Vec2>(5));
    Scene::unflatten(unflatField, flatField, 5*4, 4);
    printVectorField(unflatField);

    delete scene;
    scene = nullptr;

    return 0;
}