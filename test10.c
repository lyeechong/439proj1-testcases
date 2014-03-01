#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void spawn(void*);
void run(void*);
void go(void*);
void pr(void*);

void spawn(void *arg)
{
    struct thread *tpr = thread_create(pr, NULL);
    struct thread *trun = thread_create(run, tpr);
    thread_add_runqueue(trun);
    thread_yield();
    printf("exiting spawn\n");
    thread_exit();
}

void pr(void *arg)
{
    printf("hello\n");
    thread_exit();
}

void run(void *arg)
{
    struct thread *t = arg;
    printf("adding thread to runqueue\n");
    thread_add_runqueue(t);
    thread_yield();
    printf("exiting run\n");
    thread_exit();
}

void go(void *arg)
{
    struct thread *tspawn = thread_create(spawn, NULL);
    thread_add_runqueue(tspawn);
    thread_yield();
    printf("exiting go function\n");
    thread_exit();
}

int main(int argc, char **argv)
{
    struct thread *t1 = thread_create(go, NULL);
    thread_add_runqueue(t1);
    thread_start_threading();		
    printf("exited\n");
    return 0;
}
