cmake_minimum_required(VERSION 3.27)
project(std LANGUAGES C)

include(CTest)
enable_testing()

set(CMAKE_C_STANDARD 17)

add_subdirectory(src)
add_subdirectory(tests)

add_test(NAME tests COMMAND check_std)
