#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "threads.h"

void f1(void*);
void f2(void*);
void f3(void*);

void f1(void* arg){
    printf("f1\n");
    printf("f1 yield 1\n");
    thread_yield();
    printf("f1 yield 2\n");
    thread_yield();
    printf("creating thread 3 for f3\n");
    struct thread *t3 = thread_create(f3, NULL);
    thread_add_runqueue(t3);
    printf("f1 yield 3\n");
    thread_yield();
    printf("f1 yield 4\n");
    thread_yield();
    printf("finishing f1\n");
    thread_exit();
}

void f2(void* arg){
    printf("f2\n");
    printf("f2 yield 1\n");
    thread_yield();
    printf("creating thread 4 for f3\n");
    struct thread *t4 = thread_create(f3, NULL);
    thread_add_runqueue(t4);
    printf("f2 yield 2\n");
    thread_yield();
    printf("finishing f2\n");
    thread_exit();
}

void f3(void* arg){
    printf("f3\n");
    printf("f3 yield 1\n");
    thread_yield();
    printf("finishing f3\n");
    thread_exit();
}

int main(int argc, char **argv)
{
     printf("creating thread 1\n");
     struct thread *t1 = thread_create(f1, NULL);
     thread_add_runqueue(t1);

     printf("creating thread 2\n");
     struct thread *t2 = thread_create(f2, NULL);
     thread_add_runqueue(t2);

     printf("start threading\n");
     thread_start_threading();
     printf("exited\n");
     return 0;
}

