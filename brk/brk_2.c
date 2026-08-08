#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    void *current_break = NULL;

    
    current_break = sbrk(0);

    printf("Current Process Break :%p\n",current_break);

    brk((char*)current_break+100);

    strcpy((char*)current_break,"jay Ganesh...");
      
      printf("Data From New Memory:%s\n",(char*)new_break);

    sbrk(-100); // like Free
    return 0;
}