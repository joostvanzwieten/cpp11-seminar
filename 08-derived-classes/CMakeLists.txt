# Force CMake version 3.2 or above
cmake_minimum_required (VERSION 3.2)

# This project has the name: 08-derived-classes
project (08-derived-classes)

# Create an executable named 'derived-classes' from the source file 'derived-classes.cxx'
add_executable(derived-classes src/derived-classes.cxx)

# We make use of some features from the C++11 standard. CMake provides
# a very elegant way to make sure, that the compiler is invoked with
# the correct flags (in case that is required) to turn on support for
# these features. The target_compile_features command is much more
# elegant than enforcing, e.g., the flag '-std=c++11' which is not
# valid for all compilers and might become unnecessary once C++11 is
# the default standard. For a list of supported features see:
# http://www.cmake.org/cmake/help/v3.3/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
target_compile_features(derived-classes PRIVATE cxx_delegating_constructors)
