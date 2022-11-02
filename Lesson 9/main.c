#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHARACTER 256

// declare function
void find_pattern(char *pattern, char *userinput);
void resolve_string(char *pattern, char *userinput, char case_sensitive);

void resolve_string(char *pattern, char *userinput, char case_sensitive) {
  if (case_sensitive == 'N') {
    // change userinput to lowercase
    for (int i = 0; i < strlen(userinput); i++) {
      userinput[i] = tolower(userinput[i]);
    }
    // change pattern to lowercase
    for (int i = 0; i < strlen(pattern); i++) {
      // change the _ to whitespace
      if (pattern[i] == '_') {
        pattern[i] = ' ';
      }
      pattern[i] = tolower(pattern[i]);
    }
    find_pattern(pattern, userinput);
  } else if (case_sensitive == 'Y') {
    for (int i = 0; i < strlen(pattern); i++) {
      if (pattern[i] == '_') {
        pattern[i] = ' ';
      }
    }
    find_pattern(pattern, userinput);
  }
}

void find_pattern(char *pattern, char *userinput) {
  int i, j;
  int found = 0;
  for (i = 0; i < strlen(userinput); i++) {
    for (j = 0; j < strlen(pattern) + 1; j++) {
      // check if it reaches the end of the pattern, if yes means all pattern match return the index of the starting index that match
      if (j == strlen(pattern)) {
        found = 1;
        printf("Matches at position %d.\n", i);
        i = strlen(userinput);
      }
      // check if got . to match any character if yes, skip the current loop
      if (pattern[j] == '.') {
        continue;
      } else if (pattern[j] == userinput[i + j]) {
        continue;
      } else {
        break;
      }
    }
  }
  if (found == 0) {
    printf("No match.");
  }
}

// function to remove the \n
void remove_newline(char *str) {
  if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
}

int main(void) {
  char user_input[MAX_CHARACTER];
  char pattern[MAX_CHARACTER];
  char case_sensitive[2];
  //printf("Enter a line of text of up to 255 character:\n");
  if (fgets(user_input, MAX_CHARACTER, stdin) != NULL) {
    remove_newline(&user_input);
    //printf("Enter a pattern of text up to 255 characters:\n");
    if (fgets(pattern, MAX_CHARACTER, stdin) != NULL) {
      remove_newline(&pattern);
     // printf("Match should be case-sensitive(Y) or case-insensitive(N):\n");
      if (fgets(case_sensitive, 2, stdin) != NULL) {
        resolve_string(&pattern, &user_input, case_sensitive[0]);
      }
    }
  }
}
