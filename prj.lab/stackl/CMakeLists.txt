add_library(stackl stackl.h stackl.cpp)

add_executable(test_stackl test_stackl.cpp)

target_link_libraries(test_stackl stackl)