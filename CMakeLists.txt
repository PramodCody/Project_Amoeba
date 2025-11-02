cmake_minimum_required(VERSION 3.28)

project(Project-Amoeba LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SDL3 from source
add_subdirectory("/home/desktoppramod/SDL3/SDL" SDL3_build)

# Add source files
set(SOURCES
        main.cpp
        GridLines.cpp
        graphics.cpp
        graphics.h
        # Add more .cpp files here as needed
)

# Include directories for headers
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        /home/desktoppramod/SDL3/SDL/include
)

# Add executable
add_executable(Project_Amoeba ${SOURCES})

# Link SDL3
target_link_libraries(Project_Amoeba PRIVATE SDL3::SDL3)

