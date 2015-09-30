//
//  producerFunctions.cpp
//  program
//
//  Created by Hongyi Guo on 9/28/15.
//  Copyright © 2015 Hongyi Guo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "producerFunctions.h"
#include "dataStructures.h"
#include <time.h>

using namespace std;

extern sem_t semInputDoc;
extern sem_t semBuffer;

extern int numToProduce;
extern queue<itemProduced> itemBuffer;


int Create_RandomNum(int factor){
    srand(time(0));   //**********
    int num;
    num = (rand() * factor) % 10000 + 1;
    sleep(1);
    return num;
}

void* Create_ProducerThreads(void* num){
    long int threadNum = (long int) num;
    printf("Producer(ID:%ld) created\n",threadNum);
    for (int i = 0; i < numToProduce; i++) {
        itemProduced item;
        item.producerID = threadNum;
        item.createdNumber = i;//Create_RandomNum(i);       *****
     
        printf("Created num: %d(ID:%d)\n",item.createdNumber,item.producerID);
        //sem_wait(&semBuffer);
        //itemBuffer.push(item);
        //sem_post(&semBuffer);

        //sem_wait(&semInputDoc);
        //WriteToFile(item);
        //sem_post(&semInputDoc);
        
    }
    return NULL;
}

void* ProducerCreation(void* numProducer){
    long int num = (long int) numProducer;
    pthread_t producerThreads[num];
    for (int i = 0; i < num; i++) {
        pthread_create(&producerThreads[i], NULL, Create_ProducerThreads, (void*) i);
        sleep(0.5);
    }
    return NULL;
}