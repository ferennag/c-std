#include "file.h"

#include <stdio.h>
#include <std/core/logger.h>
#include <std/core/memory.h>

void *file_read_binary(const char *path) {
    FILE *file = fopen(path, "rb");

    if (!file) {
        LOG_ERROR("Unable to open file for reading: %s", path);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    void *buffer = memory_alloc(size);
    u64 result = fread(buffer, size, 1, file);
    fclose(file);

    if (result != 1) {
        LOG_ERROR("Unable to read from file: %s", path);
        return NULL;
    }

    return buffer;
}