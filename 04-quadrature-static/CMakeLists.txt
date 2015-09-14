# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: 04-quadrature-static 
project (04-quadrature-static)

# Create an executable named 'quadrature-static' from the source file 'quadrature-static.cxx'
add_executable(quadrature-static src/quadrature-static.cxx)
