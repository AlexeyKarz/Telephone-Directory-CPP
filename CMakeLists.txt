cmake_minimum_required(VERSION 3.27)
project(TelDirectory)

set(CMAKE_CXX_STANDARD 17)

add_executable(TelDirectory main.cpp
        User/User.h
        User/User.cpp
        LinkedList/LinkedList.h
        LinkedList/LinkedList.cpp
        LinkedList/Node.h
        LinkedList/Node.h
        LinkedList/Node.cpp)
