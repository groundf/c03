cmake_minimum_required(VERSION 3.20)

project(linalg)

add_library(${PROJECT_NAME} STATIC src/linalg.c)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)


add_executable(demo src/demo.c)
find_library(${PROJECT_NAME} ${PROJECT_NAME} lib)
target_link_libraries(demo LINK_PUBLIC ${PROJECT_NAME})