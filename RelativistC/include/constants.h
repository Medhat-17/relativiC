#ifndef CONSTANTS_H
#define CONSTANTS_H

// Purpose: Stores fundamental physical constants for the simulation.

#define C_LIGHT (2.99792458e10)     // Speed of light [cm/s]
#define H_PLANCK (6.62607015e-27)   // Planck's constant [erg s]
#define ME_ELECTRON (9.1093837e-28) // Electron mass [g]
#define SIGMA_T (6.6524587e-25)     // Thomson scattering cross-section [cm^2]
#define ELECTRON_REST_ENERGY (ME_ELECTRON * C_LIGHT * C_LIGHT) // E = mc^2 [erg]
#define K_BOLTZMANN (1.380649e-16)  // Boltzmann constant [erg/K]

// Conversion factor for converting physical time to simulation time, etc.
#define TIME_UNIT (1.0e-5) // Example time unit [s]

#endif // CONSTANTS_H
