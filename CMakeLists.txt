cmake_minimum_required(VERSION 3.24.2)

project(sofware1)

#comment

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY${CMAKE_BINARY_DIR}/bin)

set(SOURCES src/main.cpp src/participant.cpp src/config_tty.cpp)

add_executable(sofware1.bin ${SOURCES})

