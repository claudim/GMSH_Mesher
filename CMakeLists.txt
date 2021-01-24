cmake_minimum_required(VERSION 3.17)
project(GMSH_Mesher)

set(CMAKE_CXX_STANDARD 20)

find_library(GMSH_LIBRARY
        NAMES libgmsh.so)

add_executable(GMSH_Mesher main.cpp Hex_dom_gmsh_mesh.h Hex_dom_gmsh_mesh.cpp)

target_link_libraries(GMSH_Mesher PUBLIC ${GMSH_LIBRARY})