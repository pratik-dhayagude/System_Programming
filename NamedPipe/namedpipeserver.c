// named pipe server


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

    iRet = mkfifo("/tmp/Marvellous",0666);

    if(iRet == 0)
    {
        printf("named pipe gets succesfully created \n");
    }



    return 0;
}