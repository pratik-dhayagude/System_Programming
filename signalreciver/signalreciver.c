#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Pid is :%d\n",getpid());

    while(1)
    {
        sleep(1);
    }
    return 0;
}