# /c_codes/c_clibs/CMakeLists.txt

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

# 정적 라이브러리 my_lib 를 만든다.
add_library(my_lib STATIC ${SRC_FILES})

# 해당 라이브러리 컴파일 시 사용할 헤더파일 경로
target_include_directories(my_lib PUBLIC ${CMAKE_SOURCE_DIR}/c_codes/c_libs)

# 해당 라이브러리를 컴파일 할 옵션
target_compile_options(my_lib PRIVATE -Wall -Werror)

# A 라이브러리가 B 라이브러리를 사용한다면 
# A 는 B 의 컴파일 옵션들과 헤더 파일 탐색 디렉토리 목록을 물려받게 됩니다.
# 정확히 말하면 PUBLIC 으로 설정된 것은 물려 받고, PRIVATE 으로 설정된 것은 물려받지 않습니다. 
