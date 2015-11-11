#include "trie.h"

TRIE_NODE * make_trie(void);
int insert_trie(TRIE_NODE *root, char *word);

TRIE_NODE* make_trie(void)
{
	TRIE_NODE *temp;
	int i;
	if((temp=(TRIE_NODE *)malloc(sizeof(TRIE_NODE)))==NULL)
		return NULL;
	else
		{
		for(i=0;i<27;i++)
			temp->next[i]=NULL;
		return temp;
		}
}

void dealloc(TRIE_NODE * root)
{
	int i;

	if(root)
		{
			for(i=0;i<27;i++)
			if(root->next[i])
				dealloc(root->next[i]);
		free(root);
		}

}

int insert_trie(TRIE_NODE * root, char *word)
{
	char *temp=word;
	TRIE_NODE *temp1=root;
	while(*temp!='\0')
	{
		
			while(*temp&&temp1->next[*temp-96])
			{
			temp1=temp1->next[*temp-96];
				//printf(">%d,%c\n",*temp-97,*temp);
			temp++;
			}
			if((*temp)
			&&(temp1->next[*temp-96]=make_trie())==NULL)
				printf("%d,%c\n",*temp-96,*temp);
			else
			if(*temp)
			{		
				//printf("+%d,%c\n",*temp-97,*temp);
			temp1=temp1->next[*temp-96];
				//temp1->c=*temp;
			temp++;
			}
	}
	if(*temp=='\0')
		{
			if(!(temp1->next[0]))
			temp1->next[0]=make_trie();
		}
 return 0;
}

void display(TRIE_NODE * root)
{
	static char stk[100];
	static int top=-1;
	int i,empty=1;

		top++;
		for(i=0;i<27;i++)
		{
			if(root->next[i])
				{

				if(i==0)
				stk[top]='\0';
				else
				stk[top]=i+96;

				display(root->next[i]);
				empty=0;
				}
		}
		if(empty)
			{
			stk[top]='\0';
			printf("%s\n",stk);
			}
		stk[top]='\0';
		top--;
}

int main(int argc, char *argv[])
{
	int i, length;
	char arr[100];
	FILE *fp;
	TRIE_NODE *root;
	if((root=make_trie())==NULL)
		{
		printf("Problem with memory allocation\n");
		exit(1);
		}
	if(argc!=2)
		printf("usage %s <input file name>\n",argv[0]);
	else
		{
			if((fp=fopen(argv[1],"r"))==NULL)
				printf("Problem with input file.\n");
			else
			{
				while(!feof(fp))
				{
				fscanf(fp,"%s",arr);
					length=strlen(arr);
					for(i=0;i<length;i++)
					arr[i]=tolower(arr[i]);
				if(!feof(fp))
				insert_trie(root,arr);
				}
						display(root);
				fclose(fp);
			}
		}
	dealloc(root);
return 0;
}
