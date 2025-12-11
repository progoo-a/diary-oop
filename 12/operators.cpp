#include <functional>
#include <vector>
#include <memory>
#include <iostream>

struct Operator {
    char opcode;
    int precedence; 
    std::function<double(double, double)> op;

    Operator() = default;
    Operator(char code, int prec, std::function<double(double, double)> operation)
        : opcode(code), precedence(prec), op(std::move(operation)) {}
        
    double operator() (double a, double b) {
        return op(a, b);
    }
};

struct Add : public Operator {
    Add() {
        opcode = '+';
        precedence = 1;
        op = [](double a, double b) { return a + b; };
    }
};

struct Multiply : public Operator {
    Multiply() {
        opcode = '*';
        precedence = 2;
        op = [](double a, double b) { return a * b; };
    }
};

int main() {
    std::vector<std::unique_ptr<Operator>> operators;
    operators.push_back(std::make_unique<Add>());
    operators.push_back(std::make_unique<Multiply>());

    double a = 5.0;
    double b = 3.0;
    for (const auto &op : operators) {
        double result = (*op)(a, b);
        // Example output: "5 + 3 = 8" or "5 * 3 = 15"
        std::cout << a << " " << op->opcode << " " << b << " = " << result << '\n';
    }
}
