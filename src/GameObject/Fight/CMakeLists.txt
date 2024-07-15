cmake_minimum_required(VERSION 3.16)

add_library(
        Fight
        STATIC
        Fight.hpp 
        Pea.hpp
        Explosion.hpp
        )

target_link_libraries(
        Fight
        Framework
        GameObject
        GameWorld
)

target_include_directories(
        Fight
        PUBLIC
        ${CMAKE_SOURCE_DIR}/src/
        ${CMAKE_SOURCE_DIR}/src/Framework/
        ${CMAKE_SOURCE_DIR}/src/GameWorld/
        ${CMAKE_SOURCE_DIR}/src/GameObject/
)
