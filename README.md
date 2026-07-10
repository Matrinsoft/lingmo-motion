# lingmo-motion

Animation and interaction system.

## Capabilities

SpringAnimation (damped spring physics), Transition effects, Gesture recognition, Scroll physics

## Build

`ash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j\
`

## CMake Usage

`cmake
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(LingmoSdk REQUIRED COMPONENTS Motion)
`

## Dependencies

- Qt6 >= 6.5
- C++20
