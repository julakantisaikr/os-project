#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
int main()
{
int id,n;
printf("Enter the value:");
scanf("%d",&n);
pid_t f;
f=fork();
if(f==0)
{
printf("Child has created:");
while(n>0)
{
printf("the value for %d is",n);
n=n/2;
}
}
else if(f>0)
{
wait(NULL);
printf("parent section");
}
else
{
printf("case failure:");
}
}


