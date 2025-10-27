cmake_minimum_required(VERSION 4.0)
project(GrobnerBasis)

set(CMAKE_CXX_STANDARD 26)

add_executable(GrobnerBasis src/main.cpp
        include/Monomial.h
        src/Monomial.cpp
        include/Polynomial.h
        src/Polynomial.tpp)
