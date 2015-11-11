/*
AVL tree construction and traversal
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct binnode
{
	int data;
	struct binnode * left;
	struct binnode * right;
	int balance_factor;
}	* BINNODE;

BINNODE root=NULL;

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
void print_inorder(BINNODE root)
{	if(root!=NULL)
	{
		print_inorder(root->left);
		printf("%d  ",root->data);
		print_inorder(root->right);
	}
}




int tree_height(BINNODE root)
{
	int left_height=0,right_height=0;
	if(root!=NULL)
	{
		if(root->left==NULL&&root->right==NULL)
		return 0;
		else
		{
		left_height=tree_height(root->left);
		right_height=tree_height(root->right);
		
	//Finding the maximum height of subtrees
	return	1 + (left_height>right_height?left_height:right_height);
		}
	}
	else
	return 0;

}

int count_node(BINNODE root)
{
	if(root!=NULL)
		return 1 + count_node(root->left) + count_node(root->right);
	else
		return 0;
}

BINNODE search_node(BINNODE root,int data)
{
	if(root!=NULL)
	{
	if(root->data == data)
		return root;
	else if (root->data > data)
		return search_node(root->left,data);
	else if (root->data < data)
		return search_node(root->right,data);
	else
		return NULL;

	}
	else
		return NULL;

}

void insert_node(int data)
{
	BINNODE temp=NULL,temp2,temp3,parent,node,first_1,parent_f_1;
	int exist=0, diff=0,balanced=0;
	first_1=node=root;
	parent_f_1=NULL;
	parent=NULL;
	while(node&&!exist)
	{
		if(node->balance_factor)
		{
			first_1=node; parent_f_1=parent;
		}
		if(node->data >data)
		{
			parent=node; node=node->left;
		}
		else if(node->data < data)
		{
			parent=node;node=node->right;
		}

		else
		{
			exist=1;
			printf("Node exists.\n");
		}

	}
	 if(!exist)
		{
			if((temp=(BINNODE)malloc(sizeof(struct binnode)))\
			==NULL)
			printf("Error 2: Memory Allocation Problem.\n");
			else
			{
			temp->data=data;
			temp->balance_factor=0;
			temp->left=temp->right=NULL;

			if(parent->data > data)
				parent->left=temp;
			else 
				parent->right=temp;
			}

			if(first_1->data > data)
			{
				node=first_1->left;temp2=node;diff=1; 
			}
			else
			{
				node=first_1->right;temp2=node;diff=-1;
			}

			while(node!=temp)
			{
				if(node->data > data)
					{
					node->balance_factor=1;
					node=node->left;
					}
				else
					{
					node->balance_factor=-1;
					node=node->right;
					}
			}

			if(!first_1->balance_factor ||
				!(first_1->balance_factor+diff))
			{
				first_1->balance_factor+=diff;	
				balanced=1;
			}

			if(!balanced)
			{
				if(diff==1)
				{
					if(temp2->balance_factor==1)
					{
					first_1->left=temp2->right;
					temp2->right=first_1;
					first_1->balance_factor=0;
					temp2->balance_factor=0;
					}
					else
					{
					temp3=temp2->right;
					temp2->right=temp3->left;
					first_1->left=temp3->right;
					temp3->left=temp2;
					temp3->right=first_1;

					   switch(temp3->balance_factor)
						{
						case 1:
						first_1->balance_factor=-1;
						temp2->balance_factor=0;
						break;
						case 0:
						first_1->balance_factor=0;
						temp2->balance_factor=0;
						break;
						case -1:
						first_1->balance_factor=0;
						temp2->balance_factor=1;
						break;
						}

					temp3->balance_factor=0; 
					temp2=temp3;

					}
				}
				else
				{
				  if(temp2->balance_factor==-1)
				  {
				     first_1->right=temp2->left;
				     temp2->left=first_1;
				     temp2->balance_factor=0;
				     first_1->balance_factor=0;
				  }
				  else
				  {
					temp3=temp2->left;
					temp2->left=temp3->right;
					first_1->right=temp3->left;
					temp3->right=temp2;
					temp3->left=first_1;
					switch(temp3->balance_factor)
					{
					  case 1:
					       first_1->balance_factor=-1;
					       temp2->balance_factor=0;
					       break;
					  case 0:
					  	temp2->balance_factor=0;
						first_1->balance_factor=0;
						break;
					  case -1:
					  	first_1->balance_factor=0;
						temp2->balance_factor=1;
						break;

					}
				  }
				}

			if(!parent_f_1)
			root=temp2;
			else if(first_1==parent_f_1->left)
				parent_f_1->left=temp2;
			else if(first_1==parent_f_1->right)
				parent_f_1->right=temp2;
			}
		}
			
}
void menu()
{
	int c=0,data;
	BINNODE temp;
	while(c!=9)
	{
	printf("\t\t\t\tMenu for AVL tree build and Traversal\n");
	printf("\t\t\t1.Insert into AVL tree\n");
	printf("\t\t\t2.Search in AVL tree\n");
	printf("\t\t\t3.Height of the tree\n");
	printf("\t\t\t4.Number of nodes in the tree\n");
	printf("\t\t\t5.Inorder Traversal\n");
	printf("\t\t\t9.Exit\n");
		printf("\t\t\t\tEnter your choice:");
	scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("Enter the data to be inserted:");
			scanf("%d",&data);
			if(root==NULL)
			{
			if((temp=(BINNODE)malloc(sizeof(struct binnode)))\
			==NULL)
				printf("Error 1:\
				Memory Allocation Problem.\n");
			else
				{
				temp->data=data;
				temp->left=NULL;
				temp->right=NULL;
				temp->balance_factor=0;
				root=temp;
				}
			}
			else
				insert_node(data);
			break;
			case 2:
			printf("Enter the data to serach:");
			scanf("%d",&data);
			if((temp=search_node(root,data))==NULL)
				printf("Node does not exist.\n");
			else
				printf("Node found,with balance factor:%d\n"
				,temp->balance_factor);
			break;
			case 3:
				printf("Height of the tree:%d\n"\
				,tree_height(root));
			break;
			case 4:
				printf("Number of nodes in the tree:%d\n"\
				,count_node(root));
				break;
			case 5:
				print_inorder(root);
				printf("\n");
				break;
			case 9:
				deallocate(root);
				printf("Exiting...\n");
				break;


		}
	}
}

int main()
{
menu();
return 0;
}
