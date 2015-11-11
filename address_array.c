/*
 *
 *
 * */

#include<stdio.h>

int main()
{

	int arr[]={5,3,2,7,1,4,9,8};
	int i=0;

	for (i=0; i< 8; i++)
	{
	printf("Value at index % d is %d with address %p with address difference with previous element  %ld \n", i,arr[i],&arr[i],(&arr[i+1]-&arr[i]));



	} 
	



return 0;
}


/*
 
Value at index  0 is 5 with address 0x7fff21bc3b10 with address difference with previous element  1 
Value at index  1 is 3 with address 0x7fff21bc3b14 with address difference with previous element  1 
Value at index  2 is 2 with address 0x7fff21bc3b18 with address difference with previous element  1 
Value at index  3 is 7 with address 0x7fff21bc3b1c with address difference with previous element  1 
Value at index  4 is 1 with address 0x7fff21bc3b20 with address difference with previous element  1 
Value at index  5 is 4 with address 0x7fff21bc3b24 with address difference with previous element  1 
Value at index  6 is 9 with address 0x7fff21bc3b28 with address difference with previous element  1 
Value at index  7 is 8 with address 0x7fff21bc3b2c with address difference with previous element  1 

*/
