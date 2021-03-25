cmake_minimum_required(VERSION 3.17)
project(GMSH_Mesher)

set(CMAKE_CXX_STANDARD 20)

# --------------------------------------------------------------------------- #
# GMSH
# --------------------------------------------------------------------------- #

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if (LINUX)
    find_library(GMSH_LIBRARY
            NAMES libgmsh.so)
endif ()

if (APPLE)
    find_library(GMSH_LIB gmsh)
    if(NOT GMSH_LIB)
        message(FATAL_ERROR "Could not find libgmsh")
    endif()

    find_path(GMSH_INC gmsh.h)
    if(NOT GMSH_INC)
        message(FATAL_ERROR "Could not find gmsh.h")
    endif()
endif ()



add_executable(GMSH_Mesher main.cpp Hex_dom_gmsh_mesh.h)
target_include_directories(GMSH_Mesher PUBLIC ${GMSH_INC})
target_link_libraries(GMSH_Mesher PUBLIC ${GMSH_LIB})