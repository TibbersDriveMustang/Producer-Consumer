//
//  dataStructures.h
//  program
//
//  Created by Hongyi Guo on 9/28/15.
//  Copyright © 2015 Hongyi Guo. All rights reserved.
//

#ifndef dataStructures_h
#define dataStructures_h

#include <queue>
#include <pthread.h>
#include <semaphore.h>

struct itemProduced{
    int producerID;
    int createdNumber;
};

struct itemConsumed{
    int producerID;
    long consumerID;
    int consumedNumber;
};






#endif /* dataStructures_h */
