# RelativistC: Relativistic Monte Carlo Radiation Transport Engine

## Purpose

**RelativistC** is an ambitious, custom-built C project designed to simulate radiation transport processes, such as Compton scattering, within dynamically curved spacetimes, including those described by the Schwarzschild and Kerr metrics. It uses a Monte Carlo approach to trace photon geodesics and model light-matter interactions in high-energy astrophysics environments (e.g., accretion disks, black hole magnetospheres).

## Key Features

- **Relativistic Geodesic Tracing:** Uses 4th-order Runge-Kutta (RK4) integration to solve the geodesic equation for null paths in general relativity.  
- **Curved Spacetime Metrics:** Includes initial support for the Schwarzschild metric, with plans to extend to the Kerr metric.  
- **Monte Carlo Scattering:** Models photon interactions, primarily Compton Scattering, using the Klein-Nishina cross-section.  
- **Parallelism:** Utilizes OpenMP for efficient, parallel processing of individual photon trajectories.  
- **Modular Design:** Separates core physics (metric, compton), simulation structure (photon, grid), and utilities (random, io) for maintainability and easy extension.  

## Directory Structure

| File | Purpose |
|------|----------|
| **main.c** | Orchestrates simulation setup, execution, and results output. |
| **photon.h/.c** | Defines the photon state and handles its creation, movement, and scattering. |
| **metric.h/.c** | Defines and computes the metric tensor components (g_{μν}, g^{μν}) and Christoffel symbols (Γ^α_{μν}). |
| **integrator.h/.c** | Implements the Runge-Kutta 4th Order (RK4) method for integrating geodesics. |
| **random.h/.c** | Implements a robust, parallel random number generator (PCG). |
| **compton.h/.c** | Defines functions for relativistic Compton scattering, including energy and angle shifts. |
| **grid.h/.c** | Defines the spatial domain and manages grid cells for fluid properties and optical depth accumulation. |
| **parallel.h/.c** | Declares and implements OpenMP utilities for multithreaded execution. |
| **io.h/.c** | Handles reading configuration files and writing simulation output data. |
| **constants.h** | Stores fundamental physical constants (c, h, m_e, σ_T). |
| **Makefile** | Script to compile all project modules efficiently. |

## Compilation

To compile the project using the provided Makefile (requires GCC with OpenMP support):

```bash
make
```

This will produce the executable file `relativistc`.

## Execution

To run the simulation:

```bash
./relativistc
```

The program will load default settings (or read from `config.txt` if implemented), run the simulation across multiple threads, and output a summary to `relativistc_output.dat`.


![Photon Trajectories around a Black Hole](RelativistC/src/metric.png)



