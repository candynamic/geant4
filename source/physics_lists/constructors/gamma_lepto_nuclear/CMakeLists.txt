#------------------------------------------------------------------------------
# CMakeLists.txt
# Module : G4phys_ctor_glnuclear
# Package: Geant4.src.G4physicslists.G4phys_ctors.G4phys_ctor_glnuclear
#
# CMakeLists.txt for building a single granular library.
#
# Generated on : 12-Jan-2013
#
#
#------------------------------------------------------------------------------

if(GEANT4_BUILD_GRANULAR_LIBS)
    include(Geant4MacroLibraryTargets)
    GEANT4_GRANULAR_LIBRARY_TARGET(COMPONENT sources.cmake)
endif()


