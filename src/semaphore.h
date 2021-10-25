#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<pthread.h>

typedef struct semaphore {
    int size;
    int id;
    pthread_mutex_t mutex;
}semaphore;

semaphore createSemaphore(int qtd);

void acquireSemaphore(semaphore * sem); 

void releaseSemaphore(semaphore * sem);

#endif
