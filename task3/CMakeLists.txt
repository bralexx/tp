cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-c++)

project(SimpleLibrary)

include_directories(${SimpleLibrary_SOURCE_DIR}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)


add_executable(Main ${SimpleLibrary_SOURCE_DIR}/main.cpp)
add_executable(MainLib ${SimpleLibrary_SOURCE_DIR}/main_lib.cpp)

add_subdirectory(${SimpleLibrary_SOURCE_DIR}/scr}

target_link_libraries(MainLib buffer)

set_target_properties(MainLib PROPERTIES PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/include/buffer.h)

install(TARGETS Main MainLib buffer
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)

set_target_properties(MainLib PROPERTIES INSTALL_RPATH "$ORIGIN/../lib")
