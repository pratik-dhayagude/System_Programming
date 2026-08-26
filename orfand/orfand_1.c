// out put depends on sheduling 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
 {
    pid_t pid = 0;
    pid = fork();
    if(pid == 0) // child run
    {
        printf("child process is running..\n");
        printf("pid of child is : %d & ppid of child is :%d\n",getpid(),getppid());
    }
    else  // parent
    {
        printf("parent process is running..\n");
        printf("pid of parent is : %d & ppid of parent is :%d\n",getpid(),getppid());
    }
    return 0;
 }