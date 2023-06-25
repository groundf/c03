cmake_minimum_required(VERSION 3.5)

project (02_demo)

set(SOURCES
    src/core.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

#  g++ -I/directory/path/
target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)