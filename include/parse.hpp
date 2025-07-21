#pragma once
#include <string>
#include <vector>
#include <json/json.hpp>
#include <velectric.hpp>

using json = nlohmann::json;

json parseFile(std::string);
std::vector<PointCharge> extractPointCharges(json);
std::unordered_map<std::string, double> extractScene(json);