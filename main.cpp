#include <iostream>
#include <SFML/Graphics.hpp>
#include "fractal.hpp"

std::ostream& operator <<(std::ostream& os, sf::Color color) {
    os << "{" << unsigned(color.r) << "," << unsigned(color.g) << "," << unsigned(color.b) << "}";
    return os;
}
int main() {
    const int WIN_WIDTH = 1280;
    const int WIN_HEIGHT = 720;

    sf::Image image;
    image.create(WIN_WIDTH, WIN_HEIGHT, sf::Color::Black);
    int iters;
    for (unsigned int i = 0; i < WIN_WIDTH; i++) {
        for (unsigned int j = 0; j < WIN_HEIGHT; j++) {
            double di = static_cast<double>(i);
            double dj = static_cast<double>(j);
            di = (1.0- (-2.5))/(WIN_WIDTH) * (di-WIN_WIDTH) + 1.0;
            dj = (1.0- (-1.0))/(WIN_HEIGHT) * (dj-WIN_HEIGHT) + 1.0;
            fractal::LDComplex worm(di, dj);
            iters = fractal::mandelbrot_iters_to_escape(worm, 1000);
            image.setPixel(i, j, fractal::hue2rgb(iters % 360));
        }
    }
    
    // image.saveToFile("fractal.png");
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