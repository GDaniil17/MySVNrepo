add_library(matrixds matrixds.h matrixds.cpp)

add_executable(test_matrixds test_matrixds.cpp)

target_link_libraries(test_matrixds matrixds)