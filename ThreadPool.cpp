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
    ThreadPool* tp = (ThreadPool*)ar;
    tp->execute_thread();
    return NULL;
}


void* ThreadPool::execute_thread() {
    Task* task = NULL;
    while(true){
        while(tasks.empty()){
            sleep(1);
        }
        task =tasks.front();
        tasks.pop_front();
        (*task)();
    }
    return NULL;
}

int ThreadPool::add_task(Task* task)
{
    tasks.push_back(task);
}