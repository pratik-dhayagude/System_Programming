////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Author : Pratik Dhayanjay Dhayagude
//  Date: 20/08/2026
//  Project: Concurrent FTP Server
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include"Marvellous.h"

int main(int argc, char* argv[])
{

    int Socket = 0;
    int iRet = 0;

    char* ip = argv[1];
    int Port = atoi(argv[2]);
    char Buffer[1024] ={"\0"};
    char Arr[500] = {"\0"};
    printf("Jay Ganesh...\n");
    struct sockaddr_in ServerAddr;
    /*
        Step1 -> Creating the TCP Socket

    */
    Socket = socket(AF_INET, SOCK_STREAM,0); // socket() System call 
    if(Socket == -1)
    {

        printf("Unable t create the socket\n");

        return -1;
    }
    printf("Socket created successfully\n");

    /*
        Step2 -> Connition of the socket
    */

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    inet_pton(AF_INET,ip,&ServerAddr.sin_addr);
    
    iRet = connect(Socket,(struct sockaddr*)&ServerAddr,sizeof(ServerAddr)); //connect() system call
    if(iRet == -1)
    {

        printf("not Connected\n");
        return -1;
    }
    printf("Connection will be successfully");


    while(strcmp(Buffer,"bye")!=0)
    {
        printf("Send message to the client:\n");
        scanf(" %[^'\n']s",Arr);
        iRet = write(Socket,Arr,sizeof(Arr));
        if(iRet == -1)
        {

            printf("Message not write\n");
            break;
        }
       iRet = read(Socket,Buffer,sizeof(Buffer));  //read() system call 
       if(iRet < 0)
       {
            printf("Unable to read");
            break;
       }
       printf("Message from server:%s\n",Buffer);
      
        
    }
    close(iRet);
    
    return 0;
}