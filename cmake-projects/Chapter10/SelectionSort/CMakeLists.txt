set(MAIN_APP SelectionSort)
project(${MAIN_APP} C)
add_executable(${MAIN_APP} SelectionSort.c)

target_include_directories(${MAIN_APP} PRIVATE ../${COMMON_LIB_PROJECT})
target_link_directories(${MAIN_APP} PRIVATE ../cmake-build-debug/${COMMON_LIB_PROJECT})
target_link_libraries(${MAIN_APP} PRIVATE ${COMMON_LIB_NAME})