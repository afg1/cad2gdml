# cad2gdml
Simple program using CADMesh and Geant4 to export a GDML file from a CAD file (e.g. STL)

## Details

cad2gdml uses the [CADMesh](https://github.com/christopherpoole/cadmesh) library to import CAD geometries into 
[Geant4](http://geant4.cern.ch/) for conversion to GDML. GDML is a semi-standarddised syntax for geometry description
used in HEP and similar fields. Geant4 is used purely to do the conversion, no physics is done (there may be a better way to do this...).
