# 툴체인 파일의 문법은 CMakeLists.txt와 같다.
# CMAKE_INIT을 사용하면 캐시 초기화 시에만 실행된다.

# clang 20 버전을 강제하는 툴체인 이다

cmake_minimum_required(VERSION 3.28)

message(STATUS "Loading Custom Toolchain: Clang")

# 컴파일러 설정
  # 호환성 버전으로 작성
  # set(<variable> <value>... CACHE <type> <docstring> [FORCE])
  set(CMAKE_C_COMPILER "clang-20" CACHE STRING "C compiler" FORCE)
  set(CMAKE_CXX_COMPILER "clang++-20" CACHE STRING "CXX compiler" FORCE)

  # 최신 CMAKE 문법으로 작성
  # set(CACHE{<variable>} [TYPE <type>] [HELP <helpstring>...] [FORCE] VALUE [<value>...])