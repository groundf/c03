cmake_minimum_required(VERSION 3.1)

project(example01)

if (MSVC)
    message("CMAKE_BUILD_TYPE is " ${CMAKE_BUILD_TYPE})
    message("DEBUG DEFAULT FLAGS are " ${CMAKE_CXX_FLAGS_DEBUG})
    message("RELEASE DEFAULT FLAGS are " ${CMAKE_CXX_FLAGS_RELEASE})

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()

add_executable(example01 example.cpp)
