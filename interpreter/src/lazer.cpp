#include <interpreter/lazer.h>

Lazer::Lazer() {
    mAxisSates.insert(std::make_pair(Lazer::X, AxisState(Lazer::ABS, 0.0)));
    mAxisSates.insert(std::make_pair(Lazer::Y, AxisState(Lazer::ABS, 0.0)));
    mAxisSates.insert(std::make_pair(Lazer::Z, AxisState(Lazer::ABS, 0.0)));
    updateMoveCmds();
}

const std::map<Lazer::Axis, Lazer::AxisState>& Lazer::getAxisStates() const {
    return mAxisSates;
}

void Lazer::setAxisPos(Lazer::Axis axis, double value) {
    auto it = mAxisSates.find(axis);
    // if the axis is not yet in mAxisStates, simply add it and return
    if (it == mAxisSates.end()) {
        mAxisSates.insert(std::make_pair(axis, AxisState(Lazer::ABS, value)));
    } else if ((*it).second.attr == ABS) {
        (*it).second.value = value;
    } else if ((*it).second.attr == INC) {
        (*it).second.value += value;
    } else if ((*it).second.attr == FRAX) {
        throw std::runtime_error("FRAX() not yet implemented");
    }
}

void Lazer::setAxisAttribute(Axis axis, AxisAttr axisAttr) {
    auto it = mAxisSates.find(axis);
    // if the axis is not yet in mAxisStates, simply add it and return
    if (it == mAxisSates.end()) {
        mAxisSates.insert(std::make_pair(axis, AxisState(axisAttr, 0.0)));
        return;
    }
    (*it).second.attr = axisAttr;
}

void Lazer::lazerToggle(bool mode) {mToggle = mode;}

void Lazer::updateMoveCmds() {
    MoveCmd moveCmd;
    moveCmd.toggle = mToggle;
    moveCmd.time   = -1.f; // Not yet implemented
    for (auto axisState : mAxisSates) {
        moveCmd.axisPoses.insert(std::make_pair(axisState.first,
                                                axisState.second.value));
    }
    mMoveCmds.push_back(moveCmd);
}

std::vector<Lazer::MoveCmd> Lazer::getMoveCmds() const {
    std::vector<MoveCmd> result;
    result = mMoveCmds;
    return result;
}
