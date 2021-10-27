#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<pthread.h>

#ifndef OWN_SEM
#include<semaphore.h>
#endif

typedef struct semaphore {
    int id;
    int size;
#ifdef OWN_SEM
    pthread_mutex_t mutex;
#else
    sem_t sem;
#endif
}semaphore;

semaphore createSemaphore(int qtd);

void acquireSemaphore(semaphore * sem); 

void releaseSemaphore(semaphore * sem);

#endif
