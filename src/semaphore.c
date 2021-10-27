#include"semaphore.h"

int SEMAPHORE_ID_GLOBAL = 0;



semaphore createSemaphore(int qtd) {
    //This macro initialize a mutex, if you use this macro in already created Mutex, a compilation problem can occurs.
    semaphore sem;
    sem.size = qtd;
    sem.id = ++SEMAPHORE_ID_GLOBAL;
#ifdef OWN_SEM
    pthread_mutex_t temp = PTHREAD_MUTEX_INITIALIZER; 
    sem.mutex = temp;
#else
    sem_init(&(sem.sem), 0, qtd);
#endif
    return sem;
}

void acquireSemaphore(semaphore * sem) {
#ifdef OWN_SEM
    while(sem->size == 0) {
        sleep(0.01);
    }
    pthread_mutex_lock(&(sem->mutex));
    sem->size--;
    pthread_mutex_unlock(&(sem->mutex));
#else
    sem_wait(&(sem->sem));
#endif
}

void releaseSemaphore(semaphore * sem) {
#ifdef OWN_SEM
    pthread_mutex_lock(&(sem->mutex));
    sem->size++;
    pthread_mutex_unlock(&(sem->mutex));
#else
    sem_post(&(sem->sem));
#endif
}
