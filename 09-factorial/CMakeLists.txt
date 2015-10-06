# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: 09-factorial
project (09-factorial)

# Create an executable named 'factorial' from the source file 'factorial.cxx'
add_executable(factorial src/factorial.cxx)