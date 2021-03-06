/**
 * CListBaseStack.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "CListBaseStack.h"


void StackInit(Stack* pstack) {
    pstack->plist = (List*)malloc(sizeof(List));
    ListInit(pstack->plist);
}


int SIsEmpty(Stack* pstack) {
    return LCount(pstack->plist) > 0 ? FALSE : TRUE;
}


void SPush(Stack* pstack, Data data) {
    LInsertFront(pstack->plist, data);
}


Data SPop(Stack* pstack) {
    Data data;
    LFirst(pstack->plist, &data);
    LRemove(pstack->plist);
    return data; 
}


Data SPeek(Stack* pstack) {
    Data data;
    LFirst(pstack->plist, &data);
    return data;
}
