#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void pr(void*);
void run(void*);

void pr(void *arg)
{
    struct thread *t = arg;
    printf("hello1\n");
    
    thread_add_runqueue(t);
    thread_yield();
    
    printf("hello2\n");
    thread_yield();
    
    printf("hello3\n");
    thread_add_runqueue(t);
    thread_yield();
    
    printf("hello4\n");
    thread_yield();
    
    printf("hello5\n");
    thread_yield();
    
    printf("hello6\n");
    thread_yield();
    
    printf("hello7\n");
    thread_yield();
    
    printf("hello8\n");
    thread_yield();
    
    printf("hello9\n");
    thread_yield();
    
    printf("hello10 (before exit)\n");
    thread_exit();
}

void run(void *arg)
{
    struct thread *t = thread_create(pr, NULL);
    struct thread *t2 = thread_create(pr, NULL);
    thread_add_runqueue(t);
    thread_add_runqueue(t);
    thread_add_runqueue(t);
    
    thread_add_runqueue(t2);
    
    thread_yield();
    thread_add_runqueue(t);
    thread_yield();
    thread_add_runqueue(t);
    thread_yield();
    thread_add_runqueue(t);
    thread_yield();
    thread_yield();
    thread_yield();
    thread_add_runqueue(t);
    thread_add_runqueue(t);
    thread_add_runqueue(t);
    thread_add_runqueue(t);
    thread_yield();
    thread_add_runqueue(t);
    thread_yield();
    thread_add_runqueue(t);
    thread_yield();
    thread_add_runqueue(t);
    thread_yield();
    thread_yield();
    thread_exit();
}

int main(int argc, char **argv)
{
    struct thread *t1 = thread_create(run, NULL);
    thread_add_runqueue(t1);
    thread_start_threading();		
    return 0;
}
