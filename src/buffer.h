#ifndef BUFFER_H
#define BUFFER_H

#define START_POSITION 0

#include "semaphore.h"

typedef struct buffer {
    int * buf;
    int size;
    int freePosition;
    semaphore bufferFull;
    semaphore bufferEmpty;
}buffer;

buffer createBuffer(int size);

void addBuffer(buffer * buf, int number);

void removeBuffer(buffer * buf);

#endif
