#include <cmath>
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
}