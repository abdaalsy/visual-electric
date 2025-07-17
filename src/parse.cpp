#include "../include/parse.hpp"
#include "../include/velectric.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using json = nlohmann::json;

json parseFile(std::string path) {
    std::ifstream jsonReadFile(path);
    if (!jsonReadFile) {
        json obj;
        return obj;
    }
    std::ostringstream buffer;
    buffer << jsonReadFile.rdbuf();
    std::string jsonString = buffer.str();
    json jsonObj = json::parse(jsonString);
    std::cout << jsonObj.dump() << std::endl;
    return jsonObj;
}

std::vector<PointCharge> extractPointCharges(json &jsonObj) {
    std::vector<PointCharge> objects;
    for (auto &obj : jsonObj["objects"])
    {
        double q = obj["charge"].get<double>();
        double m = obj["mass"].get<double>();
        std::array<double, 2> pos0 = obj["position"].get<std::array<double, 2>>();
        Vec2 p0{pos0[0], pos0[1]};
        std::array<double, 2> vel0 = obj["velocity"].get<std::array<double, 2>>();
        Vec2 v0{vel0[0], vel0[1]};
        std::array<double, 2> acc0 = obj["acceleration"].get<std::array<double, 2>>();
        Vec2 a0{acc0[0], acc0[1]};
        PointCharge pc(m, q, p0, v0, a0);
        objects.push_back(pc);
    }
    return objects;
}

std::unordered_map<std::string, double> extractScene(json &jsonObj) {
    // needs to be reworked to reflect change in formatting to bottomLeft, topRight
    std::unordered_map<std::string, double> scene;
    double x_min = jsonObj["x_min"].get<double>();
    double x_max = jsonObj["x_max"].get<double>();
    double y_min = jsonObj["y_min"].get<double>();
    double y_max = jsonObj["y_max"].get<double>();
    scene["x_min"] = x_min;
    scene["x_max"] = x_max;
    scene["y_min"] = y_min;
    scene["y_max"] = y_max;
    return scene;
}
