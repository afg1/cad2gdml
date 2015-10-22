#include "CADMesh.hh"

#include "G4GDMLParser.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VSolid.hh"
#include "G4ThreeVector.hh"
#include "G4NistManager.hh"

#include <sstream>
#include <string>



int main(int argc, char** argv)
{
    
    std::string fname;
    std::string ofname;
    if(argc == 1)
    {
        G4cout << "Usage:" << G4endl;
        G4cout << argv[0] << " <CAD file>" << G4endl;
        return 1;
    }
    else if(argc == 2)
    {
        fname = std::string(argv[1]);
    }
    else
    {
        return 2;
    }
    
    // Set up some pointers for the volumes.
    G4VSolid* cad_solid;
    G4LogicalVolume* cad_logical;
    G4VPhysicalVolume* cad_physical;
    
    // Load a dummy material, in this case vaccum
    G4NistManager* matMan = G4NistManager::Instance();
    G4Material* vac = matMan->FindOrBuildMaterial("G4_Galactic");// For the world
    
    // Load the mesh, use the value in argv because the function doesn't like std::string::c_str() for some reason
    CADMesh* mesh = new CADMesh(argv[1], mm, G4ThreeVector(), false);
    // Get a tessellated solid from the mesh
    cad_solid = mesh->TessellatedMesh();
    // Create logical and physical volumes.
    cad_logical = new G4LogicalVolume(cad_solid, vac, "cad_logical", 0, 0, 0);
    cad_physical = new G4PVPlacement(0, G4ThreeVector(), cad_logical, "cad_physical", 0, false, 0);
    
    // Process the input filename into an output filename (i.e. <whatever>.stl -> <whatever>.gdml)
    
    // Tokenize the input filename (i.e split on '.')
    std::istringstream iss(fname);
    std::vector<std::string> tokens;
    std::string token;
    while(std::getline(iss, token, '.'))
    {
        if(!token.empty())
        {
            tokens.push_back(token);
        }
    }
    
    // Create a new string from the first token, with the addititon of .gdml;
    std::stringstream oss;
    oss << tokens[0] << ".gdml";
    ofname = oss.str();
    
    // Create a GDML parser and use it to write out the file.
    G4GDMLParser gdmlParser;
    gdmlParser.Write(ofname.c_str() , cad_physical, true);

    return 0;
}