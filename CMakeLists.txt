cmake_minimum_required(VERSION 3.15)
project(life_desktop)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "/lib/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/lib/SFML-2.5.1/lib")
set(SFML_DIR "/lib/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(life_desktop src/main.cpp
        src/game/Life.h src/game/SimpleLife.cpp src/game/SimpleLife.h
        src/game/models/Field.h src/game/models/SimpleField.cpp src/game/models/SimpleField.h
        src/game/models/cells/Cell.h src/game/models/cells/SimpleCell.cpp src/game/models/cells/SimpleCell.h)

target_link_libraries(life_desktop sfml-graphics sfml-audio)