add_library(std STATIC std/std.c
        std/defines.h
        std/containers/darray.h
        std/containers/darray.c
        std/core/memory.h
        std/core/logger.h
        std/core/memory.c
        std/core/logger.c
        std/containers/list.h
        std/containers/list.c
        std/core/file.c
        std/core/file.h)
target_include_directories(std PUBLIC .)