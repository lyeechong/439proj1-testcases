#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "threads.h"

void f2(void*);
void f3(void*);
void f4(void*);

void f1(void* arg){
    printf("f1\n");
    printf("creating thread 5\n");
    struct thread *t2 = thread_create(f2, NULL);
    thread_add_runqueue(t2);
    thread_yield();
    printf("finishing f1 after yield\n");
    thread_exit();
}

void f2(void* arg){
    printf("f2\n");
    printf("creating thread 6\n");
    struct thread *t3 = thread_create(f3, NULL);
    thread_add_runqueue(t3);    
    //thread_exit();
    thread_yield();
    printf("finishing f2 after yield\n");
    thread_exit();
}

void f3(void* arg){
    printf("f3\n");
    printf("creating thread 7\n");
    struct thread *t4 = thread_create(f4, NULL);
    thread_add_runqueue(t4);     
    thread_yield();
    printf("finishing f3 after yield\n");
    thread_exit();
}

void f4(void* arg){
    printf("test_func\n");
    thread_yield();
    printf("finishing test_func after yield\n");
    thread_exit();
} 

int main(int argc, char **argv)
{
     printf("creating thread 1\n");
     struct thread *t1 = thread_create(f1, NULL);
     thread_add_runqueue(t1);

     printf("creating thread 2\n");
     struct thread *t2 = thread_create(f4, NULL);
     thread_add_runqueue(t2);
   
     printf("creating thread 3\n");
     struct thread *t3 = thread_create(f4, NULL);
     thread_add_runqueue(t3);

     printf("creating thread 4\n");
     struct thread *t4 = thread_create(f4, NULL);
     thread_add_runqueue(t4);    

     printf("***** starting threading library *****\n");
     thread_start_threading();
     printf("\nexited\n");
     return 0;
}

