project(Tests)

add_subdirectory(googletests-lib/googletest-main)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(GoogleTests
        ../FileIO/FileManager.cpp
        ../User/User.cpp
        ../UserListManagement/UserManager.cpp
        unittests.cpp)

target_link_libraries(GoogleTests gtest gtest_main)