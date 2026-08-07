#include<stdio.h>
#include<pthread.h>

void * Demo(void * p)
{
  printf("Inside thread with value :\n");  
  printf("%d\n",*(int*)(p+0));
  printf("%d\n",*((int*)p+1));
  printf("%d\n",*((int*)p+2));
  printf("%d\n",*((int*)p+3));
  return NULL;
}
int main()
{

    pthread_t TID;
    int iRet = 0;
    int Value = 0;
    int Arr[]={11,21,51,101};


    printf("Main thread started\n");

    iRet = pthread_create(
                            &TID,  // thread id 
                            NULL,  //thread atributes 
                            Demo,  // thread call by function 
                            (int*)Arr     // parameters for they callback function
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