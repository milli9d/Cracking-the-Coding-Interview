add_library(binary_tree INTERFACE)

target_include_directories(binary_tree INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

add_library(CTCI::binary_tree ALIAS binary_tree)

# Add the source files to the library
add_executable(binary_tree_tb
    ${CMAKE_CURRENT_LIST_DIR}/binary_tree_tb.cpp
)

target_link_libraries(binary_tree_tb
    PRIVATE CTCI::binary_tree
)