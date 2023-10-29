
# The Windows SDK (where the Direct3D SDK is now part of) 
# is in the standard search paths e.g. of the linker for 
# libraries. So it's found automatically by the MSVC compiler and linker.

cmake_minimum_required(VERSION 3.15)

project(Direct3D12_Example01)

# You have to set WIN32 flag in add_executable!
add_executable(${PROJECT_NAME} WIN32 main.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE "UNICODE" "_UNICODE")

target_link_libraries(${PROJECT_NAME} PRIVATE "d3d12.lib" "dxgi.lib" "d3dcompiler.lib")

# add_custom_command(
#     TARGET ${PROJECT_NAME}
#     POST_BUILD
#     COMMAND "${CMAKE_COMMAND}" -E copy ${_shader} $<TARGET_FILE_DIR:${_name}>
# )