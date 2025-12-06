cmake_minimum_required(VERSION 3.22)
project(basic)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#
add_executable(basic_threading basic_threading.cpp)
add_executable(compute_sum compute_sum.cpp)
add_executable(with_or_without_mutex with_or_without_mutex.cpp)
add_executable(lock_guard_and_unique_lock lock_guard_and_unique_lock.cpp)
