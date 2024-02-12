//
// Created by Peter Pan on 2/11/2024.
//

#ifndef WAFFLE_SERIALIZATION_H
#define WAFFLE_SERIALIZATION_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "base64.h"
class Serialization {

public:
    std::string serialize(int value) {
        return std::to_string(value);
    }

    std::string serialize(float value) {
        return std::to_string(value);
    }

    std::string serialize(bool value) {
        std::ostringstream oss;
        oss << std::boolalpha << value;
        return oss.str();
    }

    std::string serialize(const char* value) {
        std::string s = value;
        return serialize(s);
    }

    std::string serialize(const std::string& value) {
        return value;
    }

    std::string serialize(const std::vector<unsigned char>& blob) {
        return base64_encode(blob.data(), blob.size());
    }

    std::string deserializeString(const std::string& value) {
        return value;
    }

    int deserializeInt(const std::string& value) {
        return std::stoi(value);
    }

    float deserializeFloat(const std::string& value) {
        return std::stof(value);
    }

    bool deserializeBool(const std::string& value) {
        std::istringstream iss(value);
        bool result;
        iss >> std::boolalpha >> result;
        return result;
    }

    std::vector<unsigned char> deserializeBlob(const std::string& data) {
        return base64_decode(data);
    }
};
#endif //WAFFLE_SERIALIZATION_H
