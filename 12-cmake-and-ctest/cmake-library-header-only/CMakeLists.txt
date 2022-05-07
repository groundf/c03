
cmake_minimum_required(VERSION 3.13...3.16 FATAL_ERROR)

project(sample VERSION 1.0.0 LANGUAGES CXX)

# Make sure that custom modules are found
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

set (CMAKE_CXX_STANDARD 17)


# Detect operating system and host processor
message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")
message(STATUS "The host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)


##################################################    Targets     ##################################################

# Create target and set properties
add_library(${PROJECT_NAME} INTERFACE)


##################################################    Testing     ##################################################


##################################################    Package     ##################################################

