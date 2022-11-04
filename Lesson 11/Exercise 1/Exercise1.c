#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>


struct grade_node{
    char surname[20];
    double grade;
    struct grade_node* next;
};
typedef struct grade_node GRADE_NODE;
typedef GRADE_NODE *GRADE_NODE_PTR;

void free_link(struct grade_node * p)
{
	GRADE_NODE* temp = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
	while (p->next)
	{
		temp = p->next;
		p->next = p->next->next;
		free(temp);
	}
}

int main(void)
{
	// create the head pointer
    GRADE_NODE* start = NULL;
    start = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE_PTR));
	
	// create the head node
	GRADE_NODE* head_node = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
	strcpy(head_node->surname, "Adams");
	head_node->grade = 85.0;
	head_node->next = NULL;
	start->next = head_node;

	GRADE_NODE* second_node = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
	strcpy(second_node->surname, "Pritchard");
	second_node->grade = 77.5;
	second_node->next = NULL;
	head_node->next = second_node;

	// insert into the middle of first node and third node
	GRADE_NODE* third_node = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
	strcpy(third_node->surname, "Smith");
	third_node->grade = 92.5;
	third_node->next = second_node;
	head_node->next = third_node;
	
	GRADE_NODE* temp = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
	temp = start->next;
	while (temp != NULL) {
		printf("surname= %s, grade= %.1f\n", temp->surname, temp->grade);
		temp = temp->next;
	}
	free_link(start);

	
	return 0;
}
