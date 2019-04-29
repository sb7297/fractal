#ifndef FRACTAL_FRACTAL_H
#define FRACTAL_FRACTAL_H

#include <complex>

namespace fractal {
typedef std::complex<long double> LDComplex;

LDComplex mandelbrot_step(LDComplex z_n, LDComplex c); 

int mandelbrot_iters_to_escape(LDComplex c, int escape_threshold);
}

#endif