//
// Created by galit on 25/01/17.
//

#include "Task.h"

Task::~Task() {

}

Task::Task(void (*m_fn_ptr)(void *), void *m_arg) : m_fn_ptr(m_fn_ptr), m_arg(m_arg) {

}

void Task::operator()() {
    (*m_fn_ptr)(m_arg);
}