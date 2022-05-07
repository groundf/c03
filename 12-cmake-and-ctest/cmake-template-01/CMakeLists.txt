cmake_minimum_required(VERSION 3.1...3.15)

project(project01 VERSION 1.0 LANGUAGES CXX)

set(detail_headers
	${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/detail/helper.hpp)

set(public_headers
  ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/project.hpp)


message(${CMAKE_CURRENT_BINARY_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})


add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} INTERFACE "$<BUILD_INTERFACE:${detail_headers};${header}>")

target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)

target_include_directories(${PROJECT_NAME} SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>)


# #############################################################################

if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
    file(DOWNLOAD
         https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp
         ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp
         STATUS status
         LOG log)

    list(GET status 0 status_code)
    list(GET status 1 status_string)

    if(NOT status_code EQUAL 0)
        message(FATAL_ERROR "Error downloading catch: ${status_string}!"
                "${log}")
    endif()
endif()

# #############################################################################

enable_testing()

set(test_files
	test/test_project.cpp)

add_executable(${PROJECT_NAME}_test ${test_files})

target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 17) 

add_test(
    NAME test 
    COMMAND ${PROJECT_NAME}_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}
    )
#add_subdirectory(example/)
#add_subdirectory(test/)