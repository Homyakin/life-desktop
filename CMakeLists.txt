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

add_executable(life_desktop src/main.cpp
    src/game/Life.h src/game/Field.h src/game/Cell.h
    src/game/simple/SimpleLife.cpp src/game/simple/SimpleLife.h
    src/game/simple/SimpleField.cpp src/game/simple/SimpleField.h
    src/game/simple/SimpleCell.cpp src/game/simple/SimpleCell.h
    src/game/GameStatus.h)

target_link_libraries(life_desktop sfml-graphics sfml-audio)