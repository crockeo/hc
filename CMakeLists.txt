cmake_minimum_required(VERSION 2.8)
project(hc)

# Finding cmake files.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Setting output paths.
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/lib")

# Setting the C++ 11 flag.
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# Defining the set of sources.
set(SOURCES
    src/hcexception.cpp
    src/rectangle.cpp
    src/assets.cpp
    src/sprite.cpp
    src/window.cpp
    src/main.cpp
)

# Actually setting up the executable.
add_executable(hc ${SOURCES})

# Finding SDL2 and its things.
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

target_link_libraries(hc ${SDL2_LIBRARY}
                         ${SDL2_IMAGE_LIBRARIES}
                         ${SDL2_TTF_LIBRARIES})
