cmake_minimum_required(VERSION 3.16)

add_library(
        Seeds
        STATIC
        Seed.hpp
        SunFlowerSeed.hpp
        PeashooterSeed.hpp
        WallnutSeed.hpp
        CherryBombSeed.hpp
        Shovel.hpp
        CoolDownMask.hpp
)

target_link_libraries(
        Seeds
        Framework
        GameObject
        GameWorld
)

target_include_directories(
        Seeds
        PUBLIC
        ${CMAKE_SOURCE_DIR}/src/
        ${CMAKE_SOURCE_DIR}/src/Framework/
        ${CMAKE_SOURCE_DIR}/src/GameWorld/
        ${CMAKE_SOURCE_DIR}/src/GameObject/
)
