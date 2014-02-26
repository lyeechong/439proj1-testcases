#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void pingpong(void*);

void pingpong(void *arg)
{
    int num = *(int *) arg;
    
    if(num % 2 == 1)
    {
        printf("ping! %d\n", num);
    }
    else
    {
        printf("pong! %d\n", num);
    }
    
    if(num++ < 20)
    {
      struct thread *t2 = thread_create(pingpong, &num);
      thread_add_runqueue(t2);
    }
    
    thread_exit();
}

int main(int argc, char **argv)
{
    int k = 1;
    struct thread *t1 = thread_create(pingpong, &k);
    thread_add_runqueue(t1);
    
    thread_start_threading();		
    return 0;
}
