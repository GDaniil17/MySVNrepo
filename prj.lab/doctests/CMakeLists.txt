add_executable(doctest_complex doctest_complex.cpp)

target_link_libraries(doctest_complex complex)

add_executable(doctest_rational doctest_rational.cpp)

target_link_libraries(doctest_rational rational)

add_executable(doctest_arrayd doctest_arrayd.cpp)

target_link_libraries(doctest_arrayd arrayd)

add_executable(doctest_matrixvs doctest_matrixvs.cpp)

target_link_libraries(doctest_matrixvs matrixvs)

add_executable(doctest_matrixds doctest_matrixds.cpp)

target_link_libraries(doctest_matrixds matrixds)


