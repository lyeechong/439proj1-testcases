#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void argtest(void*);

void argtest(void *arg)
{
    int i = *(int *) arg;
    printf("%d\n", i + 6);
    thread_exit();
}

int main(int argc, char **argv)
{
    int b = 5;
    struct thread *t1 = thread_create(argtest, &b);
    thread_add_runqueue(t1);
    thread_start_threading();
    return 0;
}
