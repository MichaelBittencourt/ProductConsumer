#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include"buffer.h"

typedef struct consumidor {
    buffer * buf;
} consumidor;

consumidor createConsumidor(buffer * buf);

void runCons(consumidor * consu);

#endif
