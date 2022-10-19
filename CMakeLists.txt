cmake_minimum_required(VERSION 3.22.1)

project(CPP_Playground VERSION 0.01)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/)

add_executable(${PROJECT_NAME}.elf ${SRCS})

target_include_directories(${PROJECT_NAME}.elf PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}/include/"
                            )