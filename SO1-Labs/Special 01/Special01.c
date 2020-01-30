/*
Author	    : Myungjun Kim
Contents    : Special exercise 01 - Get and print text properties (number of characters, words, and syllables in strings)
*/

/* Include files */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure */
typedef struct {
	int characters;
	int words;
	int sentences;
	int syllables;
	double readability;
} properties;

/* Function prototypes */
void printTextProperties(properties);
int getCharacterCount(const char *text, const char character);
int getNumberOfWords(const char *text);
int getNumberOfSentences(const char *text);
int getNumberOfSyllablesInWord(char *word);
int getNumberOfSyllables(const char *text);
properties getTextProperties(const char *text);

/* Main function */
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

/* Print properties to the console */
void printTextProperties(properties textProperties)
{
	printf("Characters  : %d\n", textProperties.characters);
	printf("Words       : %d\n", textProperties.words);
	printf("Sentences   : %d\n", textProperties.sentences);
	printf("Syllables   : %d\n", textProperties.syllables);
	printf("Readability : %.1f out of 100\n", textProperties.readability);
}

// Return the number of occurences of a specific character in a string.
int getCharacterCount(const char *text, const char character)
{
	int characterCounter = 0, index = 0;

	while (text[index] != '\0')
	{
		if (text[index] == character)
			characterCounter++;

		index++;
	}

	return characterCounter;
}

// Return an estimation of the number of words in a string.
int getNumberOfWords(const char *text)
{
	int wordCounter = 0;

	// Assume words are separated by a blank space (' ')
	if (text[0] != '\0')
		wordCounter = getCharacterCount(text, ' ') + 1;
	else
		wordCounter = 0;

	return wordCounter;
}

// Return an estimation of the number of sentences in a string.
int getNumberOfSentences(const char *text)
{
	int sentenceCounter = 0;

	// Assume the number of sentences corresponds to the number of periods, semicolons, exclamation marks, and question marks
	if (text[0] != '\0')
	{
		sentenceCounter += getCharacterCount(text, '.');
		sentenceCounter += getCharacterCount(text, ';');
		sentenceCounter += getCharacterCount(text, '!');
		sentenceCounter += getCharacterCount(text, '?');
	}
	else
		sentenceCounter = 0;

	return sentenceCounter;
}

// Return an estimation of the number of syllables in a word.
int getNumberOfSyllablesInWord(char *word)
{
	int size = 0, index = 0, numberOfSyllables = 0;

	while (word[index] != '\0')
	{
		size++; // Size must be known to calculate the number of syllables

		if (word[index] >= 'A' && word[index] <= 'Z') // If the letter is a capital letter, change to lowercase letter
			word[index] += 32;						  // 'A' ~ 'Z' == 65 ~ 90, 'a' ~ 'z' == 97 ~ 122

		index++;
	}

	// Words containing less than or exactly 3 characters have 1 syllable.
	if (size <= 3)
		numberOfSyllables = 1;
	// For words containing more than 3 characters, the number of syllables corresponds to the number of vowels (a, e, i, o, u) in the word.
	else
	{
		numberOfSyllables += getCharacterCount(word, 'a');
		numberOfSyllables += getCharacterCount(word, 'e');
		numberOfSyllables += getCharacterCount(word, 'i');
		numberOfSyllables += getCharacterCount(word, 'o');
		numberOfSyllables += getCharacterCount(word, 'u');
	}

	return numberOfSyllables;
}

// Return an estimation of the number of syllables in a string. Use strtok().
int getNumberOfSyllables(const char *text)
{
	// Create a copy of the string
	char *copy, *word;
	int size = 0, index = 0, syllables = 0;

	while (text[index++] != '\0')
		size++;

	if (size > 0)
	{
		if ((copy = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
			exit(EXIT_FAILURE);

		for (index = 0; index < size; index++)
			copy[index] = text[index];

		// Get a pointer to the first word in copy by calling strtok(copy, " ").
		word = strtok(copy, " ");
		syllables += getNumberOfSyllablesInWord(word);

		// Get pointers to the next words by repeatedly calling strtok(NULL, " "). The function returns NULL when there is no further word.
		while ((word = strtok(NULL, " ")) != NULL)
			syllables += getNumberOfSyllablesInWord(word);

		free(copy);
	}

	return syllables;
}

// Return a structure of type properties containing the statistical values of the string text passed to the function.
properties getTextProperties(const char *text)
{
	properties textProperties;
	int size = 0, index = 0;

	while (text[index++] != '\0')
		size++;

	textProperties.characters = size;
	textProperties.words = getNumberOfWords(text);
	textProperties.sentences = getNumberOfSentences(text);
	textProperties.syllables = getNumberOfSyllables(text);
	textProperties.readability = 206.835 - (1.015 * textProperties.words / textProperties.sentences) - (84.6 * textProperties.syllables / textProperties.words);

	return textProperties;
}