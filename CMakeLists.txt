cmake_minimum_required(VERSION 4.3.4)

project(Checklist LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(checklist.exe
        src/main.cpp
        src/table.cpp
)

target_link_libraries(checklist.exe PRIVATE Qt6::Widgets)