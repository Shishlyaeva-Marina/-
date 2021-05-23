cmake_minimum_required(VERSION 3.5)

project(exz LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    Window.cpp
    ExampleWindow.cpp
    mywindow.cpp
    )
set(HEADERS
    Window.h
    ExampleWindow.h
    mywindow.h
    )
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(exz${SDL2_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(exz main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(exz ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

