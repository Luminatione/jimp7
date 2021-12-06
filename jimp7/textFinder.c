#include <string.h>

#include "textFinder.h"

char* getWordWithSpacesOnBeginAndEnd(char* a)
{
	char* result = malloc((strlen(a) + 3) * sizeof(result));
	result[0] = ' ';
	int i, j;
	for (i = 1, j = 0; j < (int)strlen(a); ++j)
	{
		if (a[j] == '\n' || a[j] == '\r' || a[j] == ',' || a[j] == '.')
		{
			continue;
		}
		result[i] = a[j];
		++i;
	}
	result[i] = ' ';
	++i;
	result[i] = '\0';
	return result;
}
void addWord(struct textFinder* textFinder, char* rawWord)
{
	int* word = (int*)getWordWithSpacesOnBeginAndEnd(rawWord);
	struct vecInt* buf = vecIntFromRange(word, (int)strlen((char*)word) + 1, sizeof(char));
	pushBack2(textFinder->words, buf);
	freeVecInt(buf);
	free(word);
	buf = vecIntInit();
	pushBack2(textFinder->lines, buf);
	free(buf);
	textFinder->wordsAmount++;
}
void initializeTextFinder(struct textFinder* textFinder, char** words, int wordsAmount, FILE* in)
{
	textFinder->wordsAmount = 0;
	textFinder->linesAmount = 0;
	textFinder->in = in;
	textFinder->words = vecIntInit2();
	textFinder->lines = vecIntInit2();

	int i;
	for (i = 0; i < wordsAmount; i++) {
		addWord(textFinder, words[i]);
	}
}

int validateTextFinder(struct textFinder* textFinder)
{
	if (textFinder->wordsAmount == 0)
	{
		return -1;
	}

	if (textFinder->in == NULL)
	{
		return -1;
	}
	return 0;
}
void checkLine(struct textFinder* textFinder, char* line)
{
	int i;
	char* bufWithSpaces = getWordWithSpacesOnBeginAndEnd(line);

	for (i = 0; i < textFinder->wordsAmount; i++)
	{
		if (strstr(bufWithSpaces, (char*)(textFinder->words->items[i].items)) != NULL)
		{
			pushBack(&textFinder->lines->items[i], textFinder->linesAmount);
		}
	}
	free(bufWithSpaces);
}
void parseTextFinderInput(struct textFinder* textFinder)
{
	char buf[BUFSIZE];
	while (fgets(buf, BUFSIZE, textFinder->in) != NULL)
	{
		textFinder->linesAmount++;
		checkLine(textFinder, buf);
	}
}

void printWordsLines(struct textFinder* textFinder, int wordIndex)
{
	int j;
	for (j = 0; j < textFinder->lines->items[wordIndex].size; j++)
	{
		printf(" %d", textFinder->lines->items[wordIndex].items[j]);
	}
}

void printWordOutput(struct textFinder* textFinder, int wordIndex)
{
	if (textFinder->lines->items[wordIndex].size > 0)
	{
		printf("slowo%swystapilo w liniach:", (char*)(textFinder->words->items[wordIndex].items));
		printWordsLines(textFinder, wordIndex);
		printf("\n");
	}
	else
	{
		printf("nie napotkano slowa%s\n", (char*)(textFinder->words->items[wordIndex].items));
	}
}
void printTextFinderOutput(struct textFinder* textFinder)
{
	int i;
	for (i = 0; i < textFinder->wordsAmount; i++)
	{
		printWordOutput(textFinder, i);
	}
}

void freeTextFinder(struct textFinder* textFinder)
{
	freeVecInt2(textFinder->words);
	freeVecInt2(textFinder->lines);
	free(textFinder);
}
