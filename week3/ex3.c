# include <stdio.h>
# include <stdlib.h>
# include <time.h>

struct node
{
	int val;
	struct node *next, *prev;
};

int n;
struct node *head = NULL;

void print_list( struct node *node )
{
	if( node != NULL )
	{
		printf("%d ", node->val);
		print_list(node->next);
	}
}

void insert_node( struct node *node, int newVal )
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->val = newVal;
	newNode->next = NULL;
	newNode->prev = node;
	node->next = newNode;
	n++;
}

void delete_node( struct node *node )
{
	if( node->next != NULL && node->prev != NULL )
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	else if( node->next != NULL )
	{
		node->next->prev = NULL;
		head = node->next;
	}
	else if( node->prev != NULL )
	{
		node->prev->next = NULL;
	}
	else{
		head = NULL;
	}
	free(node);
	n--;
}

int main()
{
	srand(time(0));
	printf("\nPlease enter the size of LinkedList: ");
	int size;
	scanf("%d", &size);
	struct node *cur = NULL;
	int i;
	for( i = 0; i < size; i ++ )
	{
		int val = rand() % 1001;
		if( i )
		{
			insert_node(cur, val);
			cur = cur->next;
		}
		else
		{
			head = (struct node*) malloc(sizeof(struct node));
			head->prev = NULL;
			head->next = NULL;
			head->val = val;
			cur = head;
		}
	}
	printf("Initial array: "); 
	print_list(head);
	printf("\n\n");

	while( n )
	{
		int index = rand() % n;
		cur = head;
		int i;
		for(i = 0; i < index; i ++ )
		{
			cur = cur->next;
		}
		delete_node(cur);
		printf("%d th is node deleted!\n", index);
		printf("Linked list after deleting: ");
		print_list(head);
		printf("\n\n");
	}
	return 0;
}
