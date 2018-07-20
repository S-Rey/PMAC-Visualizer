#include <string>
#include <map>

class Environment {
public:
    void        setVariable(std::string variable, double value);
    double      getValue(std::string variable);
private:
    std::map<std::string, double> variables = std::map<std::string, double>();
};
