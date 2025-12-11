cmake_minimum_required(VERSION 3.16)
project(RotatingTeapot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(FreeGLUT CONFIG REQUIRED)

add_executable(rotating_teapot
    src/main.cpp
)

target_link_libraries(rotating_teapot
    PRIVATE
        SDL2::SDL2
        SDL2::SDL2main
        OpenGL::GL
        OpenGL::GLU
        FreeGLUT::freeglut_static
)
