#ifndef BUFFER_H
#define BUFFER_H

#define START_POSITION 0

#ifndef DISABLE_SEMAPHORE
#include "semaphore.h"
#endif

typedef struct buffer {
    int * buf;
    int size;
    int freePosition;
#ifndef DISABLE_SEMAPHORE
    semaphore bufferFull;
    semaphore bufferEmpty;
    semaphore semMutex;
#endif
}buffer;

buffer createBuffer(int size);

void addBuffer(buffer * buf, int number);

void removeBuffer(buffer * buf);

#endif
