cmake_minimum_required(VERSION 4.0)
project(C_pp_Study)

set(CMAKE_CXX_STANDARD 17)

# Homebrew로 설치된 Catch2를 찾습니다.
# Catch2가 설치되어 있지 않으면 오류가 발생할 수 있습니다.
find_package(Catch2 REQUIRED)

add_executable(C_pp_Study
        main.cpp
        AutoBrake.cpp
        DeadMenOfDunharrow.cpp
        AutoBrake.cpp
)

# Catch2 라이브러리를 실행 파일에 연결합니다.
# Catch2::Catch2WithMain은 main() 함수가 포함된 라이브러리입니다.
target_link_libraries(C_pp_Study PRIVATE Catch2::Catch2WithMain)
