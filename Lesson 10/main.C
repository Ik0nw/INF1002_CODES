#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//declare
int isApha(char* str);
void change_to_lower(char* str);
int guess_word(char* user_input, char* user_guess, char* guess);
int check_finish(char* guess, int size);

// check if string contain alphabets
int isAlpha(char* str)
{
	int i;
	for (i = 0; i < strlen(str) - 1; i++)
	{
		if (!isalpha(str[i])) {
			return 0;
		}

	}
	return 1;
}

void change_to_lower(char* str)
{
	int i;
	for (i = 0; i < strlen(str) - 1; i++)
	{
		str[i] = tolower(str[i]);
	}
}

void initialize_guess(char* guess)
{
	int i;
	for (i = 0; i < 12; i++)
	{
		guess[i] = '_';
	}
}

int guess_word(char* user_input, char* user_guess, char* guess)
{
	int i;
	for (i = 0; i < strlen(user_input); i++)
	{
		if (user_input[i] == user_guess)
		{
			guess[i] = user_guess;
			return 1;
		}
	}
	return 0;
}

int check_finish(char* guess, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (guess[i] != '_')
		{
			count += 1;
		}
	}
	if (count == size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(void)
{
	char user_input[13];
	int condition = 0;
	int count = 7;
	char guess[13];
	int i;
	char user_guess[2];

	for (i = 0; i < 13; i++)
	{
		guess[i] = '_';
	}
	// stop the loop if the character contains non-alphabets
	while (condition == 0)
	{
		printf("Player 1, enter a word of no more than 12 letters:\n");
		fgets(user_input, 13, stdin);
		condition = isAlpha(user_input);
		if (condition == 0)
		{
			printf("Sorry, the word must contain only English letters.\n");
			// jump back to start of loop 
			continue;
		}
		int len_userinput = strlen(user_input);
		//change to lower
		change_to_lower(user_input);
		while (count > 0)
		{
			printf("Player 2 has so far guessed:");
			for (int i = 0; i < len_userinput - 1; i++)
			{
				printf("%c ", guess[i]);
			}
			printf("\nPlayer2, you have %d guesses left. Enter your next guess:\n",count);
			// fgets to read one character from stdin
			scanf(" %c", &user_guess);
			// guess_word 
			int result = guess_word(user_input, user_guess[0], guess);
			int check_finish_condition = check_finish(guess, len_userinput);
			if (check_finish_condition == 1)
			{
				printf("Player 2 wins.\n");
				condition = 1; // break the outer loop
				break;  // break the current loop
			}
			if (result == 0)
			{
				count--;
			}
			// flush stdin
			fflush(stdin);
		}

	}

	return 0;
}
