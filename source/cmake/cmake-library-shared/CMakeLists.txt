cmake_minimum_required(VERSION 3.13...3.16 FATAL_ERROR)
project(hello VERSION 1.0.0 LANGUAGES CXX)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

set (CMAKE_CXX_STANDARD 17)

message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

###############################################################################
# Library
# #############################################################################

add_library(
    ${PROJECT_NAME}.d
    SHARED
        src/Hello.cpp    
)

target_include_directories(
    ${PROJECT_NAME}.d
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

add_library(hello::shared ALIAS ${PROJECT_NAME}.d)


# #############################################################################
# Executable
# #############################################################################

add_executable(
    ${PROJECT_NAME}
    src/Main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE 
        hello::shared
)

install(
    TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)