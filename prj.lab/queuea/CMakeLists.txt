add_library(queuea queuea.h queuea.cpp)

add_executable(test_queuea test_queuea.cpp)

target_link_libraries(test_queuea queuea)
