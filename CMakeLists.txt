cmake_minimum_required(VERSION 3.10.0)

project(thesis 
    VERSION 0.1.0
    DESCRIPTION "A header only C++ library"
    LANGUAGES CXX
)

#########################################################
# Library
#########################################################

add_library(${PROJECT_NAME} main.cpp)

#########################################################
# Testing
#########################################################

include(CTest)
enable_testing()

add_executable(test_success test_success.cpp)
add_executable(test_failure test_failure.cpp)

add_test(NAME test_success COMMAND test_success)
add_test(NAME test_failure COMMAND test_failure)

########################################################
# Packaging
########################################################

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)