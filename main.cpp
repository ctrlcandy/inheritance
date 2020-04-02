#include <iostream>
#include "parser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    IntParser num1;
    IntParser num2;
    StrParser name;
    OpParser  op1;
    OpParser  op2;
    // Шаблон: name num op num op
    CombiParser combi1(5, &name, &num1, &op1, &num2, &op2);

    std::cout << (combi1.parse(std::cin) ? "Template match" : "Template not match") << std::endl;

    return 0;
}
