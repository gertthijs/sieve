#*************************************************************************************#
#                                                                                     #
# Sieve definitions to clean up molecular structures by imposing drug-like rules      #
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
MOLWT                       170         530
ATOMS                        12          37
CARBONS                       8          28
HETERO_ATOMS                  3           9
HETERO_CARBON_RATIO         0.0         0.9
CHIRAL_CENTERS                0           6
HBOND_ACCEPTORS               1           8
HBOND_DONORS                  0           5
LIPINSKI_ACCEPTORS            1          10
LIPINSKI_DONORS               0           5
HALIDES                       0           2
HALIDE_FRACTION             0.0         0.5
FORMAL_CHARGES                0           1
TOTAL_FORMAL_CHARGE           0           0
RINGS                         1           5
ATOMS_IN_SMALLEST_RING        5           7
ATOMS_IN_LARGEST_RING         5           7
AROMATIC_RINGS                0           3
NONAROMATIC_RINGS             0           2
RINGSYSTEMS                   1           3
ATOMS_IN_SMALLEST_RINGSYSTEM  5          13
ATOMS_IN_LARGEST_RINGSYSTEM   5          13
RINGS_IN_SMALLEST_RINGSYSTEM  1           3
RINGS_IN_LARGEST_RINGSYSTEM   1           3
ROTATABLE_BONDS               0          11
RIGID_BONDS                   0           3
LOGP                       -2.0         3.0
TPSA                          7         153
LIPINSKI_VIOLATIONS           0           1
