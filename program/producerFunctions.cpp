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
using namespace std;


void* Create_ProducerThreads(void* num){
    //itemProduced itemValue;
    long int threadNum = (long int) num;
    printf("Producer(ID:%ld) created\n",threadNum);
    
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