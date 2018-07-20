#include "Environment.h"

void Environment::setVariable(std::string variable, double value) {
    auto it = this->variables.find(variable);
    if (it != this->variables.end()) {
        it->second = value;
    } else {
        auto newPair = std::make_pair(variable, value);
        this->variables.insert(newPair);
    }
}

double Environment::getValue(std::string variable) {
    auto it = this->variables.find(variable);
    if (it != this->variables.end()) {
        return it->second;
    } else {
        this->setVariable(variable, 0.0);
        return 0.0;
    }

}

