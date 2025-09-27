# CMkae 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.10)

# 프로젝트 정보
project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} ./c_codes/src/cmain.c )
# add_library()

target_link_libraries(${PROJECT_NAME} PRIVATE m)

target_compile_options(main PUBLIC -Wall -Werror)



