cmake_minimum_required(VERSION 3.22)
project(threads_using_class)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/inc)
add_subdirectory(src)

#
add_subdirectory(app)
