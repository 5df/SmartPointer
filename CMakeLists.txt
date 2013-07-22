cmake_minimum_required(VERSION 2.8)

project(smartpointer)

set(SOURCES main.cpp SmartPointer1.cpp SmartPointer2.cpp)
set(HEADERS SmartPointer1.h SmartPointer2.h)

add_executable(smartpointer
  ${SOURCES}
  ${HEADERS}
  )

set_target_properties(smartpointer
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_SOURCE_DIR}/bin
  )


