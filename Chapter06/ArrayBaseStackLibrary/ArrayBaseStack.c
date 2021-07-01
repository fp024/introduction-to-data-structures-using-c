/**
 * ArrayBaseStack.c
 *
 * 배열기반 스택 구현
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack) {
    pstack->topIndex = -1;     // topIndex의 -1은 빈상태를 의미한다.
}


int SIsEmpty(Stack* pstack) {
    if (pstack->topIndex == -1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


void SPush(Stack* pstack, Data data) {
    pstack->topIndex += 1;      // 데이터를 추가를 위한 인덱스 값 증가
    pstack->stackArray[pstack->topIndex] = data;    // 데이터 저장
}


Data SPop(Stack* pstack) {
    // int여서 명시적으로 배열의 데이터를 지울 필요는 없음.
    // 동적으로 할당 받은 데이터의 경우라면 이 함수 반환 받은 사용처에서 free()하면 될 것 같다.

    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error");
        exit(-1);
    }

    int rIdx = pstack->topIndex;
    pstack->topIndex -= 1;

    return pstack->stackArray[rIdx];
}



Data SPeek(Stack* pstack) {
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error");
        exit(-1);
    }

    return pstack->stackArray[pstack->topIndex];
}
