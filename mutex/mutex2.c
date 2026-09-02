#include<stdio.h>
#include<pthread.h>

int iCnt = 0;
pthread_mutex_t lock;


void * Increament(void * arg)
{
    //critical section start
    pthread_mutex_lock(&lock);

    iCnt++;
   
    printf("%d\n",iCnt);

    pthread_mutex_unlock(&lock);
    //critical section end
    return NULL;

}
int main()
{
    pthread_t t1,t2;
    pthread_mutex_init(&lock,NULL);

    pthread_create(&t1,NULL,Increament,NULL);
    pthread_create(&t2,NULL,Increament,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}