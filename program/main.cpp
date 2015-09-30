//
//  main.cpp
//  program
//
//  Created by Hongyi Guo on 9/28/15.
//  Copyright © 2015 Hongyi Guo. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include "dataStructures.h"
#include "producerFunctions.h"
#include "consumerFunctions.h"

using namespace std;

int numToProduce;
int numProducer;
int numConsumer;
int bufferCapacity;

sem_t semInputDoc;
sem_t semPrimeDoc;
sem_t semNonPrimeDoc;
sem_t semBuffer;

queue<itemProduced> itemBuffer;

int main_TerminateSignal = 0;


pthread_t producerCreater,consumerCreater;
int main(int argc, const char * argv[]) {
    
    cout<<"Enter the number of producers"<<endl;
    cin>>numProducer;
    
    cout<<"Enter the number of consumers"<<endl;
    cin>>numConsumer;
    
    cout<<"Enter the amount of number for each producer to create"<<endl;
    cin>>numToProduce;
    
    pthread_create(&producerCreater, NULL, ProducerCreation, (void*) numProducer);
    pthread_create(&consumerCreater, NULL, ConsumerCreation, (void*) numConsumer);
    //sleep(10);
    //Without waiting,main thread will not wait to terminate everything
    
    pthread_join(producerCreater, NULL);
    //waiting for termination
    sleep(10);
    //Don`t use multiprocess
/*    pid_t producer,consumer;
    if ((producer = fork()) < 0) {
        perror("fork");
        abort();
    }
    else if (producer == 0){
        //producerRunning();
        printf("Running producers` threads\n");
        producerGroup(numProducer);
    }
    
    if (producer != 0) {
        if((consumer = fork()) < 0){
            perror("fork");
            abort();
        }
    }
    else if( consumer == 0){
        //consumerRunning();
        printf("Running consumers` threads\n");
        consumerGroup(numConsumer);
    }
    
    //waitForTermination();
    if(producer != 0 && consumer != 0){
        sleep(10);
        printf("Terminated\n");
    }
 
 */
}
