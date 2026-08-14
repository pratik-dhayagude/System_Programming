#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t childpid = 0;
    pid_t ret = 0;
    int status = 0;

    childpid = fork();

    if(childpid == 0)
    {
      printf("child is running with PID : %d\n",getpid()); 
      sleep(10);
      printf("child process is exiting\n");
      exit(11);

    }
    else
    {
      printf("parent is running..\n"); 

      printf("parent is waiting for child : %d\n",childpid);

      ret = waitpid(childpid,&status,0);
      if(WIFEXITED(status))
      {
        printf("child exited with pid :%d\n",ret);
        printf(" Exit Status of Child is : %d\n ",WEXITSTATUS(status));
      }
    
    }

    return 0;
}