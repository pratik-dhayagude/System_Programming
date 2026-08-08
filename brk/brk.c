#include<stdio.h>          // Provides printf() function
#include<unistd.h>         // Provides brk() and sbrk() system calls
#include<string.h>         // Provides strcpy() function

int main()
{
    void *current_break = NULL;    // Pointer to store current program break

    current_break = sbrk(0);       // sbrk(0): get current program break

    printf("Current process break %p\n", current_break); // Print current break address

    brk((int *)current_break + 400);  // brk(): increase break by 100 bytes

    

    printf("data from new memory %ld\n",(int *)current_break); // Print stored data

    sbrk(-100);    // sbrk(-100): decrease break to free memory

    return 0;       
}
