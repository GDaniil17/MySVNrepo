add_library(arrayd arrayd.h arrayd.cpp)

add_executable(test_arrayd test_arrayd.cpp)

target_link_libraries(test_arrayd arrayd)