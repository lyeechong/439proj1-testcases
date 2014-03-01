#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void pr(void*);
void run(void*);

void pr_exit(void *arg)
{
    printf("hello exit\n");
    thread_exit();
}

void pr_no_exit(void *arg)
{
    printf("hello no exit\n");
}

void run(void *arg)
{
    struct thread *t1 = thread_create(pr_exit, NULL);
    struct thread *t2 = thread_create(pr_no_exit, NULL);
       
    thread_add_runqueue(t1);
    thread_add_runqueue(t2);
    thread_yield();
    printf("exiting run function\n");
    thread_exit();
}

int main(int argc, char **argv)
{
    struct thread *t = thread_create(run, NULL);
    thread_add_runqueue(t);
    thread_start_threading();
    printf("exited");
    return 0;
}
