#pragma once

#include <string>
#include <map>
#include <utility>
#include <stdexcept>
#include <iostream>  // DEBUG
#include <cmath>    // For M_PI

class Environment {
public:
    // Constructor
    Environment();
    // variables accessors and mutators
    void    setVariable(const std::string& variable, double value);
    double  getValue(std::string variable);
    const std::string toString() const;
private:
    std::map<std::string, double> variables = std::map<std::string, double>();
};
