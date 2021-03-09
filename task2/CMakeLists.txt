cmake_minimum_required(VERSION 2.8)

project(task2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
execute_process(
	COMMAND python ${PROJECT_SOURCE_DIR}/A/preparing.py
)
include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(${PROJECT_SOURCE_DIR}/B)
add_executable(C ${PROJECT_SOURCE_DIR}/C/main.cpp)
message(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(C lib.lb)
