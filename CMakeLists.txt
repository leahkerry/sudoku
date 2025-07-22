cmake_minimum_required(VERSION 3.5...3.18)
project(SimplePyBindExample)

# Python3 dev tools required for pybind11
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Get pybind11's cmake directory via Python
execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE PYBIND11_CMAKE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
set(pybind11_DIR ${PYBIND11_CMAKE_DIR})
find_package(pybind11 REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SUDOKU_SRC
    wrapper.cpp
    board.cpp
    arith.cpp
)

# Output module to build/ for import
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Build the pybind11 module
pybind11_add_module(sudoku MODULE ${SUDOKU_SRC})
set_target_properties(sudoku PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# Add __init__.py to the output dir to make it a Python package
add_custom_command(TARGET sudoku POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E touch "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/__init__.py"
)
