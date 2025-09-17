#include <stdio.h>
#include <windows.h>

#define SIZE 5
int buffer[SIZE], in = 0, out = 0;
HANDLE empty, full, mutex;

DWORD WINAPI producer(LPVOID arg) {
    for(int i = 0; i < 10; i++) {
        WaitForSingleObject(empty, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        buffer[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % SIZE;

        ReleaseMutex(mutex);
        ReleaseSemaphore(full, 1, NULL);
        Sleep(500);
    }
    return 0;
}

DWORD WINAPI consumer(LPVOID arg) {
    for(int i = 0; i < 10; i++) {
        WaitForSingleObject(full, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % SIZE;

        ReleaseMutex(mutex);
        ReleaseSemaphore(empty, 1, NULL);
        Sleep(1000);
    }
    return 0;
}

int main() {
    empty = CreateSemaphore(NULL, SIZE, SIZE, NULL);
    full = CreateSemaphore(NULL, 0, SIZE, NULL);
    mutex = CreateMutex(NULL, FALSE, NULL);

    HANDLE prod = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    HANDLE cons = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    WaitForSingleObject(prod, INFINITE);
    WaitForSingleObject(cons, INFINITE);

    CloseHandle(empty);
    CloseHandle(full);
    CloseHandle(mutex);
    return 0;
}
