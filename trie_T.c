#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define CHARARR 80
#define CHARSET 44
#define DICT_PATH "/usr/share/dict/words"

typedef struct trie_T
{
		unsigned char **str;
		struct trie_T *next[CHARSET];

} * TRIENODE;

TRIENODE make_node()
{
	TRIENODE temp;
	int i;
	if((temp=(TRIENODE)malloc(sizeof(struct trie_T)))==NULL)
		printf("problem with node creation.\n");
	temp->str=(unsigned char **)malloc(sizeof(unsigned char *)*CHARSET);
	for(i=0;i<CHARSET;i++)
		{
		temp->str[i]=NULL;
		temp->next[i]=NULL;
		}
	
return temp;
}

void dealloc(TRIENODE root)
{
int i;

	if(root)
	{
		for(i=0;i<CHARSET;i++)
		{
			if(root->str[i])
				free(root->str[i]);
				
			if(root->next[i])
				dealloc(root->next[i]);
		}
		free(root->str);

		free(root);
	}

}

void cleanup(TRIENODE root)
{
	int empty=1,i;
	for(i=0;i<CHARSET;i++)
	{
		if(root->next[i])
			continue;
		else
		{
		empty=0;
		break;
		}

	}

	if(empty)
	{
	printf("cleaned.\n");
		if(root->str)
		free(root->str);
		for(i=0;i<CHARSET;i++)
		{
		if(root->next[i])
			cleanup(root->next[i]);
		}
	}


}

int ustrlen(unsigned char * word)
{
	int i=0;

	while(*word!='\0')
	{
	i++;
	word++;
	}


return i;
}
unsigned char * copy_str(unsigned char * word)
{
	int length=ustrlen(word);
	
	unsigned char * temp, * p;
	temp=(unsigned char *) malloc(sizeof(unsigned char)*length);
	p=temp;
	while((*p++=*word++));
	return temp;

}
void ustrcpy(unsigned char * dest, unsigned char * src)
{
	while((*dest++=*src++));

}
int switch_char(unsigned char c)
{
	int i;
	switch(c)
		{

		case '\0':
			i=0;
			break;
		default:
			i=c-96;
			break;
		case 39:
			i=27;
			break;
		case '-':
			i=28;
			break;
		case 133:
			i=29;
			break;
		case 169:
			i=30;
			break;
		case 182:
			i=31;
			break;
		case 195:
			i=32;
			break;
		case '.':
			i=33;
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			i=(c-'0')+34;
			break;
		}


return i;
}

void insert_word(TRIENODE root,unsigned char *word)
{
	TRIENODE t=root;
	unsigned char *temp=word,*temp1 ;
	int length,i,j,k;

	length=ustrlen(word);

	j=0;

	while(*temp!='\0')
	{
		i=switch_char(*temp);
		if(t->next[i])
		{
			t->str[i]=NULL;

			t=t->next[i];
		}
		else
			break;

		j++;
		temp++;
	}


	if((t->next[i]==NULL) && (t->str[i]==NULL))
		{	
		t->str[i]=copy_str(word);
		
		}
	else if((t->next[i]==NULL)&&(t->str[i]))
		{

				k=i;
				temp1=t->str[i];
				t->str[i]=NULL;
			while(*temp==temp1[j])
				{
				temp++;
				j++;
				t->next[k]=make_node();
					if(t->str[k])
					{
				//	free(t->str[k]);
					t->str[k]=NULL;
					}
				t=t->next[k];
				k=switch_char(*temp);
				}

			if((*temp!=temp1[j])&&(*temp!='\0'))
				{
					t->str[k]=copy_str(word);


					if(temp1[j]=='\0')
						k=0;
					else
					k=switch_char(temp1[j]);

					t->str[k]=temp1;
					//free(temp1);
				}
			else
			if((*temp!=temp1[j])&&(*temp=='\0'))
				{
					t->str[0]=copy_str(word);
					k=switch_char(temp1[j]);
					t->str[k]=temp1;
					//free(temp1);
					//*(temp2)=NULL;
				}

		}//else if(t->next==NULL) && t->str[i]


}

void display(TRIENODE root)
{
	int i;
	for(i=0;i<CHARSET;i++)
	{
		if((root->next[i]==NULL)&&(root->str[i]))
			printf("%s\n",root->str[i]);
		else
		if((root->next[i]))
			display(root->next[i]);
		else if((root->next[i]==NULL)&&(root->str[i]==NULL))
			continue;
			
	}
}

