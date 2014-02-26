#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void pr(void*);
void run(void*);

void f1(void *arg)
{
	printf("hello 2\n");
	thread_exit(); //testing to see exit does exit
	printf("failed!!\n");
}

void f2(void *arg)
{
   struct thread *t = arg;
   thread_add_runqueue(t);
   printf("hello 1\n");
}

void run(void *arg)
{
    struct thread *t1 = thread_create(f1, NULL);
    struct thread *t2 = thread_create(f2, t1);
       
    thread_add_runqueue(t2);
    thread_exit();
}

int main(int argc, char **argv)
{
    struct thread *t = thread_create(run, NULL);
    thread_add_runqueue(t);
    thread_start_threading();
    printf("exited")
    return 0;
}
