/* Binary search with sorted array
 *
 *
 *
 *
 *
 * */

 

#include<stdio.h>
static int arr[100];
void movedown(int,int,int);
void moveup(int n, int i, int length)
{
 int temp;
if ((arr[i] <= arr[(i<<1) +1]) || (arr[i]<=arr[(i<<1)+2]))
	{

	if(arr[(i<<1)+1] > arr[(i<<1) +2])
		{
		temp=arr[i];
		arr[i]=arr[(i<<1) +1];
		arr[(i<<1) +1]=temp;
		movedown(n,((i<<1)+1),length);

		}
	else
		{
		temp=arr[i];
		arr[i]=arr[(i<<1) +2];
		arr[(i<<1) +2]=temp;
		movedown(n,((i<<1)+2),length);
		}

		


	}

}

void movedown(int n , int i, int length)
{
	int temp;

	if(i<=n)
	if((arr[i]<=arr[(i<<1)+1])||(arr[i]<=arr[(i<<1)+2]))
	{
	if(arr[(i<<1)+1] > arr[(i<<1) +2])
		{
		temp=arr[i];
		arr[i]=arr[(i<<1) +1];
		arr[(i<<1) +1]=temp;
		movedown(n,((i<<1)+1),length);

		}
	else if ( ((i<<1) +2) > length)
		{
		temp=arr[i];
		arr[i]=arr[(i<<1) +2];
		arr[(i<<1) +2]=temp;
		movedown(n,((i<<1)+2),length);
		}



	}
		


}
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

	j=high=n-1;
//heap build 
	if(n%2)
	 n=n-1;
	else
	 n=n-2;


		//printf("value of N:%d\n",n);
	for(i=(n/2);i>=0;i--)
	{ 
		moveup((n/2),i,j);
	}


	printf("Max Heap before sorting:");	
	for(i=0; i<=high ; i++)
	printf("%d  ", arr[i]);

	printf("\n");

	//Heap Sort
	while(high>1)
	{
		temp=arr[0];
		arr[0]=arr[high];
		arr[high]=temp;
		high--;
		if(high%2)
		i=high-1;
		else
		i=high-2;
		if(i!=0)
		movedown((i/2),0,high);
		else

		if(arr[0] > arr[1])
		{
		temp=arr[0];
		arr[0]=arr[1];
		arr[1]=temp;

		}
	
	}
	// printing the sorted elements
	//
	printf("The sorted array:");
	for(i=0; i<=j ; i++)
	printf("%d  ", arr[i]);

	printf("\n");

	//Binary Search
	//
	low=0;
	high=j;
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



