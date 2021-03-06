#*************************************************************************************#
#                                                                                     #
# Sieve definitions to clean up molecular structures by imposing lead-like rules      #
#                                                                                     #
# Tested on sieve v3.0.0                                                              #
#                                                                                     #
#*************************************************************************************#

#
# ALLOWED ELEMENTS
#
ONLY_ELEMENTS       H C N O F S Cl Br I Si B P


#
# PHYSICOCHEMICAL PROPERTIES
#
ANDREWS_ENERGY                      2.0    18.0
AROMATIC_RINGS                        0       4
ATOMS                                16      36
ATOMS_IN_SMALLEST_BRIDGE              1       6
ATOMS_IN_LARGEST_BRIDGE               1       6
ATOMS_IN_CORE                         9      31
ATOMS_IN_SMALLEST_RING                4       7
ATOMS_IN_LARGEST_RING                 4       7
ATOMS_IN_SMALLEST_RINGSYSTEM          3      13
ATOMS_IN_LARGEST_RINGSYSTEM           3      13
ATOMS_IN_SMALLEST_SIDECHAIN           1       5
ATOMS_IN_LARGEST_SIDECHAIN            1       5
BRIDGES                               0       2
BRIDGE_FRACTION                    0.00    0.25
CARBONS                              11      29
CHIRAL_CENTERS                        0       1
CORE_FRACTION                      0.42    1.00
CORES                                 1       1
FORMAL_CHARGES                        0       1
HALIDE_FRACTION                    0.00    0.25
HALIDES                               0       2
HBOND_ACCEPTORS                       1       8
HBOND_DONORS                          0       3
HETERO_ATOMS                          3      10
HETERO_CARBON_RATIO                   0       1
LIPINSKI_ACCEPTORS                    2       8
LIPINSKI_DONORS                       0       3
LIPINSKI_VIOLATIONS                   0       1
LOGP                                0.6     7.4
LOGS                               -8.7    -2.5
MOLWT                               230     520
NONAROMATIC_RINGS                     0       2
RIGID_BONDS                           0       4
RINGS                                 1       5
RINGS_IN_SMALLEST_RINGSYSTEM          1       3
RINGS_IN_LARGEST_RINGSYSTEM           1       3
RINGSYSTEMS                           1       4
ROTATABLE_BONDS                       0      10
SIDECHAIN_FRACTION                  0.0     0.5
SIDECHAINS                            1       6
TOTAL_FORMAL_CHARGE                  -1       1
TPSA                                  0     225
