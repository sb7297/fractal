#include <iostream>
#include "fractal.hpp"

std::ostream& operator <<(std::ostream& os, sf::Color color) {
    os << "{" << color.r << "," << color.g << "," << color.b << "}";
    return os;
}
int main() {
    auto mellior = fractal::hue2rgb(250);
    std::cout << mellior << "\n";
    return 0;
}