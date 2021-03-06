cmake_minimum_required(VERSION 2.8.9)
project(fractal)
add_executable(fractal main.cpp fractal.cpp)
add_executable(catch fractal_test.cpp fractal.cpp)

set(SFML_DIR "D:/Program Files/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

target_link_libraries(fractal sfml-graphics)
target_link_libraries(catch sfml-graphics)

target_compile_options(fractal PRIVATE
                           $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
                                -std=c++14>
                           $<$<CXX_COMPILER_ID:MSVC>:
                                /std:c++14>)
target_compile_options(catch PRIVATE
                           $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
                                -Wall -std=c++14>
                           $<$<CXX_COMPILER_ID:MSVC>:
                                /W4 /std:c++14>)