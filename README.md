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

## Installation
I'll assume you already installed CADMesh and Geant4, if not, go find the installation instructions for those packages first.

First of all, clone the repository somewhere (I reccomend /usr/local/src):
  git clone https://github.com/afg1/cad2gdml

Enter the directory, create a build directory and enter that:
  cd cad2gdml
  mkdir build
  cd build

Now run cmake, you can change the install location with a CMake flag:
  cmake ../ -DCMAKE_INSTALL_PREFIX=/usr/local/

Now run make:
  make

I haven't put an install step in my CMakeLists.txt yet, so there is no make install. Just copy the binary "cad2gdml" into /usr/local/bin or elsewhere on your path. That's it!

## Usage
To get a reminder of this, you can just do cad2gdml with no commands:
  cad2gdml
  Usage:
  cad2gdml <CAD file>

That's basically it really. Note the important caveats in the Important Notes section above though.

## Possible developments
I would like to enable an optional command line argument to change the output filename, but this is pretty low on my priorities at the moment.

Any further suggestions are welcome!
