/*

Illustration of difference between call by value and call by reference

*/

#include<stdio.h>
void swapv(int a, int b)
{
int temp;
	temp=a;
	a=b;
	b=temp;
	printf("Address of a and b inside swapv: %p and %p \n ", &a, &b);

}
void swapr(int *a, int *b)
{
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
	printf("Address of a and b inside swapr: %p and %p \n ", &a, &b);


}
int main()

{

 int a=4,b=6;
 printf("Before swapv:\n");
 printf("Value of a and b, respectively: %d and %d \n", a,b);
 swapv(a,b);
 printf("After swapv:\n");
 printf("Value of a and b, respectively: %d and %d \n", a,b);

 printf("Before swapr:\n");
 printf("Value of a and b, respectively: %d and %d \n", a,b);
 swapr(&a,&b);
 printf("After swapr:\n");
 printf("Value of a and b, respectively: %d and %d \n", a,b);

return 0;
}

/*
Before swapv:
Value of a and b, respectively: 4 and 6 
Address of a and b inside swapv: 0x7fff5ad6baec and 0x7fff5ad6bae8 
 After swapv:
Value of a and b, respectively: 4 and 6 
Before swapr:
Value of a and b, respectively: 4 and 6 
Address of a and b inside swapr: 0x7fff5ad6bae8 and 0x7fff5ad6bae0 
 After swapr:
Value of a and b, respectively: 6 and 4 

*/

