#include <iostream>
#include <string>
#include <array>
#include "include/parse.hpp"
#include "include/velectric.hpp"
#include "libs/Eigen/Dense"

using json = nlohmann::json;

int main() {
    std::cout << "JSON Parse test:" << std::endl;
    json jsonObj = parseFile("tests/problem1.json");
    std::cout << std::endl << "Point Charge test:" << std::endl;
    Eigen::Vector2d p0(0.0, 0.0);
    Eigen::Vector2d v0(0.0, 0.0);
    Eigen::Vector2d a0(0.0, 0.0);
    const PointCharge pc(9.11E-31, -1.602E-19, p0, v0, a0);
    std::cout << pc << std::endl;
    return 0;
}