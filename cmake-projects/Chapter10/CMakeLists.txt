cmake_minimum_required(VERSION 3.20)
project(Chapter10 C)

set(CMAKE_C_STANDARD 99)

if (${MSVC})
    # Visual Studio cl.exe를 사용할 때, 터미널 환경은 CP949 인데, 소스파일을 UTF-8로 저장해서 관리할 경우, 컴파일러 아래 옵션을 전달한다.
    add_compile_options(/source-charset:utf-8 /execution-charset:euc-kr)
elseif (${MINGW})
    # MinGW 환경에서는 아래 옵현을 전달한다.
    add_compile_options(-fexec-charset=CP949 -g -W -Wall)
elseif (${CYGWIN})
    # Cygwin 환경에서는 따로 인코딩 옵션을 붙여줄 필요가 없었다.
endif ()

set(COMMON_LIB_PROJECT CommonUtils)
set(COMMON_LIB_NAME ${COMMON_LIB_PROJECT})

add_subdirectory(CommonUtils)
add_subdirectory(BubbleSort)
add_subdirectory(SelectionSort)




