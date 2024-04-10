include(FetchContent)

FetchContent_Declare(check
        GIT_REPOSITORY https://github.com/libcheck/check.git
        GIT_TAG        0.15.2)
FetchContent_MakeAvailable(check)

add_executable(check_std tests.c
        containers/check_darray.c
        check_check.h
        containers/check_memory.c
        containers/check_list.c)
target_compile_options(check_std PRIVATE -g -Wall)
target_link_libraries(check_std std Check::check)
target_include_directories(check_std PRIVATE .)