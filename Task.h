//
// Created by galit on 25/01/17.
//

#ifndef ADVPRO01_TASK_H
#define ADVPRO01_TASK_H


class Task {
public :
 Task(void(*fn_ptr)(void*),void* arg);

    Task(void (*m_fn_ptr)(void *), void *m_arg);

    void operator()();
    virtual ~Task();

private:
    void (*m_fn_ptr)(void*);
    void* m_arg;
};


#endif //ADVPRO01_TASK_H
