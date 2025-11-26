cmake_minimum_required(VERSION 3.10)
project(ProjetEDO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(projet
    src/main.cpp
    src/modele.cpp
    src/solveurExplicite.cpp
    src/solveurImplicite.cpp
)

target_include_directories(projet PUBLIC include)

