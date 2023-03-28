//6)	Develop 3 child processes for doing the below tasks
//Child process 1- check the given number is even or odd
//Child peocess 2 - Check whether the given number is prime or not
//child oricess 3 - Check whether the given number is divisible by 7 or not.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int k=fork();
int l=fork();
int m=fork();
int num=10;
int flg=0;
if(k==0)
{
if(num%2==0)
{
printf("Even \n");
}
else
{
printf("Odd \n");
}
}
if(l==0)
{
if(num==1 || num==0)
{
flg=1;
}
for(int i=2;i<=num/2;i++)
{
if(num%i==0)
{
flg=1;
}
}
if(flg==0)
{
printf("prime\n");
}
else
{
printf("Not Prime\n");
}
}
if(m==0)
{
if(num%7==0)
{
printf("Divisible by 7\n");
}
else
{
printf("Not divisible by 7\n");
}
}
return 0;
}
