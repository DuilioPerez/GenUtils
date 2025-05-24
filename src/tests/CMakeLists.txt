# Test of CSLL.
add_executable(CSLL CSLL.c)
target_link_libraries(CSLL PRIVATE GenUtils-Shared)
# Test for CDLL.
add_executable(CDLL CDLL.c)
target_link_libraries(CDLL PRIVATE GenUtils-Shared)
