#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void MarvellousHandler(int no)
{
    printf("Marvellous Message arrived: %d\n",no);
}

int main()
{
    printf("Pid is :%d\n",getpid());

    signal(SIGUSR1,MarvellousHandler);

    while(1)
    {
        sleep(1);
    }
    
    return 0;
}