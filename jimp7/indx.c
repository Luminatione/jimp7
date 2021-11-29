#include <stdio.h>  // wiadomo po co
#include <stdlib.h> 
#include <string.h> // strstr

#include "vector.h"

#define BUFSIZE 8192   // zakładamy, że lines będą krótsze niż 8kB

void init2DVector(vector** vec2D, int elementSize)
{
	int i;
	for(i = 0; i < vec2D.size; ++i)
	{
		vec2D = vector(elementSize);
	}
}


int main( int argc, char **argv ) {

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	vector** words = vector(sizeof(vector*));//vector of char*
	init2DVector(words, sizeof(char));

	vector** lines = vector(sizeof(vector*));//vector of int*
	init2DVector(lines, sizeof(int));

	int i, wordsAmount = 0;
  	for( i= 2; i < argc; i++ ) {
		words[wordsAmount]= argv[i];
		lines[wordsAmount][0]= 0;
		wordsAmount++;
	}

	if( wordsAmount == 0 ) {
		fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

	int lines_amount = 0;
	vector* buf = vector(sizeof(char));//vector of char
	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		lines_amount++;
		for( i= 0; i < wordsAmount; i++ )
			if( strstr( buf, words[i] ) != NULL ) {
				lines[i][0]++;
				lines[i][lines[i][0]]= lines_amount;
			}
	}

	for( i= 0; i < wordsAmount; i++ ) {
		if( lines[i][0] > 0 ) {
			printf( "słowo \"%s\" wystąpiło w liniach:", words[i] );
			int j;
			for( j= 1; j <= lines[i][0]; j++ )
				printf( " %d", lines[i][j] );
			printf( "\n" );
		} else {
		  printf( "nie napotkano słowa \"%s\"\n", words[i] );
		}
	}
	
	return EXIT_SUCCESS;
}
