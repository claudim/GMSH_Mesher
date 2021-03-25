//******************************************************************************
// File Description :
// Main file for the generation of a hex mesh using Gmsh library.
//******************************************************************************

#include <iostream>
#include "Hex_dom_gmsh_mesh.h"


/**
 * The command line arguments are handled using main() function arguments where argc refers to the number of arguments passed, and argv[] is a pointer array which points to each argument passed to the program.
 */
int main(int argc, char *argv[] ) {

    if( argc == 4 ) {
        printf("The argument supplied is %s\n", argv[1]);
        std::string inputFileName = argv[1];
        std::string outputFileName = argv[2];
        double maxMeshElementSize = std::stod(argv[3]);

        Hex_dom_gmsh_mesh gmsh_mesher;
        gmsh_mesher.run(inputFileName, outputFileName, maxMeshElementSize);

    }
    else if( argc > 4 ) {
        printf("Too many arguments supplied.\n");
    }
    else {
        printf("Three argument expected.\n");
    }

    return 0;
}
