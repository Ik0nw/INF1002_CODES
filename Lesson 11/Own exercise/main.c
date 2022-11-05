#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct link
{
	char word[12];
	struct link* next;
}Link;

Link* find_last_node(struct link* p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	printf("This is the last node %s\n",p->word);
	return p;
}

void free_memory(struct link* p)
{
	Link* temp = (Link*)malloc(sizeof(Link));
	while (p->next)
	{
		temp = p->next;
		p->next = p->next->next;
		free(temp);
	}
}

Link* initLink(Link * p, Link * head)
{
	int i;
	strcpy(head->word, "head_node");
	head->next = NULL;
	p = head;
	char word[12];
	char stop[4] = "***";
	Link* last_node = NULL;
	while (1)
	{
		last_node = find_last_node(p);
		printf("Enter the word \n");
		scanf("%s", word);
		if (!strcmp(word, stop))
		{
			printf("You entered the stop keyword\n");
			break;
		}
		else {
			Link* temp = (Link*)malloc(sizeof(Link));
			strcpy(temp->word, word);
			temp->next = NULL;
			last_node->next = temp;
		}
	}
}

int main(void)
{
	Link* p = NULL;
	Link* head = (Link*)malloc(sizeof(Link));
	p = head;
	initLink(p,head);
	Link* temp = p;
	temp = head->next;
	while (temp != NULL)
	{
		printf("Word = %c\n", temp->word[0]);
		temp = temp->next;
	}
	free_memory(p);
}