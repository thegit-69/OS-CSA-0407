#include <stdio.h>
#include <windows.h>

int main() {
    const char *sharedMemoryName = "Local\\MySharedMemory";
    const int SIZE = 256;

    // Open the existing file mapping object
    HANDLE hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,
        FALSE,
        sharedMemoryName
    );

    if (hMapFile == NULL) {
        printf("Could not open file mapping object (%d).\n", GetLastError());
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

    printf("Reading from shared memory:\n");
    printf("%s\n", sharedMem);

    printf("Press Enter to close.\n");
    getchar();

    // Cleanup
    UnmapViewOfFile(sharedMem);
    CloseHandle(hMapFile);

    return 0;
}
