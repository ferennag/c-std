#pragma once

#include "std/defines.h"

typedef struct BinaryContents {
    void *data;
    u64 size;
} BinaryContents;

bool file_read_binary(const char *path, BinaryContents *out);