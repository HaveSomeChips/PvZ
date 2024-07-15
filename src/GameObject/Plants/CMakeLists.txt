cmake_minimum_required(VERSION 3.16)

add_library(
        Plants
        STATIC
        Plants.hpp
        PlantSpot.hpp
        SunFlower.hpp
        Peashooter.hpp
        Wallnut.hpp
        CherryBomb.hpp
)

target_link_libraries(
        Plants
        Framework
        GameObject
)

target_include_directories(
        Plants
        PUBLIC
        ${CMAKE_SOURCE_DIR}/src/
        ${CMAKE_SOURCE_DIR}/src/Framework/
        ${CMAKE_SOURCE_DIR}/src/GameWorld/
        ${CMAKE_SOURCE_DIR}/src/GameObject/
)