#include <iostream>
#include "Hex_dom_gmsh_mesh.h"


/**
 * The command line arguments are handled using main() function arguments where argc refers to the number of arguments passed, and argv[] is a pointer array which points to each argument passed to the program.
 * @return
 */
int main(int argc, char *argv[] ) {

    if( argc == 2 ) {
        printf("The argument supplied is %s\n", argv[1]);
        std::string fileName = argv[1];
        Hex_dom_gmsh_mesh gmsh_mesher;

        // Get starting timepoint
        auto start_reading = std::chrono::high_resolution_clock::now();

        gmsh_mesher.run(fileName);

        // Get ending timepoint
        auto stop_reading = std::chrono::high_resolution_clock::now();

        // Get duration
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_reading - start_reading);

        std::cout << "Time taken by read function is : "
                  << duration.count() << " microseconds" << std::endl;

    }
    else if( argc > 2 ) {
        printf("Too many arguments supplied.\n");
    }
    else {
        printf("One argument expected.\n");
    }

    return 0;
}
