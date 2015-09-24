# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: cpp11-seminar
project (cpp11-seminar)

# Output message
message("Build all examples of the C++11 seminar")

# Examples
add_subdirectory(01-hello)
add_subdirectory(02-input-output)
add_subdirectory(03-variables)
add_subdirectory(04-quadrature-static)
add_subdirectory(05-quadrature-oop1)
add_subdirectory(06-quadrature-oop1-templates)
add_subdirectory(07-quadrature-oop2-templates)
add_subdirectory(08-derived-classes)

# Homework
#add_subdirectory(H02-fraction)
add_subdirectory(H02-fraction-solved)
add_subdirectory(H03-matrix-vector)

