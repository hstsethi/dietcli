cmake_minimum_required(VERSION 3.10)
project(DietCli)

set(CMAKE_CXX_STANDARD 11)


find_package(RapidJSON REQUIRED)
include_directories(${RapidJSON_INCLUDE_DIRS})
file(GLOB SOURCES "src/*.cpp")

add_executable(dietcli ${SOURCES})

