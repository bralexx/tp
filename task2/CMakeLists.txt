cmake_minimum_required(VERSION 2.8)
project(task2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
execute_process(
	COMMAND python A/preparing.py
)

include_directories(.)
add_subdirectory(B)
add_executable(C C/main.cpp)
message("step1")
target_link_libraries(C lib.lb)
