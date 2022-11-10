#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct link
{
	char word[12];
	struct link* next;
}Link;

void free_memory(struct link* head)
{
	Link* temp = (Link*)malloc(sizeof(Link));
	while (head->next)
	{
		temp = head->next;
		head->next = head->next->next;
		free(temp);
	}
}

void change_to_lower(char* str) {
	int i;
	for (i = 0; i < strlen(str) - 1; i++) {
		str[i] = tolower(str[i]);
	}
}

void insert_element(struct link* head, char* input)
{
	Link* new_node = (Link*)malloc(sizeof(Link));
	strcpy(new_node->word, input);
	bool judge = true;
	if (head->next != NULL)
	{
		// Set 2 pointers
		Link* currentPtr = head->next;
		Link* prePtr = head;
		while (strcmp(currentPtr->word,input) < 0)
		{
			if (currentPtr->next == NULL)
			{
				currentPtr->next = new_node;
				new_node->next = NULL;
				judge = false;
				break;
			}
			currentPtr = currentPtr->next;
			prePtr = prePtr->next;
		}
		if (judge)
		{
			prePtr->next = new_node;
			new_node->next = currentPtr;
		}
	}
	else {
		head->next = new_node;
		new_node->next = NULL;
	}
}


Link* initLink(Link* p, Link* head)
{
	int i;
	head->next = NULL;
	p = head;
	char word[12];
	char stop[4] = "***";
	Link* last_node = NULL;
	while (1)
	{
		scanf("%s", word);
		if (!strcmp(word, stop))
		{
			printf("All the entered words in order:\n");
			break;
		}
		else {
			change_to_lower(word);
			insert_element(head, word);
		}
	}
}

int main(void)
{
	Link* p = NULL;
	Link* head = (Link*)malloc(sizeof(Link));
	initLink(p, head);
	Link* temp = p;
	temp = head->next;

	// print all the words in list
	while (temp != NULL)
	{
		printf("%s\n", temp->word);
		temp = temp->next;
	}
	free_memory(head);
}
