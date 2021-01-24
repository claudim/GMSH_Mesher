#include "Hex_dom_gmsh_mesh.h"

//void Hex_dom_gmsh_mesh::run(){
//
//    const std::string data_path = "/Users/claudia/CLionProjects/GMSH_Mesher/DataInput";
//    std::string name = "sfera";
//    std::string fileName = data_path + "/" + name + ".stl";
//
//    // Before using any functions in the C++ API, Gmsh must be initialized
//    gmsh::initialize();
//
//    // Add a new model, named "sfera". If gmsh::model::add() is not called, a new default (unnamed) model will be created on the fly, if necessary.
//    gmsh::model::add("sfera");
//
//    // Let's merge an STL file that we would like to mesh.
//    try {
//        gmsh::merge(fileName);
//        //gmsh::merge("sfera.stl");
//    } catch(...) {
//        gmsh::logger::write("Could not load STL mesh!");
//        gmsh::finalize();
//        return 0;
//    }
//
//    //Create a surface loop (a shell). The expression-list inside the parentheses should contain the tags of all the surfaces that constitute the surface loop.
//    int surface_loop_1 = gmsh::model::geo::addSurfaceLoop({1});
//
//    //Create a volume. The expression-list inside the parentheses should contain the tags of all the surface loops defining the volume.
//    int volume_1 = gmsh::model::geo::addVolume({surface_loop_1});
//
//    //2D mesh algorithm (1: MeshAdapt, 2: Automatic, 3: Initial mesh only, 5: Delaunay, 6: Frontal-Delaunay, 7: BAMG, 8: Frontal-Delaunay for Quads, 9: Packing of Parallelograms)
//    gmsh::option::setNumber("Mesh.Algorithm", 2);
//
//    //3D mesh algorithm (1: Delaunay, 3: Initial mesh only, 4: Frontal, 7: MMG3D, 9: R-tree, 10: HXT)
//    gmsh::option::setNumber("Mesh.Algorithm3D", 1);
//
//    //Mesh recombination algorithm (0: simple, 1: blossom, 2: simple full-quad, 3: blossom full-quad)
//    gmsh::option::setNumber("Mesh.RecombinationAlgorithm", 3);
//
//    //Mesh subdivision algorithm (0: none, 1: all quadrangles, 2: all hexahedra, 3: barycentric)
//    gmsh::option::setNumber("Mesh.SubdivisionAlgorithm", 2);
//
//    // Set Element order (1: first order elements, 2: second order element)
//    gmsh::option::setNumber("Mesh.ElementOrder", 1);
//
//    //Generate the 3D mesh of the current model
//    gmsh::model::mesh::generate(3);
//
//    //Save it to disk
//    gmsh::write("/Users/claudia/CLionProjects/GMSH_Mesher/MeshOutput/sfera_gmsh.vtk");
//
//    // This should be called when you are done using the Gmsh C++ API
//    gmsh::finalize();
//}