cmake_minimum_required(VERSION 3.16)
project(Chapter10 C)

set(CMAKE_C_STANDARD 99)

if (${MSVC})
    # Visual Studio cl.exe를 사용할 때, 터미널 환경은 CP949 인데, 소스파일을 UTF-8로 저장해서 관리할 경우, 컴파일러 아래 옵션을 전달한다.
    add_compile_options(/source-charset:utf-8 /execution-charset:euc-kr)
elseif (${MINGW})
    # MinGW 환경에서는 아래 옵션을 전달한다.
    add_compile_options(-fexec-charset=CP949 -g -W -Wall)
elseif (${CYGWIN})
    # Cygwin 환경에서는 따로 인코딩 옵션을 붙여줄 필요가 없었다.
endif ()

# 공통 함수 모음 라이브러리
set(COMMON_LIB_PROJECT CommonUtils)
set(COMMON_LIB_NAME ${COMMON_LIB_PROJECT})

# 9장에서 진행했던 Enhanced Heap
# 9장은 Visual Studio 2019 프로젝트로 진행해서, 여기에 불러다 사용하기가 애매해서, 현재 CMake 프로젝트에 소스코드를 새로 작성하자!
set(ENHANCED_HEAP_LIB_PROJECT EnhancedHeap)
set(ENHANCED_HEAP_LIB_NAME ${ENHANCED_HEAP_LIB_PROJECT})

# 7장에서 진행했던 List Base Queue
set(LIST_BASE_QUEUE_LIB_PROJECT ListBaseQueue)
set(LIST_BASE_QUEUE_LIB_NAME ${LIST_BASE_QUEUE_LIB_PROJECT})


add_subdirectory(CommonUtils)
add_subdirectory(EnhancedHeap)
add_subdirectory(ListBaseQueue)

add_subdirectory(BubbleSort)
add_subdirectory(SelectionSort)
add_subdirectory(InsertionSort)
add_subdirectory(HeapSort)
add_subdirectory(MergeSort)
add_subdirectory(QuickSort)
add_subdirectory(RadixSort)
