/*
Author	    : Myungjun Kim
Contents    : Special exercise 01 - Get and print text properties (number of characters, words, and syllables in strings)
*/

#include <stdio.h>

void printTextProperties(properties);
int getCharacterCount(char *text, char character);
int getNumberOfWords(char *text);
int getNumberOfSentences(char *text);
int getNumberOfSyllablesInWord(char *word);
int getNumberOfSyllables(char *text);
properties getTextProperties(char *text);

int main(void)
{
	// Simple test sentences
	char easy[] = "No one said; it would. be easy! AaEe IiOoUu?";

	// William Lyon Phelps: The Pleasure of Books
	char bookSpeech[] =
		"A borrowed book is like a guest in the house; it must be treated with punctiliousness, with a certain considerate formality. "
		"You must see that it sustains no damage; it must not suffer while under your roof. "
		"You cannot leave it carelessly, you cannot mark it, you cannot turn down the pages, you cannot use it familiarly. "
		"And then, some day, although this is seldom done, you really ought to return it.";

	// Determine text properties
	properties easyProperties = getTextProperties(easy);
	properties bookProperties = getTextProperties(bookSpeech);

	// Display results
	printf("\nTest string \"%s\":\n", easy);
	printTextProperties(easyProperties);

	printf("\nWilliam Lyon Phelps, The Pleasure of Books:\n");
	printTextProperties(bookProperties);

	getchar();
	return 0;
}

void printTextProperties(properties textProperties)
{
	printf("Characters  : %d\n", textProperties.characters);
	printf("Words       : %d\n", textProperties.words);
	printf("Sentences   : %d\n", textProperties.sentences);
	printf("Syllables   : %d\n", textProperties.syllables);
	printf("Readability : %.1f out of 100\n", textProperties.readability);
}