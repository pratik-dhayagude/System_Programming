#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
    int ret = 0;
    ret = nice(0);

    printf("current nice value : %d\n",ret);
    
    return 0;
}