cmake_minimum_required(VERSION 3.7.0)
project(codeforces VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_executable(codeforces main.cpp)

# round 416
add_executable(round416_a round416/a.cpp)
add_executable(round416_b round416/b.cpp)
add_executable(round416_c round416/c.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
