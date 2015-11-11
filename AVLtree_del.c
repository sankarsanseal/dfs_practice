/*
AVL tree construction and traversal
Deletion and Tree Structure display
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct binnode
{
	int data;
	struct binnode * left;
	struct binnode * right;
	int balance_factor;
}	* BINNODE;

BINNODE root=NULL;
	char arr[24][80];

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
void tilted_tree(BINNODE root)
{
	static char tab[20];
	static int top=0;

	if(root)
	{
		tab[top]='\t';
		top++;
		tab[top]='\0';
		tilted_tree(root->right);
		top--;
		tab[top]='\0';
		printf("%s",tab);
		printf("%d\n",root->data);
		tab[top]='\t';
		top++;
		tab[top]='\0';
		tilted_tree(root->left);
		top--;
		tab[top]='\0';

	}//if(root)

}//tilted_tree

void levelorder(BINNODE root,int height,int low,int high)
{
	int mid,i;
	if((low<high)&&root)
	{
		mid=low+((high-low)>>1);

		sprintf(&arr[height][mid],"%d",root->data);
		i=strlen(&arr[height][mid]);
//		printf("%d",i);
		arr[height][mid+i]=' ';
		levelorder(root->left,height+1,low,mid-2);
		levelorder(root->right,height+1,mid+2,high);

	}//if(low<high)

}//levelorder

void tree_struct()
{
	int height=0,i,j;
	for(j=0;j<24;j++)
		for(i=0;i<80;i++)
			arr[j][i]=' ';
	height=tree_height(root);
	levelorder(root,0,0,80);
	for(j=0;j<=height;j++)
		for(i=0;i<80;i++)
			{
			if(arr[j][i]=='\0')
				arr[j][i]=' ';
			arr[j][79]='\0';
			}
	for(i=0;i<=height;i++)
		printf("%s\n",arr[i]);

}

void print_inorder(BINNODE root)
{	if(root!=NULL)
	{
		print_inorder(root->left);
		printf("%d  ",root->data);
		print_inorder(root->right);
	}
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
					temp3->balance_factor=0; 
					temp2=temp3;

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

void delete_node(BINNODE node,BINNODE parent,int data)
{
	BINNODE temp1,temp2;
	if(node==NULL)
		printf("Provided data does not exist in tree.\n");
	else if(node->data>data)
	{
		delete_node(node->left,node,data);
		switch(node->balance_factor)
		{
			case 1:
			node->balance_factor=0;
			break;
			case 0:
			if(!node->left)
			node->balance_factor=-1;
			break;
			case -1:
				temp1=node->right;
				if(temp1->balance_factor==-1)
				{
					node->right=temp1->left;
					temp1->left=node;
					node->balance_factor=0;
					if(node==parent->left)
					parent->left=temp1;
					else
					parent->right=temp1;

				}
				else
				{
					temp2=temp1->left;
					temp1->left=temp2->right;
					temp2->right=temp1;
					node->right=temp2->left;
					temp2->left=node;
					if(node==parent->left)
						parent->left=temp2;
					else
						parent->right=temp2;
						node->balance_factor=
						temp2->balance_factor==
						-1?1:0;
						temp1->balance_factor=
						temp2->balance_factor==
						1?-1:0;
				}//if temp1
				break;


		}//Switch
	}//else if node==NULL

	else if(node->data < data)
	{
		delete_node(node->right,node,data);
		switch(node->balance_factor)
		{
			case 1:
				temp1=node->left;
				if(temp1->balance_factor==-1)
					{
					node->left=temp1->right;
					temp1->right=node;
					node->balance_factor=0;
					if(parent->left==node)
						parent->left=temp1;
					else
						parent->right=temp1;
					}//if temp1->balance_factor
				else
					{
					temp2=temp1->right;
					node->left=temp2->right;
					temp2->right=node;
					temp1->right=temp2->left;
					temp2->left=temp1;
					if(node==parent->left)
						parent->left=temp2;
					else
						parent->right=temp2;

						node->balance_factor=
						temp2->balance_factor==
						1?-1:0;
						temp1->balance_factor=
						temp2->balance_factor==
						-1?1:0;
					}
				break;
			case 0:
				if(!node->right)
				node->balance_factor=1;
				break;
			case -1:
				node->balance_factor=0;
				break;
		}//Switch

	}//else if node->data < data

	else if(node->left && node->right)
	{
		temp2=node;
		temp1=node->right;
		while(temp1->left)
		{
		temp2=temp1;
		temp1=temp1->left;
		}
		node->data=temp1->data;
		delete_node(temp1,temp2,temp1->data);
	}

	else
	{
		temp1=node;
		if(!(node->left) && !(node->right))
		{
			if(parent->left==node)
				parent->left=NULL;
			else
				parent->right=NULL;
		}

		else if(!(node->right))
		{
			if(parent->left==node)
				parent->left=node->left;
			else
				parent->right=node->left;

		}
		else
		{
			if(parent->left==node)
				parent->left=node->right;
			else
				parent->right=node->right;

		}

		free(temp1);
	}

}
void menu()
{
	int c=0,data;
	BINNODE temp;
	while(c!=9)
	{
	printf("\t\tMenu for AVL tree build and Traversal\n");
	printf("\t\t\t1.Insert into AVL tree\n");
	printf("\t\t\t2.Search in AVL tree\n");
	printf("\t\t\t3.Height of the tree\n");
	printf("\t\t\t4.Number of nodes in the tree\n");
	printf("\t\t\t5.Inorder Traversal\n");
	printf("\t\t\t6.Sidewise Tree structure\n");
	printf("\t\t\t7.Deletion from tree\n");
	printf("\t\t\t8.Usual Tree Structure\n");
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
			case 6:
				printf("Tree in sidewise view:\n");
				tilted_tree(root);
				break;
			case 7:
			printf("Enter the node with data to be deleted:");
				scanf("%d",&data);
				delete_node(root,root,data);
				break;
			case 8:
				printf("Tree in usual pictorial display\n");
				tree_struct();
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
