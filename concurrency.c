#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    
    // Create a new thread
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        printf("Error creating thread\n");
        return 1;
    }
    
    // Wait for the thread to finish
    pthread_join(thread, NULL);
    printf("Thread has finished execution\n");
    
    return 0;
}
