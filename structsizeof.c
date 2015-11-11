/*
 *
 *
 * Size of structure with different arrangement
 *
 *
 *
 * */


#include<stdio.h>

int main()
{

	struct permutation1
	{
	int a;
	float b;
	char c;
	long d;
	short e; 
	double f;
	char arr[7];
	long long g;
	long double h;
	
	


	} p1;

	struct permutation2
	{

	int a;
	float b;
	char c;
	char arr[7];
	long d;
	double f;
	short e;
	long long g;
	long double h;


	} p2;

	printf("Size of permutation1:%lu\n",sizeof(struct permutation1));
	printf("Size of permutation2:%lu\n",sizeof(struct permutation2));

	printf("Value of p1.arr : %d, Address of %p, address of  p1.a : %p\n",p1.arr[0],p1.arr, &(p1.a));
	printf("Value of p2.arr : %d, Address of %p, address of p2.a : %p \n",p2.arr[0],p2.arr,  &(p2.a));





return 0;

}
/* OUTPUT
 *
Size of permutation1:80
Size of permutation2:64
Value of p1.arr : 0, Address of 0x7fff0b94b0e8, address of  p1.a : 0x7fff0b94b0c0
Value of p2.arr : -80, Address of 0x7fff0b94b089, address of p2.a : 0x7fff0b94b080 
 *
 */
