#ifndef PRODUTOR_H
#define PRODUTOR_H

#include"buffer.h"

typedef struct produtor {
    buffer * buf;
}produtor;

produtor createProdutor(buffer * buf);

void runProd(produtor * prod);


#endif

