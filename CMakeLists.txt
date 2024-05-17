cmake_minimum_required(VERSION 3.27)
project(TelDirectory)

set(CMAKE_CXX_STANDARD 17)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug/teldir.txt
        ${CMAKE_CURRENT_BINARY_DIR})

add_executable(TelDirectory main.cpp
        User/User.h
        User/User.cpp
        LinkedList/LinkedList.h
        LinkedList/Node.h
        LinkedList/Node.h
        FileIO/FileManager.h
        FileIO/FileManager.cpp
        UserListManagement/UserManager.h
        UserListManagement/UserManager.cpp)
