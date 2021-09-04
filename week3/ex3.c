#include <stdio.h>
#include <stdlib.h>


// Creating a node
struct node {
  int data;
  struct node *next;
};


void print_list(struct node *head)
{
	while (head != NULL) {
	    printf("%d ", head->data);
	    head = head->next;
	}	
};


void insert_node(struct node *head, struct node *newnode, struct node *prevnode)
{

    if (prevnode == NULL)
    {
	    printf("The given previous node cannot be NULL");    
    }
         
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
 
    new_node->data = newnode;
    new_node->next = prevnode->next;
    prevnode->next = new_node;
	
};



void delete_node(struct node *head, struct node *delnode)
{
	struct node *temp = *head, *prev;
 
 
    if (temp != NULL && temp == delnode) {
        *head = temp->next; 
        free(temp);
        return;
    }
 
    while (temp != NULL && temp != delnode) {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return;
 
    prev->next = temp->next;
 
    free(temp);
	
};

int main()
{
	printf("Working on it...");
	
	struct node* head = NULL;
	
    insert_node(&head, 2, 1);

	return 0;
}

