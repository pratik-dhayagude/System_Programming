// ./myexe 
// ./myexe /home/demo
// ./myexe /home/demo 5


///////////////////////////////////////////////////////////
//  Headder File inclusion
//////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////
//  Global variable creation
//////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////
//  Helper function define
//////////////////////////////////////////////////////////

//thread prock for thread wich collect system information
static void * collecter_thread( void * arg)
{
    (void)arg;
    printf("Inside collecter thread\n");
    int fd = 0;
    fd = open("Marvellous_log.txt",O_CREAT|O_WRONLY|O_APPEND,0666);

    char Welcome[] = "Marvellous system logger";

    write(fd,Welcome,strlen(Welcome));

    while(!stop_flag)
    {
        //write they infrmation about structure
        
    }
    close(fd);
    return NULL;
}


//thread prock for thread wich logger which write information
static void * logger_thread( void * arg)
{
    (void)arg;
    printf("Inside Logger thread\n");
    while(!stop_flag)
    {

    }
    return NULL;
}


///////////////////////////////////////////////////////////
//  Entry point function of project
//////////////////////////////////////////////////////////

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

    //thread to collect information
    pthread_t t_collect;
    //thread to write the data into the log
    pthread_t t_log;

    pthread_create(&t_collect,NULL,collecter_thread,NULL);
    pthread_create(&t_log,NULL,logger_thread,NULL);

    //wating for child thread to terminate
    pthread_join(t_collect,NULL);
    pthread_join(t_log,NULL);

    printf("Terminating the Marvellous system log");

    return 0;
}