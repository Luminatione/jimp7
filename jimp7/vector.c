#include "vector.h"

#include <string.h>

void pushBack(struct vecInt* vecInt, int item)
{
    if(vecInt->items == NULL)
    {
        vecInt->items = malloc(sizeof(int));
        vecInt->capacity = 1;
        vecInt->size = 0;
    }
    if(vecInt->size < vecInt->capacity)
    {
        vecInt->items[vecInt->size] = item;
        ++vecInt->size;
        return;
    }
    vecInt->capacity*=2;
    vecInt->items = realloc(vecInt->items, vecInt->capacity * sizeof(int));
    vecInt->items[vecInt->size] = item;
    ++vecInt->size;
}

void initializeAndPushBackVec(struct vecInt2* vecInt2, struct vecInt* vecInt)
{
	int i;
    struct vecInt* vec = vecIntInit();
    vecInt2->items[vecInt2->size] = *vec;
    free(vec);
	for(i = 0; i < vecInt->size; ++i)
	{
		pushBack(&vecInt2->items[vecInt2->size], vecInt->items[i]);
	}
	++vecInt2->size;
}

void pushBack2(struct vecInt2* vecInt2, struct vecInt* vecInt)
{
    if (vecInt2->items == NULL)
    {
        vecInt2->items = malloc(sizeof(struct vecInt2));
        struct vecInt* vec = vecIntInit();
        vecInt2->items[0] = *vec;
        free(vec);
        vecInt2->capacity = 1;
        vecInt2->size = 0;
    }
    if (vecInt2->size < vecInt2->capacity)
    {
        initializeAndPushBackVec(vecInt2, vecInt);
        return;
    }
    vecInt2->capacity *= 2;
    vecInt2->items = realloc(vecInt2->items, vecInt2->capacity * sizeof(struct vecInt));
    initializeAndPushBackVec(vecInt2, vecInt);
}

void freeVecInt(struct vecInt* vecInt)
{
    free(vecInt->items);
    free(vecInt);
}

void freeVecInt2(struct vecInt2* vecInt2)
{
    int i;
    for(i = 0; i < vecInt2->capacity; ++i)
    {
        free(vecInt2->items[i].items);
    }
    free(vecInt2->items);
    free(vecInt2);
}

struct vecInt2* vecIntInit2()
{
    struct vecInt2* vecInt2 = malloc(sizeof(struct vecInt2));
    vecInt2->size = 0;
    vecInt2->capacity = 0;
    vecInt2->items = NULL;
    return vecInt2;
}

struct vecInt* vecIntFromRange(int* first, int size, int baseTypeSize)
{
    struct vecInt* vecInt = vecIntInit();
    int i;
    for(i = 0; i < size; ++i)
    {
        pushBack(vecInt, *first);
        first += baseTypeSize;
    }
    return vecInt;
}
struct vecInt* vecIntInit()
{
    struct vecInt* a = malloc(sizeof (struct vecInt));
	a->size = 0;
	a->capacity = 0;
	a->items = NULL;
    return a;
}