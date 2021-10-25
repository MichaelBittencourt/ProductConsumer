#define _GNU_SOURCE
#include"buffer.h"
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/syscall.h>

#ifndef SYS_gettid
#error "SYS_gettid unavailable on this system"
#endif

#define gettid() ((pid_t)syscall(SYS_gettid))

buffer createBuffer(int size) {
    buffer buf;
    buf.buf = (int*)malloc(sizeof(int)*size);
    buf.size = size;
    buf.freePosition = START_POSITION;
#ifndef DISABLE_SEMAPHORE
    buf.bufferFull = createSemaphore(START_POSITION);
    buf.bufferEmpty = createSemaphore(size);
    buf.semMutex = createSemaphore(1);
#endif
    return buf;
}

void addBuffer(buffer * buf, int number) {
#ifndef DISABLE_SEMAPHORE
    acquireSemaphore(&(buf->bufferEmpty));
    acquireSemaphore(&(buf->semMutex));
#endif
    if (buf->freePosition >= buf->size) {
        fprintf(stderr, "Erro durante a producao!\n");
    } else {
        buf->buf[buf->freePosition] = number;
        //pid_t tid = syscall(__NR_gettid);
        pid_t tid = gettid();
        //int tid = -1;
        printf("Produtor %d inseriu em buf[%d]: %d\n", tid, buf->freePosition, number); 
        buf->freePosition++;
    }
#ifndef DISABLE_SEMAPHORE
    releaseSemaphore(&(buf->semMutex));
    releaseSemaphore(&(buf->bufferFull));
#endif
}

void removeBuffer(buffer * buf) {
#ifndef DISABLE_SEMAPHORE
    acquireSemaphore(&(buf->bufferFull));
    acquireSemaphore(&(buf->semMutex));
#endif
    if(buf->freePosition <= START_POSITION) {
        fprintf(stderr, "Erro durante consumo!\n");
    } else {
        buf->freePosition--;
        //pid_t tid = syscall(__NR_gettid);
        pid_t tid = gettid();
        //int tid = -1;
        printf("Consumidor %d removeu buf[%d]: %d\n", tid, buf->freePosition, buf->buf[buf->freePosition]);
    }
#ifndef DISABLE_SEMAPHORE
    releaseSemaphore(&(buf->semMutex));
    releaseSemaphore(&(buf->bufferEmpty));
#endif
}
