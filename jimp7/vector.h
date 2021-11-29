#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdlib.h>

struct vecInt
{
    int* items;
    int size;
    int capacity;
};
struct vecInt2
{
    struct vecInt* items;
    int size;
    int capacity;
};
void pushBack(struct vecInt* vecInt, int item);

void pushBack2(struct vecInt2* vecInt2, struct vecInt* vecInt);

struct vecInt* vecIntInit(void);

struct vecInt2* vecIntInit2(void);

struct vecInt* vecIntFromRange(int* first, int size, int baseTypeSize);

void freeVecInt(struct vecInt* vecInt);
void freeVecInt2(struct vecInt2* vecInt2);
#endif