#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include"buffer.h"
#include"produtor.h"
#include"consumidor.h"

void * startProduct(void * params);
void * startConsumer(void * params);

int main(void) {
    srand(time(NULL));
    buffer buf = createBuffer(5);
    produtor p1 = createProdutor(&buf);
    consumidor c1 = createConsumidor(&buf);

    pthread_t tp1;
    pthread_t tc1;

    pthread_create(&tp1, NULL, startProduct, (void*)(&p1));
    pthread_create(&tc1, NULL, startConsumer, (void*)(&c1));

    pthread_join(tp1, NULL);
    pthread_join(tc1, NULL);
    return 0;
}

void * startProduct(void * params) {
    runProd((produtor *)params);
}

void * startConsumer(void * params) {
    runCons((consumidor *)params);
}
