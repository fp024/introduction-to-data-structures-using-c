/**
 * ListBaseStack.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"


void StackInit(Stack* pstack) {
    pstack->head = NULL; // 포인터 변수 head는 NULL로 초기화
}


int SIsEmpty(Stack* pstack) {
    if (pstack->head == NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


void SPush(Stack* pstack, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성

    if (newNode == NULL) {
        exit(-1);
    }

    newNode->data = data;           // 새 노드에 데이터 저장
    newNode->next = pstack->head;   // 새 노드가 추가된 노드를 가리킴

    pstack->head = newNode;     // 포인터 변수 head가 새 노드를 가리킴
}


Data SPop(Stack* pstack) {
    Data rdata;
    Node* rnode;

    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rdata = pstack->head->data;     // 삭제할 노드의 데이터를 임시로 저장
    rnode = pstack->head;           // 삭제할 노드의 주소 값을 임시로 저장

    pstack->head = pstack->head->next; // 삭제할 노드의 다음 노드를 head가 가리킴

    free(rnode); // 노드 삭제

    return rdata; // 삭제된 노드의 데이터 변환
}


Data SPeek(Stack* pstack) {
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }
    return pstack->head->data; // 스택 top의 데이터 반환
}