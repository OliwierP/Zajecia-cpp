cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(main)

file(GLOB SOURCES "src/*.cc")
include_directories(src)
include_directories(include)

add_executable(main main.cc)