add_library(std STATIC std/std.c
        std/defines.h
        std/containers/darray.h
        std/containers/darray.c
        std/core/memory.h
        std/core/logger.h
        std/core/memory.c
        std/core/logger.c)
target_include_directories(std PUBLIC .)