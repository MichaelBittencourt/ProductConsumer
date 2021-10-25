#include"semaphore.h"

int SEMAPHORE_ID_GLOBAL = 0;



semaphore createSemaphore(int qtd) {
    //This macro initialize a mutex, if you use this macro in already created Mutex, a compilation problem can occurs.
    pthread_mutex_t temp = PTHREAD_MUTEX_INITIALIZER; 
    semaphore sem;
    sem.size = qtd;
    sem.id = ++SEMAPHORE_ID_GLOBAL;
    sem.mutex = temp;
    return sem;
}

void acquireSemaphore(semaphore * sem) {
    while(sem->size == 0) {
        sleep(0.01);
    }
    pthread_mutex_lock(&(sem->mutex));
    sem->size--;
    pthread_mutex_unlock(&(sem->mutex));
}

void releaseSemaphore(semaphore * sem) {
    pthread_mutex_lock(&(sem->mutex));
    sem->size++;
    pthread_mutex_unlock(&(sem->mutex));
}
