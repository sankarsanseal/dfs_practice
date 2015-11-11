#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int label,element;
	struct node * next;
} * NODE;
void push(NODE head,int data)
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));
temp->element=data;
temp->next=head->next;
head->next=temp;

}

int pop(NODE head)
{
 NODE temp;
 int data;
if(head!=NULL)
	{
	temp=head->next;
	head->next=head->next->next;
	data=temp->element;
	free(temp);
	return data;
	}
return -1;
}

void tower_of_hanoi(int n,NODE a, NODE b, NODE c)
{
 int data;
	if(n==1)
		{
		printf("Moving from %d peg to %d peg",
		a->label,c->label);
		data=pop(a);
		printf(", element value:%d\n",data);
		push(c,data);
		}
	else
		{
		tower_of_hanoi(n-1,a,c,b);
		printf("Moving from %d peg to %d peg",a->label,c->label);
		data=pop(a);
		printf(", element value:%d\n",data);
		push(c,data);
		tower_of_hanoi(n-1,b,a,c);
		
		}
}

int main()
{

NODE a,b,c,temp;
int n,i;

printf("Enter the number of loops in first peg:");
scanf("%d",&n);

a=(NODE)malloc(sizeof(struct node));
a->label=1;
a->next=NULL;

for(i=0;i<n;i++)
	{
	temp=(NODE)malloc(sizeof(struct node));
	temp->element=n-i;
	temp->next=a->next;
	a->next=temp;

	}
printf("First peg is displayed beneath:\n");

temp=a->next;
while(temp)
{
	printf("%d\n",temp->element);
	temp=temp->next;
}

b=(NODE)malloc(sizeof(struct node));
b->label=2;
b->next=NULL;

c=(NODE)malloc(sizeof(struct node));
c->label=3;
c->next=NULL;

tower_of_hanoi(n,a,b,c);
printf("Third peg is displayed beneath:\n");

temp=c->next;
while(temp)
{
	printf("%d\n",temp->element);
	temp=temp->next;
}
return 0;
}
