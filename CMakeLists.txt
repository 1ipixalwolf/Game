cmake_minimum_required(VERSION 3.10)

# Set the project name
project(GameProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the source files
set(SOURCES
    game/main.cpp
    game/Combatants.cpp
    game/fight.cpp
    game/sleep.cpp
    game/dread.cpp
    game/math.cpp
)

# Define the header files
set(HEADERS
    game/main.h
    game/combatants.h
    game/fight.h
    game/sleep.h
    game/dread.h
    game/math.h
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE game)

# Include the stories folder
add_custom_target(CopyStories ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/stories
    ${CMAKE_BINARY_DIR}/stories
)

# Make sure the stories are copied before building the executable
add_dependencies(${PROJECT_NAME} CopyStories)
