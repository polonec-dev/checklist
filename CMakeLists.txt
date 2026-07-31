cmake_minimum_required(VERSION 3.31.12)

project(Checklist LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(checklist WIN32
        src/main.cpp
        src/table.cpp
)

target_link_libraries(checklist PRIVATE Qt6::Widgets)