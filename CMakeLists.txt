cmake_minimum_required(VERSION 3.20)

project(lingmo-motion VERSION 1.0.0 DESCRIPTION "Lingmo Motion System" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(lingmo-motion SHARED
    src/springanimation.cpp
)
target_compile_definitions(lingmo-motion PRIVATE LINGMO_MOTION_LIBRARY)

target_include_directories(lingmo-motion
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(lingmo-motion PUBLIC Qt6::Core)

install(TARGETS lingmo-motion
    EXPORT LingmoMotionTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/lingmo-motion
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
