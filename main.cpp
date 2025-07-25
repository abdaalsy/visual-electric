#include <iostream>
#include <string>
#include <array>
#include <parse.hpp>
#include <velectric.hpp>
#include <Eigen/Dense>

int main() {
    std::cout << "Vector operations test" << std::endl;
    Vec2 v = {5, 4};
    Vec2 u = {1, 2};
    std::cout << v << " - [1, 2] = " << (v - u) << std::endl;
    std::cout << v << " + [1, 2] = " << (v + u) << std::endl;
    std::cout << v << " * 3 = " << (v * 3) << std::endl;
    v *= 3;
    std::cout << "v *= 3" << std::endl;
    std::cout << "v = " << v << std::endl;

    return 0;
}