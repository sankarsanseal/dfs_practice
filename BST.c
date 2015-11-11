/*

Binary Search Tree

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct binnode
{

	int data;
	struct binnode *left,*right;
} * BINNODE;

BINNODE root=NULL;

struct parent_child
{
BINNODE parent;
BINNODE child;
} pc;

void node_insert(BINNODE * root,int data)
{
	if((*root)==NULL)
		{
		*root=(BINNODE)malloc(sizeof(struct binnode));
		(*root)->data=data;
		(*root)->left=NULL;
		(*root)->right=NULL;
		}
	else if((*root)->data>data)
		{if((*root)->left!=NULL)
			node_insert(&((*root)->left),data);
		  else
		  	{
			(*root)->left=(BINNODE) malloc(sizeof(struct binnode));
			(*root)->left->data=data;
			(*root)->left->left=NULL;
			(*root)->left->right=NULL;
			}

		}
	else if((*root)->data < data)
		{
		if ((*root)->right!=NULL)
			node_insert(&((*root)->right),data);
		else
			{
			(*root)->right=(BINNODE) malloc(sizeof(struct binnode));
			(*root)->right->data=data;
			(*root)->right->left=NULL;
			(*root)->right->right=NULL;

			
			}
		}
	else
		printf("Node already exists\n");




}


void node_delete(BINNODE root,BINNODE root_p)
{
	BINNODE temp;
	if((root!=NULL)&&(root_p!=NULL))
	{
		if(root->right!=NULL)
		{
		temp=root->right;
		pc.parent=root;
		pc.child=temp;
		while(temp->left!=NULL)
			{
			pc.parent=temp;
			temp=temp->left;
			pc.child=temp;
			}
		root->data=temp->data;
		node_delete(pc.child,pc.parent);
		
		}
		else if (root->left!=NULL)
		{
		temp=root->left;
		pc.parent=root;
		pc.child=temp;
		while(temp->right!=NULL)
			{
			pc.parent=temp;
			temp=temp->right;
			pc.child=temp;
			}
		root->data=temp->data;
		node_delete(pc.child,pc.parent);
		


		}
		else if ((root->left ==NULL)&&(root->right==NULL))
		{
		if(root_p->left==root)
			root_p->left=NULL;
		else
			root_p->right=NULL;
			
		free(root);
		
		}
	}
/*	else
		
		free_root();*/
}



void inorder(BINNODE root)
{
	if(root==NULL)
		{

		}
	else
		{
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
		}


}

void preorder(BINNODE root)
{
	if(root==NULL)
	{

	}
	else
	{
		printf("%d  ",root->data);
		preorder(root->left);
		preorder(root->right);

	}




}

void postorder(BINNODE root)
{
	if(root==NULL)
	{

	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d  ",root->data);
	}
}
void deallocate(BINNODE root)
{
 if(root==NULL)
 	{

	}
else 
	{
	deallocate(root->left);
	deallocate(root->right);
	
	free(root);

	}

}

void  search_bin(BINNODE root,int data)
{
 if(root!=NULL)
 {
  if(root->data==data)
  	{
  	pc.child=root;
	}
  else if (root->data < data)
  		{
		pc.parent=root;
		pc.child=root->right;
	 	search_bin(root->right,data);
  		}
  else if (root->data > data )
  		{
		pc.parent=root;
		pc.child=root->left;
  		 search_bin(root->left,data);
		 }

  else
  	pc.child=NULL;
  }

}


void menu()
{
int c=0, data;
//BINNODE temp=NULL,temp_p=NULL;

while (c!=8)
{
printf("\t\t\t\tMenu for Binary Serach Tree\n");
printf("\t\t1.Node Insertion\n");
printf("\t\t2.Node Deletion\n");
printf("\t\t3.Node Update\n");
printf("\t\t4.InOrder Traversal\n");
printf("\t\t5.Preorder Traversal\n");
printf("\t\t6.Postorder Traversal\n");
printf("\t\t7.Search data\n");
printf("\t\t8.Exit\n");

printf("\t\t\t Enter your choice:");
scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("Enter the data to be inserted:");
			scanf("%d",&data);
			node_insert(&root,data);
			break;
		case 2:
			printf("Enter the data to be deleted:");
			scanf("%d",&data);
			pc.parent=root;
			pc.child=NULL;
			search_bin(root,data);
			if(pc.parent==pc.child)
				{
				if((pc.child->left!=NULL)&&(pc.child->right!=NULL))
				{
				//pc.child->data=pc.child->right->data;
				node_delete(pc.child,pc.child);
				}
				else if((pc.child->left==NULL)&&(pc.child->right!=NULL))
				
				{
				//pc.child->data=pc.child->right->data;
				node_delete(pc.child,pc.child);
				}
				else if((pc.child->left!=NULL)&&(pc.child->left!=NULL))
				{
				//pc.child->data=pc.child->left->data;
				node_delete(pc.child,pc.child);
				}
				}
			else
			node_delete(pc.child,pc.parent);
			    
			break;
		case 3:
			printf("Enter the data to update:");
			scanf("%d",&data);
			search_bin(root,data);
			if(pc.child!=NULL)
			{
			pc.parent=root;
			pc.child=NULL;
			search_bin(root,data);
			if(pc.parent==pc.child)
				{
				if((pc.child->left!=NULL)&&(pc.child->right!=NULL))
				{
				//pc.child->data=pc.child->right->data;
				node_delete(pc.child,pc.child);
				}
				else if((pc.child->left==NULL)&&(pc.child->right!=NULL))
				
				{
				//pc.child->data=pc.child->right->data;
				node_delete(pc.child,pc.child);
				}
				else if((pc.child->left!=NULL)&&(pc.child->left!=NULL))
				{
				//pc.child->data=pc.child->left->data;
				node_delete(pc.child,pc.child);
				}
				}
			else
			node_delete(pc.child,pc.parent);
			 
			
			 printf("Enter the new data of that node:");
				scanf("%d",&data);
				node_insert(&root,data);
			}
			else
				printf("Provided node does not exist.\n");

			break;
		case 4:
			printf("Inorder tranversal of BST:\n");
			inorder(root);
			printf("\n");
			break;
		case 5:
			printf("Preorder traversal of BST:\n");
			preorder(root);
			printf("\n");
			break;
		case 6:
			printf("Postorder traversal of BST:\n");
			postorder(root);
			printf("\n");
			break;
		case 7:
			printf("Enter the node to search:");
			scanf("%d",&data);
			search_bin(root,data);
			if(pc.child!=NULL)
				printf("Data found.\n");
			else
				printf("Node does not exist.\n");
			break;
		case 8:
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


