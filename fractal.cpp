#include <cmath>
#include <algorithm>
#include "fractal.hpp"

namespace fractal {
using namespace std::complex_literals;

LDComplex mandelbrot_step(LDComplex z_n, LDComplex c) {
    return std::pow(z_n, 2) + c;
}

int mandelbrot_iters_to_escape(LDComplex c, int escape_threshold) {
    int iters = 0;
    LDComplex z = 0il;
    if (std::norm(c) > 2*2) return iters;
    while (iters < escape_threshold && std::norm(z) < 2*2) {
        z = mandelbrot_step(z, c);
        iters++;
    }
    return iters;
}

sf::Color hue2rgb(int degrees) {
    // degrees = std::clamp(degrees, 0, 360);
    degrees = degrees < 0 ? 0 : (degrees > 360 ? 360 : degrees);
    double h_prime = degrees/60.0;
    const double chroma = 1.0;
    double interm = chroma * (1.0 - std::abs(std::fmod(h_prime, 2) - 1));
    double red = 0.0, green = 0.0, blue = 0.0;
    if (0.0 <= h_prime && h_prime < 1.0) {
        red = chroma;
        green = interm;
        blue = 0.0;
    } else if (1.0 <= h_prime && h_prime < 2.0) {
        red = interm;
        green = chroma;
        blue = 0.0;
    } else if (2.0 <= h_prime && h_prime < 3.0) {
        red = 0.0;
        green = chroma;
        blue = interm;
    } else if (3.0 <= h_prime && h_prime < 4.0) {
        red = 0.0;
        green = interm;
        blue = chroma;
    } else if (4.0 <= h_prime && h_prime < 5.0) {
        red = interm;
        green = 0.0;
        blue = chroma;
    } else if (5.0 <= h_prime && h_prime <= 6.0) {
        red = chroma;
        green = 0.0;
        blue = interm;
    }
    sf::Uint8 ired = static_cast<sf::Uint8>(red * 255 + 0.5);
    sf::Uint8 igreen = static_cast<sf::Uint8>(green * 255 + 0.5);
    sf::Uint8 iblue = static_cast<sf::Uint8>(blue * 255 + 0.5);
    return sf::Color(ired, igreen, iblue, 255);
}

sf::Color palette(int iters, int threshold) {
    if (iters == threshold) {
        return sf::Color::White;
    }
    return sf::Color::Black;
}
}