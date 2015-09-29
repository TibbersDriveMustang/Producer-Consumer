//
//  dataStructures.h
//  program
//
//  Created by Hongyi Guo on 9/28/15.
//  Copyright © 2015 Hongyi Guo. All rights reserved.
//

#ifndef dataStructures_h
#define dataStructures_h

#include <semaphore.h>
#include <queue>
#include <pthread.h>
using namespace std;

int numToProduce;
int numProducer;
int numConsumer;
int bufferCapacity;

struct itemProduced{
    int producerID;
    int createdNumber;
};

struct itemConsumed{
    int producerID;
    int consumerID;
    int consumedNumber;
};

sem_t semInputDoc;
sem_t semPrimeDoc;
sem_t semNonPrimeDoc;
sem_t semBuffer;

queue<itemProduced> itemBuffer;

int main_TerminateSignal = 0;




#endif /* dataStructures_h */
