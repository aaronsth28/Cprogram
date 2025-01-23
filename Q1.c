#include <pthread.h>
#include <stdio.h>

int counter = 0; 
pthread_mutex_t lock;

void* increment_counter(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock); 
        counter++;
        pthread_mutex_unlock(&lock); 
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);
    printf("Final Counter Value: %d\n", counter); 
    return 0;
}