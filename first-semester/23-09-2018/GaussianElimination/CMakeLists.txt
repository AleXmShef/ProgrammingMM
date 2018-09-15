cmake_minimum_required(VERSION 3.12)
project(Gauss)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gauss main.cpp AugmentedMatrix.cpp AugmentedMatrix.h MatrixUtils.cpp MatrixUtils.h)
