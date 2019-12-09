#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void doRun(int area)
{
    int runner = 0;
    for (int i = 1; i < area+1; i++) {
        int barrier = rand() % 2;
        if (barrier == 0) {
            ++runner;
        }
        else if (barrier == 1) {
            sleep(rand() % 4);
            printf("barrier number: %d\n", i);
            ++runner;
        }
    }    
}

int main()
{
    int hight = rand() % 25;
    int runners = 3;
    int area = runners * hight;
    
    for (int i = 0; i < runners; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
        }
        if (pid == 0) {
            printf("Start runner number: %d\n", (int) getpid());
            doRun(area);
            exit(0);
        }
    }
    wait(NULL);
    
    return 0;
}
