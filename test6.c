#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

void argtest_array(void*);

void argtest_array(void *arg)
{
    int *i = arg;
    int k;
    for(k = 0; k < 10; k++)
    {
        printf("%d\n", i[k]);
    }
    thread_exit();
}

int main(int argc, char **argv)
{
    int arr[10] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};
    struct thread *t1 = thread_create(argtest_array, arr);
    thread_add_runqueue(t1);
    thread_start_threading();
    return 0;
}
