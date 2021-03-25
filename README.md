#GMSH Mesher 

A C++ implementation of full automatic tool for 3D Meshing using Gmsh Library.

## Getting Started

### Requirements

1. clang++ 10.0 or higher or an equivalent compiler (gcc/g++ 9.x or higher)
2. C++ 20
3. CMake 3.16 or newer
4. Gmsh library 5.1 (https://gmsh.info/)


### Installing
- From terminal, move to the GMSH_Mesher directory

- Create a build folder
    `mkdir build`
    
- Navigate to the newly build folder  
    `cd build` 
    
- di    
`cmake ..`

- di
`make` or `make -j6`

 
### Usage

To use the executable:

-  Open terminal

-  Move to the build directory

-  Digit

    `./GMSH_Mesher path/to/the/STLfile/filename.stl  path/to/the/output/filename.vtk resolution`
    
    or 
    
    `./GMSH_Mesher path/to/the/STLfile/filename.stl  path/to/the/output/filename.mesh resolution`
    
    Example:
    
    `./3DMesher /Users/claudia/CLionProjects/3DMesher/DataInput/bolt.stl  /Users/claudia/CLionProjects/3DMesher/MeshOutput/bolt.mesh 8`
    
## Authors

 * Claudia Di Marco
 * Riccardo Mantini

