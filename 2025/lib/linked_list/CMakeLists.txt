add_library(linked_list INTERFACE)

target_include_directories(linked_list INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

add_library(CTCI::linked_list ALIAS linked_list)

# Add the source files to the library
add_executable(linked_list_tb
    ${CMAKE_CURRENT_LIST_DIR}/linked_list_tb.cpp
)

target_link_libraries(linked_list_tb
    PRIVATE CTCI::linked_list
)