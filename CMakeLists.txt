# CMakeLists.txt
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(cad2gdml)

# GEANT4 core
find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

# CADMesh
find_package(cadmesh REQUIRED)
include_directories(${CADMESH_INCLUDE_DIRS})


add_executable(cad2gdml cad2gdml.cc) #${sources} ${headers})
target_link_libraries(cad2gdml ${Geant4_LIBRARIES})
target_link_libraries(cad2gdml ${cadmesh_LIBRARIES})