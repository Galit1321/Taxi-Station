//
// Created by galit on 25/01/17.
//

#ifndef ADVPRO01_THREADPOOL_H
#define ADVPRO01_THREADPOOL_H


#include <vector>
#include <sys/types.h>
#include <boost/serialization/deque.hpp>
#include "Task.h"

class ThreadPool {
public:
    ThreadPool(int pool_size);
    void*  execute_thread();
    int  add_task(Task *task);
    virtual ~ThreadPool();

private:
    int pool_size;
    std::vector<pthread_t> thread;
    std::deque<Task*> tasks;

};


#endif //ADVPRO01_THREADPOOL_H

