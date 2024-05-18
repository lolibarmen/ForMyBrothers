cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME Roy)
project(${PROJECT_NAME})

add_executable(Roy src/main.cpp)

#include_directories(lib/SDL/include lib/SDL_image/include)

add_subdirectory(lib/SDL EXCLUDE_FROM_ALL)
add_subdirectory(lib/SDL_image EXCLUDE_FROM_ALL)

target_link_libraries(Roy SDL3::SDL3)
target_link_libraries(Roy SDL3_image::SDL3_image)
