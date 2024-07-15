cmake_minimum_required(VERSION 3.16)

add_library(
        Zombie
        STATIC
        Zombie.hpp
        RegularZombie.hpp
)

target_link_libraries(
        Zombie
        Framework
        GameObject
        GameWorld
)

target_include_directories(
        Zombie
        PUBLIC
        ${CMAKE_SOURCE_DIR}/src/
        ${CMAKE_SOURCE_DIR}/src/Framework/
        ${CMAKE_SOURCE_DIR}/src/GameWorld/
        ${CMAKE_SOURCE_DIR}/src/GameObject/
)
