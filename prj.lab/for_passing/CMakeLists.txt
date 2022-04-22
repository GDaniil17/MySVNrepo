add_library(tmp tmp.h tmp.cpp)

add_executable(test_tmp test_tmp.cpp)

target_link_libraries(test_tmp tmp)
