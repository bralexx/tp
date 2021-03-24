cmake_minimum_required(VERSION 2.8)

project(task2)

find_package(GTest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

execute_process(
	COMMAND python ${PROJECT_SOURCE_DIR}/A/preparing.py
)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(${PROJECT_SOURCE_DIR}/B)
add_executable(C ${PROJECT_SOURCE_DIR}/C/main.cpp)
target_link_libraries(C lib.lb)

link_directories(${GTest_LIBRARY_DIRS})
target_link_libraries(C GTest::Main)


add_executable(CTest ${PROJECT_SOURCE_DIR}/C/main_test.cpp) 
#${PROJECT_SOURCE_DIR}/C/tests.cpp)
target_link_libraries(CTest lib.lb)
target_link_libraries(CTest GTest::Main)
