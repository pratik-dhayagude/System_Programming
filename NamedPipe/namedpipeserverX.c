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

    if(iRet == -1)
    {
        printf("unnamed pipe to crate named pipe \n");
        return -1;
    }

    fd = open("/tmp/Marvellous",O_WRONLY);

    if(fd == -1)
    {
        printf("unable to open named pipe\n");
        return -1;

    }

    write(fd,"jay Ganesh",10);
    printf("data gest succesfully written into they pipe by they server\n");
    close(fd);
    
    unlink("/temp/Marvellous");





    return 0;
}