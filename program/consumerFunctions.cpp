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

extern queue<itemProduced> *itemBuffer;
//extern sem_t *semBuffer;
extern dispatch_semaphore_t semBuffer;

bool isPrime(int num){
    if (num < 2) {
        return FALSE;
    }
    for (int i = 2; i < num/2 + 1; i++) {
        if(num % i == 0){
            return FALSE;
        }
    }
    return true;
}

void* Create_ConsumerThreads(void* num){
    long int threadNum = (long int) num + 1000000 + 1;
    printf("Consumer(ID:%ld) created\n",threadNum);
    
    FILE *pFile;
    itemProduced tempItem;
    while(1){
        sleep(1);
        dispatch_semaphore_wait(semBuffer, DISPATCH_TIME_FOREVER);

        if(!itemBuffer->empty()){
            tempItem = itemBuffer->front();
            itemBuffer->pop();
            printf("Consumer(%ld) consumed Item(%d) generated by producer(%d)\n",threadNum, tempItem.createdNumber,tempItem.producerID);
            printf("Buffer Size:%d\n",itemBuffer->size());
            
            if(isPrime(tempItem.createdNumber)){
                pFile = fopen("Prime-Numbers", "a+");
                if (pFile == NULL) {
                    perror("Error opening file");
                }
                fprintf(pFile, "Is Prime=>Producer ID: %d,Consumer ID: %ld,Item Number: %d;\n",tempItem.producerID,threadNum,tempItem.createdNumber);
                fclose(pFile);
            }
            else{
                pFile = fopen("Non-Prime-Numbers", "a+");
                if(pFile == NULL){
                    perror("Error opening file");
                }
                fprintf(pFile, "Not Prime=>Producer ID: %d,Consumer ID: %ld,Item Number: %d;\n",tempItem.producerID,threadNum,tempItem.createdNumber);
                fclose(pFile);
            }
         }
        
        dispatch_semaphore_signal(semBuffer);
    }
    
    return NULL;
}

void* ConsumerCreation(void* numConsumer){
    long int num = (long int) numConsumer;
    pthread_t consumerThreads[num];
    for (int i = 0; i < num; i++) {
        pthread_create(&consumerThreads[i], NULL, Create_ConsumerThreads, (void*) i);
        sleep(0.5);
    }
    while(1);
    return NULL;
}