add_library(lru_cache INTERFACE)

target_include_directories(lru_cache INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

add_library(CTCI::lru_cache ALIAS lru_cache)

# Add the source files to the library
add_executable(lru_cache_tb
    ${CMAKE_CURRENT_LIST_DIR}/lru_cache_tb.cpp
)

target_link_libraries(lru_cache_tb
    PRIVATE CTCI::lru_cache
)