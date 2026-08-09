#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<time.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/statvfs.h>

#define _GNU_SOURCE

//ctrl+c Handler
static void Sigint_handler(int sig)
{

    printf("ctrl+c Arrived\n");

}

int main(int argc , char * argv[])
{
    printf("Marvellous System logger\n");

    //structure for handling ctrl+c
    struct sigaction sa;
    memset(&sa,0,sizeof(sa));

    sa.sa_handler = Sigint_handler;

    sigaction(SIGINT,&sa,NULL);

    while(1)
    {
        sleep(1);
    }

    return 0;
}