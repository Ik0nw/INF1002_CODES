#include <stdio.h>
#include <malloc.h>

// create a struct called Link
typedef struct Link {
	char elem;
	struct Link* next;
}Link;

Link* initLink() {
	int i;
  // Create head pointer
	Link* head = (Link*)malloc(sizeof(struct Link));
  
  // Create head node
	Link* p = head;
	p->elem = 0;
	p->next = NULL;
  
  //point the head pointer to the head note
	head = p;
	
	for (int i = 0; i < 3; i++)
	{
    // create a node a
		Link* a = (Link*)malloc(sizeof(struct Link));
    // give value i to the element
		a->elem = i;
		a->next = NULL;
    // we set the current node point to the new node
		p->next = a;
    // Get the new node address to p.
		p = p->next;
	}
	
}

int main(void)
{
	
	return 0;
}
