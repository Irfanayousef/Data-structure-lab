#include<stdio.h>
#include<stdlib.h>
void main()
{
 int l,b,a,p;
 printf("Enter the length and breadth of the rectangle");
 scanf("%d %d", &l,&b);
 a=l*b;
 p=2*(l+b);
 printf("The area and perimeter of the rectangle is %d %d",a,p);
}
