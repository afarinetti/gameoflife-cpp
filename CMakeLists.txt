cmake_minimum_required(VERSION 3.22)

# set the project name
project(gameoflife VERSION 1.0.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# add sources
file(GLOB SOURCES "src/*.cpp")

# add the executable
add_executable(
    gameoflife
    ${SOURCES}
)

# add includes
target_include_directories(
    gameoflife
    PRIVATE
    ${PROJECT_SOURCE_DIR}/includes
)
