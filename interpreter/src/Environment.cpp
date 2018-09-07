#include <interpreter/Environment.h>

// The constructor method initializes the variables
Environment::Environment() {
    this->setVariable("Q800", M_PI);
    this->setVariable("I15", 0);     // Degree / Radian
    this->setVariable("M32", 0);    // Lazer off
}

void Environment::setVariable(const std::string& variable, double value) {
    // convert variable name to upper case as PMAC is case insentive
    std::string upVariable = variable;
    for (auto & c: upVariable) c = static_cast<char>(std::toupper(c));
    auto it = this->variables.find(upVariable);
    if (it != this->variables.end()) {
        it->second = value;
    } else {
        auto newPair = std::make_pair(upVariable, value);
        this->variables.insert(newPair);
    }

    // Toggle lazer value if variable is M32
    if (upVariable == "M32") {
        lazer.lazerToggle(value == 1.0);
    }
}

double Environment::getValue(std::string variable) {
    std::string upVariable = variable;
    for (auto & c: upVariable) c = static_cast<char>(std::toupper(c));
    auto it = this->variables.find(upVariable);
    if (it != this->variables.end()) {
        return it->second;
    } else {
        this->setVariable(variable, 0.0);
        return 0.0;
    }

}

const std::string Environment::toString() const {
    std::string envStr = "Environment state:\nVariables:\n";
    for (const auto &var : this->variables)
        envStr += "\t> " + var.first + ": " + std::to_string(var.second) + "\n" ;
    return envStr;
}
