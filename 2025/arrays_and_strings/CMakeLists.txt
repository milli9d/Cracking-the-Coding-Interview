
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

foreach(SOURCE ${SOURCES})
    get_filename_component(SOURCE_NAME ${SOURCE} NAME_WE)
    add_executable(${SOURCE_NAME} ${SOURCE})
endforeach()