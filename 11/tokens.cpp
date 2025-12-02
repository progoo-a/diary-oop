#include <iostream>
#include <string>
#include <sstream> 
#include <vector> 

class Token {
    public:
    
    enum class Associativity { LEFT, RIGHT };
    enum class TokenType {
        NUMBER, OPERATOR
    };
    
    Token(int a) {
        std::stringstream ss;
        ss << a;
        s = ss.str();
        type = TokenType::NUMBER;
    }
    
    Token(std::string a) {
        s = a;
        if (a == "+") {
            p = 3;
            associativity = Associativity::LEFT;
        } 
        else if (a == "-") {
            p = 3; 
            associativity = Associativity::LEFT;
        }
        type = TokenType::OPERATOR;
    }

    TokenType getType() const {
        return type;
    }

    std::string s;
    private:
    Associativity associativity; 
    int p; 
    TokenType type;
};

int main() {
    Token a(42);
    Token b("+");
    Token c(23);

    std::vector<Token> v; 
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    for (auto &t : v) {
        std::string displayType;
        switch (t.getType()) {
            case Token::TokenType::OPERATOR:
                displayType = "Opérateur";
                break;
            case Token::TokenType::NUMBER:
                displayType = "Nombre"; 
                break; 
        }

        std::cout << displayType << " " << t.s << "\n";
    }
}