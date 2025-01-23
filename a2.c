#include<stdio.h>
#include<pthread.h>

int count = 0;
pthread_mutex_t lock; 

void* fun(void* arg)
{
    pthread_mutex_lock(&lock);
    count++; 
    int current_count = count;
    printf("Thread %d has started\n", current_count);
 

    for(int i = 1; i <= 1000000; i++) {
    }


    printf("Thread %d has finished\n", current_count);
    pthread_mutex_unlock(&lock); 
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }
    pthread_create(&thread1, NULL, fun, NULL);
    pthread_create(&thread2, NULL, fun, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);


    pthread_mutex_destroy(&lock);

    return 0;
}