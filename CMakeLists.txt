cmake_minimum_required(VERSION 3.15)
project(life_desktop)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "/lib/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/lib/SFML-2.5.1/lib")
set(SFML_DIR "/lib/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/arial.ttf
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(life_desktop src/main.cpp src/Application.h src/Application.cpp
    src/life/Life.h src/life/Field.h src/life/Cell.h
    src/life/classic/ClassicLife.cpp src/life/classic/ClassicLife.h
    src/life/classic/ClassicField.cpp src/life/classic/ClassicField.h
    src/life/classic/ClassicCell.cpp src/life/classic/ClassicCell.h
    src/life/GameStatus.h)

target_link_libraries(life_desktop sfml-graphics sfml-audio)