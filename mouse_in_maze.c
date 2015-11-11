
#include<stdio.h>
#include<stdlib.h>

typedef struct maze
{
	int nx[4];
	int ny[4];
	int visited;
} MAZE;
typedef struct stk
{
	int x,y;
	int index;
	struct stk * next;
} * STK;


int dfs(MAZE  **maze,int s,int t,int p, int q)
{

	STK top=NULL,temp,f;
	int i;
	int tempx,tempy;

	top=(STK)malloc(sizeof(struct stk));
	top->next=NULL;
	top->x=s;top->y=t;
	top->index=0;
	(*(*(maze+top->y)+top->x)).visited=1;

	while(top)
	{
		for(i=top->index;i<4;)
			{
			  if(
                	((tempx=(*(*(maze+top->y)+top->x)).nx[i])!=-1)&&
			((tempy=(*(*(maze+top->y)+top->x)).ny[i])!=-1)
				)
				{
					if(
					(*(*(maze+tempy)+tempx)).visited==0)
					{
					(*(*(maze+tempy)+tempx)).visited=1;
					//(top->index)++;
					top->index=i+1;
					temp=
					(STK)malloc(sizeof(struct stk));
					temp->x=tempx;
					temp->y=tempy;
					temp->index=0;
					temp->next=top;
					top=temp;
					i=top->index;
					}//if(tempx,tempy visited
					else
						i++;
				}//if(tempx!=-1)
				else
					i++;
			}//for(i=top->index

			if((top->x==p)&&(top->y==q))
				{
				 while(top)
				 	{
					f=top;
					top=top->next;
					free(f);
					}
				return 1;
				}
			else
				{
				f=top;
				top=top->next;
				free(f);
				}


			
	}//while(top)

return 0;

}
int bfs(MAZE **maze,int s, int t, int p, int q)
{
	STK front=NULL, rear=NULL,temp,f;
	int i,tempx,tempy;

	front=rear=(STK)malloc(sizeof(struct stk));
	rear->x=s;rear->y=t;
	rear->next=NULL;

	while(front)
	{
	for(i=0;i<4;i++)
		{
			if(
			((tempx=(*(*(maze+front->y)+front->x)).nx[i])!=-1)
			&&
			((tempy=(*(*(maze+front->y)+front->x)).ny[i])!=-1)
			)
			{
				if(
				(*(*(maze+tempy)+tempx)).visited==0
				)
				{
				    temp=(STK)malloc(sizeof(struct stk));
				    temp->x=tempx;
				    temp->y=tempy;
				    temp->next=rear->next;
				    rear->next=temp;
				    rear=rear->next;
				    if((rear->x==p)&&(rear->y==q))
					break;	
				}//if visited
			}//if tempx!=-1
		}//for loop for adjacent nodes
				(*(*(maze+front->y)+front->x)).visited=1;

		if((rear->x==p)&&(rear->y==q))
		{
			while(front)
			{
			f=front;
			front=front->next;
			free(f);
			}
			
			return 1;
		}
		else
		{
			f=front;
			front=front->next;
			free(f);
		}
	}//while(front)

	return 0;
}

void open_door(MAZE  **maze,int x1,int y1,int x2,int y2)
{
	int i;
	for(i=0;i<4;i++)
		{

			if(
				((*(*(maze+y1)+x1)).nx[i]==x2)&&
				((*(*(maze+y1)+x1)).ny[i]==y2)
				)
				break;
			else if((*(*(maze+y1)+x1)).nx[i]==-1)
			{
			(*(*(maze+y1)+x1)).nx[i]=x2;
			(*(*(maze+y1)+x1)).ny[i]=y2;
				break;
			}
		}
}

void initialize_maze()
{

}

void maze_runner(FILE * itf)
{
	int m,n,s,t,p,q,door,i,j,k,x1,y1,x2,y2;
//matrix of maze
	 MAZE ** ratmat;

	
	fscanf(itf,"%d%d",&m,&n);	
	fscanf(itf,"%d%d",&s,&t);
	fscanf(itf,"%d%d",&p,&q);
//row pointers for each maze row.
	ratmat=(MAZE **)malloc(sizeof(MAZE *)*m);
//assigning columns to each row pointer
	for(i=0;i<m;i++)
		*(ratmat+i)=(MAZE *)malloc(sizeof(MAZE)*n);

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			for(k=0;k<4;k++)
			(*(*(ratmat+i)+j)).nx[k]=
			(*(*(ratmat+i)+j)).ny[k]=-1;

	fscanf(itf,"%d",&door);

		for(i=0;i<door;i++)
		{
		fscanf(itf,"%d%d%d%d",&x1,&y1,&x2,&y2);
		open_door(ratmat,x1,y1,x2,y2);
		open_door(ratmat,x2,y2,x1,y1);

		}//for door input



	if(dfs(ratmat,s,t,p,q))
		printf("Path exists using DFS.\n");
	else
		printf("Path does not exist using DFS.\n");

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			(*(*(ratmat+i)+j)).visited=0;
	if(bfs(ratmat,s,t,p,q))
		printf("Path exists using BFS.\n");
	else
		printf("Path does not exist using BFS.\n");
	
	for(i=0;i<m;i++)
			if(*(ratmat+i))
			{
			free((*(ratmat+i)));
			}
	if(ratmat)
	free(ratmat);
}

int main(int argc , char * argv[])
{
	int turn=-1,i;
	FILE * itf=NULL;//input test file
	if(argc!=2)
	{
		printf("usage: %s <test input file>",argv[0]);
	}
	else
	{
		itf=fopen(argv[1],"r");
		fscanf(itf,"%d",&turn);
		for(i=0;i<turn;i++)
		{
		printf("Test Case %d\n",i+1);
		maze_runner(itf);
		}
	}

	if(itf)
		fclose(itf);

return 0;
}
