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
extern queue<itemProduced> *itemBuffer;


/*int Create_RandomNum(int factor){
    srand(time(0));   //**********
    int num;
    num = (rand() * factor) % 10000 + 1;
    sleep(1);
    return num;
}*/

void* Create_ProducerThreads(void* num){
    long int threadNum = (long int) num;
    printf("Producer(ID:%ld) created\n",threadNum);
    
    FILE *pFile;
    
    for (int i = 0; i < numToProduce; i++) {
        sleep(1);
        int numTemp;
        itemProduced item;
        item.producerID = threadNum + 1;
        
        srand(time(NULL) + i + item.producerID);



        numTemp = rand() % 10000 + 1;
        item.createdNumber = numTemp ;//Create_RandomNum(i);       ******
        printf("Created num: %d(ID:%d)\n",item.createdNumber,item.producerID);
        sem_wait(&semBuffer);
        itemBuffer->push(item);
        printf("buffer size:%d\n",itemBuffer->size());
        sem_post(&semBuffer);
        
        sem_wait(&semInputDoc);
        pFile = fopen("../../../Input-numbers", "a+");
        if(pFile == NULL)
            perror("Error opening file");
        else{
            fprintf(pFile, "Producer ID: %d,Item Number: %d;\n",item.producerID,item.createdNumber);
            fclose(pFile);
        }
        sem_post(&semInputDoc);
        
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
    for (int i = 0; i < num;i++){
        pthread_join(producerThreads[i], NULL);
    }
    return NULL;
}