add_library(matrixvs matrixvs.h matrixvs.cpp)

add_executable(test_matrixvs test_matrixvs.cpp)

target_link_libraries(test_matrixvs matrixvs)