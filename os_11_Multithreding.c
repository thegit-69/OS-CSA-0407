#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by each thread
void* printMessage(void* arg) {
    char* message = (char*)arg;
    for (int i = 0; i < 2; i++) {
        printf("%s: Iteration %d\n", message, i + 1);
        sleep(1); // Sleep for 1 second to simulate work
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int ret1, ret2;

    // Creating first thread
    ret1 = pthread_create(&thread1, NULL, printMessage, "Thread 1");
    if (ret1) {
        printf("Error creating Thread 1\n");
        exit(-1);
    }

    // Creating second thread
    ret2 = pthread_create(&thread2, NULL, printMessage, "Thread 2");
    if (ret2) {
        printf("Error creating Thread 2\n");
        exit(-1);
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have completed execution.\n");
    return 0;
}
