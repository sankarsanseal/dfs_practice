/* Binary search with sorted array
 *
 *
 *
 *
 *
 * */

#include<stdio.h>
static int arr[100];
int main()
{

	int low=0,high=-1,mid=0,n=0,i=0,j,temp,x;

	printf("Enter the number of elements to be used for binary search:");
	scanf("%d",&n);



	for (i =0; i<n;i++)
	{
	printf("Enter the %d element:",i+1);
	scanf("%d",&arr[i]);



	}

	high=n-1;
//heap build 
	if(n%2)
	 n=n-1;
	else
	 n=n-2;


		printf("value of N:%d\n",n);
	for(i=(n/2);i>=0;i--)
	{ 
		printf("value of I:%d\n",i);

	if((arr[i] <= arr[(i<<1)+1]) && (arr[(i<<1)+1] >= arr [(i<<1)+2]))
		{
		//swaping
		printf("value of I:%d\n",i);
		temp=arr[i];
		arr[i]=arr[(i<<1)+1];
		arr[(i<<1) + 1] =temp;

		j=(i<<1) +1;

		while(j <= (n/2))
			{
			if((arr[j] <= arr[(j<<1)+1]) && \
				(arr[(j<<1)+1] >= arr [(j<<1)+2]))
				{
				//swaping
				temp=arr[j];
				arr[j]=arr[(j<<1)+1];
				arr[(j<<1) + 1] =temp;
				j=(j<<1) +1;
			
				}
			else if ( (arr[j] <= arr[( j <<1)+ 2]) && \
					( arr[(j<<1)  +2 ] >= arr[ (j<<1) +1] ))	
				{
				//swaping
				temp=arr[j];
				arr[j]=arr[(j<<1) +2];
				arr[ (j<<1) + 2] =temp;
				j=(j<<1) +2;


				}


			}



		}
	else if ( (arr[i] <= arr[(i<<1)+ 2]) && ( arr[(i<<1)  +2 ] >= arr[ (i<<1) +1] ))	
		{
		//swaping
		printf("value of I:%d",i);
		temp=arr[i];
		arr[i]=arr[(i<<1) +2];
		arr[ (i<<1) + 2] =temp;
		j=(i<<1) +2;
		while(j <= (n/2))
			{
			if((arr[j] <= arr[(j<<1)+1]) && \
				(arr[(j<<1)+1]>= arr [(j<<1)+2]))
				{
				//swaping
				temp=arr[j];
				arr[j]=arr[(j<<1)+1];
				arr[(j<<1) + 1] =temp;
				j=(j<<1) +1;
			
				}
			else if ( (arr[j] <= arr[( j <<1)+ 2]) && \
					( arr[(j<<1)  +2 ] >= arr[ (j<<1) +1] ))	
				{
				//swaping
				temp=arr[j];
				arr[j]=arr[(j<<1) +2];
				arr[ (j<<1) + 2] =temp;
				j=(j<<1) +2;


				}

			}




		}
		}

	printf("Max Heap before sorting:");	
	for(i=0; i<=high ; i++)
	printf("%d  ", arr[i]);

	printf("\n");

	//Heap Sort

	printf("high value:%d",high);
	for(; high >1;high-- )
	{
	//swap 
	printf("high value:%d",high);
	temp=arr[0];
	arr[0]=arr[high];
	arr[high]=temp;

	if(high%2)
	i=high-1;
	else
	i=high-2;
		j=0;
		while(j <= (i/2))
			{
			if((arr[j] <= arr[(j<<1)+1]) && \
				(arr[(j<<1)+1] >= arr [(j<<1)+2]))
				{
				//swaping
				temp=arr[j];
				arr[j]=arr[(j<<1)+1];
				arr[(j<<1) + 1] =temp;
				j=(j<<1) +1;
			
				}
			else if ( (arr[j] <= arr[( j <<1)+ 2]) && \
					( arr[(j<<1)  +2 ] >= arr[ (j<<1) +1] ))	
				{
				//swaping
				temp=arr[j];
				arr[j]=arr[(j<<1) +2];
				arr[ (j<<1) + 2] =temp;
				j=(j<<1) +2;


				}

			}

		 


	}	

	// printing the sorted elements
	//
	printf("The soreted array:");
	for(i=0; i<n ; i++)
	printf("%d  ", arr[i]);

	printf("\n");

	//Binary Search
	//
	low=0;
	high=n-1;
	j=-1;
	printf("Enter the element to be search:");
	scanf("%d",&x);
	while (low <=high && j==-1)
	{
	
		mid=low + ((high - low)/2);
		if( arr[mid]== x)
		{
		printf("Element is found at %d location where starting index is 0.\n", mid);
		j=0;
		}
		else if ( arr[mid] > x )
		 high=--mid ;
		else if ( arr[mid] < x)
		 low=++mid;


	}

	if (j==-1)

		printf("Element is not in the list.\n");

return 0;

}



