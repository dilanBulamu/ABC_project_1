cmake_minimum_required(VERSION 3.20)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp number_types/polar.h number_types/complex.h number_types/fraction.h number_types/point.h number_types/number.h number_types/complex.cpp number_types/fraction.cpp number_types/polar.cpp number_types/number.cpp number_types/point.cpp random.h container.h container.cpp)
