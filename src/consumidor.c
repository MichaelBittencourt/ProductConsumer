#include"consumidor.h"
#include"buffer.h"
#include<unistd.h>
#include<stdlib.h>

consumidor createConsumidor(buffer * buf) {
    consumidor consu;
    consu.buf = buf;
    return consu;
}

void runCons(consumidor * consu) {
    while(1) {
        //sleep((rand() % 10)/10.0);
        removeBuffer(consu->buf);
    }
}
