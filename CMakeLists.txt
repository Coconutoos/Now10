cmake_minimum_required(VERSION 3.21)
project(Unter)

set(CMAKE_CXX_STANDARD 14)

add_executable(Unter main.cpp model/Cliente.cpp model/Cliente.h view/menuView.cpp view/menuView.h model/Alimento.cpp model/Alimento.h controller/clienteController.cpp controller/clienteController.h view/clienteView.cpp view/clienteView.h)
