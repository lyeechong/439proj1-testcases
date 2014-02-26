#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void fib(void*);
void square(void*);

void fib(void *arg)
{
    int fib_i = *(int *) arg;
    int first = 0;
    int second = 1;
    int count = 0;
    
    while(count++ < fib_i) {        
        int temp = second;
        second = first + second;
        first = temp;
        
        thread_yield();
    }
    printf("the %dth fib number is %d\n", fib_i, first);
    thread_exit();
}

void square(void *arg)
{
    int i = *(int *) arg;
    int curr = i;
    while (curr < i + 10) {
        printf("%d squared is %d\n", curr, curr*curr);
        curr++;
        thread_yield();
    }
    thread_exit();
}

int main(int argc, char **argv)
{
    int k = 30;
    struct thread *t1 = thread_create(fib, &k);
    thread_add_runqueue(t1);
    
    int s = 19;
    struct thread *t2 = thread_create(square, &s);
    thread_add_runqueue(t2);
    
    thread_start_threading();		
    return 0;
}
