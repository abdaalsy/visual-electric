#include <iostream>
#include <string>
#include "include/parse.hpp"

using json = nlohmann::json;

int main() {
    json jsonObj = parseFile("src/problem1.json");
    return 0;
}