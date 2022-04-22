add_library(matrixls matrixls.h matrixls.cpp)

add_executable(test_matrixls test_matrixls.cpp)

target_link_libraries(test_matrixls matrixls)
