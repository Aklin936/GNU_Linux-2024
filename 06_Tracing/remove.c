#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>

typedef int (*remove_type)(const char *pathname);

int remove(const char *pathname) {
    remove_type real_remove = dlsym(RTLD_NEXT, "remove");