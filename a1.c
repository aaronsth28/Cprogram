#include <stdio.h>
#include <pthread.h>

int i = 0;
pthread_mutex_t lock;

void* odd(void* arg)
{
    while (i <= 100)
    {
        pthread_mutex_lock(&lock);
        if (i % 2 != 0)
        {
            printf("Number: %d\n", i);
            i++;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* even(void* arg)
{
    while (i <= 100)
    {
        pthread_mutex_lock(&lock);
        if (i % 2 == 0)
        {
            printf("Number: %d\n", i);
            i++;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, odd, NULL);
    pthread_create(&t2, NULL, even, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}
