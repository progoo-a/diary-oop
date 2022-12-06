#include <iostream>
#include <cstring>

void version() {}

int main(int argc, char *argv[]) {
    std::string expression;
    int verbose = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {
            version();
            exit(0);
        }
        if (strcmp(argv[i], "--verbose") == 0) {
            verbose++;
        }
        expression = argv[i];
    }
    if (expression.size() == 0) {
        std::getline(std::cin, expression);
    }
    std::cout << "L'expression est : " << expression << "\n";
}
