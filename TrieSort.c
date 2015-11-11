#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 26

struct node{
	struct node* childNodes[SIZE];
	short int isLeafNode;
};

typedef struct node* trieNode;

trieNode root;

trieNode makeTrie(){
	int i;
	trieNode tn=(trieNode)malloc(sizeof(struct node));
	if(tn==NULL){
		printf("\n No space");
		exit(1);
	}
	tn->isLeafNode=0;
	for(i=0;i<SIZE;i++){
		tn->childNodes[i]=NULL;
	}
	return tn;
}

trieNode insertTrie(trieNode root, char str[]){
	int i=0,j;
	char s;
	if(root==NULL){
		root=makeTrie();
	}
	trieNode temp=root;
	while(str[i]!='\0'){
		s=str[i];
		//if(s>='a' && s<='z'){
			j=((int)s - (int)'a');
		//}
		if(temp->childNodes[j]==NULL){
			//if no node exists at the index, create a new node
			temp->childNodes[j] = makeTrie();
		}
		temp=temp->childNodes[j]; //go one level deeper
		i++;
	}
	temp->isLeafNode=1;
	return root;
}

void printWordsLexicographically(trieNode tnode,char str[],int n,FILE *output){
	int i;
	for(i=0;i<SIZE;i++){
		if(tnode->childNodes[i]!=NULL){
			str[n]=(97+i);
			str[n+1]='\0';
			if(((tnode->childNodes[i])->isLeafNode)==1){
				//print word
				//printf("\n %s",str);
				fprintf(output,"%s\n",str);
			}
			printWordsLexicographically(tnode->childNodes[i],str,n+1,output);
		}
	}	
}

int main(int argc,char *argv[]){
	FILE *input,*output;
	char temp[100],word[100];
	int i,maxWordLength=0,j,len;
	if(argc!=2){
		printf("Error! One argument(filename) expected.\n");
		exit(1);
	}
	if(!(input=fopen(argv[1],"r"))){	
		printf("\n File cannot be found\n\n");
	}
	else{
		printf("\n Inserting words...");
		while(fscanf(input,"%s",temp)!=EOF){
			len=strlen(temp);
			for(i = 0; i<len; i++){
				j=0;
				if((temp[i]>='a' && temp[i]<='z') || (temp[i]>='A' && temp[i]<='Z')){
					word[j++] = tolower(temp[i]);
				}
			}
			word[j]='\0';
			if(strlen(word)>maxWordLength){
				maxWordLength=strlen(word)+1;
			}
			root=insertTrie(root,word);
			printf("\n Inserting word:%s",word);
		}
		fclose(input);
		printf("\n Insertion over.");
	}
	char str[maxWordLength+1];
	str[0]='\0';
	if(!(output=fopen("OutputFile.txt","a+"))){
		printf("\n Output file cannot be opened");
		exit(1);
	}
	if(root!=NULL){
		printf("\n\n Printing words lexicographically:\n");
		printWordsLexicographically(root,str,0,output);
	}else{
		printf("\n Trie is empty.");
	}
	fclose(output);
	return 0;
}
