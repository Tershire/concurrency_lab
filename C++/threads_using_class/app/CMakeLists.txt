add_executable(execute execute.cpp)
add_executable(execute_alternative execute_alternative.cpp)

target_link_libraries(execute
    threads_using_class)
target_link_libraries(execute_alternative
    threads_using_class)
