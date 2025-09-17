#include <stdio.h>
#include <windows.h>

int main() {
    const char *sharedMemoryName = "Local\\MySharedMemory";
    const int SIZE = 256;

    // Create a file mapping object (shared memory)
    HANDLE hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        SIZE,
        sharedMemoryName
    );

    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    // Map view of the file
    char *sharedMem = (char *)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        SIZE
    );

    if (sharedMem == NULL) {
        printf("Could not map view of file (%d).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    printf("Enter a message to write to shared memory:\n");
    fgets(sharedMem, SIZE, stdin);

    printf("Message written to shared memory.\n");

    printf("Press Enter to close.\n");
    getchar();

    // Cleanup
    UnmapViewOfFile(sharedMem);
    CloseHandle(hMapFile);

    return 0;
}
