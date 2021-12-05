set(MAIN_APP RadixSort)
project(${MAIN_APP} C)
add_executable(${MAIN_APP} RadixSort.c)

# Commutils 라이브러리 추가
target_include_directories(${MAIN_APP} PRIVATE ../${COMMON_LIB_PROJECT})
target_link_directories(${MAIN_APP} PRIVATE ../cmake-build-debug/${COMMON_LIB_PROJECT})
target_link_libraries(${MAIN_APP} PRIVATE ${COMMON_LIB_NAME})

# List Base Queue 라이브러리 추가
target_include_directories(${MAIN_APP} PRIVATE ../${LIST_BASE_QUEUE_LIB_PROJECT})
target_link_directories(${MAIN_APP} PRIVATE ../cmake-build-debug/${LIST_BASE_QUEUE_LIB_PROJECT})
target_link_libraries(${MAIN_APP} PRIVATE ${LIST_BASE_QUEUE_LIB_NAME})