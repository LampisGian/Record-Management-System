cmake_minimum_required(VERSION 3.30)
project(Record_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories("Source Code ")
include_directories(/usr/local/mysql-8.3.0-macos14-arm64/include)

add_executable(Record_Management_System
    "Source Code /Book.cpp"
    "Source Code /Book.hpp"
    "Source Code /DatabaseManager.cpp"
    "Source Code /DatabaseManager.hpp"
    "Source Code /FileManager.cpp"
    "Source Code /FileManager.hpp"
    "Source Code /main.cpp"
        "Source Code /BookService.cpp"
        "Source Code /BookService.hpp")

target_link_libraries(Record_Management_System /usr/local/mysql-8.3.0-macos14-arm64/lib/libmysqlclient.dylib)