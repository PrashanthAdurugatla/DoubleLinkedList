#include<stdio.h>
#include<malloc.h>

typedef struct Node
{
	int i;
	struct Node *prev;
	struct Node *next;
}node;


node * insert(node *head, node*tail, int key);
void display(node *head);
void display_reverse(node *head, node *tail);
node * removee(node *head, node *tail, int key);
void search(node *head, int key);
node * append(node *head, node *tail, int key);
void clear(node *head);

void menu()
{
	printf("\n1. To Insert a Node ");
	printf("\n2. To Display a list ");
	printf("\n3. To Display a list in Reverse order ");
	printf("\n4. To Remove a Node from a list ");
	printf("\n5. To search a Node ");
	printf("\n6. To Append a Node ");
	printf("\n7. To Clear a List ");
	printf("\n-1. To Exit ");
}

int main()
{
	int value, key;
	node *head, *tail=NULL;
	
	menu();
	
	
	
	while(1)
	{
		printf("\n\nEnter a value to perform Operation: ");
		scanf("%d",&value);
	
		if(value==-1)
			break;
			
		switch(value)
		{
			case 0:
				printf("\nError");
				break;
				
			case 1:
				printf("\nEnter a Key to insert: ");
				scanf("%d",&key);
				insert(head, tail, key);
				break;
				
			case 2:
				display(head);
				break;
				
			case 3:
				display_reverse(head, tail);
				break;
				
			
			case 4:
				printf("\nEnter a Key to Remove: ");
				scanf("%d",&key);
				removee(head, tail, key);
				break;
				
				
			case 5:
				printf("\nEnter a Key to be Searched: ");
				scanf("%d",&key);
				printf("\nShowing the results for the Operation: ");
				search(head,key);
				break;
				
			case 6:
				printf("\nEnter a Key to insert: ");
				scanf("%d",&key);
				append(head, tail, key);
				break;
				
			case 7:
				clear(head);
				break;
				
		}
	}
}
 
 
node * insert(node *head, node*tail, int key)
{
	
	node *a = (node *)malloc(sizeof(node));
	a->i=key;
	a->prev=NULL;
	a->next=NULL;
	
	if(!head)
		head=tail=a;
		
	else
	{
		node *p=head;
		node *q=NULL;
		
		while(p!=NULL&&key>p->i)
		{
			q=p;
			p=p->next;
		}
		
		if(q==NULL)
			head=a;
		
		else
			q->next=a;
	
		if(p==NULL)
			tail=a;
	
		else
			p->prev=a;
		
		a->prev=q;
		a->next=p;
		
	}	
	return head;
}

void display(node *head)
{
	if(!head)
		printf("\n List is Empty");
		
	else
	{
		node *a=head;
		while(a)
		{
			printf("%d==>",a->i);
			a=a->next;
		}
	
	}
}

void display_reverse(node *head, node *tail)
{
	
	if(!head)
		printf("List is Empty");
		
	else
	{	
		node *a = tail;
		while(a)
		{
			printf("%d==>", a->i);
			a=a->prev;		
		}
	}
}

node * removee(node *head, node *tail, int key)
{
	node *p = head;
	node *q = NULL;
	if(!p)
		printf("Operation can not be performed.");
		
	else if(p)
	{
		while(p&&p->i!=key)
		{
			q=p;
			p=p->next;
		}
		
		
		if(!q)
			head=p->next;
	
		else
			q->next=p->next;
	
		if(!p->next)
			tail=q;
	
		else
			p->next->next=q;
		
		free(p);
		return head;		
	}
	
	else
		printf("Key Not Found");
}

void search(node *head, int key)
{
	if(!head)
		printf("\nList is Empty");
		
	else
	{
		node *a = head;
		while(a)
		{
			if(a->i=key)
			{
				printf("True");
				break;
			}
				
			a=a->next;
		}
	}
}

node * append(node *head, node *tail, int key)    // return tail or head? 
{
	
	node *a = (node *)malloc(sizeof(node));
	a->i=key;
	a->prev=NULL;
	a->next=NULL;
	
	if(!head)
		head=tail=a;
		
	else
	{
		tail->next=a;
		a->prev=tail;
		tail=a;
	}
	return head;	
	
}

void clear(node *head)
{
	if(!head)
		printf("\nList is Empty");
	
	else
	{
		while(head)
		{
		node *a = head;
		head=head->next;
		free(a);
		}
		printf("\nList is Cleared");
	}
}
