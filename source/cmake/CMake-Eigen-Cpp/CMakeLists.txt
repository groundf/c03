cmake_minimum_required(VERSION 3.5)

project(eigen_trial)

# find_package(Eigen3 REQUIRED)
# link_directories(${Eigen_INCLUDE_DIRS})

include_directories(
    ${CMAKE_SOURCE_DIR}/
    ${CMAKE_SOURCE_DIR}/external/eigen-3.3.9/
)

add_executable(${PROJECT_NAME} "main.cpp" "Ising2D.hpp")

target_link_libraries(${PROJECT_NAME}
   ${Eigen_LIBRARIES}
   )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
