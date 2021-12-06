a.out: jimp7.o textFinder.o vector.o
  cc jimp7.o textFinder.o vector.o
jimp7.o: jimp7.c textFinder.h
  cc -c jimp7.c -Wall -pedantic -Wextra
textFinder.o: textFinder.c textFinder.h vector.o
  cc -c textFinder.c vector.o -Wall -pedantic -Wextra
vector.o: vector.c vector.h
  cc -c vector.c -Wall -pedantic -Wextra
