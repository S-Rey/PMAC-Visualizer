#pragma once

#include <vector>
#include <map>


class Lazer {
public:
    enum Axis {X, Y, Z, A, B, C, U, V, W} axis;
    enum AxisAttr {INC, ABS, FRAX};
    enum MoveMod {LINEAR, RAPID, CIRCLE1, CIRCLE2, PVT,
                  SPLINE1, SPLINE2, CC0, CC1, CC2, CC3};

    // Structure keeping track of the state of a given axis, used in axisStates
    struct AxisState {
        AxisAttr attr;
        double value;
        AxisState(AxisAttr attr, double value) : attr(attr), value(value) {}
    };

    struct MoveCmd {
        std::map<Axis, double> axisPoses; // value always in absolute coordinate
        bool toggle;    // true : lazer on, false : lazer off
        double time;
        MoveCmd() {}
        MoveCmd(std::map<Axis, double> axisPoses, bool toggle, double time)
            : axisPoses(axisPoses), toggle(toggle), time(time) {}
    };
    
    Lazer();
    const std::map<Axis, AxisState>& getAxisStates() const;
    void setAxisPos(Axis axis, double value);
    void setAxisAttribute(Axis axis, AxisAttr axisAttr);
    void lazerToggle(bool mode);
    void updateMoveCmds();
    std::vector<MoveCmd> getMoveCmds() const;
private:
    std::map<Axis, AxisState> mAxisSates;
    bool mToggle = false;
    std::vector<MoveCmd> mMoveCmds;
};
