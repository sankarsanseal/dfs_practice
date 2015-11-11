/*

Counting one with out using any operand

*/
#include<stdio.h>

int main()
{
	int num,count=0;
	printf("Enter the number of which count the 1's in binary expansions:");
	scanf("%d",&num);
	while(num!=0)
		{
		num=num&(num-1);
		count++;


		}
	printf("Number of 1's in the binary expansion %d",count);
return 0;
}

/*
Enter the number for counting 1s in the binary form:The number of 1's in the binary expansion:32
*/

