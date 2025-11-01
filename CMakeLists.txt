# CMkae 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.28)

# 프로젝트 정보
project(
  MyLearningRoot
  LANGUAGES C CXX
)
# 3. (중요) clangd를 위한 .json 파일 생성 설정
# 이 설정을 맨 위에 두면 모든 하위 프로젝트에 적용됩니다.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 의미: 이 프로젝트에서 사용할 C++ 표준 버전은 20이다.
# 즉, -std=c++20 플래그를 컴파일러에 추가하도록 CMake에게 지시합니다.
# set(CMAKE_C_STANDARD 23)
# # 의미: C++20을 반드시 사용해야 한다.
# # 설정하지 않으면 이전 표준 (C++17 등)으로 자동으로 fallback 가능
# set(CMAKE_C_STANDARD_REQUIRED YES)
# # 의미: 컴파일러의 비표준 확장 기능은 사용하지 않는다.
# set(CMAKE_C_EXTENSIONS OFF)


# "cpp_code" 폴더로 내려가서 거기 있는 CMakeLists.txt를 실행
add_subdirectory(cpp_code)

# "c_code" 폴더로 내려가서 거기 있는 CMakeLists.txt를 실행
# add_subdirectory(c_code)


# # 실행 파일
#   add_executable(main ${CMAKE_SOURCE_DIR}/c_codes/src/cmain.c)

# # main 에 my_lib 를 링크 
#   target_link_libraries(main my_lib)

# # main 를 컴파일 할 옵션 설정.
#   target_compile_options(main PUBLIC -Wall -Werror)


