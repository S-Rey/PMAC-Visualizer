#pragma once

#include <string>
#include <map>
#include <vector>
#include <utility>
#include <stdexcept>
#include <iostream>  // DEBUG
#include <cmath>    // For M_PI

struct MoveCmd {
    double x;
    double y;
    double z;
    bool  on;
    enum MoveMod {LINEAR, RAPID, CIRCLE1, CIRCLE2, PVT, 
          SPLINE1, SPLINE2, CC0, CC1, CC2, CC3} mode;
    MoveCmd() {MoveCmd(0.0, 0.0, 0.0, false, MoveCmd::MoveMod::LINEAR);}
    MoveCmd(double x, double y, double z, bool on, MoveCmd::MoveMod mode) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->on =on;
        this->mode = mode;
    }
};

class Environment {
public:
    Environment();
    void    setVariable(const std::string& variable, double value);
    double  getValue(std::string variable);
    const   std::string toString() const;

    MoveCmd lazerState;
private:
    std::map<std::string, double> variables;
    std::vector<MoveCmd> moveInstructions;
};
