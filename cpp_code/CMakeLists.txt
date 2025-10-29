# made by google gemini
cmake_minimum_required(VERSION 3.28)

project(CppProject CXX)

# ----------------------------------------------------
# 1. "excel" 라이브러리 정의
# ----------------------------------------------------
# src/excel/ 에 있는 모든 .cpp 파일을 찾아서 EXCEL_SOURCES 변수에 답음
file(GLOB EXCEL_SOURCES "src/excel/*.cpp")

# "excel_lib" 라는 라이브러리를 만듦
add_library(excel_lib ${EXCEL_SOURCES})

# (중요) "excel_lib" 에게 헤더 파일이 어디 있는지 알려줌
# PUBLIC 키워드: "excel_lib" 자신도 'include' 폴더가 필요하고,
#               나중에 "excel_lib"를 쓰는 대상(my_app) 도 'include' 폴더가 필요함
target_include_directories(excel_lib PUBLIC lib)


# 'my_app' 이라는 이름의 실행 파일을 만듦
add_executable(my_app src/app/main.cpp)

# (가장 중요) "my_app"이 "excel_lib"를 사용하도록 연결(링크)
# 이 한 줄로 my_app은 excel_lib의 모든 기능을 쓰고,
# "include" 폴더 경로도 자동으로 인식하게 됩니다.
target_link_libraries(my_app PRIVATE excel_lib)

# (참고) 만약 t2.cpp로 별도 실행 파일을 만들고 싶다면?
# add_executable(my_app2 src/app/t2.cpp)
# target_link_libraries(my_app2 PRIVATE excel_lib)

