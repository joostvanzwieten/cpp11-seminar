# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: 03-variables 
project (03-variables)

# Create an executable named 'variables' from the source file 'variables.cxx'
add_executable(variables src/variables.cxx)
