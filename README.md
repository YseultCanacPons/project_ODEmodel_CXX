# ODE Solver Project

This project implements a numerical solver for a system of Oradinary Differential Equations (ODEs) using both **explicit** and **implicit** Euler schemes.

---

## Objectives

- Implement a modular ODE simulation framework
- Compare explicit vs. implicit Euler methods
- Use object-oriented programming and clean C++ architecture
- Structure a small project using CMake
- Ensure code readability and maintainability

---

## Project Structure

```
/
├── include/
│ ├── etat.h
│ ├── parametres.h
│ ├── modele.h
│ └── solveur.h
├── src/
│ ├── main.cpp
│ ├── modele.cpp
│ ├── solveurExplicite.cpp
│ └── solveurImplicite.cpp
├── CMakeLists.txt
└── README.md
```

---

## Build Instructions (CMake)

This project uses **CMake** to configure and build the executable.

```bash
mkdir build
cd build
cmake ..
make
```

The compiled program will be available as : **./projet**

---

## Running the Program

After execution, the program asks for :
1. Time step **dt**
2. Number of iterations **N**
3. Choice of solver
  - **1** -> explicit Euler
  - **2** -> inplicit Euler (Newton)

Example run :
```
Donnez le pas de temps dt : 1
Donnez le nombre total de pas N : 100
Choisissez le solveur (1 = explicite, 2 = implicite) : 2
Valeur finale de CA = 0.522211
Valeur finale de CS = 0.652763
Valeur finale de CT = 0.326382
```

---

## Mathematical Model

The ODE system models interactions between three compartments :
$
dCA/dt = -α·CA + β·CS  
dCS/dt =  α·CA − (β + γ)·CS + δ·CT  
dCT/dt =  γ·CS − δ·CT
$
Parameters are stored in parametres.h and can be modified easily.

---

## Numerical Methods

### Explicit Euler

Simple and fast, but conditionally stable :
$
y_{n+1} = y_n + dt * f(y_n)
$

### Implicit Euler (Newton method)

Stable for stiff systems :
$
y_{n+1} = y_n + dt * f(y_{n+1})
$

Impplemented with :
- Analytical Jacobian
- Newton iterations
- Convergence tolerance
- Invariant enforcement (state non-negativity)

---

## C++ Design Principles

- Clear seperation between model and solver
- Header/source split (h/cpp)
- Abstract base class for solvers
- Encapsulation of Newton method inside implicit solver
- **inline** invariants to avoid multiple definition issues

