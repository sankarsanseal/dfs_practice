/*

Employee Record Base

*/
#include<stdio.h>
#include<stdlib.h>


typedef struct employee_rec
	{
	int emp_no;
	char emp_name[40];
	double emp_sal;
	char emp_add[40];
	char emp_mobile[12];

	} emp_rec; 

long record_search(FILE * fp, int emp_no)
{
 emp_rec ser_emp;
 fseek(fp,0,SEEK_SET);
 	while(!feof(fp))
	{
		fread(&ser_emp,sizeof(emp_rec),1,fp);
		if(ser_emp.emp_no==emp_no)
			return ftell(fp)-sizeof(emp_rec);


	}
	return -1;

}
void record_insert(FILE * fp,FILE * eno)
{
 emp_rec newemp;
 int new_emp_no=0;

 fread(&new_emp_no,sizeof(int),1,eno);
 new_emp_no++;
 fseek(fp,0,2);
printf("New Employee number:%d\n",new_emp_no);
	newemp.emp_no=new_emp_no;
	printf("Enter the name of the employee:");
	getchar();
	fgets(newemp.emp_name,sizeof(newemp.emp_name),stdin);
	printf("Enter the salary of the employee:");
	scanf("%lf",&(newemp.emp_sal));
	printf("Enter the address of the employee:");
	getchar();
	scanf("%[^\n]s",newemp.emp_add);
	printf("Enter the mobile no of the employee:");
	getchar();
	scanf("%[^\n]s",newemp.emp_mobile);
fwrite(&newemp,sizeof(emp_rec),1,fp);
fseek(eno,0,0);
fwrite(&new_emp_no,sizeof(int),1,eno);
fseek(eno,0,0);

}


void record_delete(FILE * fp, FILE * delemp)
{
	emp_rec del_emp;
	int emp_no;
	long pos;
	printf("Enter the employee number for deletion:");
	scanf("%d",&emp_no);
	pos=record_search(fp,emp_no);
	if(pos!=-1)
	{
	fseek(fp,pos,SEEK_SET);
	del_emp.emp_no=-1;
	fwrite(&del_emp,sizeof(emp_rec),1,fp);
	fseek(delemp,0,SEEK_END);
	fwrite(&emp_no,sizeof(int),1,delemp);
	fwrite(&pos,sizeof(long),1,delemp);
	}

}

void record_update(FILE * fp)
{
	emp_rec upd_emp;
	int emp_no,c=0;
	long pos;
	

	printf("Enter the employee no for update:");
	scanf("%d",&emp_no);
	pos=record_search(fp,emp_no);
	if(pos !=-1)
	{
	fseek(fp,pos,SEEK_SET);
	fread(&upd_emp,sizeof(emp_rec),1,fp);
	printf("\t\t\tDetails of Employee No: %d\n",upd_emp.emp_no);
	printf("\tEmployee Name:%s\n",upd_emp.emp_name);
	printf("\tEmployee Salary:%lf",upd_emp.emp_sal);
	printf("\tEmployee Address:%s\n",upd_emp.emp_add);
	printf("\tEmployee Mobile:%s\n",upd_emp.emp_mobile);
    
    	printf("Do you want to update Name?\n1. For Yes \n2. For No\n:");
	scanf("%d",&c);
	getchar();
	if(c==1)
		scanf("%[^\n]s",upd_emp.emp_name);
    	printf("Do you want to update Salary?\n1. For Yes \n2. For No\n:");
	scanf("%d",&c);
	getchar();
	if(c==1)
		scanf("%lf",&upd_emp.emp_sal);
    	printf("Do you want to update Address?\n1. For Yes \n2. For No\n:");
	scanf("%d",&c);
	getchar();
	if(c==1)
		scanf("%[^\n]s",upd_emp.emp_add);
    	printf("Do you want to update Mobile?\n1. For Yes \n2. For No\n:");
	scanf("%d",&c);
	getchar();
	if(c==1)
		scanf("%[^\n]s",upd_emp.emp_mobile);

	fseek(fp,-sizeof(emp_rec),SEEK_CUR);
	fwrite(&upd_emp,sizeof(emp_rec),1,fp);


	}

}

void menu()
{
 emp_rec ser_emp;
 int c=0,emp_no;
 long pos;
 FILE * fp,* eno,* delemp;
 if((fp=fopen("emp.dat","rb+"))==NULL)
 	{
	printf("Error 1: Problem with main file opening.\n");
	exit(ferror(fp));
	}
if((eno=fopen("empno.dat","rb+"))==NULL)
	{
	printf("Error 2: Problem with employee no file.\n");
	exit(ferror(fp));
	}
if((delemp=fopen("delemp.dat","rb+"))==NULL)
	{
	printf("Error 3: Problem with deleted employee file.\n");
	delemp=fopen("delemp.dat","wb+");
	}


	

 while(c!=6)
 	{
	printf("\t\t\t\t Menu for Employee Record Base\n");
	printf("\t\t\t1.Employee Record Insertion\n");
	printf("\t\t\t2.Employee Record Search\n");
	printf("\t\t\t3.Employee Record Update\n");
	printf("\t\t\t4.Employee Record Delete\n");
	printf("\t\t\t5.Display All Employees\n");
	printf("\t\t\t6.Exit the program.\n");

	printf("\t\t\t\t Enter your choice:");
	scanf("%d",&c);
		switch(c)
		{
			case 1:
				record_insert(fp,eno);
				break;
			case 2:
				printf("Enter the employee no to search:");
				scanf("%d",&emp_no);
				if((pos=record_search(fp,emp_no))==-1)
				   printf("Employee does not exist.\n");
				else
				{
				   printf("Employee exists.\n");
				   fseek(fp,pos,SEEK_SET);
				   fread(&ser_emp,sizeof(emp_rec),1,fp);
	printf("\t\t\tDetails of Employee No: %d\n",ser_emp.emp_no);
	printf("\tEmployee Name:%s\n",ser_emp.emp_name);
	printf("\tEmployee Salary:%lf",ser_emp.emp_sal);
	printf("\tEmployee Address:%s\n",ser_emp.emp_add);
	printf("\tEmployee Mobile:%s\n",ser_emp.emp_mobile);
				}
				break;
			case 3:
				record_update(fp);
				break;
			case 4:
				record_delete(fp,delemp);
				break;
			case 5:
				fseek(fp,0,SEEK_END);
				pos=ftell(fp);
				fseek(fp,0,SEEK_SET);
				while((pos!=ftell(fp))&&(!feof(fp)))
				{
				fread(&ser_emp,sizeof(emp_rec),1,fp);
				if(ser_emp.emp_no!=-1)
				{
	printf("\t\t\tDetails of Employee No: %d\n",ser_emp.emp_no);
	printf("\tEmployee Name:%s\n",ser_emp.emp_name);
	printf("\tEmployee Salary:%lf",ser_emp.emp_sal);
	printf("\tEmployee Address:%s\n",ser_emp.emp_add);
	printf("\tEmployee Mobile:%s\n",ser_emp.emp_mobile);
	printf("\n\n");		}	

				}
				break;
			case 6:
				printf("Exiting...and closing the files\n");
				fclose(fp);
				fclose(eno);
				fclose(delemp);
				break;
		}


	}

}

int main()
{
menu();
return 0;
}
