#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

sem_t sem;
sem_t sem2;
sem_t sem3;

#define MAX 6
void *escribirA(void *nada)
{
    int num;
    for (num = 0; num < MAX; num++)
    {
        sem_wait(&sem);
        printf("A");
        fflush(NULL);
        sleep(2);
        sem_post(&sem2);
    }
    pthread_exit(NULL);
}

void *escribirB(void *nada)
{
    int num;
    for (num = 0; num < MAX; num++)
    {
        sem_wait(&sem2);
        printf("B");
        fflush(NULL);
        sleep(1);
        sem_post(&sem3);
    }
    pthread_exit(NULL);
}

void *escribirC(void *nada)
{
    int num;
    for (num = 0; num < MAX; num++)
    {
        sem_wait(&sem3);
        printf("C");
        fflush(NULL);
        sleep(3);
        sem_post(&sem);
    }
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    pthread_t th1, th2, th3;
    sem_init(&sem, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);

    srandom(time(NULL));
    pthread_create(&th1, NULL, (void *)escribirA, NULL);
    pthread_create(&th2, NULL, (void *)escribirB, NULL);
    pthread_create(&th3, NULL, (void *)escribirC, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    return 0;
}
