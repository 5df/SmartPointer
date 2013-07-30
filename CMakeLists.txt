cmake_minimum_required(VERSION 2.8)

project(smartpointer)

set(SOURCES test.cpp SmartPointer1.cpp SmartPointer2.cpp)
set(HEADERS SmartPointer1.h SmartPointer2.h)

# Enable C++ 11
list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# Require to have CTest support. Must be called in top-level CMakeLists.txt.
enable_testing()

# Find the location of Boost.Test library, stores it in variable BOOST_TEST.
find_library(BOOST_TEST boost_unit_test_framework)

# Make Boost.Test generate the main() entry point.
add_definitions(-DBOOST_TEST_DYN_LINK )

# Create executable test_sp from source file)
add_executable(test_sp ${SOURCES} ${HEADERS})

# Link test_sp with Boost.Test library.
target_link_libraries(test_sp ${BOOST_TEST})

# Create a test named test_smart_pointer using executable test_sp.
add_test(test_smart_pointer test_sp)

set_target_properties(test_sp
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_SOURCE_DIR}/bin
  )


