#include <iostream>
#include <SFML/Graphics.hpp>
#include "fractal.hpp"

std::ostream& operator <<(std::ostream& os, sf::Color color) {
    os << "{" << unsigned(color.r) << "," << unsigned(color.g) << "," << unsigned(color.b) << "}";
    return os;
}
int main() {
    const int WIN_WIDTH = 800;
    const int WIN_HEIGHT = 600;

    sf::Image image;
    image.create(WIN_WIDTH, WIN_HEIGHT, sf::Color::Black);
    for (unsigned int i = 0; i < WIN_WIDTH; i++) {
        for (unsigned int j = 0; j < WIN_HEIGHT; j++) {
            image.setPixel(i, j, fractal::hue2rgb(i % 360));
        }
    }

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "My window!");

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();

        window.draw(sprite);

        window.display();
    }
    return 0;
}