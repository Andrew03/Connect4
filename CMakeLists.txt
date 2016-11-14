# sets the minimum version of cmake 
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )
#	sets the project title
project ( connect_four )
#	allows the compiler to optimize code, set to Debug type if you want to debug
set( CMAKE_BUILD_TYPE Release )
# enables testing
enable_testing()

#	sets where the project binaries compiles to
set( CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build )
# sets where the executable compiles to
set( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR} )
# sets where the built libraries are compiled to
set( LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR} )

# sets compiler settings
set( CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Werror" )

#	brings header files into the project
include_directories( ${PROJECT_SOURCE_DIR} )
add_subdirectory( ${PROJECT_SOURCE_DIR}/lib/board )
add_subdirectory( ${PROJECT_SOURCE_DIR}/lib/game )

#	sets all the source files to the SOURCES variable
set( GLOB SOURCES "*.cpp" )


#	adds the executable file
add_executable( connect4 ${PROJECT_SOURCE_DIR}/main.cpp )
target_link_libraries( connect4 board )
target_link_libraries( connect4 game )
