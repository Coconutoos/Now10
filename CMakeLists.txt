cmake_minimum_required(VERSION 3.21)
project(Unter)

set(CMAKE_CXX_STANDARD 14)

add_executable(Unter main.cpp Cliente.cpp Cliente.h menuView.cpp menuView.h Alimento.cpp Alimento.h)
