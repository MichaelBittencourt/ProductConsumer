#ifndef BUFFER_H
#define BUFFER_H

#define START_POSITION 0

typedef struct buffer {
    int * buf;
    int size;
    int freePosition;
}buffer;

buffer createBuffer(int size);

void addBuffer(buffer * buf, int number);

void removeBuffer(buffer * buf);

#endif
