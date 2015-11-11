/*

Inorder Traversal with stack only

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct binnode
{
int data;
struct binnode * left, * right;
} * BINNODE;
BINNODE root=NULL;
BINNODE stk[127];
void insert_node(BINNODE root, int data)
{
  BINNODE temp;
	if(root->data>data)
	{
		if(root->left==NULL)
		{
		if((temp=(BINNODE)malloc(sizeof(struct binnode)))==NULL)
			printf("Error 1: memory alllocation.\n");
		else
			{
			root->left=temp;
			temp->data=data;
			temp->left=temp->right=NULL;
			}
		}
		else
			insert_node(root->left,data);
	}
	else if(root->data < data)
		{
		if(root->right==NULL)
		{

		if((temp=(BINNODE)malloc(sizeof(struct binnode)))==NULL)
			printf("Error 2: memory allocation problem.\n");
		else
			{
			temp->data=data;
			temp->left=temp->right=NULL;
			root->right=temp;
			}
		}
		else
			insert_node(root->right,data);
		}
	else
		printf("Node already exists.\n");

}

void print_inorder(BINNODE root)
{
int top=-1;
BINNODE temp=root;
			
		while(1)
		{
			while(temp)
			{ top++;
			stk[top]=temp;
			temp=temp->left;
			}

			if(top==-1)
				break;
			temp=stk[top];
			top--;
	  		printf("%d  ",temp->data);
				temp=temp->right;
		}
		
	  
	  printf("\n");

}
void deallocate(BINNODE root)
{
if(root!=NULL)
   {
	if(root->left!=NULL)
 	deallocate(root->left);
	if(root->right!=NULL)
 	deallocate(root->right);
 	free(root);
   }
}

int main()
{

int data,c=0;
	while(c!=9)
		{
		printf("\t\t\tMenu for Inorder traversal with Stack\n");
		printf("\t\t1.Insert data.\n");
		printf("\t\t2.Traverse the tree.\n");
		printf("\t\t9.Exit.\n");
		printf("\t\t\tEnter your choice:");

		scanf("%d",&c);
		switch(c)
			{
			case 1:
				printf("Enter the data to be inserted:");
				scanf("%d",&data);
				if(root==NULL)
				{
		if((root=(BINNODE)malloc(sizeof(struct binnode)))==NULL)
			printf("Error 0: memory allocation problem.\n");
		else
			{
			root->data=data;
			root->left=root->right=NULL;
			}
				}
				else
				insert_node(root,data);

				break;
			case 2:
				print_inorder(root);
				break;
			case 9:
				deallocate(root);
				break;
			}
		}
return 0;
}
