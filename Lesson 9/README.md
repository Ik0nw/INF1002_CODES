# Tinygrep

Unix systems provide a utility known as grep that searches the lines of a file for a given pattern of
characters. (The pattern is known as a regular expression and the name grep comes from “global
regular expression print”). We won’t learn how to use files until Week 12, so we’ll just search a
string entered at the keyboard. We’ll also support only very simple patterns.
Write a program, called tinygrep, that performs as follows:
1. The program asks the user to enter a line of text of up to 255 characters.
2. The program asks the user to enter a pattern (a string), also of up to 255 characters.
3. The program asks the user whether the match should be case-sensitive or case-insensitive.
4. The program outputs whether the pattern occurs anywhere in the line of text, and, if it does,
the index of the string at which the first instance of the pattern occurs.
The rules for patterns are as follows:


![my_image](/IMG/1667190183901.jpg)

• Any English letter matches itself. If the match is case-sensitive, lower case letters match
only lower case letters, and upper case letters match only upper case letters. If the match is
case-insensitive, lower case letters match upper case letters, and vice versa.

• A dot (.) matches any character.

• An underscore (_) matches any form of whitespace (i.e. any character for which
isspace() returns a true value).

• All other characters match only themselves.

The following table shows some examples.
Text Pattern Case-Sensitive Output

You might like to proceed as follows:

1. Write a main program that reads the strings and case-sensitivity information as described
above.

2. Ignoring the pattern-matching rules for now, write a loop that simply searches the input
text for an occurrence of the pattern string using strncmp() or similar function.

3. Replace strncmp() with a new function that matches case-sensitively or case-insensitively
depending on the user’s answer to this question.

4. Modify your new function to handle dot and underscore characters according to the rules
above.
