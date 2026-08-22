// named pipe client


#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;

    int iRet = 0;

    char Arr[100] ={'\0'};


    fd = open("/tmp/Marvellous",O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open named pipe\n");
        return -1;

    }

    read(fd,Arr,3);
    printf("data gest succesfully read from they pipe by they client\n");
    printf("data is :%s\n",Arr);
    close(fd);

    //////////////////////////////////////////////////////////////////////////////
    
    fd = open("/tmp/Marvellous",O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open named pipe\n");
        return -1;

    }


    read(fd,Arr,7);
    printf("data gest succesfully read from they pipe by they client\n");
    printf("data is :%s\n",Arr);

    close(fd);

    return 0;
}