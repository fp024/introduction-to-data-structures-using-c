/**
 * CListBaseStack.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "CListBaseStack.h"


void StackInit(Stack* pstack) {
    ListInit(pstack);
}


int SIsEmpty(Stack* pstack) {
    return LCount(pstack) > 0 ? FALSE : TRUE;
}


void SPush(Stack* pstack, Data data) {
    LInsertFront(pstack, data);
}


Data SPop(Stack* pstack) {
    Data data;
    LFirst(pstack, &data);
    LRemove(pstack);
    return data; // 이부분이 해깔린다. 
}


Data SPeek(Stack* pstack) {
    Data data;
    LFirst(pstack, &data);
    return data;
}
