# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: variadic-templates 
project (variadic-templates)

# Create an executable named 'variadic-templates' from the source file 'variadic-templates.cxx'
add_executable(variadic-templates src/variadic-templates.cxx)

# We make use of some features from the C++11 standard. CMake provides
# a very elegant way to make sure, that the compiler is invoked with
# the correct flags (in case that is required) to turn on support for
# these features. The target_compile_features command is much more
# elegant than enforcing, e.g., the flag '-std=c++11' which is not
# valid for all compilers and might become unnecessary once C++11 is
# the default standard. For a list of supported features see:
# http://www.cmake.org/cmake/help/v3.3/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
target_compile_features(variadic-templates PRIVATE cxx_variadic_templates)
