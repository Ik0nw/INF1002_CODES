#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
//declare
void sort_score(struct Student* pStudent, int size);
struct Student
{
	int age;
	char name[20];
	float score;
};

void sort_score(struct Student* pStudent, int size)
{
	// create a empty
	struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
	int i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (pStudent[j].score > pStudent[j + 1].score)
			{
				*temp = pStudent[j];
				pStudent[j] = pStudent[j + 1];
				pStudent[j + 1] = *temp;
			}
		}
	}
}

int main(void)
{
	int len;
	printf("How many student you want to take in? \n");
	scanf("%d", &len);
	struct Student* pStu;
	pStu = (struct Student*)malloc(len * sizeof(struct Student));
	for (int i = 0; i < len; i++)
	{
		printf("What is the name of student %d\n", i + 1);
		scanf("%s", pStu[i].name);
		printf("What is the age of student %d\n", i + 1);
		scanf("%d", &pStu[i].age);
		printf("What is the score of student %d\n", i + 1);
		scanf("%f", &pStu[i].score);
	}
	sort_score(pStu, len);
	
	for (int i = 0; i < len; i++)
	{ 
		printf("Student %d: %s, %d, %f\n", i + 1, pStu[i].name, pStu[i].age, pStu[i].score);
	}

	free(pStu);

	return 0;
	
}