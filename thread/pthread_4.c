#include<stdio.h>
#include<pthread.h>

void * Demo(void * p)
{
  printf("Inside thread\n");
  return NULL;
}
int main()
{

    pthread_t TID;
    int iRet = 0;

    printf("Main thread started\n");

    iRet = pthread_create(
                            &TID,  // thread id 
                            NULL,  //thread atributes 
                            Demo,  // thread call by function 
                            NULL   // parameters for they callback function
                        );

    

    if(iRet ==0)
    {
        printf("thread gets created succesfully with tid: %lu\n",(unsigned long)TID);
    }
    //wait
    pthread_join(TID,NULL);
    
    printf("End of main thread\n");
   
    
    return 0;
}