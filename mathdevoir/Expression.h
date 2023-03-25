#include <string>

class Expression
{
private:
    std::string exp;
    float evalOp(float, float, char) const;
    std::string gettokenType(std::string) const;

public:
    Expression(std::string);
    // ~Expression();
    float eval();
};
