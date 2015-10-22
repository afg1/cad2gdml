# cad2gdml
Simple program using CADMesh and Geant4 to export a GDML file from a CAD file (e.g. STL)

## Details
cad2gdml uses the [CADMesh](https://github.com/christopherpoole/cadmesh) library to import CAD geometries into 
[Geant4](http://geant4.cern.ch/) for conversion to GDML. GDML is a semi-standarddised syntax for geometry description
used in HEP and similar fields. Geant4 is used purely to do the conversion, no physics is done (there may be a better way to do this...).

## Important notes
There are some important caveats to using this code:
* Materials are ignored, so everything in the GDML file comes out as vacuum. This means you will have to modify the GDML file to get the right materials before trying to track though it.
* The output file name is generated from the input file name, so *whatever*.stl -> *whatever*.gdml
* There is no checking for file overwrite, so be careful.
