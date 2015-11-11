/*Counting the one shifting the given number
 *
 *
 * */
#include <stdio.h>

int main()
{

unsigned int num,count =0;
printf("Enter the number for counting 1s in the binary form:");
scanf("%d",&num);
	while(num>0)
	{
	if(num&1)
	count++;
	num=num>>1;


	}

printf("The number of 1's in the binary expansion:%u",count);


return 0;
}
