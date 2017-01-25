//
// Created by galit on 25/01/17.
//

#include "ThreadPool.h"
ThreadPool::ThreadPool(int size): pool_size(size) {
    for (int i=0;i<size;i++){
        pthread_t id;
        int ret=pthread_create(&id,NULL,start_thread,(void*)this);
        if (ret!=0){
            perror("thread creation error");
        }
        this->thread.push_back(id);

    }
}

ThreadPool::~ThreadPool() {
for (int i=0;i<pool_size;i++){
    pthread_join(thread[i],NULL);
}
}
 void* start_thread(void* ar){

 }