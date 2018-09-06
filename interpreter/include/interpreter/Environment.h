#pragma once

#include <string>
#include <map>
#include <vector>
#include <utility>
#include <stdexcept>
#include <iostream>  // DEBUG
#include <cmath>    // For M_PI
#include <interpreter/lazer.h>


class Environment {
public:
    Environment();
    void    setVariable(const std::string& variable, double value);
    double  getValue(std::string variable);
    const   std::string toString() const;

    Lazer lazer;
private:
    std::map<std::string, double> variables;
};
