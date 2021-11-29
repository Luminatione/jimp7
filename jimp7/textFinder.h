#ifndef _TEXTFINDER_H
#define _TEXTFINDER_H

#include <stdio.h> 

#include "vector.h"

#define BUFSIZE 8192

typedef struct vecInt2 vector2;
typedef struct vecInt vector;

struct textFinder {
	FILE* in;

	vector2* words;
	vector2* lines;
	int wordsAmount;
	int linesAmount;
};

void initializeTextFinder(struct textFinder* textFinder, char** words, int wordsAmount, FILE* in);

int validateTextFinder(struct textFinder* textFinder);

void parseTextFinderInput(struct textFinder* textFinder);

void printTextFinderOutput(struct textFinder* textFinder);

void freeTextFinder(struct textFinder* textFinder);

#endif
