#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT    256
#define MAX_INTENT   32
#define MAX_ENTITY   64
#define MAX_RESPONSE 256

typedef struct node {
	char intent[MAX_INTENT];
	char entity[MAX_ENTITY];
	char response[MAX_RESPONSE];
	struct node* next;
}NODE;

struct node* find_last_node(struct node *p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}

void knowledge_write(FILE* f, struct node* p)
{
	const char* intent_list[3];
	intent_list[0] = "[what]";
	intent_list[1] = "[where]";
	intent_list[2] = "[who]";
	char buffer[255];
	int j = 0;
	// empty string
	char empty[MAX_INPUT] = "";
	int count = 0;
	while (p != NULL)
	{
		if (!strcmp(empty,p->entity) == 0)
		{
			if (count == 1)
			{
				fputs("\n",f);
			}
			strcpy(empty, p->entity);
			fputs(p->entity, f);
			fputs("\n", f);
			count = 1;
		}
		j = snprintf(buffer, 255, "%s=%s\n", p->intent, p->response);
		fputs(buffer, f);
		p = p->next;
	}
}
int main(void)
{
	FILE* fp;
	struct node* Ptr = NULL;
	struct node * head_node = (struct node*)malloc(sizeof(struct node));
	head_node->next = NULL;
	
	
	fp = fopen("sample.ini", "r");
	if (fp == NULL)
	{
		perror("Failed: ");
		return;
	}
	struct node* last_node = head_node;
	char entity[10];
	char buffer[255];
	while (fgets(buffer, 255, fp))
	{
		// Remove trailing new line
		buffer[strcspn(buffer, "\n")] = 0;
		// if the line is empty, skip it
		if (strlen(buffer) == 0)
		{
			continue;
		}
		
		if (buffer[0] == '[')
		{
			strcpy(entity, buffer);
		}
		else
		{
			// split the string by "="
			char* token = strtok(buffer, "=");
			char* intent = token;
			token = strtok(NULL, "=");
			char* response = token;
			// create a new node
			struct node* new_node = (struct node*)malloc(sizeof(struct node));
			strcpy(new_node->entity, entity);
			strcpy(new_node->intent, intent);
			strcpy(new_node->response, response);
			new_node->next = NULL;
			// add the new node to the linked list
			last_node->next = new_node;
			last_node = new_node;
		}
	}

	// print the linked list
	struct node* p = head_node->next;
	/*
	while (p != NULL)
	{
		printf("%s %s %s\n", p->entity, p->intent, p->response);
		p = p->next;
	}
	*/

	FILE* fp2;
	fp2 = fopen("write.ini", "w");
	

	knowledge_write(fp2,head_node->next);
	
	return 0;
}
