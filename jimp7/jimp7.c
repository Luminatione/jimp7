#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h> 

#include "textFinder.h"

typedef struct textFinder textFinder;


int main(int argc, char** argv) {
	FILE* in = argc > 1 ? fopen(argv[1], "r") : stdin;

	textFinder* textFinder = malloc(sizeof(struct textFinder));
	initializeTextFinder(textFinder, argv + 2, argc - 2, in);

	if (validateTextFinder(textFinder) != 0)
	{
		printf("%s: Nie poprawne parametry wywolania", argv[0]);
		return EXIT_FAILURE;
	}

	parseTextFinderInput(textFinder);
	printTextFinderOutput(textFinder);
	freeTextFinder(textFinder);
	fclose(in);

	return EXIT_SUCCESS;
}
