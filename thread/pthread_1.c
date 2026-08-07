#include<stdio.h>


void Demo(int *p)
{
    *p=11;

}
int main()
{
     int no = 11;
     Demo(&no);
     printf("Return value is :%d\n",no);
    
    return 0;
}