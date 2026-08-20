////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Author : Pratik Dhayanjay Dhayagude
//  Date: 20/08/2026
//  Project: Concurrent FTP Server
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include"Marvellous.h"

int main(int argc,char* argv[])
{
	int iRet = 0;
	int Port = 0;
	int bRet = 0;
	int lRet = 0;
	int cRet = 0;
	char Arr[500]= "\0";
	
	char Buffer[1024] = "\0";
	pid_t pid =0;
	struct sockaddr_in ServerAddr;
	struct sockaddr_in ClientAddr;
	
	Port = atoi(argv[1]);
	socklen_t AddrLen = sizeof( ClientAddr);

	printf("Jay Ganesh...\n");
	
	
	
	/*
      	   Step1 -> Creating the socket
      		
      	*/	
	iRet = socket(AF_INET,	// Creating the Tcp Socket 
      		  SOCK_STREAM,
      			 0);
      			 
      			 
 	if(iRet == -1)
      	{
      		printf("Socket is not created\n");
      		return -1;
      	}
      	printf("Socket created successfully\n");
      	
      	
      	/*
      	
      		Step2 -> Bind the Socket and Server
      	*/
      	ServerAddr.sin_family = AF_INET;
      	ServerAddr.sin_port = htons(Port);
      	ServerAddr.sin_addr.s_addr= INADDR_ANY;
      	
      	
      	bRet = bind(iRet,(struct sockaddr*)&ServerAddr,sizeof(ServerAddr)); // Bind() System Call to bind the socket
      	
      	
      	if(bRet == -1)
      	{
      	
      		printf("unable to bind the socket\n");
      		return -1;
      	}
      	
      	printf("Bind the socket uccessfully\n");
      	
      	
      	/*
      	
      		Step3 -> Listen the resquest 
      	
      	*/	
      	lRet = listen(iRet,11); // Listen() System Call to listen mode
      	
      	if(lRet == -1)
      	{
      		printf("Unable to listen the resquet:\n");
      		return -1;
      	}
      	printf("Server waiting at port number:%d\n",Port);
      	
      	/*
      	
      	
      		Step4 -> Server is waiting for the resquest
      	*/
      	
      	for(;;)
      	{
      		cRet = accept(iRet,(struct sockaddr *)&ClientAddr,&AddrLen);  // Accept() System Call to accept the client request
      		
      		if(cRet < 0)
      		{
      			printf("Unable to handel the request\n");
      			continue;
           		
      		}
      		printf("Client gets connected :%s\n",inet_ntoa(ClientAddr.sin_addr));
      		
      		
      		pid = fork(); // fork() system call to creating the new process
      		
      		if(pid < 0)
      		{
      			printf("thred is not created\n");
      			continue;
      		}
      		
      		if(pid == 0)
      		{
      			printf("New process cerated for the client request\n");
      			close(iRet);
      			
      			
				while(strcmp(Buffer,"bye")!= 0)
				{
					iRet = 	read(cRet,Buffer,sizeof(Buffer));
					if(iRet == -1)
					{
						printf("Unable to handel the client request\n");
						break;
					
					}
					else{
						printf("Message from client:%s\n",Buffer);
					
					}
					
					printf("Send one message to the client\n");
					scanf(" %[^'\n']s",Arr);

					iRet = write(cRet,Arr,sizeof(Arr));
					
					if(iRet < 0)
					{
						printf("Unable to handel the client request\n");
						
					
					}
						
				}
				
				printf("Client Dissconnected\n");
			    exit(0); // exit() system call to terminate the successfull process termination
			
      		}
      		else
      		{
      			close(cRet);
      		
      		}
			
     
      	}
		
       	
	
	return 0;


}
