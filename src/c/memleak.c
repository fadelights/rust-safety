#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // imports `sleep` -- use <windows.h> on Windows

char* leak() {
    size_t size = 4L * 1024 * 1024 * 1024; // 4GB
    char* ptr = (char*) malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // access memory to prevent optimization
    for (size_t i = 0; i < size; i += 1024 * 1024) {
        ptr[i] = 0; // initialize each megabyte to zero
    }

    return ptr;
}

int main() {
    char* p = leak();

    sleep(5);
    free(p);
    sleep(5);

    return 0;
}
