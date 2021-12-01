set(MAIN_APP HeapSort)
project(${MAIN_APP} C)
add_executable(${MAIN_APP} HeapSort.c)

# Commutils 라이브러리 추가
target_include_directories(${MAIN_APP} PRIVATE ../${COMMON_LIB_PROJECT})
target_link_directories(${MAIN_APP} PRIVATE ../cmake-build-debug/${COMMON_LIB_PROJECT})
target_link_libraries(${MAIN_APP} PRIVATE ${COMMON_LIB_NAME})

# Enhanced Heap 라이브러리 추가
target_include_directories(${MAIN_APP} PRIVATE ../${ENHANCED_HEAP_LIB_PROJECT})
target_link_directories(${MAIN_APP} PRIVATE ../cmake-build-debug/${ENHANCED_HEAP_LIB_PROJECT})
target_link_libraries(${MAIN_APP} PRIVATE ${ENHANCED_HEAP_LIB_NAME})
