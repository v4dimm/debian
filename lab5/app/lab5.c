#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <pthread.h>

void* doRun(void* arg)
{
    int *area_ptr = (int*) arg;
    int area = *area_ptr;
    
    for (int i = 0; i < area; i++) {
        int barrier = rand() % 2;
        if (barrier != 0) {
            sleep(rand() % 4);
            printf("barrier number: %d\n", i);
        }
        else {
            continue;
        }
    }
    
    pthread_exit(0);
}

int main()
{
    int hight = rand() % 25;
    int runners = 3;
    int area = runners * hight;
    
    //Thread id
    pthread_t tid[runners];
    
    for (int i = 0; i < runners; i++) {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        printf("Runner %d starts\n", i + 1);
        pthread_create(&tid[i], &attr, doRun, &area);
    }
    
    for (int i = 0; i < runners; i++) {
        pthread_join(tid[i], NULL);
    }
    
    return 0;
}