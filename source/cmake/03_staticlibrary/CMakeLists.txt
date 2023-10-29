cmake_minimum_required(VERSION 3.5)

project(03_demo)


# Generate the static library from the library sources

add_library(core_library STATIC 
    src/core.cpp
)

target_include_directories(core_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


# Add an executable with the above sources
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# link the new core_library target with the core_binary target
target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        core_library
)