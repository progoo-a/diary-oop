
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream ifs; 
    ifs.open("toto.txt", std::ios_base::in);
    std::string fuu;
    getline(ifs, fuu);
    std::cout << fuu;
}
