# Force CMake version 2.6 or above
cmake_minimum_required (VERSION 2.6)

# This project has the name: 05-quadrature-oop1 
project (05-quadrature-oop1)

# Create an executable named 'quadrature-oop1' from the source file 'quadrature-oop1.cxx'
add_executable(quadrature-oop1 src/quadrature-oop1.cxx)

# We make use of some features from the C++11 standard. CMake provides
# a very elegant way to make sure, that the compiler is invoked with
# the correct flags (in case that is required) to turn on support for
# these features. The target_compile_features command is much more
# elegant than enforcing, e.g., the flag '-std=c++11' which is not
# valid for all compilers and might become unnecessary once C++11 is
# the default standard. For a list of supported features see:
# http://www.cmake.org/cmake/help/v3.3/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
target_compile_features(quadrature-oop1 PRIVATE cxx_auto_type
                                                cxx_delegating_constructors
                                                cxx_lambdas)