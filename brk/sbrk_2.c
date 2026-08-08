#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    void *current_break = NULL;

    void *new_break = NULL;
    
    current_break = sbrk(0);

    printf("Current Process Break :%p\n",current_break);

    new_break = sbrk(100);

    strcpy((char*)new_break,"jay Ganesh...");
      
      printf("Data From New Memory:%s\n",(char*)new_break);

    sbrk(-100); // like Free
    return 0;
}