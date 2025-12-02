#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Token {
public:
  enum class TokenType { NUMBER, OPERATOR };

  Token(TokenType type, std::string symbol)
      : type(type), symbol(std::move(symbol)) {}
  virtual ~Token() = default;

  TokenType getType() const { return type; }
  const std::string &getSymbol() const { return symbol; }

protected:
  TokenType type;
  std::string symbol;
};

class Operator : public Token {
public:
  enum class Associativity { LEFT, RIGHT };

  Operator(std::string s, int p, Associativity a,
           std::function<int(int, int)> f)
      : Token(TokenType::OPERATOR, std::move(s)), priority(p), associativity(a),
        f(std::move(f)) {}

  int apply(int a, int b) const { return f(a, b); }

private:
  int priority;
  Associativity associativity;
  std::function<int(int, int)> f;
};

class Addition : public Operator {
public:
  Addition()
      : Operator("+", 3, Operator::Associativity::LEFT,
                 [](int a, int b) { return a + b; }) {}
};

class Number : public Token {
public:
  explicit Number(int n)
      : Token(TokenType::NUMBER, std::to_string(n)), value(n) {}

  int getValue() const { return value; }

private:
  int value;
};

int main() {
  Number a(42);
  Addition b;
  Number c(23);

  std::vector<Token *> v;
  v.push_back(&a);
  v.push_back(&b);
  v.push_back(&c);

  for (auto t : v) {
    std::string displayType;
    switch (t->getType()) {
    case Token::TokenType::OPERATOR:
      displayType = "Opérateur";
      break;
    case Token::TokenType::NUMBER:
      displayType = "Nombre";
      break;
    }

    std::cout << displayType << " " << t->getSymbol() << "\n";
  }
}
