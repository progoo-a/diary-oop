#include <unordered_map>
#include <iostream>

enum class Color {
    WHITE, BLUE, RED, GREEN, YELLOW, BROWN
};

struct IceCream {
    std::string flavor;
    Color color;
    IceCream(std::string flavor, Color color) :
        flavor{flavor}, color{color} {}
};

int main() {
    std::unordered_map<Color, IceCream>ice_creams;
    ice_creams.insert({Color::GREEN,
                       IceCream("Pistache", Color::GREEN)});
    ice_creams[Color::YELLOW] = IceCream("Vanilla", Color::YELLOW);
    ice_creams[Color::BROWN] = IceCream("Chocolate", Color::BROWN);

    ice_creams.insert({Color::YELLOW,
                       IceCream("Lemon", Color::YELLOW)});
    //std::cout << ice_creams[Color::YELLOW].second.flavor << "\n";
    //auto u = ice_creams[Color::YELLOW];
    std::cout << ice_creams.at(Color::YELLOW).flavor << "\n";
    //std::cout << ice_creams[Color::YELLOW].flavor << "\n";
    for (auto k : ice_creams) {
        std::cout << k.second.flavor;
    }
}
