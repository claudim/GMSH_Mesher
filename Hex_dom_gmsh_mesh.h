#ifndef INC_3DMESHER_HEX_DOM_GMSH_MESH_H
#define INC_3DMESHER_HEX_DOM_GMSH_MESH_H

#include <set>
#include <cmath>
#include <filesystem>

// The Gmsh C++ API is entirely defined in the `gmsh.h' header (which contains the full documentation of all the functions in the API)
#include "gmsh.h"

class Hex_dom_gmsh_mesh {
public:
    void run(std::string inputFileName, std::string outputFileName) {

//            const std::string data_path = "/home/claudia/CLionProjects/GMSH_Mesher/DataInput";
//            //std::string name = "sfera";
//            //std::string name = "cube100x100axisAligned";
//            //std::string name = "bunny";
//            std::string name = "bolt";
//            std::string fileName = data_path + "/" + name + ".stl";

            // Before using any functions in the C++ API, Gmsh must be initialized
            gmsh::initialize();

            // Add a new model, named "sfera". If gmsh::model::add() is not called, a new default (unnamed) model will be created on the fly, if necessary.
            std::string name = std::filesystem::path(inputFileName ).filename();
            if(std::filesystem::path(name).has_extension())
            {
                //remove extension
                size_t lastindex = name.find_last_of(".");
                name = name.substr(0, lastindex);
            }

            gmsh::model::add(name);
            //gmsh::model::add("bunny");
           //gmsh::model::add("bolt");
            //gmsh::model::add("cube100x100axisAligned");
            //gmsh::model::add("sfera");

            // Let's merge an STL file that we would like to mesh.
            try {
                gmsh::merge(inputFileName);
            } catch(...) {
                gmsh::logger::write("Could not load STL mesh!");
                gmsh::finalize();
            }

        // Angle between two triangles above which an edge is considered as sharp:
        double angle = 40;

        // For complex geometries, patches can be too complex, too elongated or too
        // large to be parametrized; setting the following option will force the
        // creation of patches that are amenable to reparametrization:
       // bool forceParametrizablePatches = false;
        bool forceParametrizablePatches = true;

        // For open surfaces include the boundary edges in the classification process:
        bool includeBoundary = true;

        // Force curves to be split on given angle:
        double curveAngle = 180;

        gmsh::model::mesh::classifySurfaces(angle * M_PI / 180., includeBoundary,
                                            forceParametrizablePatches,
                                            curveAngle * M_PI / 180.);

//      Create a geometry for all the discrete curves and surfaces in the mesh, by computing a parametrization for each one
        gmsh::model::mesh::createGeometry();

        // Create a volume from all the surfaces
        std::vector<std::pair<int, int> > s;
        gmsh::model::getEntities(s, 2);
        std::vector<int> sl;
        for(auto surf : s) sl.push_back(surf.second);
        int l = gmsh::model::geo::addSurfaceLoop(sl);
        gmsh::model::geo::addVolume({l});

        gmsh::model::geo::synchronize();


//            //Create a surface loop (a shell). The expression-list inside the parentheses should contain the tags of all the surfaces that constitute the surface loop.
//            int surface_loop_1 = gmsh::model::geo::addSurfaceLoop({1});
//            //int surface_loop_1 = gmsh::model::geo::addSurfaceLoop({:});
//
//            //Create a volume. The expression-list inside the parentheses should contain the tags of all the surface loops defining the volume.
//            int volume_1 = gmsh::model::geo::addVolume({surface_loop_1});
//
//            gmsh::model::geo::synchronize();

            //2D mesh algorithm (1: MeshAdapt, 2: Automatic, 3: Initial mesh only, 5: Delaunay, 6: Frontal-Delaunay, 7: BAMG, 8: Frontal-Delaunay for Quads, 9: Packing of Parallelograms)
            gmsh::option::setNumber("Mesh.Algorithm", 2);

            //3D mesh algorithm (1: Delaunay, 3: Initial mesh only, 4: Frontal, 7: MMG3D, 9: R-tree, 10: HXT)
            gmsh::option::setNumber("Mesh.Algorithm3D", 1);

            //Mesh recombination algorithm (0: simple, 1: blossom, 2: simple full-quad, 3: blossom full-quad)
            gmsh::option::setNumber("Mesh.RecombinationAlgorithm", 3);

            //Mesh subdivision algorithm (0: none, 1: all quadrangles, 2: all hexahedra, 3: barycentric)
            gmsh::option::setNumber("Mesh.SubdivisionAlgorithm", 2);

            // Set Element order (1: first order elements, 2: second order element)
            gmsh::option::setNumber("Mesh.ElementOrder", 1);

            //Generate the 3D mesh of the current model
            gmsh::model::mesh::generate(3);

            //Save it to disk
            //gmsh::write("/Users/claudia/CLionProjects/3DMesher/MeshOutput/GmshHexMeshOutput/cube100x100axisAligned_gmsh.vtk");
            //gmsh::write("/Users/claudia/CLionProjects/3DMesher/MeshOutput/GmshHexMeshOutput/sfera_gmsh.vtk");
            //gmsh::write("/Users/claudia/CLionProjects/3DMesher/MeshOutput/GmshHexMeshOutput/bunny_gmsh.vtk");
            //std::string fileOutputName = "/home/claudia/CLionProjects/GMSH_Mesher/MeshOutput/" + name + "_gmsh.vtk";
            //gmsh::write(fileOutputName);

            gmsh::write(outputFileName);

            // This should be called when you are done using the Gmsh C++ API
            gmsh::finalize();

    };
};


#endif //INC_3DMESHER_HEX_DOM_GMSH_MESH_H
