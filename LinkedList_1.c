#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int info;
	struct node *link;
};
struct node *create_linked_list(struct node *start);
void display_linked_list(struct node *start);
void count_linked_list(struct node *start);
struct node *add_link_beg(struct node *start, int data);
struct node *add_link_end(struct node *start, int data);
struct node *add_link_pos(struct node *start, int pos, int data);
struct node *add_link_after(struct node *start, int data, int item);
struct node *add_link_before(struct node *start, int data, int item);
struct node *del_link_beg(struct node *start);
struct node *del_link_end(struct node *start);
struct node *del_link_pos(struct node *start, int pos);
void search_link(struct node *start, int data);


void main()
{
	int pos, data, item;
	int choice; 
	struct node *start = NULL;

	while (1)
	{
		printf("1   : Enter 1  to create the link\n");
		printf("2   : Enter 2  to display the link\n");
		printf("3   : Enter 3  to count the linked list\n");
		printf("4   : Enter 4  to add nodes begining at the link\n");
		printf("5   : Enter 5  to add node end of the link\n");
		printf("6   : Enter 6  to add node at particular position of the link\n");
		printf("7   : Enter 7  to add node after the particular positon\n");
		printf("8   : Enter 8  to add node before the particular position\n");		
		printf("9   : Enter 9 to deleter the link\n");
		printf("10   : Enter 10 to delete the link at the begining\n");
		printf("11  : Enter 11  to delete the link at the end\n");
		printf("12  : Enter 12 to search for the link\n");
		printf("13  : Enter 13 to quit the program\n");
	
	printf("\nEnter your choice :\n");
	scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				start = create_linked_list(start);
				break;
			case 2: 
				display_linked_list(start);
				break;
			case 3: 
				count_linked_list(start);
				break;
			case 4:
				printf("Enter the Element to be insert:\n");
				scanf("%d", &data);
				start = add_link_beg(start, data);
				break; 
			case 5:
		       		 printf("Enter the Element to be insert:\n");
		       		 scanf("%d", &data);
	                         start = add_link_end(start, data);
		        	break; 
			case 6:
		       		 printf("Enter the Element and the position to be insert:\n");
		       		 scanf("%d%d", &data, &pos);
		        	 start = add_link_pos(start, data, pos);
		      		  break; 
			case 7:
			        printf("Enter the Element add the position to be insert:\n");						
				scanf("%d%d", &data, &item);
				start = add_link_after(start, data, item);
				break;
			case 8 :
				printf("Enter the Element and the position to be insert:\n");
			        scanf("%d%d", &data, &item);
			        start = add_link_before(start, data, item);
				break;
			case 9 :
				start = del_link_beg(start);
				break;
			case 10 :
				start = del_link_end(start);
				break;
			case 11 :
				printf("Enter the position to delete\n");
				scanf("%d", &pos);
				start = del_link_pos(start, pos);
				break;
			case 12 :
				printf("Enter the data to be searched\n");
				scanf("%d", &data);
				search_link(start, data);
				break;
			case 13 :
				exit(1);
			default :
				printf("Enter the correct choice\n");
		}
	}
	//return 0;

}
void dispalay_linked_list(struct node *start)
{
	struct node *temp = start;
	while (temp->link != NULL)
	{
		printf("%d\t", temp->info);
		temp = temp->link;
	}
	printf("\n");
}


void count_linked_list(struct node *start)
{
	struct node *temp = start;
	int count = 0;
	while(temp->link != NULL)
	{
		count ++;
	}
	printf("The  number of nodes in a linked list is: %d\n", count);
	
}


struct node *add_link_beg(struct node *start, int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof (struct node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}

struct node *add_link_end(struct node *start, int data)
{
	struct node *temp, *p;
	temp = (struct node *)malloc(sizeof (struct node));
	p = start;
	while(p->link != NULL)
	{
		p = p->link;
	}
	p->link = temp;
	temp->info = data;
	temp->link = NULL;

	return start;
}

struct node *add_link_pos(struct node *start, int data, int pos)
{
	struct node *temp, *p;
	temp = (struct node *)malloc(sizeof(struct node));
	p = start;
	for (int i=0; p->link != NULL; i++)
	{
		p = p->link;
		if(i==pos-1)
		{
			temp->link = p->link;
			temp->info = data;
			p->link = temp;
		}
	}
	return start;
}

struct node *add_link_before(struct node *start, int data, int item)
{
	struct node *temp, *p;
	if(start == NULL)
	{
		printf("List is Empty\n");
		return start;
	}
	if(start->info == item)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->link = start;
		temp->info = data;
		start = temp;
		return start;
	}
	p = start;
	while (p->link != NULL)
	{
		if(p->link->info == item)
		{
			temp = (struct node *)malloc(sizeof (struct node));
			temp->link = p->link;
			temp->info = data;
			p->link = temp;
			return start;
		}
		p=p->link;
	}
	printf("%d is not present in the list \n", item);
	return start;
}

struct node *add_link_after(struct node *start, int data, int item)
{
	struct node *temp, *p;
	if(start == NULL)
	{
		printf("List is Empty\n");
		return start;
	}
	if (item == start->info)
	{	
		temp = (struct node *)malloc(sizeof (struct node));
		start->link = temp;
		temp->info = data;
		temp->link = NULL;
		return start;
	}
	p = start;
	while (p->link != NULL)
	{
		if (p->info == item)
		{
			temp = (struct node *)malloc(sizeof (struct node));
			temp->link = p->link;
			p->link = temp;
			temp->info = data;
			return start;
		}
		p = p->link;
	}
	printf("%d is not found in the list\n", item);
	return start;
}

struct node *create_linked_list(struct node *start)
{
	struct node *temp, *p;
	int num_node, data;
	printf("Enter the number of nodes to create\n");
	scanf("%d", &num_node);
	printf("Enter the data\n");
	scanf("%d", &data);
	add_link_beg(start, data);
	for(int i=2; i<num_node; i++)
	{
		printf("Enter  the info for %d node\n", i);
		scanf("%d", &data);
		add_link_end(start, data);
	}
	return start;
}

struct node *del_link_beg(struct node *start)
{
	struct node *temp = start;
	start = temp->link;
	free(temp);
	return start;	
}

struct node *del_list_end(struct node *start)
{
	struct node *temp, *p;
	p=start;
	while (p->link != NULL)
	{
		p=p->link;
	}
	temp = start;
	while(temp->link != p);
	{
		temp = temp->link;
	}
	temp->link = NULL;
	free(p);
	return start;
}

struct node *del_link_pos(struct node *start, int pos)
{
	struct node *temp, *p;
	temp = start;
	for(int i=0; temp->link != NULL; i++)
	{
		if(i==pos-1)
		{
			p=temp;
		}
		temp = temp->link;
		p->link = temp;
		free(temp);
	}
	return start;
}

void search_link(struct node *start, int data)
{
	struct node *temp=start;
	int pos=1;
	while(temp->link != NULL)
	{
		if(temp->info == data)
		{
			printf("%d is found at %d node \n", data, pos);
		    exit(0);
		}
		temp = temp->link;
		pos++;
	}
	printf("%d is not found in the list\n", data);
	exit(0);
}
