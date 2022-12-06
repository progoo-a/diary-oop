#include <iostream>
#include <string>
#include <vector>

using number = double;

class Token {
    std::string val;
    public:
    Token(std::string value="") : val{value} {};
    std::string value() const { return val; }
};

class Number : public Token {
    number num;
    public:
    Number(number value) : Token{std::to_string(value)}, num{value} { }
    Number(std::string value) : Token{value} {
        num = std::stod(value);
    }
};

class Operator : public Token {
    public:
    using Token::Token;
    virtual int precedence() = 0;
    virtual std::string symbol() = 0;
    virtual number operator() (number a, number b) = 0;
    std::string value() const {
        return symbol();
    }
};

class OperatorPlus : public Operator {
    number operator() (number a, number b) { return a + b; }
    std::string symbol() { return "+"; }
    int precedence() { return 3; }
};

int main() {
    std::vector<Token> tokens;
    tokens.push_back(Number(33.2));
    tokens.push_back(OperatorPlus());
    tokens.push_back(Number(42));
    for (auto token : tokens) {
        std::cout << token.value();
    }
}
