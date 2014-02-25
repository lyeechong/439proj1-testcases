#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

typedef short Boolean;
#define TRUE 1
#define FALSE 0

void fib(void *arg)
{
    int first = 0;
    int second = 1;
    while(first < 100) {
  
        printf("thread 2: %d\n",first);
        int temp = second;
        second = first + second;
        first = temp;
        thread_yield();
    }
    //thread_exit();
}

void powers(void *arg)
{
    int i = 1;
    while (i < 10) {
        printf("thread 3: %d\n", i*i);
        i++;
        thread_yield();
    }
    //thread_exit();
}

void multiplesOf5(void *arg)
{
    int i = 1;
    struct thread *t2 = thread_create(fib, NULL);
    thread_add_runqueue(t2);
    struct thread *t3 = thread_create(powers, NULL);
    thread_add_runqueue(t3);
    while(i < 50) {
        printf("thread 1: %d\n", i*5);
        i++;
        thread_yield();
    }
    //thread_exit();
}


int main(int argc, char **argv)
{
	struct thread *thread1 = thread_create(multiplesOf5, NULL);
  thread_add_runqueue(thread1);
  thread_start_threading();
  //printf("current thread address = %p\n", cur_RQO->t);			
	return 0;
}
