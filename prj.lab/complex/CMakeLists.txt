add_library(complex complex.h complex.cpp)

add_executable(test_complex test_complex.cpp)

target_link_libraries(test_complex complex)