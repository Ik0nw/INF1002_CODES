Write a program called guessword that plays a two-player word-guessing game using a similar
procedure to the guessint program from Lab 8. The game will proceed as follows:
1. Player 1 will be asked to enter a word of up 12 letters. The word should contain only the
lower-case English letters from ‘a’ to ‘z’, and no punctuation marks or digits.
a. If Player 1 enters a word with upper case letters, the program should change them
to lower case.

    - If Player 1 enters a word with punctuation marks or digits, he or she should be
asked to enter another word.

    - The program does not need to check that the word is a “real” word (i.e. in a
dictionary).

2. Player 2 (who again has not been watching Player 1) will be asked to guess one letter at a
time.

    - At the beginning of each round, the program will output a row of characters
containing one underscore for every letter in the word to be guessed. If Player 2 has
previously guessed a letter that is in the word, the underscore will be replaced by
that letter.

    - Player 2 will enter one letter. If he or she enters an upper-case letter, the program
will convert it to lower case. If he or she enters a punctuation mark or digit, he or
she will be considered to have made an incorrect guess.

    - If the letter is not in the word, the number of incorrect guesses will be incremented.

    - If the letter is in the word, every position in the word in which that letter occurs will

be revealed at the start of the next round.

3. The game ends when either Player 2 has guessed all of the letters of the word, or when
Player 2 has made seven incorrect guesses.

Some sample output is shown below, with the user input shown in red:

![my_image](/IMG/1667323124077.png)
