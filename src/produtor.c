#include"produtor.h"
#include"buffer.h"
#include<unistd.h>
#include<stdlib.h>

produtor createProdutor(buffer * buf) {
    produtor prod;
    prod.buf = buf;

    return prod;
}

void runProd(produtor * prod) {
    while(1) {
        int numero = (rand() % 20)/10.0;
        sleep(numero);
        addBuffer(prod->buf, numero);
    }
}
