cmake_minimum_required(VERSION 3.20)

project(lingmo-motion-tests VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Test)

add_executable(test_springanimation
    test_springanimation.cpp
)

target_link_libraries(test_springanimation PRIVATE
    Qt6::Core
    Qt6::Test
    lingmo-motion
)

add_test(NAME test_springanimation COMMAND test_springanimation)
