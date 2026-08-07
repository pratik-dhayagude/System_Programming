#include<stdio.h>
#include<pthread.h>

void * Demo(void * p)
{
    int iSum =0;

    printf("Inside thread with value:\n");  
 
    iSum = (*((int*)p+0))+(*((int*)p+1))+(*((int*)p+2))+(*((int*)p+3));
    // return (int*)iSum;
    pthread_exit((int*)iSum);
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

    
    pthread_join(TID,&Value); 
    
    printf("Sumation is : %d\n",Value);
    printf("End of main thread\n");
   
    
    return 0;
}