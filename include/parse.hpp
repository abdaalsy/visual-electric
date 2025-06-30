#include <string>
#include "../libs/json.hpp"
#include "PointCharge.hpp"

#ifndef PARSE_H
#define PARSE_H

using json = nlohmann::json;

json parseFile(std::string);
std::vector<PointCharge> extractPointCharges(json);
std::unordered_map<std::string, double> extractScene(json);

#endif