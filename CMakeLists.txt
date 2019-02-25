project( liborza-qt LANGUAGES CXX C )

cmake_minimum_required( VERSION 2.7 )

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_C_STANDARD 11 )

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
set(CMAKE_C_FLAGS "-std=c11 ${CMAKE_C_FLAGS}")


# RPATH
set( CMAKE_MACOSX_RPATH 1 )

set( CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE )

set( LIBORZAQT_ROOT_PATH "${PROJECT_SOURCE_DIR}" )

add_subdirectory( src/ )
