# @file CMakeLists.txt
# 
# CMake files for functional decomposition examples

cmake_minimum_required(VERSION 3.10)

# project info
project(InputWords)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Assume each *.cpp file is a separate application for using WordInput
file(GLOB APPLICATIONS "*.cpp")
file(GLOB WORDINPUTLIST "WordInput.cpp")
list(GET WORDINPUTLIST 0 WORDINPUT)
list(REMOVE_ITEM APPLICATIONS ${WORDINPUT})
file(GLOB WORDINPUTLIST "WordReader.cpp")
list(GET WORDINPUTLIST 0 WORDINPUT)
list(REMOVE_ITEM APPLICATIONS ${WORDINPUT})

# Generate executable for each application
foreach(APP ${APPLICATIONS})

    # Use basename (no path, no extension) of .cpp file for application name
    get_filename_component(APPBASENAME "${APP}" NAME_WE)

	message("Generating target ${APPBASENAME}")

    # Application is based on .cpp file only
    add_executable(${APPBASENAME} ${APPBASENAME}.cpp WordInput.cpp WordReader.cpp)

endforeach()
