//
//  consumerFunctions.cpp
//  program
//
//  Created by Hongyi Guo on 9/28/15.
//  Copyright © 2015 Hongyi Guo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "consumerFunctions.h"
#include "dataStructures.h"

using namespace std;
extern queue<itemProduced> itemBuffer;


void* Create_ConsumerThreads(void* num){
    long int threadNum = (long int) num + 1000000 + 1;
    printf("Consumer(ID:%ld) created\n",threadNum);
    return NULL;
}

void* ConsumerCreation(void* numConsumer){
    long int num = (long int) numConsumer;
    pthread_t consumerThreads[num];
    for (int i = 0; i < num; i++) {
        pthread_create(&consumerThreads[i], NULL, Create_ConsumerThreads, (void*) i);
        sleep(0.5);
    }
    return NULL;
}