unsigned char * search_str(TRIENODE root,unsigned char * arr)
{
	int i,j,k,length;
	TRIENODE temp=root;
	unsigned char * temp1;

	length=ustrlen(arr);
	for(i=0,j=0;i<length;i++,j++)
	{
			arr[i]=tolower(arr[i]);
			k=switch_char(arr[i]);
			if(temp->next[k])
				temp=temp->next[k];
			else
				break;
		//	printf("%c %d\n",arr[i],k); 

	}
	//printf("i : %d j : %d k : %d\n ",i,j,k);

		if((i==length)&&(arr[i]=='\0'))
		{
	//		printf("> %c %d %s\n",arr[i],k, temp->str[0]); 
			if(
			(temp->str[0])&&((temp->str[0][j])=='\0')
			&&(temp->next[0]==NULL)	)
				return temp->str[0];
			else
				return NULL;
		}
		//display(temp);
		else
		if((temp->next[k]==NULL)&&(temp->str[k]))
		{
			temp1=temp->str[k];
			//printf("%si\n",temp1);


			for(arr[i]=tolower(arr[i]);
				(arr[i]==temp1[j])
				&&i<length;i++,j++,arr[i]=tolower(arr[i]));

			if((i==length)&&(arr[i]=='\0')&&temp1[j]!='\0')
				return NULL;
			else
			if((i==length)&&(arr[i]=='\0')
				&&(temp1[j]=='\0'))
				return temp1;
			else
				return NULL;
		}
		else
				return NULL;
	

	

}

void suggestion(TRIENODE root, unsigned char * word)
{
	unsigned char *temp;
	if((temp=search_str(root,word)))
		printf("%s\n",temp);
	
}


void search_menu(TRIENODE root)
{
	unsigned char arr[CHARARR],arr2[CHARSET],*found=NULL,c;
	int length,i,j;
	long unsigned int start,end;

	printf("Enter the word to be search:");
	scanf("%s",arr);
	length=ustrlen(arr);
	ustrcpy(arr2,arr);

	start=clock();
	found=search_str(root,arr);
	end=clock();

	if(found)
	{
		printf("Given word \"%s\" is  in dictionary.\n",
			arr2);
		printf("Above successful search done with %lu CPU cycles.\n"
		,end-start);
	}
	else
	{
		
		printf("Given word \"%s\" is not in dictionary\n",
			arr2);
	printf("Above unsuccessful search done with %lu CPU cycles.\n"
		,end-start);

		printf("Suggestion deleting single character:\n");
		start=clock();
		for(i=length-1;i>0;i--)
			{
			for(j=i;j<length;j++)
				arr[j]=arr[j+1];
			suggestion(root,arr);
			ustrcpy(arr,arr2);
			}
		end=clock();
		printf("above list searched with %lu CPU cycles\n", 
		end-start);

		printf("Sugesstion with added single character:\n");
		start=clock();
			for(i=length;i>=0;i--)
			{
				arr[i+1]=arr[i];
				for(j=0;j<26;j++)
				{
				 arr[i]=j+97;
				 suggestion(root,arr);
				}
			}
		end=clock();
		printf("above list searched with %lu CPU cycles\n", 
		end-start);
			ustrcpy(arr,arr2);
		printf("Suggestion with single changed character:\n");
		start=clock();
			for(i=length-1;i>=0;i--)
			{
				c=arr[i];
				for(j=0;j<26;j++)
				{
				arr[i]=j+97;

				suggestion(root,arr);
				}
				arr[i]=c;
			}
		end=clock();
		printf("above list searched with %lu CPU cycles\n", 
		end-start);
			ustrcpy(arr,arr2);
		printf("Suggestion with swapped charaters:\n");
		start=clock();
			for(i=length-1;i>0;i--)
				for(j=i-1;j>=0;j--)
				{
				c=arr[i];
				arr[i]=arr[j];
				arr[j]=c;
//				 printf("%s\n",arr);
				suggestion(root,arr);
				c=arr[i];
				arr[i]=arr[j];
				arr[j]=c;
				}	
		end=clock();
		printf("above list searched with %lu CPU cycles\n", 
		end-start);
	}
}


int main()
{

	TRIENODE root=NULL;
	FILE *dict;
	unsigned char arr[CHARARR];
	int length,i;
	long unsigned int start, end;
	if((dict=fopen(DICT_PATH,"r"))==NULL)
		printf("Problem with dictionary file.\n");
	else
		{
			start=clock();
			if(root==NULL)
			{
			//root creation of T
				root=make_node();
			}//if(root==NULL)
			while(!feof(dict))
			{
				
				//inserting words in T
					fscanf(dict,"%s",arr);
					length=ustrlen(arr);

					//printf("%d:%s\n",length,arr);
					for(i=0;i<length;i++)
					{
						
					if(islower(arr[i]))
						continue;
					else
						arr[i]=tolower(arr[i]);
						
					}

					if(!feof(dict))
					//printf("%s\n",arr);
					insert_word(root,arr);
				

			}//while(!feof)

			end=clock();
			printf("Trie T is constructed with %lu CPU clocks\n"
				,end-start);

			//display(root->next['t'-96]);
			cleanup(root);

			search_menu(root);
			

		}
	printf("Total process ends after %lu CPU clock cycles\n",clock());
	fclose(dict);
//	dealloc(root);
return 0;
}
