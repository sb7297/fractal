cmake_minimum_required(VERSION 2.8.9)
project(fractal)
add_executable(fractal main.cpp fractal.cpp)
add_executable(catch fractal_test.cpp fractal.cpp)

target_compile_options(fractal PRIVATE
                           $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
                                -std=c++14>
                           $<$<CXX_COMPILER_ID:MSVC>:
                                >)
target_compile_options(catch PRIVATE
                           $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
                                -Wall -std=c++14>
                           $<$<CXX_COMPILER_ID:MSVC>:
                                /W4>)