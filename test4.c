#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void fib(void*);
void square(void*);

void fib(void *arg)
{
    int first = 0;
    int second = 1;
    struct thread *t2 = thread_create(square, NULL);
    thread_add_runqueue(t2);
    while(first < 500) {
  
        printf("fib %d\n", first);
        int temp = second;
        second = first + second;
        first = temp;
        thread_yield();
    }
    thread_exit();
}

void square(void *arg)
{
    int i = 1;
    while (i < 10) {
        printf("%d squared is %d\n", i, i*i);
        i++;
        thread_yield();
    }
    thread_exit();
}

int main(int argc, char **argv)
{
    struct thread *t1 = thread_create(fib, NULL);
    thread_add_runqueue(t1);
    thread_start_threading();		
    return 0;
}
