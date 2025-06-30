#include "../include/parse.hpp"
#include "../include/PointCharge.hpp"
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
    std::cout << jsonObj.dump(4) << std::endl;
    return jsonObj;
}
