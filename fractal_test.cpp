#define CATCH_CONFIG_MAIN
#include <complex.h>
#include "lib/catch.hpp"
#include "fractal.hpp"

using namespace std::complex_literals;
/*
TEST_CASE("Tests are working.", "[fractal]") {
    REQUIRE(fractal::hello() == "Hello!");
}
*/

TEST_CASE("Mandelbrot steps correctly.", "[mandelbrot]") {
    REQUIRE(fractal::mandelbrot_step(0il, 0il) == 0il);
    REQUIRE(fractal::mandelbrot_step(0il, 1il) == 1il);
}

TEST_CASE("Escape time is calculated correctly.", "[mandelbrot]") {
    REQUIRE(fractal::mandelbrot_iters_to_escape(10il, 500) == 0);
    REQUIRE(fractal::mandelbrot_iters_to_escape(0il, 500) == 500);
}