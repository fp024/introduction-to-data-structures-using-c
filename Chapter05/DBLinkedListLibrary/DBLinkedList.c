#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DBLinkedList.h"


void ListInit(List* plist) {
    plist->head = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}



void LInsert(List* plist, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));    // 새 노드 생성

    if (newNode == NULL) {
        assert(FALSE);
        return;
    }

    newNode->data = data;

    // 아래 문자에서 plist->head는 NULL이다!
    newNode->next = plist->head;    // 새 노드의 next를 NULL로 초기화

    if (plist->head != NULL) {
        plist->head->prev = newNode;
    }

    newNode->prev = NULL;           // 새 노드의 prev를 NULL로 초기화
    plist->head = newNode;          // 포인터 변수 head가 새노드를 가리키게 함.


    (plist->numOfData)++;
}




void LInsertTail(List* plist, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));    // 새 노드 생성

    if (newNode == NULL) {
        assert(FALSE);
        return;
    }

    newNode->data = data;   // 새 노드에 데이터 저장
    newNode->next = NULL;
    newNode->prev = NULL;

    if (plist->head == NULL) {
        plist->head = newNode;
        plist->cur = newNode;
    }
    else {
        while (plist->cur->next != NULL) {
            plist->cur = plist->cur->next;
        }

        plist->cur->next = newNode;
        newNode->prev = plist->cur;

        plist->cur = newNode;
    }

    (plist->numOfData)++;
}



int LFirst(List* plist, Data* pdata) {
    if (plist->head == NULL) {
        return FALSE;
    }

    plist->cur = plist->head;

    *pdata = plist->cur->data;
    return TRUE;
}



int LNext(List* plist, Data* pdata) {
    if (plist->head == NULL || plist->cur->next == NULL) {
        return FALSE;
    }

    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;

    return TRUE;
}


int LPrevious(List* plist, Data* pdata) {
    if (plist->head == NULL || plist->cur->prev == NULL) {
        return FALSE;
    }

    plist->cur = plist->cur->prev;

    *pdata = plist->cur->data;

    return TRUE;
}


Data LRemove(List* plist) {
    // TODO: 문제 05-2 먼저 풀고 구현하자.
    return NULL;
}


int LCount(List* plist) {
    return plist->numOfData;
}
