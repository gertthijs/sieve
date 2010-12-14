cmake_minimum_required (VERSION 2.6) 

# Project
project(sieve)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)
find_package(OpenBabel2 REQUIRED)

# Version
set (${PROJECT_NAME}_VERSION_MAJOR 3)
set (${PROJECT_NAME}_VERSION_MINOR 0)
set (${PROJECT_NAME}_VERSION_PATCH 2)
configure_file ("${PROJECT_SOURCE_DIR}/sieveConfig.h.in" "${PROJECT_SOURCE_DIR}/include/sieveConfig.h")

# Release type
set (CMAKE_BUILD_TYPE Release)

# Sieve code
set (SieveDir ${PROJECT_SOURCE_DIR}/src)
set (sources     ${SieveDir}/main.cpp
                 ${SieveDir}/calculator.cpp
                 ${SieveDir}/counter.cpp
                 ${SieveDir}/options.cpp
                 ${SieveDir}/parseCommandLine.cpp
                 ${SieveDir}/filters/filter.cpp
                 ${SieveDir}/filters/filterAbsorption.cpp
                 ${SieveDir}/filters/filterAndrewsEnergy.cpp
                 ${SieveDir}/filters/filterAromaticOverTotalRingFraction.cpp
                 ${SieveDir}/filters/filterAromaticRingFraction.cpp
                 ${SieveDir}/filters/filterAromaticRings.cpp
                 ${SieveDir}/filters/filterAtoms.cpp
                 ${SieveDir}/filters/filterAtomsInCore.cpp
                 ${SieveDir}/filters/filterAtomsInLargestAromaticRing.cpp
                 ${SieveDir}/filters/filterAtomsInLargestBridge.cpp
                 ${SieveDir}/filters/filterAtomsInLargestNonaromaticRing.cpp
                 ${SieveDir}/filters/filterAtomsInLargestRing.cpp
                 ${SieveDir}/filters/filterAtomsInLargestRingsystem.cpp
                 ${SieveDir}/filters/filterAtomsInLargestSidechain.cpp
                 ${SieveDir}/filters/filterAtomsInSmallestAromaticRing.cpp
                 ${SieveDir}/filters/filterAtomsInSmallestBridge.cpp
                 ${SieveDir}/filters/filterAtomsInSmallestNonaromaticRing.cpp
                 ${SieveDir}/filters/filterAtomsInSmallestRing.cpp
                 ${SieveDir}/filters/filterAtomsInSmallestRingsystem.cpp
                 ${SieveDir}/filters/filterAtomsInSmallestSidechain.cpp
                 ${SieveDir}/filters/filterBonds.cpp
                 ${SieveDir}/filters/filterBridgeFraction.cpp
                 ${SieveDir}/filters/filterBridges.cpp
                 ${SieveDir}/filters/filterCarbons.cpp
                 ${SieveDir}/filters/filterChiralCenters.cpp
                 ${SieveDir}/filters/filterCoreFraction.cpp
                 ${SieveDir}/filters/filterCores.cpp
                 ${SieveDir}/filters/filterDistance.cpp
                 ${SieveDir}/filters/filterElements.cpp
                 ${SieveDir}/filters/filterElementsExcluded.cpp
                 ${SieveDir}/filters/filterElementsOnly.cpp
                 ${SieveDir}/filters/filterFlexibility.cpp
                 ${SieveDir}/filters/filterFormalCharges.cpp
                 ${SieveDir}/filters/filterFragment.cpp
                 ${SieveDir}/filters/filterHalideFraction.cpp
                 ${SieveDir}/filters/filterHalides.cpp
                 ${SieveDir}/filters/filterHbondAcceptors.cpp
                 ${SieveDir}/filters/filterHbondDonors.cpp
                 ${SieveDir}/filters/filterHeteroAtoms.cpp
                 ${SieveDir}/filters/filterHeteroCarbonRatio.cpp
                 ${SieveDir}/filters/filterIntegerProperty.cpp
                 ${SieveDir}/filters/filterLigandEfficiency.cpp
                 ${SieveDir}/filters/filterLipinskiAcceptors.cpp
                 ${SieveDir}/filters/filterLipinskiDonors.cpp
                 ${SieveDir}/filters/filterLipinskiViolations.cpp
                 ${SieveDir}/filters/filterLogp.cpp
                 ${SieveDir}/filters/filterLogs.cpp
                 ${SieveDir}/filters/filterMolwt.cpp
                 ${SieveDir}/filters/filterNonaromaticOverTotalRingFraction.cpp
                 ${SieveDir}/filters/filterNonaromaticRingFraction.cpp
                 ${SieveDir}/filters/filterNonaromaticRings.cpp
                 ${SieveDir}/filters/filterRealProperty.cpp
                 ${SieveDir}/filters/filterRigidBonds.cpp
                 ${SieveDir}/filters/filterRingFraction.cpp
                 ${SieveDir}/filters/filterRings.cpp
                 ${SieveDir}/filters/filterRingsInLargestRingsystem.cpp
                 ${SieveDir}/filters/filterRingsInSmallestRingsystem.cpp
                 ${SieveDir}/filters/filterRingsystemFraction.cpp
                 ${SieveDir}/filters/filterRingsystems.cpp
                 ${SieveDir}/filters/filterRotatableBonds.cpp
                 ${SieveDir}/filters/filterSdf.cpp
                 ${SieveDir}/filters/filterSdfTag.cpp
                 ${SieveDir}/filters/filterSdfTagValue.cpp
                 ${SieveDir}/filters/filterSidechainFraction.cpp
                 ${SieveDir}/filters/filterSidechains.cpp
                 ${SieveDir}/filters/filterSimilarity.cpp
                 ${SieveDir}/filters/filterSimilarityStack.cpp
                 ${SieveDir}/filters/filterTitle.cpp
                 ${SieveDir}/filters/filterTotalFormalCharge.cpp
                 ${SieveDir}/filters/filterTpsa.cpp
)

# Include files from sieve project
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/filters)
include_directories(${OPENBABEL2_INCLUDE_DIR})

# Executables
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} ${OPENBABEL2_LIBRARIES})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)



#-----------------------------------------
# packaging source tar.gz
#
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Sieve: filtering of molecules.")
set(CPACK_PACKAGE_VENDOR "Silicos NV")
set(CPACK_PACKAGE_VERSION_MAJOR @sieve_VERSION_MAJOR@)
set(CPACK_PACKAGE_VERSION_MINOR @sieve_VERSION_MINOR@)
set(CPACK_PACKAGE_VERSION_PATCH @sieve_VERSION_PATCH@)

set(CPACK_RESOURCE_FILE_LICENSE "COPYING")
set(CPACK_RESOURCE_FILE_README "README.TXT")

set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES 
	".svn;/CMakeFiles/;.DS_Store;/_CPack_Packages/;CMakeCache.txt;sieve.tmproj;Makefile"
)
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

include(CPack)

