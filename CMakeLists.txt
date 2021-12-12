cmake_minimum_required(VERSION 3.21)
project(huskyTechS)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_CURRENT_SOURCE_DIR huskyTech1)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D WIN32")
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(huskyTechS
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Map.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sprite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Character.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TileRenderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HuskyMath.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MapGenerator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Entity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Blendspace.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HuskySTD.cpp
        )
target_link_libraries(huskyTechS ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})