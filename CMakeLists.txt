cmake_minimum_required(VERSION 3.17)
project(Latex_Note_Generator)

set(CMAKE_CXX_STANDARD 17)

include_directories(Latex-Note-Generator)

add_executable(Latex_Note_Generator
        Latex-Note-Generator/cxxopts.hpp
        Latex-Note-Generator/LatexGenerator.cpp
        Latex-Note-Generator/LatexGenerator.hpp
        Latex-Note-Generator/Main.cpp
        Latex-Note-Generator/Main.hpp)
