#include<stdio.h>
#include<stdlib.h>
void CreateLL( int Num);
void InsertAtEnd( int Num);
void InsertAtMid( int key,int Num);
void InsertAtBeg( int Num);
int DeleteAtBeg( void);
int DeleteAtEnd( void);
int LinkListSearch(int Key);
void Print(void);

struct Node
{
	int Data;
	struct Node * Next;
};
typedef struct Node Node;
Node * Head;

void CreateLL( int Num)
{
	Node * temp;
	if(Head==NULL)
	{
		Head=(Node *)malloc(sizeof(Node));
		Head->Data=Num;
		Head->Next=NULL;
	}
	else
	{
		temp=Head;
		while(temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=(Node *)malloc(sizeof(Node));
		
		temp->Next->Next=NULL;
		temp->Next->Data=Num;
		
	}
}
void InsertAtEnd( int Num)
{
	Node * temp;
	if(Head==NULL)
	{
		Head=(Node *)malloc(sizeof(Node));
		Head->Data=Num;
		Head->Next=NULL;
	}
	else
	{
		temp=Head;
		while(temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=(Node *)malloc(sizeof(Node));
		
		temp->Next->Next=NULL;
		temp->Next->Data=Num;
		
	}
}
void InsertAtBeg( int Num)
{
		Node * temp;
	if(Head==NULL)
	{
		Head=(Node *)malloc(sizeof(Node));
		Head->Data=Num;
		Head->Next=NULL;
	}
	else
	{
		temp=Head;
		Head=(Node *)malloc(sizeof(Node));
		Head->Data=Num;
		Head->Next=temp;
	}
}
int DeleteAtBeg( void)
{
	Node * temp;int num;
	if(Head==NULL)
	{
		return 999;
	}
	else
	{
		temp=Head;
		Head=temp->Next;
		num=temp->Data;
		free(temp);
		return num;
	}
	
}
int DeleteAtEnd( void)
{
	Node * temp,*temp1;
	int num;
	if(Head==NULL)
	{
		return 999; 
	}
	else
	{
		if(Head->Next==NULL)
		{
		   num=Head->Data;
		   free(Head);
		   Head=NULL;
		   return num;	
		}
		else
		{
			temp=Head;
			while(temp->Next!=NULL)
			{    temp1=temp;
				temp=temp->Next;
			}
			num=temp->Data;
			temp1->Next=NULL;
			free(temp);
			return num;
		}
	}
}
void Print(void)
{
	Node * temp;
	temp=Head;
	if(Head==NULL)
	printf("\nLink List is Empty");
	else
	{
		while(temp->Next!=NULL)
		{
			printf("%d->",temp->Data);
			temp=temp->Next;
		}
		printf("%d->NULL",temp->Data);
		
}
}
int LinkListSearch(int Key)
{
	Node * temp;
	int count=1;
	if(Head==NULL)
	{
		return 999; 
	}
	else
	{ temp=Head;
		while(temp->Data!=Key)
		{
			count++;
			temp=temp->Next;
			if(temp==NULL)
			return 999;
			
		}
		if(temp->Data==Key)
			 return count;
	}
		
}	
void InsertAtMid( int Key,int Num)
{
	Node *temp,*temp1;
	if(Head==NULL)
	{
		printf("Link List Is Empty") ;
		
	}
	else
	{
		temp=Head;
		while(temp->Data!=Key)
		{
		  	temp=temp->Next;
			if(temp==NULL)
			return ;	
		}
		temp1=temp->Next;
		temp->Next=(Node *)malloc(sizeof(Node));
		temp->Next->Data=Num;
		temp->Next->Next=temp1;
	}
	
}	

void main(void)
{
	
	Head=NULL;
	int Choice,Num,Key;
	while(1)
	{
		printf("\nPragram to Illustrate Concept of Link List");
		printf("\n1. Create Link List");
		printf("\n2. Insert At Beg");
		printf("\n3. Insert At Mid");
		printf("\n4. Insert At End");
		printf("\n5. Delete At Beg");
		printf("\n6. Delete At End");
		printf("\n7. Search Element");
		printf("\n8. Print");
		printf("\n9. Exit");
		printf("\nEnter Your Choice\n");
		scanf("\n %d",&Choice);
		switch(Choice)
		{
			case 1: 
				  printf("\nEnter Number\n");
				   scanf("%d",&Num);
			      CreateLL(Num);
			      break;
		   case 3: 
				  printf("\nEnter Key and Number \n");
				  scanf("%d %d",&Key,&Num);
			      InsertAtMid(Key,Num);
			      break;
		   case 2: 
				  printf("\nEnter Number\n");
				  scanf("%d",&Num);
			      InsertAtBeg(Num);
			      break;
		   case 4: 
				  printf("\nEnter Number\n");
				  scanf("%d",&Num);
			      InsertAtEnd(Num);
			      break;
		    case 5:
	       	       Num=DeleteAtBeg();
	       	       if(Num==999)
	       	       printf("\nLink List is Empty");
	       	       else
	       	        printf("\nNode %d Deleted from Link List ",Num);
	       	       break;
	       case 6:
	       	       Num=DeleteAtEnd();
	       	       if(Num==999)
	       	       printf("\nLink List is Empty");
	       	       else
	       	        printf("\nNode %d Deleted from Link List ",Num);
	       	       break;
	       	case 7:
			        printf("\nEnter Number\n");
				    scanf("%d",&Num);
				   Key=LinkListSearch(Num);
	       	       if(Key==999)
	       	       printf("\nLink List is Empty");
	       	       else
	       	        printf("\n Node %d Found at %d Position Link List ",Num,Key);
	       	       break;
			 case 8:
	       	       Print();
	       	       break;
	         case 9:
	       	       exit(0);
		}
	}
    
}


