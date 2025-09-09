#include<stdio.h>
#include<stdlib.h>
void main()
{
 int a,b,temp;
 printf("Enter two numbers");
 scanf("%d %d",&a ,&b);
 temp=a;
 a=b;
 b=temp;
 printf("The swapped values are %d %d",a,b);
} 
