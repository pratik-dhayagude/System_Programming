// ./myexe 
// ./myexe /home/demo
// ./myexe /home/demo 5

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

static volatile sig_atomic_t stop_flag =0;

//ctrl+c Handler
static void Sigint_handler(int sig)
{
    (void)sig;

    printf("Marvellous SystemLogger is terminating\n");

    //Tell the thread to stop they execution
    stop_flag = 1;


}

//structure which holds all system information
typedef struct 
{
    double cpu; // cpu usage percentage
    double mem; // Ram usage percentage
    double disk; // Hard Disk usage percentage
}Snapshot;

//Global object which holds information
static Snapshot snap;

//mutex log for critical section
pthread_mutex_t mutx = PTHREAD_MUTEX_INITIALIZER;

//defafult path for disk

static const char*  disk_path = "/";

// Sleep timer for log 
static  int interval_sec = 2;

int main(int argc , char * argv[])
{

    if(argc == 2)
    {
        disk_path = argv[1];
    }
    else if(argc == 3)
    {
        disk_path = argv[1];
        interval_sec = atoi(argv[2]);

    }
    printf("Marvellous System logger\n");

    printf("Path is: %s\n",disk_path);
    printf("Interval is: %d\n",interval_sec);

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