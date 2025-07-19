cmake_minimum_required(VERSION 3.5...3.18)
project(SimplePyBindExample)

find_package (Python3 COMPONENTS Interpreter Development REQUIRED) # the Development component is required, else we get an error: https://github.com/pybind/pybind11/issues/3996

execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE PYBIND11_CMAKE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SUDOKU_SRC
    wrapper.cpp
    board.cpp      # Add other .cpp files your board.h depends on
    # ... add more source files here ...
	arith.cpp
)

set(pybind11_DIR ${PYBIND11_CMAKE_DIR})

message(STATUS "Using pybind11 found at: ${pybind11_DIR}")
find_package(pybind11 REQUIRED)

# Create Python module
pybind11_add_module(sudoku SHARED ${SUDOKU_SRC})

set_target_properties(sudoku PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

# Needed for importing the "sudoku" module from the build directory
set(INIT_PY "${CMAKE_CURRENT_BINARY_DIR}/__init__.py")
if(NOT EXISTS ${INIT_PY})
    file(WRITE ${INIT_PY} "")
endif()

add_custom_command(TARGET sudoku POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE_DIR:sudoku>/$<TARGET_FILE_NAME:sudoku>
            ${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_FILE_NAME:sudoku>
)