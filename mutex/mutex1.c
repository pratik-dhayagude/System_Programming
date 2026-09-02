#include<stdio.h>
#include<pthread.h>

int iCnt = 0;

void * Increament(void * arg)
{
    //critical section start
    iCnt++;
    //critical section end
    printf("%d\n",iCnt);
    return NULL;

}
int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,Increament,NULL);
    pthread_create(&t2,NULL,Increament,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}