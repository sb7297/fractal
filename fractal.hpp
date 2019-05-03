#ifndef FRACTAL_FRACTAL_H
#define FRACTAL_FRACTAL_H

#include <complex>
#include <SFML/Graphics/Color.hpp>

namespace fractal {
typedef std::complex<long double> LDComplex;

LDComplex mandelbrot_step(LDComplex z_n, LDComplex c); 

int mandelbrot_iters_to_escape(LDComplex c, int escape_threshold);

sf::Color palette(int iters, int threshold);

sf::Color hue2rgb(int degrees);
}

#endif