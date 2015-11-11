/* Counting the number of ones shifting the comparator
 * So we can compare with negative numbers too
 *
 *
 *
 * */
#include<stdio.h>
#include<limits.h>

int main()
{

int  num, count=0;
unsigned i=1;
printf("Enter the interger for comparation:");
scanf("%d",&num);
	while(i!=INT_MIN)
	{
	if(num&i)
	count++;
	i=i<<1;



	}
	if (num <0)
	count++;
printf("The number of ones in the binary expansion of the given integer:%d\n",count);

return 0;

}
