#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct person{
char name [50];
char surname[50];
char musical_work[50];
int age;
struct person *next;
}*top;

top headp=NULL;

void swap(top, top);
void print();
void addNode(char [], char  [], char  [], int );
void deleteNode();
void Sort_Alphabetically();
void Sort_Increasingly();


int main(int argc, char const *argv[])
{
	int select_menu,age;
	char name[50],surname[50],creation[50];

	printf("\n\t****MENU****\n1- Add a Person to the Stack\n2- Pop a Person from the Stack\n3- Sort Alphabetical Order\n4- Sort Age in Increasing Order\n5- Exit menu\n\t*************\nSelect your Choise: ");
	scanf("%d",&select_menu);
	while(select_menu!=5)
	{
		if (select_menu==1)
		{
			printf("Name: ");
			scanf(" %[^\n]%*c", name); 
			//fgets( name, 20, stdin); 
			printf("Surname: ");
			scanf(" %[^\n]%*c", surname); 			
			printf("Creation: ");
			scanf(" %[^\n]%*c", creation); 			
			printf("Age: ");
			scanf("%d",&age);
			addNode(name,surname,creation,age);
			print();
		}
		else if (select_menu==2)
		{
			deleteNode();
			print();
		}
		else if (select_menu==3)
		{
			Sort_Alphabetically();
			print();
		}
		else if (select_menu==4)
		{
			Sort_Increasingly();
			print();
		}
		else 
		{
			printf("Wrong Input!!!!!\n");
		}
	printf("\n\t****MENU****\n1- Add a Person to the Stack\n2- Pop a Person from the Stack\n3- Sort Alphabetical Order\n4- Sort Age in Increasing Order\n5- Exit menu\n\t*************\nSelect your Choise: ");
	scanf("%d",&select_menu);
	}
	return 0;
}

void addNode(char aname[], char asurname [], char creation [], int aage)
{
	top node = (top)malloc(sizeof(top)*100);
	node->next = NULL;
	node->age=aage;
	strcpy(node->name,aname);
	strcpy(node->surname,asurname);
	strcpy(node->musical_work,creation);

	if (headp==NULL)		//1st element
	{
		headp=node;
		node->next = NULL;
	}
	else
	{
		node->next=headp;
		headp=node;
	}
}

void print()
{
	int i=1;
	if (headp==NULL)
	{
		printf("Stack is NULL\n");
	}
	else
	{
		top iter;
		iter=headp;
		while(iter!=NULL)
		{
			printf("--------------------\n");
			printf("%d)%s\n",i++,iter->name);
			printf("%s\n",iter->surname);
			printf("%s\n",iter->musical_work);
			printf("%d\n",iter->age);
			iter=iter->next;
		}
		printf("--------------------\n");
	}
}

void deleteNode()
{
	if (headp==NULL)
	{
		printf("Stack is empty");
	}
	else 
	{
		top temp_node;
		temp_node=headp;
		headp=headp->next;		//pop here
		free(temp_node);		// delete in memory
	}
}
// in sorting i used bubble sort beacuse its simple and easy to application
void Sort_Alphabetically()
{
	int i,j,k,swapped=0;
	top current_p,previous_p=NULL;

	while(swapped!=1)			//untill all elements swapped "while" continuous
	{
		swapped=1;
		current_p=headp;
		previous_p=NULL;
		while(current_p!=NULL)
		{
			if (previous_p!=NULL)
			{
				if (0>strcmp(current_p->name,previous_p->name))
				{
					swap(current_p,previous_p);
					swapped=0;
				}
			}
			previous_p=current_p;
			current_p=current_p->next;
		}
	}
}
void Sort_Increasingly()
{
	int i,j,k,swapped=0;
	top current_p, previous_p=NULL;
	while(swapped!=1)
	{
		swapped=1;
		current_p=headp;
		previous_p=NULL;
		while(current_p!=NULL)
		{
			if (previous_p!=NULL)
			{
				if (current_p->age<previous_p->age)
				{
					swap(current_p,previous_p);
					swapped=0;
				}
			}
			previous_p=current_p;
			current_p=current_p->next;
		}
	}
}

void swap(top previous, top current)
{
	top temp_node=(top)malloc(sizeof(top)*100);
	temp_node->age=previous->age;
	strcpy(temp_node->name,previous->name);
	strcpy(temp_node->surname,previous->surname);
	strcpy(temp_node->musical_work,previous->musical_work);

	previous->age=current->age;
	strcpy(previous->name,current->name);
	strcpy(previous->surname,current->surname);
	strcpy(previous->musical_work,current->musical_work);

	current->age=temp_node->age;
	strcpy(current->name,temp_node->name);
	strcpy(current->surname,temp_node->surname);
	strcpy(current->musical_work,temp_node->musical_work);

	free(temp_node);
}