add_library(std STATIC std.c
        defines.h
        containers/darray.h
        containers/darray.c
        core/memory.h
        core/logger.h
        core/memory.c
        core/logger.c)
target_include_directories(std PUBLIC .)