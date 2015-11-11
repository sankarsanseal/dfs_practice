/*



*/
#include<stdio.h>

int add (int a, int b)
{
	int c;

	c=a+b;
	printf("Address of var c inside add function:%p\n",&c);
	return c;
}
int main()
{
	int a,b,c;
	a=5;
	b=6;
	c=add(a,b);
	printf("Address of var c inside main function:%p\n",&c);





return 0;
}



/*
Address of var c inside add function:0x7fff5c254b04
Address of var c inside main function:0x7fff5c254b30

*/

