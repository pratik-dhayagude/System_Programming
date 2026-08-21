#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void MarvellousHandler(int no)
{
    if(no ==SIGUSR1)
    {
     printf("Marvellous mesage -SIGUSR1 arrived\n");
    }
    else if(no == SIGINT)
    {
        printf("Marvellous message - SIGINT arrived\n");
    }

}

int main()
{
    printf("Pid is :%d\n",getpid());

    signal(SIGUSR1,MarvellousHandler);
    signal(SIGINT,MarvellousHandler);


    while(1)
    {
        sleep(1);
    }
    
    return 0;
}