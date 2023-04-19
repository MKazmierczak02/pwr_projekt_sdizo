cmake_minimum_required(VERSION 3.24)
project(projekt_sdizo)

enable_testing()

set(SOURCE_FILES main.cpp)
add_executable(project_run ${SOURCE_FILES})

add_subdirectory(Structures)
add_subdirectory(tests)
add_subdirectory(Handlers)
add_subdirectory(TimeTests)
