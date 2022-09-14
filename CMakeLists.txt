cmake_minimum_required(VERSION 3.23)
project(bataille)

set(CMAKE_CXX_STANDARD 14)

add_executable(bataille main.cpp Player.cpp Player.h Card.cpp Card.h Pile.cpp Pile.h tools.cpp tools.h)
