#ifndef FRACTAL_FRACTAL_H
#define FRACTAL_FRACTAL_H

#include <complex>
#include <SFML/Graphics/Color.hpp>

namespace fractal {
typedef std::complex<long double> LDComplex;

LDComplex mandelbrot_step(const LDComplex& z_n, const LDComplex& c); 

int mandelbrot_iters_to_escape(const LDComplex& c, int escape_threshold);

sf::Color generate_palette(int iters, int threshold);

sf::Color hue2rgb(int degrees);
}

#endif