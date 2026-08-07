#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

void * Demo(void * p)
{
    int fd = 0;
    int iRet=0,iCount=0,iCnt=0;
    char Buffer[1024] ={'\0'};

    fd = open("PPA.txt",O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(iCnt = 0;iCnt<iRet;iCnt++)
        {
            if((Buffer[iCnt]>='A')&&(Buffer[iCnt]<='Z'))
            {
                iCount++;
            }
        }
    }
    close(fd);
    printf("Number of capital characters :%d\n",iCount);
   

  
  return NULL;
}

void * Hello(void * p)
{
    int fd = 0;
    int iRet=0,iCount=0,iCnt=0;
    char Buffer[1024] ={'\0'};

    fd = open("LB.txt",O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(iCnt = 0;iCnt<iRet;iCnt++)
        {
            if((Buffer[iCnt]>='a')&&(Buffer[iCnt]<='b'))
            {
                iCount++;
            }
        }
    }
    close(fd);
    printf("Number of small characters :%d\n",iCount);
   
 
   return NULL;
}

int main()
{

    pthread_t TID1,TID2;
    int iRet = 0;

    printf("Main thread started\n");

    iRet = pthread_create(
                            &TID1,  // thread id 
                            NULL,  //thread atributes 
                            Demo,  // thread call by function 
                            NULL   // parameters for they callback function
                        );

    

    if(iRet ==0)
    {
        printf("thread gets created succesfully with tid: %lu\n",(unsigned long)TID1);
    }



    iRet = pthread_create(
                            &TID2,  // thread id 
                            NULL,  //thread atributes 
                            Hello,  // thread call by function 
                            NULL   // parameters for they callback function
                        );

    

    if(iRet == 0)
    {
        printf("thread gets created succesfully with tid: %lu\n",(unsigned long)TID2);
    }

    //wait
    pthread_join(TID2,NULL);

    pthread_join(TID1,NULL);
    
    printf("End of main thread\n");
   
    
    return 0;
}