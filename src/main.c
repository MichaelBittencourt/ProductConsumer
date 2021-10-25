#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include"buffer.h"
#include"produtor.h"
#include"consumidor.h"

#define QTD_PRODUCTORS 3
#define QTD_CONSUMERS 5

void * startProduct(void * params);
void * startConsumer(void * params);

int main(void) {
    srand(time(NULL));
    buffer buf = createBuffer(5);
    
    produtor productors[QTD_PRODUCTORS];
    for (int i = 0; i < QTD_PRODUCTORS; i++) {
        productors[i] = createProdutor(&buf);
    }

    consumidor consumers[QTD_CONSUMERS];
    for (int i = 0; i < QTD_CONSUMERS; i++) {
        consumers[i] = createConsumidor(&buf);
    }

    pthread_t theadsProd[QTD_PRODUCTORS];
    pthread_t theadsCons[QTD_CONSUMERS];

    for (int i = 0; i < QTD_PRODUCTORS; i++) {
        pthread_create(&theadsProd[i], NULL, startProduct, (void*)(&productors[i]));
    }

    for (int i = 0; i < QTD_CONSUMERS; i++) {
        pthread_create(&theadsCons[i], NULL, startConsumer, (void*)(&consumers[i]));
    }

    for (int i = 0; i < QTD_PRODUCTORS; i++) {
        pthread_join(theadsProd[i], NULL);
    }

    for (int i = 0; i < QTD_CONSUMERS; i++) {
        pthread_join(theadsCons[i], NULL);
    }

    return 0;
}

void * startProduct(void * params) {
    runProd((produtor *)params);
}

void * startConsumer(void * params) {
    runCons((consumidor *)params);
}
