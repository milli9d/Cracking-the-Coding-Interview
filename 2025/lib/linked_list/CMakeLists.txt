add_library(ring_buffer INTERFACE)

target_include_directories(ring_buffer INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

add_library(CTCI::ring_buffer ALIAS ring_buffer)

# Add the source files to the library
add_executable(ring_buffer_tb
    ${CMAKE_CURRENT_LIST_DIR}/ring_buffer_tb.cpp
)

target_link_libraries(ring_buffer_tb
    PRIVATE CTCI::ring_buffer
)