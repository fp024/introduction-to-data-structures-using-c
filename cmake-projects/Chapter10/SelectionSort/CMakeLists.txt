cmake_minimum_required(VERSION 3.20)
set(MAIN_APP SelectionSort)
project(${MAIN_APP} C)
add_executable(${MAIN_APP} SelectionSort.c)

set(LIB_PROJECT CommonUtils)
set(LIB_NAME ${LIB_PROJECT})

target_include_directories(${MAIN_APP} PRIVATE ../${LIB_PROJECT})
target_link_directories(${MAIN_APP} PRIVATE ../cmake-build-debug/${LIB_PROJECT})
target_link_libraries(${MAIN_APP} PRIVATE ${LIB_NAME})